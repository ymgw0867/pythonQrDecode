// BcDecodeVCSample1Dlg.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "BcDecodeVCSample1.h"
#include "BcDecodeVCSample1Dlg.h"
#include "MdFOcrResultCode.h"
#include "Barcode.h"

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
// CBcDecodeVCSample1Dlg �_�C�A���O

CBcDecodeVCSample1Dlg::CBcDecodeVCSample1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBcDecodeVCSample1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBcDecodeVCSample1Dlg)
		// ����: ���̈ʒu�� ClassWizard �ɂ���ă����o�̏��������ǉ�����܂��B
	//}}AFX_DATA_INIT
	// ����: LoadIcon �� Win32 �� DestroyIcon �̃T�u�V�[�P���X��v�����܂���B
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBcDecodeVCSample1Dlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CBcDecodeVCSample1Dlg)
    //}}AFX_DATA_MAP
    DDX_Control(pDX, IDC_MDBCDECODECTRL1, m_BcCtrl);
}

BEGIN_MESSAGE_MAP(CBcDecodeVCSample1Dlg, CDialog)
	//{{AFX_MSG_MAP(CBcDecodeVCSample1Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON_FILESELECT, OnButtonFileSelect)
	ON_BN_CLICKED(IDC_BUTTON_FILEOPEN, OnButtonFileOpen)
	ON_WM_DROPFILES()
	ON_MESSAGE(WM_USER_SHOWDIALOG, WmUserShowDialog)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON_DECODE, OnButtonDecode)
	ON_LBN_SELCHANGE(IDC_LIST_BC, OnSelchangeListBc)
    ON_CBN_SELCHANGE(IDC_COMBO_DIRECTION, OnSelChangeComboDirection)
    ON_CBN_SELCHANGE(IDC_COMBO_BARTYPE, OnSelChangeComboBarType)
    ON_CBN_SELCHANGE(IDC_COMBO_CHECK, OnSelChangeComboCheck)
	ON_EN_CHANGE(IDC_EDIT_LIMITCODES, OnChangeEditLimitCode)
    ON_EN_CHANGE(IDC_EDIT_LENGTH, OnChangeEditLength)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBcDecodeVCSample1Dlg ���b�Z�[�W �n���h��

BOOL CBcDecodeVCSample1Dlg::OnInitDialog()
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
    ((CComboBox*)GetDlgItem(IDC_COMBO_DIRECTION))->SetCurSel(0);
    ((CComboBox*)GetDlgItem(IDC_COMBO_BARTYPE))->SetCurSel(0);
    ((CComboBox*)GetDlgItem(IDC_COMBO_CHECK))->SetCurSel(0);
    ((CComboBox*)GetDlgItem(IDC_COMBO_SCALE))->SetCurSel(0);
	
	return TRUE;  // TRUE ��Ԃ��ƃR���g���[���ɐݒ肵���t�H�[�J�X�͎����܂���B
}

//---------------------------------------------------------------------------
void CBcDecodeVCSample1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//
//---------------------------------------------------------------------------
void CBcDecodeVCSample1Dlg::OnPaint() 
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
HCURSOR CBcDecodeVCSample1Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//---------------------------------------------------------------------------
// �o�[�R�[�h�F�����C�u�����̏��������s��
//
// �g�p���Ă��郁�\�b�h
//	MdBcDecode_Initialize	�o�[�R�[�h�F�����C�u�����̏������������s��
//
// �g�p���Ă���v���p�e�B
//	MdBcDecode_LimitCodes	�F������o�[�R�[�h�̏����
//  MdBcDecode_XDpi         �F������o�[�R�[�h�̉��𑜓x
//
//---------------------------------------------------------------------------
mdINT32 CBcDecodeVCSample1Dlg::BcDecodeInitialize()
{
    mdINT32 nResult = 0, nLimitCodes = 0;
    mdCHAR szLimitCodes[MAX_STR] = "";
    mdCHAR szErrMsg[MAX_STR] = "";

    // �o�[�R�[�h�F�����C�u�����̏��������s���܂�

#if 1
    // (1)HASP�Łi�n�[�h�E�F�A�v���e�N�g�j
    // (2)�F�ؔŁi�\�t�g�E�F�A�v���e�N�g�j

    nResult = m_BcCtrl.MdBcDecode_Initialize();

#else
    // (3)�z�z�^�E�x���_�[�R�[�h

    LPCTSTR ProductId = "XXXXX";
    // TODO - "XXXX" �ɂ́A���iID�t�@�C���ɋL�ڂ��ꂽ��������w�肵�Ă��������B

    nResult = m_BcCtrl.MdBcDecode_InitializeByLicense( ProductId );

#endif

	if(nResult != MDRC_OK)
	{
		// �o�[�R�[�h�F�����C�u�����̏������Ɏ��s
        sprintf( szErrMsg,
            "�������Ɏ��s���܂����B(%d)\n�T���v���v���O�������I�����܂��B",
            nResult );
        MessageBox( szErrMsg );
		CDialog::OnOK();
	}
    else
	{
        // �F������o�[�R�[�h�̏�������擾
		nLimitCodes = m_BcCtrl.GetMdBcDecode_LimitCodes();
		_itoa(nLimitCodes, szLimitCodes, 10);
		((CEdit*)GetDlgItem(IDC_EDIT_LIMITCODES))->SetWindowText(szLimitCodes);

        // �F������o�[�R�[�h�̉��𑜓x(�����l)���擾
        mdINT32 nDpiX = m_BcCtrl.GetMdBcDecode_XDpi();
        mdCHAR szDpiX[MAX_STR] = "";
        _itoa(nDpiX, szDpiX, 10);
        ((CEdit*)GetDlgItem(IDC_EDIT_DPIX))->SetWindowText(szDpiX);
	}

	return nResult;
}

//---------------------------------------------------------------------------
// �o�[�R�[�h�F�����C�u�����̏I���������s��
//
// �g�p���Ă��郁�\�b�h
//	MdBcDecode_Terminate	�o�[�R�[�h�F�����C�u�����̏I���������s��
//
//---------------------------------------------------------------------------
void CBcDecodeVCSample1Dlg::BcDecodeTerminate()
{
	m_BcCtrl.MdBcDecode_Terminate();// �o�[�R�[�h�F�����C�u�����̏I���������s���܂�
}

//---------------------------------------------------------------------------
// �o�[�R�[�h�F�����s
//
// �g�p���Ă��郁�\�b�h
//	MdBcDecode_Decode		���[�h�����摜�ɑ΂��ăo�[�R�[�h�̌��o�ƔF�����s��
//	MdBcDecode_GetRect		MdBcDecode_ActiveCode�v���p�e�B�őI�������o�[�R�[�h�̍��W���擾
//
// �g�p���Ă���v���p�e�B
//  MdBcDecode_XDpi         �F������o�[�R�[�h�̉��𑜓x
//  MdBcDecode_YDpi         �F������o�[�R�[�h�̏c�𑜓x
//	MdBcDecode_ActiveCode	�F�����ʂ��擾����o�[�R�[�h�ԍ�
//
//---------------------------------------------------------------------------
void CBcDecodeVCSample1Dlg::OnButtonDecode() 
{
    // �F�����ʂ̃��Z�b�g
    ((CEdit*)GetDlgItem(IDC_EDIT_VERSION))->SetWindowText("");
    ((CEdit*)GetDlgItem(IDC_EDIT_RESULT))->SetWindowText("");
	((CListBox*)GetDlgItem(IDC_LIST_BC))->ResetContent();


    // �𑜓x�̐ݒ�
	mdINT32 nScale = ((CComboBox*)GetDlgItem(IDC_COMBO_SCALE))->GetCurSel() + 1;
    mdCHAR szDpiX[MAX_STR] = "";
    GetDlgItem(IDC_EDIT_DPIX)->GetWindowText(szDpiX, MAX_STR);
    long nDpiX = atol(szDpiX) * nScale;
    long nDpiY = atol(szDpiX) * nScale;

    m_BcCtrl.SetMdBcDecode_XDpi( nDpiX );
    m_BcCtrl.SetMdBcDecode_YDpi( nDpiY );

    mdCHAR szDlgMsg[MAX_STR] = "";

    // �o�[�R�[�h�F��(�S��)
	mdINT32 nResult = m_BcCtrl.MdBcDecode_Decode();
	if(nResult > 0)
	{
        mdINT32 nCode;
	    mdINT32 nLeft = 0, nTop = 0, nWidth = 0, nHeight = 0;
	    CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST_BC);
        mdCHAR szBcCode[MAX_STR] = "";
		for(nCode = 0; nCode < nResult; nCode++)
		{
            // �ΏۂƂȂ�o�[�R�[�h��I��
			m_BcCtrl.SetMdBcDecode_ActiveCode(nCode + 1);

            // �o�[�R�[�h�̍��W�ƕ��������擾
			m_BcCtrl.MdBcDecode_GetRect(
										&nLeft,
										&nTop,
										&nWidth,
										&nHeight);
			sprintf(szBcCode,
                "�o�[�R�[�h %2d (%4d,%4d,%4d,%4d)",
                nCode + 1, nLeft, nTop, nWidth, nHeight);
			pListBox->AddString(szBcCode);
		}
		pListBox->SetSel(0);
		OutputText();

        sprintf( szDlgMsg,
            "�F���I���B(%d)",
            nResult );
        MessageBox( szDlgMsg );
	}
    else
    {   // �o�[�R�[�h�Ȃ�
        sprintf( szDlgMsg,
            "�o�[�R�[�h��������܂���ł����B(%d)",
            nResult );
        MessageBox( szDlgMsg );
    }
}

//---------------------------------------------------------------------------
// �o�[�R�[�h�F�����ʏo��
//
// �g�p���Ă��郁�\�b�h
//	MdBcDecode_GetMaxCodes  �F�������o�[�R�[�h�̑������擾����
//	MdBcDecode_GetStrData   MdBcDecode_ActiveCode�v���p�e�B�őI�������o�[�R�[�h��
//                          �F�����ʂ𕶎���Ƃ��Ď擾����
//	MdBcDecode_GetVersion   MdBcDecode_ActiveCode�v���p�e�B�őI�������o�[�R�[�h��
//                          ��ʂ��擾����
//
// �g�p���Ă���v���p�e�B
//	MdBcDecode_ActiveCode   �F�����ʂ��擾�������o�[�R�[�h�ԍ�
//
//---------------------------------------------------------------------------
void CBcDecodeVCSample1Dlg::OutputText()
{
	CListBox* pListBox = NULL;
	CEdit* pEditResult = NULL, *pEditVersion = NULL;
	CString strResult;
	mdINT32 nCode = 0, nMaxCodes = 0, nResult = 0;

	pListBox = (CListBox*)GetDlgItem(IDC_LIST_BC);
	pEditResult = (CEdit*)GetDlgItem(IDC_EDIT_RESULT);
	pEditVersion = (CEdit*)GetDlgItem(IDC_EDIT_VERSION);

    // �F�������o�[�R�[�h�����擾
	nMaxCodes = m_BcCtrl.MdBcDecode_GetMaxCodes();
	if(nMaxCodes > 0)
	{
		for(nCode = 0; nCode < nMaxCodes; nCode ++)
		{
			nResult = pListBox->GetSel(nCode);
			if(nResult > 0)
			{
                // �ΏۂƂȂ�o�[�R�[�h��I��
				m_BcCtrl.SetMdBcDecode_ActiveCode(nCode + 1);
                // �F�����ʂ��擾(S-JIS)
				strResult = strResult + m_BcCtrl.MdBcDecode_GetStrData() + "\r\n";
                // �F�����ʂ�\��
				pEditResult->SetWindowText(strResult);

                int i;
                for( i = 0; i < Number( LNG_BC_BARTYPE ); i++ )
                {
                    if( m_BcCtrl.MdBcDecode_GetVersion() == LNG_BC_BARTYPE[i] )
                    {
                        pEditVersion->SetWindowText( STR_BC_BARTYPE[i] );
                        break;
                    }
                    pEditVersion->SetWindowText( "��ʕs��" );
                }
			}
		}
	}
}

//---------------------------------------------------------------------------
// �F������o�[�R�[�h�̏������ݒ�
//
// �g�p���Ă���v���p�e�B
//	MdBcDecode_LimitCodes	�F������o�[�R�[�h�̏����
//
//---------------------------------------------------------------------------
void CBcDecodeVCSample1Dlg::OnChangeEditLimitCode() 
{
	mdINT32 nLimitCodes = 0;
	mdCHAR szLimitCodes[MAX_STR] = "";

	((CEdit*)GetDlgItem(IDC_EDIT_LIMITCODES))->GetWindowText(szLimitCodes, MAX_STR);
	nLimitCodes = atoi(szLimitCodes);

    // �F������o�[�R�[�h�̏������ݒ�
	m_BcCtrl.SetMdBcDecode_LimitCodes(nLimitCodes);
}
//---------------------------------------------------------------------------
// �F������o�[�R�[�h�̌�����ݒ�
//
// �g�p���Ă���v���p�e�B
//	MdBcDecode_Length	�F������o�[�R�[�h�̌���
//
//---------------------------------------------------------------------------
void CBcDecodeVCSample1Dlg::OnChangeEditLength() 
{
	mdINT32 nLength = 0;
	mdCHAR szLength[MAX_STR] = "";

	((CEdit*)GetDlgItem(IDC_EDIT_LENGTH))->GetWindowText(szLength, MAX_STR);
	nLength = atoi(szLength);

    // �F������o�[�R�[�h�̌�����ݒ�
	m_BcCtrl.SetMdBcDecode_Length(nLength);
}

#if 0
//---------------------------------------------------------------------------
void CBcDecodeVCSample1Dlg::OnChangeEditReplaceCntrl()
{
    // IDC_EDIT_REPLACE_CNTRL ��ݒ�B
    mdCHAR szReplaceCntrl[MAX_STR] = "";
	((CEdit*)GetDlgItem(IDC_EDIT_REPLACE_CNTRL))->GetWindowText(szReplaceCntrl, MAX_STR);

    // ����R�[�h�ɑ΂���u��������ݒ�
	m_BcCtrl.MdBcDecode_SetOption(nLength);
    
}
#endif

//---------------------------------------------------------------------------
// �o�[�R�[�h�̓ǎ������ݒ�
//
// �g�p���Ă���v���p�e�B
//	MdBcDecode_Direction		�o�[�R�[�h�̓ǎ����
//
//---------------------------------------------------------------------------
void CBcDecodeVCSample1Dlg::OnSelChangeComboDirection() 
{
	mdINT32 nResult = 0;

	nResult = ((CComboBox*)GetDlgItem(IDC_COMBO_DIRECTION))->GetCurSel();

    // �o�[�R�[�h�̓ǎ������ݒ�
	m_BcCtrl.SetMdBcDecode_Direction(LNG_BC_DIRECTION[nResult]);
}

//---------------------------------------------------------------------------
// �o�[�R�[�h�̎�ʂ�ݒ�
//
// �g�p���Ă���v���p�e�B
//	MdBcDecode_BarType      �o�[�R�[�h�̎��
//
//---------------------------------------------------------------------------
void CBcDecodeVCSample1Dlg::OnSelChangeComboBarType() 
{
	mdINT32 nBarType = 0;
    CComboBox* pComboBoxCheck = NULL;

    nBarType = ((CComboBox*)GetDlgItem(IDC_COMBO_BARTYPE))->GetCurSel();

    // �o�[�R�[�h�̎�ʂ�ݒ�
	m_BcCtrl.SetMdBcDecode_BarType(LNG_BC_BARTYPE[nBarType]);

    // �I�����ꂽ��ʂɉ����ă`�F�b�N��ʂ��X�V
    pComboBoxCheck = (CComboBox*)GetDlgItem(IDC_COMBO_CHECK);
    pComboBoxCheck->ResetContent();
    switch( LNG_BC_BARTYPE[nBarType] )
    {
        int i;
    case BC_BARTYPE_ANY:
        for( i = 0; i < Number(LNG_BC_CHECK_ANY); i++ )
        {
            pComboBoxCheck->AddString( STR_BC_CHECK_ANY[i] );
        }
        break;
    case BC_BARTYPE_JAN13:
    case BC_BARTYPE_JAN8:
        for( i = 0; i < Number(LNG_BC_CHECK_JAN); i++ )
        {
            pComboBoxCheck->AddString( STR_BC_CHECK_JAN[i] );
        }
        break;
    case BC_BARTYPE_ITF:
        for( i = 0; i < Number(LNG_BC_CHECK_ITF); i++ )
        {
            pComboBoxCheck->AddString( STR_BC_CHECK_ITF[i] );
        }
        break;
    case BC_BARTYPE_CODE39:
        for( i = 0; i < Number(LNG_BC_CHECK_CODE39); i++ )
        {
            pComboBoxCheck->AddString( STR_BC_CHECK_CODE39[i] );
        }
        break;
    case BC_BARTYPE_CODE128:
        for( i = 0; i < Number(LNG_BC_CHECK_CODE128); i++ )
        {
            pComboBoxCheck->AddString( STR_BC_CHECK_CODE128[i] );
        }
        break;
    case BC_BARTYPE_NW7:
        for( i = 0; i < Number(LNG_BC_CHECK_NW7); i++ )
        {
            pComboBoxCheck->AddString( STR_BC_CHECK_NW7[i] );
        }
        break;
	//->2011/10/28
	case BC_BARTYPE_CUSTOM:
        for( i = 0; i < Number(LNG_BC_CHECK_ANY); i++ )
        {
            pComboBoxCheck->AddString( STR_BC_CHECK_ANY[i] );
        }
        break;
    case BC_BARTYPE_RSS14:
        for( i = 0; i < Number(LNG_BC_CHECK_ANY); i++ )
        {
            pComboBoxCheck->AddString( STR_BC_CHECK_ANY[i] );
        }
        break;
	//<-
    default:
        break;
    }
    pComboBoxCheck->SetCurSel( 0 );

    // �`�F�b�N��������
    m_BcCtrl.SetMdBcDecode_CheckITF(BC_CHECK_NONE);
    m_BcCtrl.SetMdBcDecode_CheckCODE39(BC_CHECK_NONE);
    m_BcCtrl.SetMdBcDecode_CheckNW7(BC_CHECK_NONE);
}

//---------------------------------------------------------------------------
// �o�[�R�[�h�̃`�F�b�N����ݒ�
//
// �g�p���Ă���v���p�e�B
//	MdBcDecode_CheckITF     ITF�o�[�R�[�h�̃`�F�b�N��
//	MdBcDecode_CheckCODE39  CODE39�o�[�R�[�h�̃`�F�b�N��
//	MdBcDecode_CheckNW7     NW-7�o�[�R�[�h�̃`�F�b�N��
//
//---------------------------------------------------------------------------
void CBcDecodeVCSample1Dlg::OnSelChangeComboCheck() 
{
    mdINT32 nBarType = 0;
	mdINT32 nCheck = 0;

    nBarType = ((CComboBox*)GetDlgItem(IDC_COMBO_BARTYPE))->GetCurSel();
	nCheck = ((CComboBox*)GetDlgItem(IDC_COMBO_CHECK))->GetCurSel();

    // �`�F�b�N��������
    m_BcCtrl.SetMdBcDecode_CheckITF(BC_CHECK_NONE);
    m_BcCtrl.SetMdBcDecode_CheckCODE39(BC_CHECK_NONE);
    m_BcCtrl.SetMdBcDecode_CheckNW7(BC_CHECK_NONE);

    switch( LNG_BC_BARTYPE[nBarType] )
    {
    case BC_BARTYPE_ITF:
        m_BcCtrl.SetMdBcDecode_CheckITF(LNG_BC_CHECK_ITF[nCheck]);
        break;
    case BC_BARTYPE_CODE39:
        m_BcCtrl.SetMdBcDecode_CheckCODE39(LNG_BC_CHECK_CODE39[nCheck]);
        break;
    case BC_BARTYPE_NW7:
        m_BcCtrl.SetMdBcDecode_CheckNW7(LNG_BC_CHECK_NW7[nCheck]);
        break;
    default:
        break;
    }
}

//---------------------------------------------------------------------------
// ���͉摜�Ő��̎擾
//
// �g�p���Ă��郁�\�b�h
//	MdBcDecode_CountPage  ���͉摜�̕Ő����擾����
//
//---------------------------------------------------------------------------
int CBcDecodeVCSample1Dlg::CountPage( mdCHAR* szFileName )
{
    int nPage;
    CSpinButtonCtrl* pSpinPage = NULL;

    nPage = m_BcCtrl.MdBcDecode_CountPage( szFileName );
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
    return nPage;
}

//---------------------------------------------------------------------------
// �u�J���v�{�^���̏���
//
// �g�p���Ă��郁�\�b�h
//	MdBcDecode_LoadImage	�摜�̃��[�h���s��
//  MdBcDecode_GetImageDpiX ���͉摜�̉��𑜓x���擾����
//
//---------------------------------------------------------------------------
void CBcDecodeVCSample1Dlg::OnButtonFileOpen() 
{	
    // �F�����ʂ����Z�b�g
    ((CEdit*)GetDlgItem(IDC_EDIT_VERSION))->SetWindowText("");
    ((CEdit*)GetDlgItem(IDC_EDIT_RESULT))->SetWindowText("");
    ((CListBox*)GetDlgItem(IDC_LIST_BC))->ResetContent();

    // �摜�̓ǂݍ���
    mdCHAR szFileName[_MAX_PATH] = "";
    GetDlgItem(IDC_EDIT_FILENAME)->GetWindowText(szFileName, _MAX_PATH);
    mdINT32 nResult = m_BcCtrl.MdBcDecode_LoadImage( szFileName,
        ((CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_PAGE))->GetPos() );
    
    mdCHAR szDlgMsg[MAX_STR] = "";
	if(nResult == MDRC_OK)
	{
        // �𑜓x���擾
        mdINT32 nDpiX = m_BcCtrl.MdBcDecode_GetImageDpiX();
        mdCHAR szDpiX[MAX_STR] = "";
        _itoa(nDpiX, szDpiX, 10);
        ((CEdit*)GetDlgItem(IDC_EDIT_DPIX))->SetWindowText(szDpiX);

        sprintf( szDlgMsg,
            "�摜�̓ǂݍ��݂ɐ����B(%d)",
            nResult );
        MessageBox( szDlgMsg );
    }
    else
	{
		// �摜�̓ǂݍ��݂Ɏ��s
        sprintf( szDlgMsg,
            "�摜�̓ǂݍ��݂Ɏ��s���܂����B(%d)",
            nResult );
        MessageBox( szDlgMsg );
	}
}

//---------------------------------------------------------------------------
// �u�I���v�{�^���̏���
//
//---------------------------------------------------------------------------
void CBcDecodeVCSample1Dlg::OnButtonFileSelect() 
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
            pEdit->GetWindowText(szFileName, _MAX_PATH);
            int nPage = CountPage( szFileName );

            mdCHAR szDlgMsg[MAX_STR] = "";
            sprintf( szDlgMsg, "�摜�Ő��F%d", nPage );
            MessageBox( szDlgMsg );
        }
	}
}

//---------------------------------------------------------------------------
// �h���b�O�A���h�h���b�v���̏���
//
//---------------------------------------------------------------------------
void CBcDecodeVCSample1Dlg::OnDropFiles(HDROP hDropInfo) 
{
	mdINT32 nResult = 0;
	mdCHAR szFileName[_MAX_PATH] = "";

	nResult = ::DragQueryFile(hDropInfo, 0, szFileName, _MAX_PATH);
	if(nResult > 0)
	{
		GetDlgItem(IDC_EDIT_FILENAME)->SetWindowText(szFileName);
        int nPage = CountPage( szFileName );

        mdCHAR szDlgMsg[MAX_STR] = "";
        sprintf( szDlgMsg, "�摜�Ő��F%d", nPage );
        MessageBox( szDlgMsg );
	}
	
	CDialog::OnDropFiles(hDropInfo);
}

//---------------------------------------------------------------------------
// �_�C�A���O�쐬���̏���
//
//---------------------------------------------------------------------------
int CBcDecodeVCSample1Dlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
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
LRESULT CBcDecodeVCSample1Dlg::WmUserShowDialog(UINT wParam, LPARAM lParam)
{
	mdINT32 nResult = 0;

	nResult = BcDecodeInitialize();

	return nResult;
}

//---------------------------------------------------------------------------
// �_�C�A���O�I�����̏���
//
//---------------------------------------------------------------------------
void CBcDecodeVCSample1Dlg::OnClose() 
{
	BcDecodeTerminate();

	CDialog::OnClose();
}

//---------------------------------------------------------------------------
void CBcDecodeVCSample1Dlg::OnSelchangeListBc() 
{
	OutputText();
}
