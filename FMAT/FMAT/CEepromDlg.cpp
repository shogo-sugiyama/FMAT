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

    // 8列作成（Addr/Value×4）
    m_ClistCtrl.InsertColumn(0, L"Addr1", LVCFMT_RIGHT, 50);
    m_ClistCtrl.InsertColumn(1, L"Value1", LVCFMT_RIGHT, 70);
    m_ClistCtrl.InsertColumn(2, L"Addr2", LVCFMT_RIGHT, 50);
    m_ClistCtrl.InsertColumn(3, L"Value2", LVCFMT_RIGHT, 70);
    m_ClistCtrl.InsertColumn(4, L"Addr3", LVCFMT_RIGHT, 50);
    m_ClistCtrl.InsertColumn(5, L"Value3", LVCFMT_RIGHT, 70);
    m_ClistCtrl.InsertColumn(6, L"Addr4", LVCFMT_RIGHT, 50);
    m_ClistCtrl.InsertColumn(7, L"Value4", LVCFMT_RIGHT, 70);

    // 32行分のデータを作る
    for (int row = 0; row < 32; ++row)
    {
        CString addrStr;
        int nIndex = m_ClistCtrl.InsertItem(row, L"");

        // Addr1
        addrStr.Format(L"%d", 1 + row);
        m_ClistCtrl.SetItemText(nIndex, 0, addrStr);
        // Addr2
        addrStr.Format(L"%d", 33 + row);
        m_ClistCtrl.SetItemText(nIndex, 2, addrStr);
        // Addr3
        addrStr.Format(L"%d", 65 + row);
        m_ClistCtrl.SetItemText(nIndex, 4, addrStr);
        // Addr4
        addrStr.Format(L"%d", 97 + row);
        m_ClistCtrl.SetItemText(nIndex, 6, addrStr);

        // Value列は空欄（後で編集用）
        m_ClistCtrl.SetItemText(nIndex, 1, L"");
        m_ClistCtrl.SetItemText(nIndex, 3, L"");
        m_ClistCtrl.SetItemText(nIndex, 5, L"");
        m_ClistCtrl.SetItemText(nIndex, 7, L"");
    }
    return TRUE;
}

void CEepromDlg::OnBnClickedOk()
{
    // TODO: ここにコントロール通知ハンドラー コードを追加します。
    CDialogEx::OnOK();
}
