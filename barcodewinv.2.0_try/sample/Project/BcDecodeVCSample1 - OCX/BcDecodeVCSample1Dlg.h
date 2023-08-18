// BcDecodeVCSample1Dlg.h : ヘッダー ファイル
//
//{{AFX_INCLUDES()
//}}AFX_INCLUDES

#if !defined(AFX_BCDECODEVCSAMPLE1DLG_H__59890E2B_E9BF_4789_B667_2E95B21FDA99__INCLUDED_)
#define AFX_BCDECODEVCSAMPLE1DLG_H__59890E2B_E9BF_4789_B667_2E95B21FDA99__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MdFOcrDef.h"
#include "mdbcdecodectrl1.h"

#define WM_USER_SHOWDIALOG (WM_USER + 1000)// ダイアログ表示完了検知用メッセージ

/////////////////////////////////////////////////////////////////////////////
// CBcDecodeVCSample1Dlg ダイアログ

class CBcDecodeVCSample1Dlg : public CDialog
{
// 構築
public:
	CBcDecodeVCSample1Dlg(CWnd* pParent = NULL);	// 標準のコンストラクタ

// ダイアログ データ
	//{{AFX_DATA(CBcDecodeVCSample1Dlg)
	enum { IDD = IDD_BCDECODEVCSAMPLE1_DIALOG };
	//}}AFX_DATA

	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CBcDecodeVCSample1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV のサポート
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	HICON m_hIcon;

	mdINT32	BcDecodeInitialize();
	void	BcDecodeTerminate();
	void	OutputText();
    int     CountPage( mdCHAR* szFileName );

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CBcDecodeVCSample1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
    afx_msg void OnButtonFileSelect(); 
	afx_msg void OnButtonFileOpen();
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg LRESULT WmUserShowDialog(UINT wParam, LPARAM lParam);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnClose();
	afx_msg void OnButtonDecode();
	afx_msg void OnSelchangeListBc();
    afx_msg void OnSelChangeComboDirection();
    afx_msg void OnSelChangeComboBarType();
    afx_msg void OnSelChangeComboCheck();
	afx_msg void OnChangeEditLimitCode();
    afx_msg void OnChangeEditLength();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
    CMdbcdecodectrl1 m_BcCtrl;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_BCDECODEVCSAMPLE1DLG_H__59890E2B_E9BF_4789_B667_2E95B21FDA99__INCLUDED_)
