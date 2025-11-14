#include "pch.h"
#include "Comm.h"
#include "Flowlib.h"


#define		RCV_BUFF_A_SIZE	128
#define		COMMAND_SIZE	8
#define     COMPORT 10
#define		ACK	6

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
	close();
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
bool Flowlib::SendPacket(unsigned char* Data)
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
bool Flowlib::ReceivePacket(unsigned char* Data)
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
bool Flowlib::CheckEoc(unsigned char* Data)
{
	if (*(Data + 7) != AddCheckSum(Data))
		return false;
	return true;
};

//add check sum
char Flowlib::AddCheckSum(unsigned char* Data)
{
	char sum = 0;
	for (int i = 0; i < 7; i++)
	{
		sum += Data[i];
	}
	return sum;
};

//read eeprom
bool Flowlib::ReadEeprom(int Adr, int* Value)
{
	unsigned char rbuff[8];
	MakePacket(m_SendData, Adr);
	SendPacket(m_SendData);
	ReceivePacket(rbuff);
	if (rbuff[0] != ACK)
		return false;
	*Value = 0;
	*Value = rbuff[2];
	*Value = *Value << 8;
	*Value |= rbuff[1];
	return true;

};


//write eeprom
bool Flowlib::WriteEeprom(unsigned char* Data)
{

	if (Data == nullptr)
	{
		log("WriteEeprom Invalid Parameter");
		return false;
	}

	unsigned char sbuff[8] = {};
	unsigned char rbuff[8] = {};

	return true;
	sbuff[0] = 21;
	sbuff[1] = Data[0];
	sbuff[2] = Data[1];
	sbuff[3] = Data[2];
	sbuff[4] = Data[3];
	sbuff[5] = 0;
	sbuff[6] = 0;
	sbuff[7] = AddCheckSum(sbuff);

	if (!SendPacket(sbuff))
	{
		log("WriteEeprom Send Error");
		return false;
	}

	if (!ReceivePacket(rbuff))
	{
		log("WriteEeprom Receive Error");
		return false;
	}

	if (rbuff[0] != ACK)
	{
		log("WriteEeprom ACK Error");
		return false;
	}

	return true;
};

//make packet
bool Flowlib::MakePacket(unsigned char* tbuff, int eppadr)
{
	
	tbuff[0] = 20;
	tbuff[1] = (unsigned char) eppadr;
	tbuff[2] = (unsigned char)(eppadr >> 8);
	tbuff[3] = 0;
	tbuff[4] = 0;
	tbuff[5] = 0;
	tbuff[6] = 0;
	tbuff[7] = AddCheckSum(tbuff);
		
	return true;
};

//open sereal
bool Flowlib::OpenSerial(int comport, int baudrate)
{
	//COMOpen
	if (m_Com.CommStart(comport, baudrate, true) == false) {
		return false;
	}
	log("OpenSerial Complete");
	return true;
};


//close serial
bool Flowlib::CloseSerial()
{
	//COMClose
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
