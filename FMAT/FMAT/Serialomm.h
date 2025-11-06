#pragma once
#include "IComm.h"

class SerialComm : public IComm
{
public:
    SerialComm();
    ~SerialComm() override;

    bool Open(const CommOpenParams& p, CString& err) override;
    void Close() override;
    bool Write(const void* buf, DWORD n, DWORD& written, CString& err) override;
    bool Read(void* buf, DWORD n, DWORD& read, CString& err) override;
    bool IsOpen() const override { return m_h != INVALID_HANDLE_VALUE; }

private:
    HANDLE m_h = INVALID_HANDLE_VALUE;
    OVERLAPPED m_ovRead{};
    OVERLAPPED m_ovWrite{};
    DWORD m_timeoutMs = 1000;
};

