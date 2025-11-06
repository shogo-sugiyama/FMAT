// CEepromDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "FMAT.h"
#include "CEepromDlg.h"
#include "afxdialogex.h"


// CEepromDlg ダイアログ

IMPLEMENT_DYNAMIC(CEepromDlg, CDialogEx)

CEepromDlg::CEepromDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CEepromDlg::~CEepromDlg()
{
}

void CEepromDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST__EEPROM, m_ClistCtrl);
}


BEGIN_MESSAGE_MAP(CEepromDlg, CDialogEx)
    ON_BN_CLICKED(IDOK, &CEepromDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CEepromDlg メッセージ ハンドラー
BOOL CEepromDlg::OnInitDialog() {
    CDialogEx::OnInitDialog();
    m_ClistCtrl.ModifyStyle(0, LVS_REPORT | LVS_SINGLESEL | LVS_SHOWSELALWAYS | LVS_EDITLABELS);
    m_ClistCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_DOUBLEBUFFER);

    m_ClistCtrl.InsertColumn(0, L"Addr", LVCFMT_RIGHT, 60);
    m_ClistCtrl.InsertColumn(1, L"Value", LVCFMT_RIGHT, 80);
    m_ClistCtrl.InsertColumn(2, L"備考", LVCFMT_LEFT, 160);

    // 行を用意（例：0x01〜0x21）
    for (int i = 1; i < 0x21; ++i) {
        CString addr; addr.Format(L"%d", i);
        int row = m_ClistCtrl.InsertItem(i, addr);
        m_ClistCtrl.SetItemText(row, 1, L"");   // 値（編集対象）
        m_ClistCtrl.SetItemText(row, 2, L"");   // 備考
    }
    return TRUE;
}


void CEepromDlg::OnBnClickedOk()
{
    // TODO: ここにコントロール通知ハンドラー コードを追加します。
    CDialogEx::OnOK();
}
