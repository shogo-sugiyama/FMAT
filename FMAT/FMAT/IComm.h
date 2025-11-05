// IComm.h : 通信バックエンドの共通インターフェース
#pragma once
#include <afxstr.h>  // CString 用
#include <windows.h>

struct CommOpenParams {
    CString portOrPath; // "COM3" or WinUSB path
    DWORD   baud = 115200; // COM の場合のみ使用
    DWORD   timeoutMs = 1000;
};

class IComm {
public:
    virtual ~IComm() {}
    virtual bool Open(const CommOpenParams& p, CString& err) = 0;
    virtual void Close() = 0;
    virtual bool Write(const void* buf, DWORD n, DWORD& written, CString& err) = 0;
    virtual bool Read(void* buf, DWORD n, DWORD& read, CString& err) = 0;
    virtual bool IsOpen() const = 0;
};
