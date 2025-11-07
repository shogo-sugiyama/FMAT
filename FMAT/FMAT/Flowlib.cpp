#include "pch.h"
#include "Comm.h"
#include "Flowlib.h"

#define		RCV_BUFF_A_SIZE	128
#define		COMMAND_SIZE	8
#define     COMPORT 10

UINT ReadThread(LPVOID pParam)
{
	BYTE	buff[RCV_BUFF_A_SIZE] = {};
	DWORD	readBytes = 0;

	Flowlib* FlowPtr = (Flowlib*)pParam;

	while (!FlowPtr->m_ThreadDone)
	{
		if (!ReadFile(FlowPtr->m_Com.m_hCommPort, &buff, RCV_BUFF_A_SIZE, &readBytes, NULL))
		{
			FlowPtr->log("Receive Error !!");
			return -1;
		}
		else if (readBytes > 0)
		{
			for (DWORD i = 0; i < readBytes; i++)
			{
				if (readBytes < COMMAND_SIZE) {
					FlowPtr->m_RecieveData[FlowPtr->m_nCount] = buff[i];
					FlowPtr->m_nCount++;
				}
				if (FlowPtr->m_nCount == COMMAND_SIZE)
				{
					FlowPtr->m_nCount = 0;
					FlowPtr->m_bReceived = TRUE;
					break;
				}
			}

		}
	}
	return 0;
}

//constructor
Flowlib::Flowlib()
{
};

//destructor
Flowlib::~Flowlib()
{
};

//open
bool Flowlib::open()
{
	TCHAR msg[256];
	CWinThread* pServerMainThread = AfxBeginThread(ReadThread, this);
	if (pServerMainThread && pServerMainThread->m_hThread)
	{
		log("Create ReadThread OK");
	}
	else
	{
		log("Create ReadThread Error");
		return false;
	}
	if (!OpenSerial(COMPORT, 9600))
	{
		log("Serial Open Error");
		return false;
	}
	return true;
};

//close
bool Flowlib::close()
{
	m_ThreadDone = TRUE;
	Sleep(10);
	if (!CloseSerial())
	{
		log("Serial Close Error");
		return false;
	}
	return true;
};

//send packet
bool Flowlib::SendPacket(char* Data)
{
	int size = 8;
	DWORD NumberOfBytesWritten = 0;
	do {
		if (!WriteFile(m_Com.m_hCommPort, Data, size, &NumberOfBytesWritten, NULL))
		{
			log("Send Packet Error");
			return false;
		}
	} while (size != NumberOfBytesWritten && m_Com.m_bOpen);
	log("Send Packet");
	return true;
};

//recieve packet
bool Flowlib::ReceivePacket(char* Data)
{
	while (true)
	{
		if (m_bReceived)
		{
			memcpy(Data, m_RecieveData, 8);
			m_bReceived = FALSE;
			break;
		}
		if (m_Com.nNGErrorComm != 0)
		{
			m_Com.nNGErrorComm = 0;
			log("Receive Packet Error");
			return false;
		}
	}
	if (!CheckEoc(Data))
	{
		log("EOC Check Error");
		return false;
	}
	log("Receive Packet");
	return true;
};

//check erc
bool Flowlib::CheckEoc(char* Data)
{
	if (*(Data + 7) != AddCheckSum(Data))
		return false;
	return true;
};

//add check sum
char Flowlib::AddCheckSum(char* Data)
{
	char sum = 0;
	for (int i = 0; i < 7; i++)
	{
		sum += Data[i];
	}
	return sum;
};

//read eeprom
bool Flowlib::ReadEeprom(int Adr, int* Data)
{
	return true;
};

//write eeprom
bool Flowlib::WriteEeprom(char* Data)
{
	return true;
};

//make packet
bool Flowlib::MakePacket(char* Data)
{
	return true;
};

//open sereal
bool Flowlib::OpenSerial(int comport, int baudrate)
{
	//COM¥Ý©`¥ÈOpen
	if (m_Com.CommStart(comport, baudrate, true) == false) {
		return false;
	}
	log("OpenSerial Complete");
	return true;
};


//close serial
bool Flowlib::CloseSerial()
{
	//COM¥Ý©`¥ÈClose
	if (m_Com.CommStop() == false) {
		return false;
	}

	log("CloseSerial Complete");
	return true;
};

bool Flowlib::log(char* message)
{
	if (strlen(message) > 0)
	{
		char LogMsg[1024] = {};
		TCHAR FileName[1024];
		SYSTEMTIME st;
		LPCTSTR msg;
		GetSystemTime(&st);

		_stprintf_s(FileName, _T("FMAT_EepromRW.log"));
		sprintf_s(LogMsg, "%04d/%02d/%02d %02d:%02d:%02d.%02d %s\n", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds, message);

		FILE* File = NULL;
		_tfopen_s(&File, FileName, _T("at"));
		if (File != NULL) {
			fwrite(LogMsg, 1, strlen(LogMsg), File);
			fclose(File);
		}
	}
	return true;
};
