#include "Flowlib.h"

#pragma once


// CEepromDlg ダイアログ

class CEepromDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEepromDlg)

public:
	CEepromDlg(CWnd* pParent = nullptr);   // 標準コンストラクター
	virtual ~CEepromDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_ClistCtrl;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	Flowlib* m_Flowptr = NULL;

};
