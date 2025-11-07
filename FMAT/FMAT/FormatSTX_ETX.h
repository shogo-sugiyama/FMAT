#pragma once

//#define		STX_ETX_RX_LEN		20
#define		STX_ETX_TX_LEN		30
#define		STX_ETX_SP1_RX_LEN	172

class FormatSTX_ETX
{
public:

public:
	FormatSTX_ETX(void);
	~FormatSTX_ETX(void);
	char m_Buff[256] = {};
};

