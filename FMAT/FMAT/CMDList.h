#pragma once
//
//			EMF300 COMMAND LIST
//
//										Ver	 3.16
//										1995	12.11
//										Ver	 4.00
//
//
// *******************V306 / V061での実装　******************************
//
//
//	**********DSP->SNS Command ASIO　　*********
// Original
//
// #define S_HRESET	EQU	1//	HARDWARE RESET COMMAND
// #define S_ACTIVE	EQU	2//	ACTIVATE SENSOR
// #define S_DACTIVE	EQU	3//	DEACTIVATE SENSOR
// #define S_GETFLOW	EQU	4//	GET SAMPLES SENSOR
// #define S_SOFTSTART	EQU	5// *RESTART WITH RAM DATA(DO NOT SET ROM DEFAULT)(DO NOT SET EEPROM DATA)
// #define S_SETEP_RAM	EQU	6// *WRITE DATA TO RAM BUFFER(DO NOT WRITE TO EEPROM)
// #define S_RDAD		EQU	7// +READ AD DATA(FLOW)
// #define S_RDADCUR	EQU	8// +READ AD DATA(CURRENT)
// #define S_RDADEL	EQU	9// +READ AD DATA(ELECTRODE)
// #define S_RDADVOL	EQU	10// +READ AD DATA(VOLTAGE)
// #define S_RDADFLCR	EQU	11// +READ AD DATA(flow & current)
// #define S_RDADELVL	EQU	12// +READ AD DATA(electrode & voltage)
// #define S_CHKEL	EQU	13//	CHECK ELECTRODE
// #define S_CHKCOIL	EQU	14// +CHECK COIL
// #define S_ELTEST	EQU	15// +ELCT ON / OFF TEST
// #define S_SETDEFAULT	EQU	16//	SET DEFAULT DATA TO EEPROM
// #define S_SETEPROM	EQU	19// *RELOAD EEPROM DATA TO RAM
// #define S_RDEPROM	EQU	20//	READ EEPROM DATA
// #define S_WREPROM	EQU	21//	WRITE EEPROM DATA
//
// Ver4 拡張
//
// #define S_INQUIRY 	EQU	22// Typeの問い合わせ
//

//
//	***********CSIO Command TOTAL-- > DSP / PC-- > DSP / PC-- > TOTAL**********
//
// Original
//
// #define CM_ERROR	EQU	0// ERROR POLLING COMMAND
// #define CM_DATA	EQU	1// AVGFLW LOW POLLING COMMAND
// #define CM_VOLCLR	EQU	2// VOLUME CLEAR COMMAND
// #define CM_RESET	EQU	3// COMMUNICATION CHANNEL RESET COMMAND
// #define CM_TEST	EQU	4// COMMUNICATION TEST(ECHO BACK RESET COMMAND)
//
// Ver3　拡張
//
// #define CM_AVGFLW	EQU	5// 平均流量 COMMAND
// #define CM_TOTVOL	EQU	6// 総流量 COMMAND
// #define CM_MRESET	EQU	7// ﾓﾆﾀｰ積算計 リセットキー押下問い合わせ COMMAND
//
// Ver4　拡張
//
// #define CM_REPEAT1	EQU	8// 表示　Data
// #define CM_REPEAT2	EQU	9// 表示　Data
// #define CM_RDEPROM	EQU	10// (PC-- > TOTAL) READ EEPROM DATA
// #define CM_WREPROM	EQU	11// (PC-- > TOTAL) WRITE EEPROM DATA
// #define CM_SETDEFAULT	EQU	12// (PC-- > TOTAL) Default Data をEEPROMへセットする。
// #define CM_INQUIRY 	EQU	13// (PC-- > TOTAL) Typeの問い合わせ
// #define CM_HRESET	EQU	14// (PC-- > TOTAL) HW Reset
// OnLineResponse  0, ff, ff, ff, ff, ff, ff, 6		To Total CSIO

//
//	*********Total / Display　ASIO　Command　　**********
//
//	Displayでは　CommandはOnLine状態以外では受け付けない。
//
// Original
//
// #define D_HRESET	EQU	30// RESET(THIS FUNCTION  USE WATCH DOG TIMER RESET)SEND ACK BEFORE DONE
// #define D_ONLREQ	EQU	31// ONLINE REQUEST
// #define D_CLRVOL	EQU	32// CLEAR VOLUME DATA REQUEST
// #define D_OFLREQ	EQU	33// OFFLINE REQUEST
// #define D_LCDTEST	EQU	35// LCD TEST
// #define D_SWTEST	EQU	36// SWITCH TEST
// #define D_EXTONOF	EQU	37// EXTERNAL OUTPUT ON / OFF TEST
// #define D_LEDONOF	EQU	38// LED ON / OFF TEST
// #define D_SPWONOF	EQU	39// SENSOR POWER ON / OFF TEST
// #define D_RDEPROM	EQU	50// READ EEPROM DATA
// #define D_WREPROM	EQU	51// WRITE EEPROM DATA
// #define D_SETDEFAULT	EQU	56// SET DEFAULT DATA TO EEPROM
// #define D_SETDFRAM	EQU	57// SET DEFAULT DATA TO RAM
// #define D_SETEPROM	EQU	59// RELOAD EEPROM DATA
//
// Ver4　拡張
//
// #define D_INQUIRY 	EQU	34// Typeの問い合わせ



// *************************************************************************************

//
//	**********DSP->SNS Command ASIO　　*********
// Original
//
// #define S_HRESET	EQU	1//	HARDWARE RESET COMMAND
// #define S_ACTIVE	EQU	2//	ACTIVATE SENSOR
// #define S_DACTIVE	EQU	3//	DEACTIVATE SENSOR
// #define S_GETFLOW	EQU	4//	GET SAMPLES SENSOR
// #define S_SOFTSTART	EQU	5// *RESTART WITH RAM DATA(DO NOT SET ROM DEFAULT)(DO NOT SET EEPROM DATA)
// #define S_SETEP_RAM	EQU	6// *WRITE DATA TO RAM BUFFER(DO NOT WRITE TO EEPROM)
// #define S_RDAD		EQU	7// +READ AD DATA(FLOW)
// #define S_RDADCUR	EQU	8// +READ AD DATA(CURRENT)
// #define S_RDADEL	EQU	9// +READ AD DATA(ELECTRODE)
// #define S_RDADVOL	EQU	10// +READ AD DATA(VOLTAGE)
// #define S_RDADFLCR	EQU	11// +READ AD DATA(flow & current)
// #define S_RDADELVL	EQU	12// +READ AD DATA(electrode & voltage)
// #define S_CHKEL	EQU	13//	CHECK ELECTRODE
// #define S_CHKCOIL	EQU	14// +CHECK COIL
// #define S_ELTEST	EQU	15// +ELCT ON / OFF TEST
// #define S_SETDEFAULT	EQU	16//	SET DEFAULT DATA TO EEPROM
// #define S_SETEPROM	EQU	19// *RELOAD EEPROM DATA TO RAM
// #define S_RDEPROM	EQU	20//	READ EEPROM DATA
// #define S_WREPROM	EQU	21//	WRITE EEPROM DATA
//
// Ver4 拡張
//
// #define S_INQUIRY 	EQU	22// Typeの問い合わせ
//
//	***********CSIO Command TOTAL-- > DSP / PC-- > DSP / PC-- > TOTAL**********
//
// Original
//
// #define CM_ERROR	EQU	0// ERROR POLLING COMMAND
// #define CM_DATA	EQU	1// AVGFLW LOW POLLING COMMAND
// #define CM_VOLCLR	EQU	2// VOLUME CLEAR COMMAND
// #define CM_RESET	EQU	3// COMMUNICATION CHANNEL RESET COMMAND
// #define CM_TEST	EQU	4// COMMUNICATION TEST(ECHO BACK RESET COMMAND)
//
// Ver3　拡張
//
// #define CM_AVGFLW	EQU	5// 平均流量 COMMAND
// #define CM_TOTVOL	EQU	6// 総流量 COMMAND
// #define CM_MRESET	EQU	7// ﾓﾆﾀｰ積算計 リセットキー押下問い合わせ COMMAND
//
// Ver4　拡張
//
// #define CM_REPEAT1	EQU	8// 表示　Data
// #define CM_REPEAT2	EQU	9// 表示　Data
// #define CM_RDEPROM	EQU	10// (PC-- > TOTAL) READ EEPROM DATA
// #define CM_WREPROM	EQU	11// (PC-- > TOTAL) WRITE EEPROM DATA
// #define CM_SETDEFAULT	EQU	12// (PC-- > TOTAL) Default Data をEEPROMへセットする。
// #define CM_INQUIRY 	EQU	13// (PC-- > TOTAL) Typeの問い合わせ
// #define CM_HRESET	EQU	14// (PC-- > TOTAL) HW Reset
// #define CM_ONLREQ	EQU	15// (PC-- > TOTAL ONLY) Online Request
// OnLineResponse  0, ff, ff, ff, ff, ff, ff, 6		To Total CSIO
// #define CM_OFLREQ	EQU	16// (PC-- > TOTAL ONLY) OffLine Request
//
// #define CM_SRDEPROM	EQU	20// DSP経由SNS READ EEPROM DATA
// #define CM_SWREPROM	EQU	21// DSP経由SNS WRITE EEPROM DATA
// #define CM_SSETDEFAULT	EQU	22// DSP経由SNS Default Data をEEPROMへセットする。
// #define CM_SINQUIRY 	EQU	23// DSP経由SNS Typeの問い合わせ
// #define CM_SHRESET	EQU	24// DSP経由SNS HW Reset
//
// Ver4　Reserve 未実装
//
// #define CM_CLRVOL	EQU	17// 未実装
// #define CM_OFLREQ	EQU	18// 未実装
// #define CM_LCDTEST	EQU	19// 未実装
// #define CM_SWTEST	EQU	25// 未実装
// #define CM_EXTONOF	EQU	26// 未実装
// #define CM_LEDONOF	EQU	27// 未実装
// #define CM_SPWONOF	EQU	28// 未実装
// #define CM_SETDFRAM	EQU	29// 未実装
// #define CM_SETEPROM	EQU	30// 未実装
//
//
//	*********Total / Display　ASIO　Command　　**********
//
//	Displayでは　CommandはOnLine状態以外では受け付けない。
//
// Original
//
// #define D_HRESET	EQU	30// RESET(THIS FUNCTION  USE WATCH DOG TIMER RESET)SEND ACK BEFORE DONE
// #define D_ONLREQ	EQU	31// ONLINE REQUEST
// #define D_CLRVOL	EQU	32// CLEAR VOLUME DATA REQUEST
// #define D_OFLREQ	EQU	33// OFFLINE REQUEST
// #define D_LCDTEST	EQU	35// LCD TEST
// #define D_SWTEST	EQU	36// SWITCH TEST
// #define D_EXTONOF	EQU	37// EXTERNAL OUTPUT ON / OFF TEST
// #define D_LEDONOF	EQU	38// LED ON / OFF TEST
// #define D_SPWONOF	EQU	39// SENSOR POWER ON / OFF TEST
// #define D_RDEPROM	EQU	50// READ EEPROM DATA
// #define D_WREPROM	EQU	51// WRITE EEPROM DATA
// #define D_SETDEFAULT	EQU	56// SET DEFAULT DATA TO EEPROM
// #define D_SETDFRAM	EQU	57// SET DEFAULT DATA TO RAM
// #define D_SETEPROM	EQU	59// RELOAD EEPROM DATA
//
// Ver4　拡張
//
// #define D_INQUIRY 	EQU	34// Typeの問い合わせ
//
// Ver4　拡張
//
// #define D_DATA		EQU	40// AVG Flow and Volume POLLING COMMAND
// #define D_IFLW		EQU	41// 個別流量　Polling
// #define D_IVOL		EQU	42// 個別Volume　Polling
// #define D_IELCT	EQU	43// 個別電極試験　Polling
// #define D_HRESET	EQU	44// HW Reset
// #define D_CLRVOL	EQU	45// Volume Clear
//
//
//
//	**********Total　ASIO　経由Display, Display, Monitor, RepeaterへのCommand　　**********
//			CSIO上はTotal->DSPのCSIOCommandと同じ。（OnlineCommand)
// Ver4　拡張
//
// #define CM_#define D_RDEPROM	EQU	46//
// #define CM_#define D_WREPROM	EQU	47//
// #define CM_#define D_SETDEFAULT EQU	48//
// #define CM_#define D_INQUIRY 	EQU	49// *
// #define CM_#define D_HRESET	EQU	52// HW Reset
//
//
//	**********Total(ASIO)経由Display(CSIO)経由Sensor(ASIO)へのCommand**********
//			CSIO上はTotal->DSPのCSIOCommandと同じ。（OnlineCommand)
//
//
// Ver4　拡張
//
// #define CM_#define S_RDEPROM	EQU	53//
// #define CM_#define S_WREPROM	EQU	54//
// #define CM_#define S_SETDEFAULT EQU	55//
// #define CM_#define S_INQUIRY 	EQU	58// *
// #define CM_#define S_HRESET 	EQU	60//
//
//
//
//
//			EMF300 COMMAND
//
//	********From DSP To SNS （ASIO)**********
//
//	Command Format
//
//	Command
//	PR0
//	PR1
//	PR2
//	PR3
//	PR4
//	PR5
//	EOC	CheckSum
//
//
//	Response Format  注：一部Command11, 12etc.はこの規則に従わない。
//
//	Command		Echo Back
//	Result		OK / NG
//	PR0
//	PR1
//	PR2
//	PR3
//	PR4
//	EOC	CheckSum
//
// ----------------------------------------------
//
// 1		-- > SNS
//
#define S_HRESET	EQU	1
//
//	HARDWARE RESET COMMAND
//
//	SENSOR USE WATCH DOG TIMER RESET
//
// ---------------------------------------------- -

//
// 2		-- > SNS
//
//
#define S_ACTIVE	EQU	2
//
//	ACTIVATE SENSOR
//
//	PR0		0:	FLOW MODE
//			1:	ELECTRODE MODE
//			2:	ELCT AD TEST MODE
// ---------------------------------------------- -
//
// 3		-- > SNS
//
//
#define S_DACTIVE	EQU	3
//
//	DEACTIVATE SENSOR
//
//	SENSOR CHANGE STATUS SEQ-- > 0
//
//	STOP COIL DRIVE& AD
//
// ---------------------------------------------- -
//
// 4		-- > SNS
//
//
#define S_GETFLOW	EQU	4
//
//	GET SAMPLES SENSOR
//
//	RESULT
//	PR0
//	PR1, PR2		NO.1 FLOW DATA
//	PR3, PR4		NO.2 FLOW DATA
//
// ---------------------------------------------- -
//
// 5		-- > SNS		Diag Use Only
//
//
#define S_SOFTSTART	EQU	5// No Apl.Use
//
//	RESTART WITH RAM DATA
//	(DO NOT SET ROM DEFAULT)
//	(DO NOT SET EEPROM DATA)
//
// ---------------------------------------------- -
//
// 6		-- > SNS		Diag Use Only
//
#define S_SETEP_RAM	EQU	6// No Apl.Use
//
//
//	WRITE DATA TO RAM BUFFER
//	(DO NOT WRITE TO EEPROM)
//
//	CMD + 1		WORD ADR.OF EEPROM
//	CMD + 2, CMD + 3	WORD DATA
//
//	PR0		CHECK SUM
//	PR1, PR2		PREVIOUS DATA
//	PR3, PR4		READ BACK DATA
//
//

// ---------------------------------------------- -
//
// 7		-- > SNS		Diag Use Only
//
//	READ AD DATA(FLOW)
//
#define S_RDAD	EQU	7
//
//
//	PR0
//	PR1		AD  UP
//	PR2		AD  UP
//	PR3		AD  DOWN
//	PR4		AD  DOWN
//
// ---------------------------------------------- -
//
// 8		-- > SNS		Diag Use Only
//
//	READ AD DATA(CURRENT)
//
//
#define S_RDADCUR	EQU	8
//
//
//
//
//	PR0
//	PR1		AD  UP
//	PR2		AD  UP
//	PR3		AD  DOWN
//	PR4		AD  DOWN
//
// ------------------------------------------------
// 9		-- > SNS		Diag Use Only
//
//	READ AD DATA(ELECTRODE)
//
//
#define S_RDADEL	EQU	9
//
//
//
//
//	PR0
//	PR1		AD  UP
//	PR2		AD  UP
//	PR3		AD  DOWN
//	PR4		AD  DOWN
//
// ------------------------------------------------
//
// 10		-- > SNS		Diag Use Only
//
//
#define S_RDADVOL	EQU	10
//
//	READ AD DATA(VOLTAGE)
//
//
//
//	PR0
//	PR1		AD  UP
//	PR2		AD  UP
//	PR3		AD  DOWN
//	PR4		AD  DOWN
//
// --------------------------------------------------
//
// 11		-- > SNS		Diag Use Only
//
#define S_RDADFLCR	EQU	11
//
//	READ AD DATA(flow& current)
//
//
//
//	cmd		flow AD up
//	result		flow AD up
//	PR0		flow AD dn
//	PR1		flow AD dn
//	PR2		current AD UP
//	PR3		current AD up
//	PR4		current AD dn
//	eoc		current AD dn
//
// -------------------------------------------------- -
//
// 12	-- > SNS		Diag Use Only
//
//
#define S_RDADELVL	EQU	12
//
//	READ AD DATA(electrode& voltage)
//
//
//
//	cmd		elct AD up
//	result		elct AD up
//	PR0		elct AD dn
//	PR1		elct AD dn
//	PR2		volt AD UP
//	PR3		volt AD up
//	PR4		volt AD dn
//	eoc		volt AD dn
//
// ----------------------------------------------------
//
// 13	-- > SNS
//
//
#define S_CHKEL	EQU	13
//
//	CHECK ELECTRODE
//
//
//
//	result	0	ELCT ERROR
//			1	ELCT OK
//	PR0		ELCT_SUM
//	PR1		ELCT_SUM + 1
//	PR2		ELCT_SUM + 2
//	PR3		BAELCT
//	PR4		BAELCT + 1
//	eoc
//
// ---------------------------------------------- -
//
// 14	-- > SNS
//
//
#define S_CHKCOIL	EQU	14
//
//	CHECK COIL
//
//	PR1	0	COIL	OFF
//		1	COIL	UP
//		2	COIL	DOWN
//
// ---------------------------------------------- -
//
// 15	-- > SNS
//
//
#define S_ELTEST	EQU	15
//
//	ELCT TEST
//
//	PR1	0	COIL	OFF
//		1	COIL	UP
//		2	COIL	DOWN
//
// ---------------------------------------------- -
//
// 16		-- > SNS
//
//
#define S_SETDEFAULT	EQU	16
//
//	SET DEFAULT DATA TO EEPROM
//
// ---------------------------------------------- -
//
// 19 		-- > SNS	No Apl.Use
//
//
#define S_SETEPROM	EQU	19
//
//	RELOAD EEPROM DATA TO RAM
//
//
// ---------------------------------------------- -
//
// 20		-- > SNS
//
//
#define S_RDEPROM	EQU	20
//
//	READ EEPROM DATA
//
//	CMD + 1	WORD ADR OF EEPROM
//
//	PR0, PR1	EEPROM DATA
//
// ---------------------------------------------- -
//
// 21		-- > SNS
//
//
#define S_WREPROM	EQU	21
//
//	WRITE EEPROM DATA
//
//	CMD + 1		WORD ADR.OF EEPROM
//	CMD + 2, CMD + 3	WORD DATA
//
//	PR0
//	PR1, PR2		PREVIOUS DATA
//	PR3, PR4		READ BACK DATA
//
//

// ---------------------------------------------- -
//
// 22		-- > SNS		From Ver4.00
//
//
#define S_INQUIRY 	EQU	22// Typeの問い合わせ
//
//	PR0		TYPE
//	PR1		VERSION
//	PR2		INIT_CODE// EEPROMの値ではない。
//	PR3		ERROR// 最後のError
//	PR4		ERROR数

//
//	**********COMMAND TOTAL--->DSP(CSIO)*************
//
//	Command Format
//
//	0 Adr		0: Host(Total) 1 - 6 : DSP 7 : Monitor 8 : Repeater 9 : Listener
//	1 CMD
//	2 PR0
//	3 PR1
//	4 PR2
//	5 PR3
//	6 PR4
//	7 EOC
//
//	Response Format(Adr.が増えて、代わりにCMDのEchoBackが省略されている。Errorは個別Command定義による。）
	//
//	0 Adr		0:Host
//	1 PR0
//	2 PR1
//	3 PR2
//	4 PR3
//	5 PR4
//	6 PR5
//	7 EOC
//
//	SC COOMAND
//
#define CM_ERROR	EQU	0// ERROR POLLING COMMAND
//
//	0	HOST ADR. = 0  SET
//	1	EPERCN// ERROR COUNTER
//	2	EPERCD// ERROR CODE 0
//	3	EPERCD// ERROR CODE 1
//	4	EPERCD// ERROR CODE 2
//	5	EPERCD// ERROR CODE 3
//	6	EPERCD// ERROR CODE 4
//	7	EOC
//
#define CM_DATA		EQU	01H// AVGFLW LOW POLLING COMMAND
//
//	Response
//
//	0 HOST ADR. = 0  SET
//	1 FLOW Low
//	2 FLOW High
//	3 VOLUME Low
//	4 VOLUME Mid Low
//	5 VOLUME Mid High
//	6 VOLUME High
//	7 EOC
//
#define CM_VOLCLR	EQU	02H// VOLUME CLEAR COMMAND
//
//	0 HOST ADR. = 0  SET
//	1 0
//	2 0
//	3 0
//	4 0
//	5 0
//	6 0
//	7 EOC

//
#define CM_COMRESET	EQU	03H// COMMUNICATION CHANNEL RESET COMMAND

//
//	0 HOST ADR. = 0  SET
//	1 1
//	2 2
//	3 3
//	4 4
//	5 5
//	6 6
//	7 EOC


#define CM_TEST		EQU	04H// COMMUNICATION TEST(ECHO BACK RESET COMMAND)
//
//
//	0 HOST ADR. = 0  SET
//	1 Echo
//	2 Echo
//	3 Echo
//	4 Echo
//	5 Echo
//	6 Echo
//	7 EOC

//
//
//	COMMAND TOTAL積算計--->ﾓﾆﾀｰ積算計(MAIN) 再修正
//
//
#define CM_AVGFLW	EQU	05H// 平均流量 COMMAND　　// Ver3 拡張
//
//	Flow Data を旧Monitorに送るCommandでResponseは不要
//
//	0  7			Monitorのみ可能
//	1  5
//	2  AVGFLW Low
//	3  AVGFLW High
//	4 -
//	5 -
//	6 -
//	7 -



#define CM_TOTVOL	EQU	06H// 総流量 COMMAND　　// Ver3 拡張
//
//	Volume Data を旧Monitorに送るCommandでResponseは不要
//
//	0  7			Monitorのみ可能
//	1  6
//	2  Volume Low
//	3  Volume Mid Low
//	4  Volume Mid High
//	5  Volume High
//	6 -
//	7 -


#define CM_MRESET	EQU	07H// ﾓﾆﾀｰ積算計 リセットキー押下問い合わせ COMMAND// Ver3 拡張
//
//	COMMAND TOTAL積算計--->Monitor
//       MonitorはTOTALに対してClearの要求の有無を返答する。
//
//	0  0			0のみ可能
//	1  #define CM_MRESET　 = 7
//	2  0 / 1  Clear 要求の有無
//	3 -
//	4 -
//	5 -
//	6 -
//	7 EOC
//
#define CM_REPEAT1	EQU	08H// 表示　Data　Ver4　拡張
//
//	0  Adr
//	1  Command  8
//	2		SEG0, SEG1, SEG2 - 01
//	3		SEG2 - 2, SEG3, SEG4, SEG5 - 0
//	4		SEG5 - 12, SEG6, SEG7
//	5		SEG8, SEG9, SEG10 - 01
//	6		SEG10 - 2, SEG11, SEG12
//	7 EOC
//

#define CM_REPEAT2	EQU	09H// 表示　Data　Ver4　拡張
//	0  Adr
//	1  Command  9
//	2		SEG13, SEG14, SEG15 - 01
//	3		SEG15 - 2, SEG16, SEG17, SEG18 - 0
//	4		SEG18 - 12, SEG19, SEG20
//	5		SEG21, SEG22, SEG23 - 01
//	6		SEG23 - 2, SEG24, SEG25
//	7  EOC
//
//	全てのSegmentを３Bitsずつ、LSBから詰めて送る。
//
//

#define CM_RDEPROM	EQU	10//	READ EEPROM DATA  Ver4　拡張
//
//
//  	0  ADR// Command
//  	1  CMD = 10
//  	2  WORD ADR OF EEPROM
//  	3  0
//  	4  0
//  	5  0
//  	6  0
//  	7  EOC
//
//  	0  ADR = 0// Response
//  	1  CMD = 10
//  	2  EEPROM DATA
//  	3  EEPROM DATA
//  	4  0
//  	5  0
//  	6  0
//  	7  EOC
//
//
#define CM_WREPROM	EQU	11//	WRITE EEPROM DATA  Ver4　拡張

//  	0  ADR// Command
//  	1  CMD = 11
//  	2  WORD ADR OF EEPROM
//  	3  EEPROM DATA
//  	4  EEPROM DATA
//  	5  0
//  	6  0
//  	7  EOC

//  	0  ADR = 0// Response
//  	1  CMD = 11
//  	2  PREVIOUS DATA
//  	3  PREVIOUS DATA
//  	4  READ BACK DATA
//  	5  READ BACK DATA
//  	6  0
//  	7  EOC

#define CM_SETDEFAULT	EQU	12// Ver4　拡張


//  	0  ADR// Command
//  	1  CMD = 12
//  	2  0
//  	3  0
//  	4  0
//  	5  0
//  	6  0
//  	7  EOC

//  	0  ADR = 0// Response
//  	1  CMD = 12
//  	2  0 / 1// 1 = Ok, 0 = fail
//  	3  0
//  	4  0
//  	5  0
//  	6  0
//  	7  EOC

#define CM_INQUIRY 	EQU	13// Typeの問い合わせ Ver4　拡張　未実装

//	0  Adr// Command
//	1  Command = 13
//	2  0
//	3  0
//	4  0
//	5  0
//	6  0
//	7  EOC

//	0  Adr = 0
//	1  TYPE
//	2  VERSION
//	3  INIT_CODE
//	4  EPFLAG1
//	5  EPFLAG2
//	6  ERROR数
//	7  EOC
#define CM_HRESET	EQU	14// HW Reset Ver4　拡張

//	0  Adr// Command
//	1  Command = 14
//	2  0
//	3  0
//	4  0
//	5  0
//	6  0
//	7  EOC

//	0  Adr = 0
//	1  14
//	2  0
//	3  0
//	4  0
//	5  0
//	6  0
//	7  EOC
//
//
// OnLineResponse  0, ff, ff, ff, ff, ff, ff, 6		To Total CSIO
//

// TotalからDSPへの問い合わせに対して、OnLineResponseを戻すとTotalはCSIOに対してOnline状態になる。
//　これはPC接続でしか使わない。
//
// Total は、パケット（OnLineResponse）をエコーバックして了解を示す。　


//
//	*****Total->DSP->SNS Command*****
//

#define CM_SRDEPROM	EQU	15// DSP経由SNS　Command READ EEPROM DATA  Ver4　拡張
//
//
//  	0  ADR// Command
//  	1  CMD = 10
//  	2  WORD ADR OF EEPROM
//  	3  0
//  	4  0
//  	5  0
//  	6  0
//  	7  EOC
//
//  	0  ADR = 0// Response
//  	1  CMD = 10
//  	2  EEPROM DATA
//  	3  EEPROM DATA
//  	4  0
//  	5  0
//  	6  0
//  	7  EOC
//
//
#define CM_SWREPROM	EQU	16// DSP経由SNS　Command WRITE EEPROM DATA  Ver4　拡張

//  	0  ADR// Command
//  	1  CMD = 11
//  	2  WORD ADR OF EEPROM
//  	3  EEPROM DATA
//  	4  EEPROM DATA
//  	5  0
//  	6  0
//  	7  EOC

//  	0  ADR = 0// Response
//  	1  CMD = 11
//  	2  PREVIOUS DATA
//  	3  PREVIOUS DATA
//  	4  READ BACK DATA
//  	5  READ BACK DATA
//  	6  0
//  	7  EOC

#define CM_SSETDEFAULT	EQU	17// DSP経由SNS　Command Ver4　拡張


//  	0  ADR// Command
//  	1  CMD = 12
//  	2  0
//  	3  0
//  	4  0
//  	5  0
//  	6  0
//  	7  EOC

//  	0  ADR = 0// Response
//  	1  CMD = 12
//  	2  0 / 1// 1 = Ok, 0 = fail
//  	3  0
//  	4  0
//  	5  0
//  	6  0
//  	7  EOC

#define CM_SINQUIRY 	EQU	18// DSP経由SNS　Command Typeの問い合わせ Ver4　拡張　未実装

//	0  Adr// Command
//	1  Command = 13
//	2  0
//	3  0
//	4  0
//	5  0
//	6  0
//	7  EOC

//	0  Adr = 0
//	1  TYPE
//	2  VERSION
//	3  INIT_CODE
//	4  EPFLAG1
//	5  EPFLAG2
//	6  ERROR数
//	7  EOC
#define CM_SHRESET	EQU	19// DSP経由SNS　Command HW Reset Ver4　拡張

//	0  Adr// Command
//	1  Command = 14
//	2  0
//	3  0
//	4  0
//	5  0
//	6  0
//	7  EOC

//	0  Adr = 0
//	1  14
//	2  0
//	3  0
//	4  0
//	5  0
//	6  0
//	7  EOC
//
//	未実装Command
//
//
// 　Total, Display, Monitor, Repeater への　Command　CSIO　　Ver4　拡張　未実装
//
#define CM_CLRVOL	EQU	20
#define CM_OFLREQ	EQU	21
#define CM_LCDTEST	EQU	22
#define CM_SWTEST	EQU	23
#define CM_EXTONOF	EQU	24
#define CM_LEDONOF	EQU	25
#define CM_SPWONOF	EQU	26
#define CM_SETDFRAM	EQU	27
#define CM_SETEPROM	EQU	28

//
//
//	**********Total　ASIO　Command**********
//
//
// Ver4　拡張

//	Command Format	0  Command
//			1  Adr(0 - 14では、Total向けなので0固定）
	//			2　Adrのない物に較べて一つずつずらす。
	//			3
	//			4
	//			5
	//			6
	//			7　EOC



	#define CM_T_DATA	EQU	0// AVG Flow and Volume POLLING COMMAND
	#define CM_T_IFLW	EQU	1// 個別流量　Polling
	#define CM_T_IVOL	EQU	2// 個別Volume　Polling
	#define CM_T_IELCT	EQU	3// 個別電極試験　Polling
	#define CM_T_RDEPROM	EQU	4// READ EEPROM DATA
	#define CM_T_WREPROM	EQU	5// WRITE EEPROM DATA
	#define CM_T_SETDEFAULT	EQU	6// Default Data をEEPROMへセットする。
	#define CM_T_INQUIRY 	EQU	7// Typeの問い合わせ
	#define CM_T_HRESET	EQU	8// HW Reset
	#define CM_T_CLRVOL	EQU	9// Volume Clear
	#define CM_T_LCDTEST	EQU	10// LCD Test
	#define CM_T_SWTEST	EQU	11// SW Test
	#define CM_T_EXTONOF	EQU	12// EXT Test
	#define CM_T_LEDONOF	EQU	13// LED Test
	#define CM_T_SPWONOF	EQU	14// SNS Power Test
	//
//
//
//	**********Total　ASIO　経由Display, Display, Monitor, RepeaterへのCommand　　**********
//			CSIO上はTotal->DSPのCSIOCommandと同じ
//
//	Ver4 拡張
//
//
//
//
#define CM_#define D_RDEPROM		EQU	15
//
//
//  	0  CMD = 15// Command
//  	1  Adr
//  	2  WORD ADR OF EEPROM
//  	3  0
//  	4  0
//  	5  0
//  	6  0
//  	7  EOC
//
//  	0
//  	1  CMD = 10
//  	2  EEPROM DATA
//  	3  EEPROM DATA
//  	4  0
//  	5  0
//  	6  0
//  	7  EOC
//
#define CM_#define D_WREPROM		EQU	16
//

//  	0  CMD = 16// Command
//  	1  Adr
//  	2  WORD ADR OF EEPROM
//  	3  EEPROM DATA
//  	4  EEPROM DATA
//  	5  0
//  	6  0
//  	7  EOC

//  	0  ADR = 0// Response
//  	1  CMD = 16
//  	2  PREVIOUS DATA
//  	3  PREVIOUS DATA
//  	4  READ BACK DATA
//  	5  READ BACK DATA
//  	6  0
//  	7  EOC
//
#define CM_#define D_SETDEFAULT		EQU	17
//
//  	0  CMD = 17// Command
//  	1  Adr
//  	2  0
//  	3  0
//  	4  0
//  	5  0
//  	6  0
//  	7  EOC

//  	0  ADR = 0// Response
//  	1  CMD = 17
//  	2  0 / 1// 1 = Ok, 0 = fail
//  	3  0
//  	4  0
//  	5  0
//  	6  0
//  	7  EOC

//
#define CM_#define D_INQUIRY 		EQU	18
//
//  	0  CMD = 18// Command
//  	1  Adr
//	2  0
//	3  0
//	4  0
//	5  0
//	6  0
//	7  EOC

//	0  Adr
//	1  TYPE
//	2  VERSION
//	3  EPFLAG1
//	4  EPFLAG2
//	5  EPFLAG3
//	6  ERROR数
//	7  EOC
#define CM_#define D_HRESET		EQU	19// Typeの問い合わせ

//  	0  CMD = 19// Command
//  	1  Adr
//	2  0
//	3  0
//	4  0
//	5  0
//	6  0
//	7  EOC

//	0  Adr = 0
//	1  19
//	2  0
//	3  0
//	4  0
//	5  0
//	6  0
//	7  EOC

//	**********Total(ASIO)経由Display(CSIO)経由Sensor(ASIO)へのCommand**********
//			CSIO上はTotal->DSPのCSIOCommandと同じ
//
//	Ver4 拡張
//
#define CM_#define S_RDEPROM		EQU	20
//
//
//  	0  CMD = 20// Command
//  	1  Adr
//  	2  WORD ADR OF EEPROM
//  	3  0
//  	4  0
//  	5  0
//  	6  0
//  	7  EOC
//
//  	0  ADR = 0// Response
//  	1  CMD = 20
//  	2  EEPROM DATA
//  	3  EEPROM DATA
//  	4  0
//  	5  0
//  	6  0
//  	7  EOC
//
//
#define CM_#define S_WREPROM		EQU	21

//  	0  CMD = 21// Command
//  	1  Adr
//  	2  WORD ADR OF EEPROM
//  	3  EEPROM DATA
//  	4  EEPROM DATA
//  	5  0
//  	6  0
//  	7  EOC

//  	0  ADR = 0// Response
//  	1  CMD = 21
//  	2  PREVIOUS DATA
//  	3  PREVIOUS DATA
//  	4  READ BACK DATA
//  	5  READ BACK DATA
//  	6  0
//  	7  EOC
#define CM_#define S_SETDEFAULT		EQU	22
//  	0  CMD = 22// Command
//  	1  Adr
//  	2  0
//  	3  0
//  	4  0
//  	5  0
//  	6  0
//  	7  EOC

//  	0  ADR = 0// Response
//  	1  CMD = 22
//  	2  0 / 1// 1 = Ok, 0 = fail
//  	3  0
//  	4  0
//  	5  0
//  	6  0
//  	7  EOC

#define CM_#define S_INQUIRY 		EQU	23
//
//  	0  CMD = 23// Command
//  	1  Adr
//	2  0
//	3  0
//	4  0
//	5  0
//	6  0
//	7  EOC

//	0  Adr
//	1  TYPE
//	2  VERSION
//	3  EPFLAG1
//	4  EPFLAG2
//	5  EPFLAG3
//	6  ERROR数
//	7  EOC


#define CM_#define S_HRESET 		EQU	24
//
//  	0  CMD = 24// Command
//  	1  Adr
//	2  0
//	3  0
//	4  0
//	5  0
//	6  0
//	7  EOC

//	0  Adr
//	1  TYPE
//	2  VERSION
//	3  EPFLAG1
//	4  EPFLAG2
//	5  EPFLAG3
//	6  ERROR数
//	7  EOC


//
//
//
//
//	**************ONLINE COMMAND TO DSP**************
//
//
//
//
// ------------------------------------------------------------------ -
//
//	RESET(THIS FUNCTION  USE WATCH DOG TIMER RESET)
//	SEND ACK BEFORE DONE
//
#define D_HRESET	EQU	30
//
// ------------------------------------------------------------------ -
//
//	ONLINE REQUEST
//
#define D_ONLREQ	EQU	31
//
// ------------------------------------------------------------------ -
//
//	CLEAR VOLUME DATA REQUEST
//
#define D_CLRVOL	EQU	32
//
//
// ------------------------------------------------------------------ -
//
//	OFFLINE REQUEST
//
#define D_OFLREQ	EQU	33
//
// ----------------------------------------------------------------------
//
#define D_INQUIRY 	EQU	34// Typeの問い合わせ　　Ver4　拡張

//	PR0		TYPE
//	PR1		VERSION
//	PR2		EPFLAG1
//	PR3		EPFLAG2
//	PR4		EPFLAG3
//
// ------------------------------------------------------------------------------
//
//	LCD TEST
//
#define D_LCDTEST	EQU	35
//
// ----------------------------------------------------------------------
//
//	SWITCH TEST
//
#define D_SWTEST	EQU	36
//
// ----------------------------------------------------------------------
//
//	EXTERNAL OUTPUT ON / OFF TEST
//
#define D_EXTONOF	EQU	37
//
//	PR0	#0		EXT_OP1 OFF
//	PR0	#1		EXT_OP1 ON
//	PR1	#0		EXT_OP2 OFF
//	PR1	#1		EXT_OP2 ON
//
// ----------------------------------------------------------------------
//
//	LED ON / OFF TEST
//
//
#define D_LEDONOF	EQU	38
//
//	CHECK PR0	#1	B_LIGHT_ON
//	CHECK PR0	#0	B_LIGHT_OFF
//
// ----------------------------------------------------------------------
//
//	SENSOR POWER ON / OFF TEST
//
#define D_SPWONOF	EQU	39
//
//	CHECK PR0	#1	B_LIGHT_ON
//	CHECK PR0	#0	B_LIGHT_OFF
//
// ----------------------------------------------------------------------
//
//
//	READ EEPROM DATA
//
#define D_RDEPROM	EQU	50
//
// ---------------------------------------------------------------------- -
//
//	WRITE EEPROM DATA
//
#define D_WREPROM	EQU	51
//
//
// ---------------------------------------------------------------------- -

//
//	SET DEFAULT DATA TO EEPROM
//
#define D_SETDEFAULT	EQU	56
//
//
// ----------------------------------------------------------------------
//
//	SET DEFAULT DATA TO RAM
//
#define D_SETDFRAM	EQU	57
//
//
// --------------------------------------------------------------------------
//
//	RELOAD EEPROM DATA
//
#define D_SETEPROM	EQU	59
//
// ----------------------------------------------------------------------
