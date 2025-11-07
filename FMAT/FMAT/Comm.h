#pragma once

#include	<Windows.h>
#include	<Winbase.h>

#include "FormatSTX_ETX.h"

#ifndef STX
#define		STX			0x02
#define		ETX			0x03
#endif


class CComm
{
private:
public:
	FormatSTX_ETX	m_FormatSTX_ETX;

	HANDLE			m_Mutex;
	int				m_nError;
	bool			m_bStop;
	bool			m_bOpen;
	bool			m_bReceived;

	HANDLE			m_hReadThread;
	CString			m_ReadStr;				// ŽóM•¶Žš—ñ
	CString			m_ReadLine;				// 1sŽóM•¶Žš—ñ
	int				m_nCount;

	HANDLE			m_hCommPort;
	OVERLAPPED m_OverlappedRead, m_OverlappedWrite;
	bool			m_bTest;
	int				m_nSp;		// “ÁŽêƒ‚[ƒh
	int				m_Return;		// •ÔMó‘ÔƒfƒoƒbƒO•\Ž¦—p

public:
	CEvent			m_evReadLine;			// ˆês“Ç‚Ýo‚µƒCƒxƒ“ƒg
	CEvent			m_evReadCancel;			// ˆês“Ç‚Ýo‚µƒLƒƒƒ“ƒZƒ‹ƒCƒxƒ“ƒg
	CString			m_strMessage;
	DWORD nNGErrorComm = 0;

public:
	CComm(void);
	~CComm(void);

//	int CommStart(CString CommPortName, int CommBoudRates, int typeFormat);
	int CommStart(int nCommPort, int CommBoudRates, bool bCheck);
	int CommStop();
	int GetErrorCode() { return m_nError;  }
	// ŽóMThread
	static DWORD FAR PASCAL ReadThread(CComm* parent);
};
