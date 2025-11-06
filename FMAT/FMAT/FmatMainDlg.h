// FmatMainDlg.h
class CFmatMainDlg : public CDialogEx {
    // ...
private:
    CDeviceSession m_dev;
    void AppendLog(LPCTSTR s);
    void BusyUI(BOOL busy);
    // …
    afx_msg void OnBnClickedBtnEeprom();    // 各ボタン
    afx_msg void OnBnClickedBtnSireal();
    // …
    DECLARE_MESSAGE_MAP()
};
