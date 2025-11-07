#include "Comm.h"
#pragma once

class Flowlib
{
public:

	//constructor
	Flowlib();

	//destructor
	~Flowlib();

	//open
	bool open();

	//close
	bool close();

	//send packet
	bool SendPacket(char* Data);

	//recieve packet
	bool ReceivePacket(char* Data);
	//check erc
	bool CheckEoc(char* Data);
	//add check sum
	char AddCheckSum(char* Data);
	//read eeprom
	bool ReadEeprom(int adr, int* Data);
	//read eeprom
	bool ReadEepromALL(char* Data);
	//write eeprom
	bool WriteEeprom(char* Data);
	//make packet
	bool MakePacket(char* Data);
	//open sereal
	bool OpenSerial(int comport, int baudrate);
	//close serial
	bool CloseSerial();
	//Log
	bool log(char* message);

	unsigned char m_EepromData[256][8] = {};
	unsigned char m_RecieveData[128] = {};
	bool m_bReceived = FALSE;
	int m_nCount = 0;
	HANDLE m_XFerThreadHandle;
	CComm m_Com;
	bool m_ThreadDone = FALSE;
private:
	int m_debuglevel = 1;
	unsigned char m_SendData[8] = {};





};
UINT ReadThread(LPVOID pParam);
