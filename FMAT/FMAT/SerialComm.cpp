#include "pch.h"          // プリコンパイルヘッダを使うプロジェクトの場合
#include "SerialComm.h"
#include <windows.h>

SerialComm::SerialComm() {}
SerialComm::~SerialComm() { Close(); }

// 以下にあなたの提示した Open / Close / Write / Read を貼り付ける
// （この部分はそのままでOK）
bool SerialComm::Open(const CommOpenParams& p, CString& err)
{
    Close();
    CString path = p.portOrPath;
    if (path.Left(3).CompareNoCase(L"COM") == 0 && path.GetLength() > 4) {
        // COM10+ は "\\.\COM10" 形式が必要
        path.Format(L"\\\\.\\%s", p.portOrPath.GetString());
    }
    m_h = CreateFile(path, GENERIC_READ | GENERIC_WRITE, 0, nullptr,
        OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, nullptr);
    if (m_h == INVALID_HANDLE_VALUE) { err = L"CreateFile failed"; return false; }

    // タイムアウト覚書
    m_timeoutMs = p.timeoutMs;

    // DCB 設定（8N1 固定の例）
    DCB dcb{}; dcb.DCBlength = sizeof(DCB);
    if (!GetCommState(m_h, &dcb)) { err = L"GetCommState failed"; Close(); return false; }
    dcb.BaudRate = p.baud; dcb.ByteSize = 8; dcb.Parity = NOPARITY; dcb.StopBits = ONESTOPBIT;
    dcb.fOutxCtsFlow = dcb.fOutxDsrFlow = FALSE; dcb.fDtrControl = DTR_CONTROL_ENABLE;
    dcb.fRtsControl = RTS_CONTROL_ENABLE;
    if (!SetCommState(m_h, &dcb)) { err = L"SetCommState failed"; Close(); return false; }

    // バッファとタイムアウト
    SetupComm(m_h, 1 << 20, 1 << 20); // 1MB
    COMMTIMEOUTS to{}; to.ReadIntervalTimeout = MAXDWORD; // Overlapped時の推奨
    to.ReadTotalTimeoutConstant = m_timeoutMs;
    to.WriteTotalTimeoutConstant = m_timeoutMs;
    SetCommTimeouts(m_h, &to);

    // Overlappedイベント
    m_ovRead.hEvent = CreateEvent(nullptr, TRUE, FALSE, nullptr);
    m_ovWrite.hEvent = CreateEvent(nullptr, TRUE, FALSE, nullptr);
    if (!m_ovRead.hEvent || !m_ovWrite.hEvent) { err = L"CreateEvent failed"; Close(); return false; }
    return true;
}

void SerialComm::Close()
{
    if (m_h != INVALID_HANDLE_VALUE) {
        CancelIo(m_h);
        if (m_ovRead.hEvent)  CloseHandle(m_ovRead.hEvent);
        if (m_ovWrite.hEvent) CloseHandle(m_ovWrite.hEvent);
        CloseHandle(m_h);
    }
    m_h = INVALID_HANDLE_VALUE; m_ovRead = {}; m_ovWrite = {};
}

bool SerialComm::Write(const void* buf, DWORD n, DWORD& written, CString& err)
{
    written = 0; if (m_h == INVALID_HANDLE_VALUE) { err = L"not open"; return false; }
    ResetEvent(m_ovWrite.hEvent);
    if (!WriteFile(m_h, buf, n, nullptr, &m_ovWrite)) {
        if (GetLastError() != ERROR_IO_PENDING) { err = L"WriteFile failed"; return false; }
        DWORD rc = WaitForSingleObject(m_ovWrite.hEvent, m_timeoutMs);
        if (rc != WAIT_OBJECT_0 || !GetOverlappedResult(m_h, &m_ovWrite, &written, FALSE)) {
            err = L"Write timeout/error"; CancelIo(m_h); return false;
        }
    }
    else {
        GetOverlappedResult(m_h, &m_ovWrite, &written, FALSE);
    }
    return true;
}

bool SerialComm::Read(void* buf, DWORD n, DWORD& read, CString& err)
{
    read = 0; if (m_h == INVALID_HANDLE_VALUE) { err = L"not open"; return false; }
    ResetEvent(m_ovRead.hEvent);
    if (!ReadFile(m_h, buf, n, nullptr, &m_ovRead)) {
        if (GetLastError() != ERROR_IO_PENDING) { err = L"ReadFile failed"; return false; }
        DWORD rc = WaitForSingleObject(m_ovRead.hEvent, m_timeoutMs);
        if (rc != WAIT_OBJECT_0 || !GetOverlappedResult(m_h, &m_ovRead, &read, FALSE)) {
            err = L"Read timeout/error"; CancelIo(m_h); return false;
        }
    }
    else {
        GetOverlappedResult(m_h, &m_ovRead, &read, FALSE);
    }
    return true;
}
