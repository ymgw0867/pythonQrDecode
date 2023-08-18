// QrDecodeVCSample1Dlg.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "QrDecodeVCSample1.h"
#include "QrDecodeVCSample1Dlg.h"
#include "MdFOcrResultCode.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#ifndef MAX_STR
#define MAX_STR 1024
#endif

/////////////////////////////////////////////////////////////////////////////
// �A�v���P�[�V�����̃o�[�W�������Ŏg���Ă��� CAboutDlg �_�C�A���O

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂�
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �̃T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// ���b�Z�[�W �n���h��������܂���B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQrDecodeVCSample1Dlg �_�C�A���O

CQrDecodeVCSample1Dlg::CQrDecodeVCSample1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CQrDecodeVCSample1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQrDecodeVCSample1Dlg)
		// ����: ���̈ʒu�� ClassWizard �ɂ���ă����o�̏��������ǉ�����܂��B
	//}}AFX_DATA_INIT
	// ����: LoadIcon �� Win32 �� DestroyIcon �̃T�u�V�[�P���X��v�����܂���B
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CQrDecodeVCSample1Dlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CQrDecodeVCSample1Dlg)
    //}}AFX_DATA_MAP
    DDX_Control(pDX, IDC_MDQRDECODECTRL1, m_QrCtrl);
}

BEGIN_MESSAGE_MAP(CQrDecodeVCSample1Dlg, CDialog)
	//{{AFX_MSG_MAP(CQrDecodeVCSample1Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_FILEOPEN, OnButtonFileopen)
	ON_WM_DROPFILES()
	ON_MESSAGE(WM_USER_SHOWDIALOG, WmUserShowDialog)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON_DECODE, OnButtonDecode)
	ON_LBN_SELCHANGE(IDC_LIST_QR, OnSelchangeListQr)
	ON_CBN_SELCHANGE(IDC_COMBO_FINDER, OnSelChangeComboFinder)
	ON_EN_CHANGE(IDC_EDIT_LIMITCODES, OnChangeEditLimitcode)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQrDecodeVCSample1Dlg ���b�Z�[�W �n���h��

BOOL CQrDecodeVCSample1Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// "�o�[�W�������..." ���j���[���ڂ��V�X�e�� ���j���[�֒ǉ����܂��B

	// IDM_ABOUTBOX �̓R�}���h ���j���[�͈̔͂łȂ���΂Ȃ�܂���B
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���̃_�C�A���O�p�̃A�C�R����ݒ肵�܂��B�t���[�����[�N�̓A�v���P�[�V�����̃��C��
	// �E�B���h�E���_�C�A���O�łȂ����͎����I�ɐݒ肵�܂���B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R����ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R����ݒ�
	
	// TODO: ���ʂȏ��������s�����͂��̏ꏊ�ɒǉ����Ă��������B
	((CComboBox*)GetDlgItem(IDC_COMBO_FINDER))->SetCurSel(3);
	
	return TRUE;  // TRUE ��Ԃ��ƃR���g���[���ɐݒ肵���t�H�[�J�X�͎����܂���B
}

//---------------------------------------------------------------------------
void CQrDecodeVCSample1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

//---------------------------------------------------------------------------
// �����_�C�A���O�{�b�N�X�ɍŏ����{�^����ǉ�����Ȃ�΁A�A�C�R����`�悷��
// �R�[�h���ȉ��ɋL�q����K�v������܂��BMFC �A�v���P�[�V������ document/view
// ���f�����g���Ă���̂ŁA���̏����̓t���[�����[�N�ɂ�莩���I�ɏ�������܂��B

//---------------------------------------------------------------------------
void CQrDecodeVCSample1Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �`��p�̃f�o�C�X �R���e�L�X�g

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// �N���C�A���g�̋�`�̈���̒���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �A�C�R����`�悵�܂��B
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//---------------------------------------------------------------------------
// �V�X�e���́A���[�U�[���ŏ����E�B���h�E���h���b�O���Ă���ԁA
// �J�[�\����\�����邽�߂ɂ������Ăяo���܂��B
//
//---------------------------------------------------------------------------
HCURSOR CQrDecodeVCSample1Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//---------------------------------------------------------------------------
// QR�R�[�h�F�����C�u�����̏��������s��
//
// �g�p���Ă��郁�\�b�h
//	MdQrDecode_Initialize	QR�R�[�h�F�����C�u�����̏������������s��
//
// �g�p���Ă���v���p�e�B
//	MdQrDecode_LimitCodes	���o���ĔF������QR�R�[�h�̏�������w�肷��
//
//---------------------------------------------------------------------------
mdINT32 CQrDecodeVCSample1Dlg::QrDecodeInitialize()
{
    mdINT32 nResult = 0, nLimitCodes = 0;
    mdCHAR szLimitCodes[MAX_STR] = "";
    mdCHAR szErrMsg[MAX_STR] = "";

    // QR�R�[�h�F�����C�u�����̏��������s���܂�

#if 1
    // (1)HASP�Łi�n�[�h�E�F�A�v���e�N�g�j
    // (2)�F�ؔŁi�\�t�g�E�F�A�v���e�N�g�j

    nResult = m_QrCtrl.MdQrDecode_Initialize();

#else
    // (3)�z�z�^�E�x���_�[�R�[�h

    LPCTSTR ProductId = "XXXXX";
    // TODO - "XXXX" �ɂ́A���iID�t�@�C���ɋL�ڂ��ꂽ��������w�肵�Ă��������B

    nResult = m_QrCtrl.MdQrDecode_InitializeByLicense( ProductId );

#endif

	if(nResult != MDRC_OK)
	{
		// QR�R�[�h�F�����C�u�����̏������Ɏ��s
        sprintf( szErrMsg,
            "�������Ɏ��s���܂����B\n�T���v���v���O�������I�����܂��B(%d)",
            nResult );
        MessageBox( szErrMsg );
		CDialog::OnOK();
	}
    else
	{
		nLimitCodes = m_QrCtrl.GetMdQrDecode_LimitCodes();  // �F������QR�R�[�h�̏�������擾
		_itoa(nLimitCodes, szLimitCodes, 10);
		((CEdit*)GetDlgItem(IDC_EDIT_LIMITCODES))->SetWindowText(szLimitCodes);
	}

	return nResult;
}

//---------------------------------------------------------------------------
// QR�R�[�h�F�����C�u�����̏I���������s��
//
// �g�p���Ă��郁�\�b�h
//	MdQrDecode_Terminate	QR�R�[�h�F�����C�u�����̏I���������s��
//
//---------------------------------------------------------------------------
void CQrDecodeVCSample1Dlg::QrDecodeTerminate()
{
	m_QrCtrl.MdQrDecode_Terminate();// QR�R�[�h�F�����C�u�����̏I���������s���܂�
}

//---------------------------------------------------------------------------
// QR�R�[�h�F�����s
//
// �g�p���Ă��郁�\�b�h
//	MdQrDecode_LoadImage	�摜�̃��[�h���s��
//	MdQrDecode_Decode		���[�h�����摜�ɑ΂���QR�R�[�h�̌��o�ƔF�����s��
//	MdQrDecode_GetRect		MdQrDecode_ActiveCode�v���p�e�B�őI������QR�R�[�h�̍��W���擾
//
// �g�p���Ă���v���p�e�B
//	MdQrDecode_ActiveCode	�F�����ʂ��擾������QR�R�[�h�ԍ����w�肷��
//
//---------------------------------------------------------------------------
void CQrDecodeVCSample1Dlg::OnButtonDecode() 
{
	mdINT32 nResult = 0, nCode = 0;
	mdINT32 nLeft = 0, nTop = 0, nWidth = 0, nHeight = 0;
	mdCHAR szFileName[_MAX_PATH] = "", szQrCode[MAX_STR] = "";
	CListBox* pListBox = NULL;
    mdCHAR szErrMsg[MAX_STR] = "";

    ((CEdit*)GetDlgItem(IDC_EDIT_RESULT))->SetWindowText("");
    ((CEdit*)GetDlgItem(IDC_EDIT_VERSION))->SetWindowText("");
    ((CEdit*)GetDlgItem(IDC_EDIT_CORRECT))->SetWindowText("");
    ((CEdit*)GetDlgItem(IDC_EDIT_MASKID))->SetWindowText("");
    ((CEdit*)GetDlgItem(IDC_EDIT_STAPP))->SetWindowText("");

	GetDlgItem(IDC_EDIT_FILENAME)->GetWindowText(szFileName, _MAX_PATH);

	pListBox = (CListBox*)GetDlgItem(IDC_LIST_QR);
	pListBox->ResetContent();

	nResult = m_QrCtrl.MdQrDecode_LoadImage(                    // �摜�̓ǂݍ���
        szFileName,
        ((CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_PAGE))->GetPos() );

	if(nResult == MDRC_OK)
	{
        // �ǂݎ��𑜓x���Z�b�g
        m_QrCtrl.SetMdQrDecode_XDpi( m_QrCtrl.MdQrDecode_GetImageDpiX() );
        m_QrCtrl.SetMdQrDecode_YDpi( m_QrCtrl.MdQrDecode_GetImageDpiY() );

		nResult = m_QrCtrl.MdQrDecode_Decode();					// QR�R�[�h�F��(�S��)
		if(nResult > 0)
		{
			for(nCode = 0; nCode < nResult; nCode ++)
			{
				m_QrCtrl.SetMdQrDecode_ActiveCode(nCode + 1);	// �ΏۂƂȂ�QR�R�[�h��I��
				m_QrCtrl.MdQrDecode_GetRect(					// QR�R�[�h�̍��W�ƕ��������擾
											&nLeft,
											&nTop,
											&nWidth,
											&nHeight);
				sprintf(szQrCode,
                    "QR�R�[�h %2d (%4d,%4d,%4d,%4d)",
                    nCode + 1, nLeft, nTop, nWidth, nHeight);
				pListBox->AddString(szQrCode);
			}
			pListBox->SetSel(0);
			OutputText();
		}
        else
        {   // QR�R�[�h�Ȃ�
            sprintf( szErrMsg,
                "QR�R�[�h��������܂���ł����B(%d)",
                nResult );
            MessageBox( szErrMsg );
        }
	}
    else
	{
		// �摜�̓ǂݍ��݂Ɏ��s
        sprintf( szErrMsg,
            "�摜�̓ǂݍ��݂Ɏ��s���܂����B(%d)",
            nResult );
        MessageBox( szErrMsg );
	}
}

//---------------------------------------------------------------------------
// QR�R�[�h�F�����ʏo��
//
// �g�p���Ă��郁�\�b�h
//	MdQrDecode_GetMaxCodes		�F������QR�R�[�h�̑������擾����
//	MdQrDecode_GetStrData		MdQrDecode_ActiveCode�v���p�e�B�őI������QR�R�[�h��
//                              �F�����ʂ𕶎���Ƃ��Ď擾����
//	MdQrDecode_GetVersion		MdQrDecode_ActiveCode�v���p�e�B�őI������QR�R�[�h��
//                              �^�Ԃ��擾����
//	MdQrDecode_GetCorrectLevel	MdQrDecode_ActiveCode�v���p�e�B�őI������QR�R�[�h��
//                              �������x�����擾����
//	MdQrDecode_GetMaskID		MdQrDecode_ActiveCode�v���p�e�B�őI������QR�R�[�h��
//                              �}�X�NID���擾����
//
// �g�p���Ă���v���p�e�B
//	MdQrDecode_ActiveCode		�F�����ʂ��擾������QR�R�[�h�ԍ����w�肷��
//
//---------------------------------------------------------------------------
void CQrDecodeVCSample1Dlg::OutputText()
{
	CListBox* pListBox = NULL;
	CEdit* pEditResult = NULL, *pEditVersion = NULL, *pEditCorrect = NULL, *pEditMaskID = NULL;
	CString strResult;
	mdINT32 nCode = 0, nMaxCodes = 0, nResult = 0;
	mdCHAR szValue[MAX_STR] = "";

	pListBox = (CListBox*)GetDlgItem(IDC_LIST_QR);
	pEditResult = (CEdit*)GetDlgItem(IDC_EDIT_RESULT);
	pEditVersion = (CEdit*)GetDlgItem(IDC_EDIT_VERSION);
	pEditCorrect = (CEdit*)GetDlgItem(IDC_EDIT_CORRECT);
	pEditMaskID = (CEdit*)GetDlgItem(IDC_EDIT_MASKID);

	nMaxCodes = m_QrCtrl.MdQrDecode_GetMaxCodes();  // �F������QR�R�[�h�����擾
	if(nMaxCodes > 0)
	{
		for(nCode = 0; nCode < nMaxCodes; nCode ++)
		{
			nResult = pListBox->GetSel(nCode);
			if(nResult > 0)
			{
                int stIndex, stTotal, stParity;
                mdCHAR szStInfo[MAX_STR] = "";

				m_QrCtrl.SetMdQrDecode_ActiveCode(nCode + 1);           // �ΏۂƂȂ�QR�R�[�h��I��
                // �F�����ʂ��擾(S-JIS)
				strResult = strResult + m_QrCtrl.MdQrDecode_GetStrData() + "\r\n";
				pEditResult->SetWindowText(strResult);                  // �F�����ʂ�\��

				_itoa(m_QrCtrl.MdQrDecode_GetVersion(), szValue, 10);   // QR�R�[�h�̌^�Ԃ��擾
				pEditVersion->SetWindowText(szValue);                   // QR�R�[�h�̌^�Ԃ�\��

				// QR�R�[�h�̒������x���̎擾�ƕ\��
				switch(m_QrCtrl.MdQrDecode_GetCorrectLevel())
				{
				case 1:
					pEditCorrect->SetWindowText("L");
					break;
				case 2:
					pEditCorrect->SetWindowText("M");
					break;
				case 3:
					pEditCorrect->SetWindowText("Q");
					break;
				case 4:
					pEditCorrect->SetWindowText("H");
					break;
				default:
					break;
				}

				_itoa(m_QrCtrl.MdQrDecode_GetMaskID(), szValue, 10);    // QR�R�[�h�̃}�X�NID���擾
				pEditMaskID->SetWindowText(szValue);                    // QR�R�[�h�̃}�X�NID��\��

                stIndex = m_QrCtrl.MdQrDecode_GetStruAppeIndex();
                stTotal = m_QrCtrl.MdQrDecode_GetStruAppeTotal();
                stParity = m_QrCtrl.MdQrDecode_GetStruAppeParity();
                sprintf( szStInfo, "%d/%d (%d)", stIndex, stTotal, stParity );
                ((CEdit*)GetDlgItem(IDC_EDIT_STAPP))->SetWindowText(szStInfo);
			}
		}
	}
}

//---------------------------------------------------------------------------
// �F������QR�R�[�h�̏������ݒ�
//
// �g�p���Ă���v���p�e�B
//	MdQrDecode_LimitCodes	���o���ĔF������QR�R�[�h�̏�������w�肷��
//
//---------------------------------------------------------------------------
void CQrDecodeVCSample1Dlg::OnChangeEditLimitcode() 
{
	mdINT32 nLimitCodes = 0;
	mdCHAR szLimitCodes[MAX_STR] = "";

	((CEdit*)GetDlgItem(IDC_EDIT_LIMITCODES))->GetWindowText(szLimitCodes, MAX_STR);
	nLimitCodes = atoi(szLimitCodes);

	m_QrCtrl.SetMdQrDecode_LimitCodes(nLimitCodes);		// �F������QR�R�[�h�̏������ݒ�
}

//---------------------------------------------------------------------------
// QR�R�[�h�̌��o���x����ݒ�
//
// �g�p���Ă���v���p�e�B
//	MdQrDecode_Finder		QR�R�[�h�̌��o���x����ݒ肷��
//
//---------------------------------------------------------------------------
void CQrDecodeVCSample1Dlg::OnSelChangeComboFinder() 
{
	mdINT32 nResult = 0;

	nResult = ((CComboBox*)GetDlgItem(IDC_COMBO_FINDER))->GetCurSel() - 3;

	m_QrCtrl.SetMdQrDecode_Finder(nResult);				// QR�R�[�h�̌��o���x����ݒ�
}

//---------------------------------------------------------------------------
// ���͉摜�Ő��̎擾
//
// �g�p���Ă��郁�\�b�h
//	MdQrDecode_CountPage  ���͉摜�̕Ő����擾����
//
//---------------------------------------------------------------------------
void CQrDecodeVCSample1Dlg::CountPage( mdCHAR* szFileName )
{
    int nPage;
    CSpinButtonCtrl* pSpinPage = NULL;

    nPage = m_QrCtrl.MdQrDecode_CountPage( szFileName );
    pSpinPage = (CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_PAGE);
    if( nPage > 0 )
    {
        pSpinPage->SetRange( 1, nPage );
        pSpinPage->SetPos( 1 );
    }
    else
    {
        pSpinPage->SetRange( 0, 0 );
        pSpinPage->SetPos( 0 );
    }
}

//---------------------------------------------------------------------------
// �u�J���v�{�^���̏���
//
//---------------------------------------------------------------------------
void CQrDecodeVCSample1Dlg::OnButtonFileopen() 
{
	mdINT32 nResult = 0;
    CString filter("���ׂĂ̑Ή��t�@�C�� (*.bmp;*.tif;*.jpg;*.png;*.pdf)|*.bmp; *.tif;*.jpg;*.png;*.pdf||");

	CFileDialog fileDlg(
		TRUE,
		NULL,
		NULL,
		OFN_FILEMUSTEXIST |
        OFN_HIDEREADONLY,
		filter,
		NULL);

	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_FILENAME);

	if(pEdit != NULL)
	{
		if(fileDlg.DoModal() == IDOK)
		{
            mdCHAR szFileName[_MAX_PATH] = "";

			pEdit->SetWindowText(fileDlg.GetPathName());

			GetDlgItem(IDC_EDIT_FILENAME)->SetWindowText(fileDlg.GetPathName());

            pEdit->GetWindowText(szFileName, _MAX_PATH);
            CountPage( szFileName );
		}
	}
}

//---------------------------------------------------------------------------
// �h���b�O�A���h�h���b�v���̏���
//
//---------------------------------------------------------------------------
void CQrDecodeVCSample1Dlg::OnDropFiles(HDROP hDropInfo) 
{
	mdINT32 nResult = 0;
	mdCHAR szFileName[_MAX_PATH] = "";

	nResult = ::DragQueryFile(hDropInfo, 0, szFileName, _MAX_PATH);
	if(nResult > 0)
	{
		GetDlgItem(IDC_EDIT_FILENAME)->SetWindowText(szFileName);
        CountPage( szFileName );
	}
	
	CDialog::OnDropFiles(hDropInfo);
}

//---------------------------------------------------------------------------
int CQrDecodeVCSample1Dlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
    {
		return -1;
    }
	
	PostMessage(WM_USER_SHOWDIALOG);// �_�C�A���O�\���������m�p
	
	return 0;
}

//---------------------------------------------------------------------------
// �_�C�A���O�\���������̏���
//
//---------------------------------------------------------------------------
LRESULT CQrDecodeVCSample1Dlg::WmUserShowDialog(UINT wParam, LPARAM lParam)
{
	mdINT32 nResult = 0;

	nResult = QrDecodeInitialize();

	return nResult;
}

//---------------------------------------------------------------------------
// �_�C�A���O�I�����̏���
//
//---------------------------------------------------------------------------
void CQrDecodeVCSample1Dlg::OnClose() 
{
	QrDecodeTerminate();

	CDialog::OnClose();
}

//---------------------------------------------------------------------------
void CQrDecodeVCSample1Dlg::OnSelchangeListQr() 
{
	OutputText();
}
