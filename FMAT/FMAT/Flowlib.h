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
	bool SendPacket(unsigned char* Data);

	//recieve packet
	bool ReceivePacket(unsigned char* Data);
	//check erc
	bool CheckEoc(unsigned char* Data);
	//add check sum
	char AddCheckSum(unsigned char* Data);
	//read eeprom
	bool ReadEeprom(int adr, int* Data);
	//read eeprom
	bool ReadEepromALL(unsigned char* Data);
	//write eeprom
	bool WriteEeprom(unsigned char* Data);
	//make packet
	bool MakePacket(unsigned char* Data, int eepadr);
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
