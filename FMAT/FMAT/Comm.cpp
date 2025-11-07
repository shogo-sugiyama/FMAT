#include "pch.h"
#include "Comm.h"
#include "winsock2.h"
#include <ws2tcpip.h>

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
#define new DEBUG_NEW 
#endif

CComm::CComm(void)
{
	m_bOpen = false;
	m_hReadThread = 0;
	m_nError = 0;
	m_Mutex = CreateMutex(NULL, TRUE, NULL);
	m_bStop = false;
	m_hCommPort = NULL; // NVALID_HANDLE_VALUE;
	memset(&m_OverlappedRead, 0, sizeof(OVERLAPPED));
	memset(&m_OverlappedWrite, 0, sizeof(OVERLAPPED));
	m_nCount = 0;
	m_ReadStr.Empty();
	m_ReadLine.Empty();
	m_nSp = 0;
	m_Return = 0;
	m_bReceived = false;
}


CComm::~CComm(void)
{
	ReleaseMutex(m_Mutex);
	CloseHandle(m_Mutex);
	m_Mutex = NULL;
}

// ’ÊMŠJŽn
//int CComm::CommStart(CString CommPortName, int CommBoudRates, int typeFormat)
int CComm::CommStart(int nCommPort, int CommBoudRates, bool bCheck)
{
#if 0
	int			rc;
	if (m_bOpen)
	{
		rc = CommStop();
		if (!rc)
		{
			m_strMessage.Format("’ÊMƒ|[ƒg‚ð•Â‚¶‚é‚±‚Æ‚ªo—ˆ‚Ü‚¹‚ñ‚Å‚µ‚½B\nƒVƒXƒeƒ€‚ð—§‚¿ã‚°’¼‚µ‚Ä‚Ý‚Ä‰º‚³‚¢B");
			return false;
		}
	}
#endif

	DCB		portConfig;
	BOOL    nBret = FALSE;

	m_bStop = false;
	m_bTest = true;

	/* ’ÊMƒfƒoƒCƒX‚Ì–¼‘O‚ÌƒAƒhƒŒƒX */
	// Žw’èƒ|[ƒg‚ðŠJ‚­
	TCHAR szPort[20];
	//	szPort.Format(_T("COM%d"), nCommPort );
	wsprintf(szPort, _T("\\\\.\\COM%d"), nCommPort);

	m_hCommPort = CreateFile(
		szPort,
		GENERIC_READ | GENERIC_WRITE,               // “Ç‚Ý‘‚«‚ðŽw’è
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, // | FILE_FLAG_OVERLAPPED,
//		0,
NULL);
	m_nError = 0;

	if (m_hCommPort == INVALID_HANDLE_VALUE)
	{
		m_strMessage.Format(_T("Port could not open."));
		m_nError = 1;
		return false;
	}
	memset(&m_OverlappedRead, 0, sizeof(OVERLAPPED));
	memset(&m_OverlappedWrite, 0, sizeof(OVERLAPPED));

	//SetCommMask(m_hCommPort, EV_RXCHAR | EV_CTS | EV_DSR);

	nBret = SetupComm(		//Ý’è
		m_hCommPort,		// @’ÊMƒfƒoƒCƒX‚Ìƒnƒ“ƒhƒ‹FCreateFile()‚ÅŽæ“¾‚µ‚½ƒnƒ“ƒhƒ‹‚ðŽw’è
		1024,				//   ŽóMƒoƒbƒtƒ@[ƒTƒCƒYF@ŽóM‚Ìƒoƒbƒtƒ@[ƒTƒCƒY‚ðƒoƒCƒg’PˆÊ‚ÅŽw’è
		1024				// @‘—Mƒoƒbƒtƒ@[ƒTƒCƒYF@‘—M‚Ìƒoƒbƒtƒ@[ƒTƒCƒY‚ðƒoƒCƒg’PˆÊ‚ÅŽw’è
	);

	if (nBret == FALSE)		//@Ž¸”s‚µ‚½ê‡
	{
		m_strMessage.Format(_T("SetupComm failed."));
		m_nError = 2;
		CloseHandle(m_hCommPort);
		return false;
	}

	nBret = PurgeComm(		//Á‹Ž
		m_hCommPort,		// @’ÊMƒfƒoƒCƒX‚Ìƒnƒ“ƒhƒ‹FCreateFile()‚ÅŽæ“¾‚µ‚½ƒnƒ“ƒhƒ‹‚ðŽw’è
		PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR
		//   ŽÀs‚·‚é‘€ìF ã‹L‚Í–¢ˆ—‚Ì“Ç‘‚«‚Ì’†Ž~‹y‚Ñ‘—ŽóM‚Ìƒoƒbƒtƒ@[‚ÌƒNƒŠƒA‚ðŽw’è
	);

	if (nBret == FALSE)		//Ž¸”s‚µ‚½ê‡
	{
		m_strMessage.Format(_T("PurgeComm failed."));
		m_nError = 3;
		CloseHandle(m_hCommPort);
		return false;
	}

	GetCommState(m_hCommPort, &portConfig);		//Œ»Ý‚ÌÝ’è’l‚ð“Ç‚Ýž‚Ý
	portConfig.DCBlength = sizeof(DCB);
	portConfig.BaudRate = CommBoudRates;
	portConfig.ByteSize = 8;
	portConfig.Parity = NOPARITY;
	portConfig.StopBits = ONESTOPBIT;	// stopbits = 1

	portConfig.fBinary = TRUE;
	portConfig.fParity = FALSE;

#if 1
	portConfig.fOutxCtsFlow = FALSE;
	portConfig.fRtsControl = RTS_CONTROL_DISABLE;
#else
	portConfig.fOutxCtsFlow = TRUE;
	portConfig.fRtsControl = RTS_CONTROL_ENABLE;
#endif

#if 1
	portConfig.fOutxDsrFlow = FALSE;
	portConfig.fDtrControl = DTR_CONTROL_DISABLE;
#else
	portConfig.fOutxDsrFlow = TRUE;
	portConfig.fDtrControl = DTR_CONTROL_ENABLE;
#endif

	portConfig.fOutX = FALSE;
	portConfig.fInX = FALSE;
	portConfig.fTXContinueOnXoff = FALSE; // TRUE;
	portConfig.XonLim = 100;
	portConfig.XoffLim = 100;
	portConfig.XonChar = 0x11;
	portConfig.XoffChar = 0x13;
	portConfig.fNull = FALSE;
	portConfig.fAbortOnError = TRUE;
	portConfig.fErrorChar = 0x00;
	portConfig.ErrorChar = 0x03;
	portConfig.EvtChar = 0x02;

	// ƒ|[ƒg‚Ìƒ{[ƒŒ[ƒgAƒpƒŠƒeƒB“™‚ðÝ’è
	nBret = SetCommState(m_hCommPort, &portConfig);
	if (nBret == FALSE)		//Ž¸”s‚µ‚½ê‡
	{
		m_strMessage.Format(_T("’ÊMƒ|[ƒg %d ‚ªƒI[ƒvƒ“‚Å‚«‚Ü‚¹‚ñ‚Å‚µ‚½B\n’ÊMÝ’è‚ð•ÏX‚µ‚Ä‚Ý‚Ä‰º‚³‚¢B"), nCommPort);
		m_nError = 4;
		return false;
	}

#if 1
	COMMTIMEOUTS timeout; // COMMTIMEOUTS\‘¢‘Ì‚Ì•Ï”‚ðéŒ¾

	GetCommTimeouts(m_hCommPort, &timeout);			// ƒ^ƒCƒ€ƒAƒEƒg‚ÌÝ’èó‘Ô‚ðŽæ“¾

	timeout.ReadIntervalTimeout = 10;				// •¶Žš“ÇžŽž‚Ì‚Q•¶ŽšŠÔ‚Ì‘S‘Ì‘Ò‚¿ŽžŠÔimsecj
	//timeout.ReadIntervalTimeout = MAXDWORD;			// •¶Žš“ÇžŽž‚Ì‚Q•¶ŽšŠÔ‚Ì‘S‘Ì‘Ò‚¿ŽžŠÔimsecj

	timeout.ReadTotalTimeoutMultiplier = 0;			//“Çž‚Ì‚P•¶Žš‚ ‚½‚è‚ÌŽžŠÔ
	timeout.ReadTotalTimeoutConstant = 10;			//“ÇžƒGƒ‰[ŒŸo—p‚Ìƒ^ƒCƒ€ƒAƒEƒgŽžŠÔ
	//timeout.ReadTotalTimeoutConstant = 0;			//“ÇžƒGƒ‰[ŒŸo—p‚Ìƒ^ƒCƒ€ƒAƒEƒgŽžŠÔ
			//(ŽóMƒg[ƒ^ƒ‹ƒ^ƒCƒ€ƒAƒEƒg) = ReadTotalTimeoutMultiplier * (ŽóM—\’èƒoƒCƒg”) + ReadTotalTimeoutConstant

	timeout.WriteTotalTimeoutMultiplier = 0;		//‘‚«ž‚Ý‚P•¶Žš‚ ‚½‚è‚Ì‘Ò‚¿ŽžŠÔ
	timeout.WriteTotalTimeoutConstant = 10;			//‘‚«ž‚ÝƒGƒ‰[ŒŸo—p‚Ìƒ^ƒCƒ€ƒAƒEƒgŽžŠÔ
	//timeout.WriteTotalTimeoutConstant = 0;			//‘‚«ž‚ÝƒGƒ‰[ŒŸo—p‚Ìƒ^ƒCƒ€ƒAƒEƒgŽžŠÔ
			//(‘—Mƒg[ƒ^ƒ‹ƒ^ƒCƒ€ƒAƒEƒg) = WriteTotalTimeoutMultiplier * (‘—M—\’èƒoƒCƒg”) + WriteTotalTimeoutConstant

	nBret = SetCommTimeouts(m_hCommPort, &timeout);	//SetCommTimeOut()ŠÖ”‚Éƒ|[ƒgƒnƒ“ƒhƒ‹‚¨‚æ‚ÑCOMMTIMEOUTS\‘¢‘Ì‚Ì
													//ƒAƒhƒŒƒX‚ð‘ã“ü‚µ‚Ü‚·B

	if (nBret == FALSE) //Ž¸”s‚µ‚½ê‡
	{
		m_strMessage.Format(_T("SetCommTimeouts failed."));
		m_nError = 5;
		CloseHandle(m_hCommPort);
		return false;
	}
#endif

	DWORD	dwThreadID = 0;
	if (bCheck == false)
	{
		m_hReadThread = ::CreateThread((LPSECURITY_ATTRIBUTES)NULL,
			(SIZE_T)0,
			(LPTHREAD_START_ROUTINE)ReadThread,
			(LPVOID)this,
			(DWORD)0,
			(LPDWORD)&dwThreadID);
		m_bOpen = true;
		m_nCount = 0;
	}
	else
		m_bOpen = true;
	return true;
}

// ’ÊMI—¹
int CComm::CommStop()
{
	DWORD		ExitCode;
	int			i;

	m_bStop = true;
	//	::SetCommMask(m_hCommPort, EV_RXCHAR);

	if (m_hReadThread)
	{
		//for (i = 0; i < 100; i++)
		for (i = 0; i < 30; i++)
		{
			GetExitCodeThread(m_hReadThread, &ExitCode);
			if (ExitCode != STILL_ACTIVE)
			{
				m_hReadThread = 0;
				m_bOpen = false;
				//return TRUE;
				break;
			}
			Sleep(10);
		}
		//		m_bOpen = false;
		//return FALSE;
	}
	if (m_hCommPort != INVALID_HANDLE_VALUE)
	{
		CloseHandle(m_hCommPort);
	}
	if (m_hReadThread != 0) {
		TerminateThread(m_hReadThread, -1);
	}

	m_bOpen = false;
	return TRUE;
}
DWORD nNGError = 0;

// ŽóMThread
DWORD FAR PASCAL CComm::ReadThread(CComm* parent)
{
	//#define		RCV_BUFF_A_SIZE	128
#define		RCV_BUFF_A_SIZE	256
	BYTE	buff[RCV_BUFF_A_SIZE] = {};
	DWORD	readBytes = 0;
	static int find_etx = 0;
	char	strHex[32] = {};
	DWORD dwErrors;  /* ƒGƒ‰[î•ñ */
	COMSTAT ComStat; /* ƒfƒoƒCƒX‚Ìó‘Ô */

//	::SetCommMask(parent->m_hCommPort, EV_RXCHAR| EV_ERR|EV_BREAK);
	::SetCommMask(parent->m_hCommPort, EV_RXCHAR);
	while (!parent->m_bStop)
	{
		// “¯ŠúŽ®‚È‚Ì‚ÅŽóM‚ªæ‚É—ˆ‚È‚¢‚Æ‘—M‘¤‚Å‘—M‚Å‚«‚È‚¢
		//		if (!parent->m_bTest)
		//			::WaitCommEvent(parent->m_hCommPort, &dwEvent, NULL);
		readBytes = 0;
		if (parent->m_bOpen && nNGError < 5)
		{
			if (!ReadFile(parent->m_hCommPort, &buff, RCV_BUFF_A_SIZE, &readBytes, NULL))
			{
				ClearCommError(parent->m_hCommPort, &dwErrors, &ComStat);
				parent->m_nCount = 0;
				find_etx = 0;
				nNGError++;
				parent->nNGErrorComm = 1;
			}
			else if (readBytes > 0)
			{
				nNGError = 0;
				{
					for (DWORD i = 0; i < readBytes; i++)
					{
						if (parent->m_nCount < 256) {
							parent->m_FormatSTX_ETX.m_Buff[parent->m_nCount] = buff[i];
						}
						if (++parent->m_nCount > RCV_BUFF_A_SIZE)
						{
							parent->m_nCount = 0;
							find_etx = 0;
						}
						sprintf_s(strHex, 32, "%02x ", buff[i]);
						//switch (buff[i])
						switch (i)
						{
						//case STX:
						case 0:
							parent->m_ReadStr = strHex;
							find_etx = 0;
							break;
						//case ETX:
						case 7:
							find_etx = 1;
							parent->m_ReadStr += strHex;
							break;
						default:
							parent->m_ReadStr += strHex;
							if (find_etx)
							{
								WaitForSingleObject(parent->m_Mutex, 0);
								parent->m_ReadLine = parent->m_ReadStr;
								//								if (parent->m_FormatSTX_ETX.SetBuff())
								//									parent->m_evReadLine.SetEvent();			// ˆês“Ç‚Ýo‚µƒCƒxƒ“ƒg
								ReleaseMutex(parent->m_Mutex);
								find_etx = 0;
								parent->m_nCount = 0;
								parent->m_bReceived = true;
							}
							break;
						}
					}
				}
			}
		}
		else
		{
			if (parent->m_bOpen)
			{
				parent->m_bOpen = false;
				parent->m_evReadLine.SetEvent();			// ˆês“Ç‚Ýo‚µƒCƒxƒ“ƒg
			}
			nNGError = 0;
		}
	}
	return 0;
}
