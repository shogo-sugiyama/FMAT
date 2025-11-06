// FmatMainDlg.cpp（ログ表示やBusy制御）
void CFmatMainDlg::AppendLog(LPCTSTR s) {
    CEdit* ed = (CEdit*)GetDlgItem(IDC_EDIT_LOG);
    int len = ed->GetWindowTextLength();
    ed->SetSel(len, len);
    ed->ReplaceSel(CString(s) + L"\r\n");
}

void CFmatMainDlg::BusyUI(BOOL busy) {
    const int ids[] = { IDC_BTN_EEPROM, IDC_BTN_SIREAL, IDC_BTN_ERROR,
                        IDC_BTN_FUNCTION, IDC_BTN_PARAM, IDC_BTN_DIAG };
    for (int id : ids) GetDlgItem(id)->EnableWindow(!busy);
}

// 例: EEPROM R/W ボタン押下
void CFmatMainDlg::OnBnClickedBtnEeprom()
{
    BusyUI(TRUE);
    AppendLog(L"[EEPROM] start");

    // まだ未接続なら一度だけOpen（設定は後でオプションダイアログ化）
    if (!m_dev.IsOpen()) {
        CString err;
        CommOpenParams p; p.portOrPath = L"COM3"; p.baud = 115200; p.timeoutMs = 1500;
        if (!m_dev.Open(p, err)) {
            AppendLog(L"Open failed: " + err);
            BusyUI(FALSE); return;
        }
        AppendLog(L"Open OK");
    }

    // ワーカースレッドで処理 → UIはブロックしない
    AfxBeginThread([](LPVOID pDlg)->UINT {
        auto* dlg = reinterpret_cast<CFmatMainDlg*>(pDlg);
        CString err; std::vector<BYTE> data;
        bool ok = dlg->m_dev.CmdReadEeprom(data, err);
        ::PostMessage(dlg->m_hWnd, WM_APP + 1, ok, ok ? 0 : (LPARAM)new CString(err));
        return 0;
        }, this);

    // 完了メッセージで結果反映
    // メッセージマップに ON_MESSAGE(WM_APP+1, &CFmatMainDlg::OnEepromDone) を追加
}

LRESULT CFmatMainDlg::OnEepromDone(WPARAM ok, LPARAM lParam)
{
    if (ok) AppendLog(L"[EEPROM] done (bytes read: …)");
    else { CString* perr = (CString*)lParam; AppendLog(L"[EEPROM] error: " + *perr); delete perr; }
    BusyUI(FALSE);
    return 0;
}
