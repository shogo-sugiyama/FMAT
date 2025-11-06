// DeviceSession.cpp（プロトコルは仮：STX(0x02) + CMD + LEN + PAYLOAD + CRC8）
bool CDeviceSession::CmdReadEeprom(std::vector<BYTE>& out, CString& err)
{
    BYTE pkt[4] = { 0x02, 0x10 /*READ_EE*/, 0x00 /*len*/, 0x00 /*crc*/ };
    pkt[3] = /* CalcCrc8 */ 0; // TODO
    std::vector<BYTE> rx;
    if (!TxRx(pkt, 4, rx, /*expect min*/ 8, err)) return false;
    // TODO: 受信整合性検査→out へコピー
    out = rx;
    return true;
}
