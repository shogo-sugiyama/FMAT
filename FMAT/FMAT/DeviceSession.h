// DeviceSession.h : 1接続=1セッション。要求をワーカースレッドで実行。
class CDeviceSession {
public:
    CDeviceSession();
    ~CDeviceSession();
    bool Open(const CommOpenParams& p, CString& err);
    void Close();
    bool IsOpen() const;

    // 代表的なアクション（後で中身を埋める）
    bool CmdReadEeprom(std::vector<BYTE>& out, CString& err);
    bool CmdWriteEeprom(const std::vector<BYTE>& in, CString& err);
    // …Sireal/Error/Function/Diag/Parameter も同様に

private:
    std::unique_ptr<IComm> m_comm; // まずは SerialComm を入れる
    // 例：フレーム化ヘルパ
    bool TxRx(const BYTE* tx, DWORD txLen, std::vector<BYTE>& rx, DWORD expect, CString& err);
};
