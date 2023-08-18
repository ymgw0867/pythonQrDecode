// BcDecodeVCSample1Dlg.h : �w�b�_�[ �t�@�C��
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

#define WM_USER_SHOWDIALOG (WM_USER + 1000)// �_�C�A���O�\���������m�p���b�Z�[�W

/////////////////////////////////////////////////////////////////////////////
// CBcDecodeVCSample1Dlg �_�C�A���O

class CBcDecodeVCSample1Dlg : public CDialog
{
// �\�z
public:
	CBcDecodeVCSample1Dlg(CWnd* pParent = NULL);	// �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CBcDecodeVCSample1Dlg)
	enum { IDD = IDD_BCDECODEVCSAMPLE1_DIALOG };
	//}}AFX_DATA

	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CBcDecodeVCSample1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �̃T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	HICON m_hIcon;

	mdINT32	BcDecodeInitialize();
	void	BcDecodeTerminate();
	void	OutputText();
    int     CountPage( mdCHAR* szFileName );

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
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
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_BCDECODEVCSAMPLE1DLG_H__59890E2B_E9BF_4789_B667_2E95B21FDA99__INCLUDED_)
