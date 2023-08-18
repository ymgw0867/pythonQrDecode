// QrDecodeVCSample1Dlg.h : �w�b�_�[ �t�@�C��
//
//{{AFX_INCLUDES()
//}}AFX_INCLUDES

#if !defined(AFX_QRDECODEVCSAMPLE1DLG_H__59890E2B_E9BF_4789_B667_2E95B21FDA99__INCLUDED_)
#define AFX_QRDECODEVCSAMPLE1DLG_H__59890E2B_E9BF_4789_B667_2E95B21FDA99__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MdFOcrDef.h"
#include "mdqrdecodectrl1.h"

#define WM_USER_SHOWDIALOG (WM_USER + 1000)// �_�C�A���O�\���������m�p���b�Z�[�W

/////////////////////////////////////////////////////////////////////////////
// CQrDecodeVCSample1Dlg �_�C�A���O

class CQrDecodeVCSample1Dlg : public CDialog
{
// �\�z
public:
	CQrDecodeVCSample1Dlg(CWnd* pParent = NULL);	// �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CQrDecodeVCSample1Dlg)
	enum { IDD = IDD_QRDECODEVCSAMPLE1_DIALOG };
	//}}AFX_DATA

	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CQrDecodeVCSample1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �̃T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	HICON m_hIcon;

	mdINT32	QrDecodeInitialize();
	void	QrDecodeTerminate();
	void	OutputText();
    void    CountPage( mdCHAR* szFileName );

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CQrDecodeVCSample1Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonFileopen();
	afx_msg void OnDropFiles(HDROP hDropInfo);
	afx_msg LRESULT WmUserShowDialog(UINT wParam, LPARAM lParam);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnClose();
	afx_msg void OnButtonDecode();
	afx_msg void OnSelchangeListQr();
	afx_msg void OnSelChangeComboFinder();
	afx_msg void OnChangeEditLimitcode();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
    CMdqrdecodectrl1 m_QrCtrl;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_QRDECODEVCSAMPLE1DLG_H__59890E2B_E9BF_4789_B667_2E95B21FDA99__INCLUDED_)
