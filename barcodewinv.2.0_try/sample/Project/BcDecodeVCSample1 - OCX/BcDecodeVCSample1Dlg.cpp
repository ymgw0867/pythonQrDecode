// BcDecodeVCSample1Dlg.cpp : インプリメンテーション ファイル
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
// アプリケーションのバージョン情報で使われている CAboutDlg ダイアログ

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ダイアログ データ
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard は仮想関数のオーバーライドを生成します
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV のサポート
	//}}AFX_VIRTUAL

// インプリメンテーション
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
		// メッセージ ハンドラがありません。
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBcDecodeVCSample1Dlg ダイアログ

CBcDecodeVCSample1Dlg::CBcDecodeVCSample1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBcDecodeVCSample1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBcDecodeVCSample1Dlg)
		// メモ: この位置に ClassWizard によってメンバの初期化が追加されます。
	//}}AFX_DATA_INIT
	// メモ: LoadIcon は Win32 の DestroyIcon のサブシーケンスを要求しません。
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
// CBcDecodeVCSample1Dlg メッセージ ハンドラ

BOOL CBcDecodeVCSample1Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// "バージョン情報..." メニュー項目をシステム メニューへ追加します。

	// IDM_ABOUTBOX はコマンド メニューの範囲でなければなりません。
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

	// このダイアログ用のアイコンを設定します。フレームワークはアプリケーションのメイン
	// ウィンドウがダイアログでない時は自動的に設定しません。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンを設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンを設定
	
	// TODO: 特別な初期化を行う時はこの場所に追加してください。
    ((CComboBox*)GetDlgItem(IDC_COMBO_DIRECTION))->SetCurSel(0);
    ((CComboBox*)GetDlgItem(IDC_COMBO_BARTYPE))->SetCurSel(0);
    ((CComboBox*)GetDlgItem(IDC_COMBO_CHECK))->SetCurSel(0);
    ((CComboBox*)GetDlgItem(IDC_COMBO_SCALE))->SetCurSel(0);
	
	return TRUE;  // TRUE を返すとコントロールに設定したフォーカスは失われません。
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
// もしダイアログボックスに最小化ボタンを追加するならば、アイコンを描画する
// コードを以下に記述する必要があります。MFC アプリケーションは document/view
// モデルを使っているので、この処理はフレームワークにより自動的に処理されます。
//
//---------------------------------------------------------------------------
void CBcDecodeVCSample1Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画用のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// クライアントの矩形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンを描画します。
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//---------------------------------------------------------------------------
// システムは、ユーザーが最小化ウィンドウをドラッグしている間、
// カーソルを表示するためにここを呼び出します。
//
//---------------------------------------------------------------------------
HCURSOR CBcDecodeVCSample1Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//---------------------------------------------------------------------------
// バーコード認識ライブラリの初期化を行う
//
// 使用しているメソッド
//	MdBcDecode_Initialize	バーコード認識ライブラリの初期化処理を行う
//
// 使用しているプロパティ
//	MdBcDecode_LimitCodes	認識するバーコードの上限数
//  MdBcDecode_XDpi         認識するバーコードの横解像度
//
//---------------------------------------------------------------------------
mdINT32 CBcDecodeVCSample1Dlg::BcDecodeInitialize()
{
    mdINT32 nResult = 0, nLimitCodes = 0;
    mdCHAR szLimitCodes[MAX_STR] = "";
    mdCHAR szErrMsg[MAX_STR] = "";

    // バーコード認識ライブラリの初期化を行います

#if 1
    // (1)HASP版（ハードウェアプロテクト）
    // (2)認証版（ソフトウェアプロテクト）

    nResult = m_BcCtrl.MdBcDecode_Initialize();

#else
    // (3)配布型・ベンダーコード

    LPCTSTR ProductId = "XXXXX";
    // TODO - "XXXX" には、商品IDファイルに記載された文字列を指定してください。

    nResult = m_BcCtrl.MdBcDecode_InitializeByLicense( ProductId );

#endif

	if(nResult != MDRC_OK)
	{
		// バーコード認識ライブラリの初期化に失敗
        sprintf( szErrMsg,
            "初期化に失敗しました。(%d)\nサンプルプログラムを終了します。",
            nResult );
        MessageBox( szErrMsg );
		CDialog::OnOK();
	}
    else
	{
        // 認識するバーコードの上限数を取得
		nLimitCodes = m_BcCtrl.GetMdBcDecode_LimitCodes();
		_itoa(nLimitCodes, szLimitCodes, 10);
		((CEdit*)GetDlgItem(IDC_EDIT_LIMITCODES))->SetWindowText(szLimitCodes);

        // 認識するバーコードの横解像度(初期値)を取得
        mdINT32 nDpiX = m_BcCtrl.GetMdBcDecode_XDpi();
        mdCHAR szDpiX[MAX_STR] = "";
        _itoa(nDpiX, szDpiX, 10);
        ((CEdit*)GetDlgItem(IDC_EDIT_DPIX))->SetWindowText(szDpiX);
	}

	return nResult;
}

//---------------------------------------------------------------------------
// バーコード認識ライブラリの終了処理を行う
//
// 使用しているメソッド
//	MdBcDecode_Terminate	バーコード認識ライブラリの終了処理を行う
//
//---------------------------------------------------------------------------
void CBcDecodeVCSample1Dlg::BcDecodeTerminate()
{
	m_BcCtrl.MdBcDecode_Terminate();// バーコード認識ライブラリの終了処理を行います
}

//---------------------------------------------------------------------------
// バーコード認識実行
//
// 使用しているメソッド
//	MdBcDecode_Decode		ロードした画像に対してバーコードの検出と認識を行う
//	MdBcDecode_GetRect		MdBcDecode_ActiveCodeプロパティで選択したバーコードの座標を取得
//
// 使用しているプロパティ
//  MdBcDecode_XDpi         認識するバーコードの横解像度
//  MdBcDecode_YDpi         認識するバーコードの縦解像度
//	MdBcDecode_ActiveCode	認識結果を取得するバーコード番号
//
//---------------------------------------------------------------------------
void CBcDecodeVCSample1Dlg::OnButtonDecode() 
{
    // 認識結果のリセット
    ((CEdit*)GetDlgItem(IDC_EDIT_VERSION))->SetWindowText("");
    ((CEdit*)GetDlgItem(IDC_EDIT_RESULT))->SetWindowText("");
	((CListBox*)GetDlgItem(IDC_LIST_BC))->ResetContent();


    // 解像度の設定
	mdINT32 nScale = ((CComboBox*)GetDlgItem(IDC_COMBO_SCALE))->GetCurSel() + 1;
    mdCHAR szDpiX[MAX_STR] = "";
    GetDlgItem(IDC_EDIT_DPIX)->GetWindowText(szDpiX, MAX_STR);
    long nDpiX = atol(szDpiX) * nScale;
    long nDpiY = atol(szDpiX) * nScale;

    m_BcCtrl.SetMdBcDecode_XDpi( nDpiX );
    m_BcCtrl.SetMdBcDecode_YDpi( nDpiY );

    mdCHAR szDlgMsg[MAX_STR] = "";

    // バーコード認識(全域)
	mdINT32 nResult = m_BcCtrl.MdBcDecode_Decode();
	if(nResult > 0)
	{
        mdINT32 nCode;
	    mdINT32 nLeft = 0, nTop = 0, nWidth = 0, nHeight = 0;
	    CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST_BC);
        mdCHAR szBcCode[MAX_STR] = "";
		for(nCode = 0; nCode < nResult; nCode++)
		{
            // 対象となるバーコードを選択
			m_BcCtrl.SetMdBcDecode_ActiveCode(nCode + 1);

            // バーコードの座標と幅高さを取得
			m_BcCtrl.MdBcDecode_GetRect(
										&nLeft,
										&nTop,
										&nWidth,
										&nHeight);
			sprintf(szBcCode,
                "バーコード %2d (%4d,%4d,%4d,%4d)",
                nCode + 1, nLeft, nTop, nWidth, nHeight);
			pListBox->AddString(szBcCode);
		}
		pListBox->SetSel(0);
		OutputText();

        sprintf( szDlgMsg,
            "認識終了。(%d)",
            nResult );
        MessageBox( szDlgMsg );
	}
    else
    {   // バーコードなし
        sprintf( szDlgMsg,
            "バーコードが見つかりませんでした。(%d)",
            nResult );
        MessageBox( szDlgMsg );
    }
}

//---------------------------------------------------------------------------
// バーコード認識結果出力
//
// 使用しているメソッド
//	MdBcDecode_GetMaxCodes  認識したバーコードの総数を取得する
//	MdBcDecode_GetStrData   MdBcDecode_ActiveCodeプロパティで選択したバーコードの
//                          認識結果を文字列として取得する
//	MdBcDecode_GetVersion   MdBcDecode_ActiveCodeプロパティで選択したバーコードの
//                          種別を取得する
//
// 使用しているプロパティ
//	MdBcDecode_ActiveCode   認識結果を取得したいバーコード番号
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

    // 認識したバーコード数を取得
	nMaxCodes = m_BcCtrl.MdBcDecode_GetMaxCodes();
	if(nMaxCodes > 0)
	{
		for(nCode = 0; nCode < nMaxCodes; nCode ++)
		{
			nResult = pListBox->GetSel(nCode);
			if(nResult > 0)
			{
                // 対象となるバーコードを選択
				m_BcCtrl.SetMdBcDecode_ActiveCode(nCode + 1);
                // 認識結果を取得(S-JIS)
				strResult = strResult + m_BcCtrl.MdBcDecode_GetStrData() + "\r\n";
                // 認識結果を表示
				pEditResult->SetWindowText(strResult);

                int i;
                for( i = 0; i < Number( LNG_BC_BARTYPE ); i++ )
                {
                    if( m_BcCtrl.MdBcDecode_GetVersion() == LNG_BC_BARTYPE[i] )
                    {
                        pEditVersion->SetWindowText( STR_BC_BARTYPE[i] );
                        break;
                    }
                    pEditVersion->SetWindowText( "種別不明" );
                }
			}
		}
	}
}

//---------------------------------------------------------------------------
// 認識するバーコードの上限数を設定
//
// 使用しているプロパティ
//	MdBcDecode_LimitCodes	認識するバーコードの上限数
//
//---------------------------------------------------------------------------
void CBcDecodeVCSample1Dlg::OnChangeEditLimitCode() 
{
	mdINT32 nLimitCodes = 0;
	mdCHAR szLimitCodes[MAX_STR] = "";

	((CEdit*)GetDlgItem(IDC_EDIT_LIMITCODES))->GetWindowText(szLimitCodes, MAX_STR);
	nLimitCodes = atoi(szLimitCodes);

    // 認識するバーコードの上限数を設定
	m_BcCtrl.SetMdBcDecode_LimitCodes(nLimitCodes);
}
//---------------------------------------------------------------------------
// 認識するバーコードの桁数を設定
//
// 使用しているプロパティ
//	MdBcDecode_Length	認識するバーコードの桁数
//
//---------------------------------------------------------------------------
void CBcDecodeVCSample1Dlg::OnChangeEditLength() 
{
	mdINT32 nLength = 0;
	mdCHAR szLength[MAX_STR] = "";

	((CEdit*)GetDlgItem(IDC_EDIT_LENGTH))->GetWindowText(szLength, MAX_STR);
	nLength = atoi(szLength);

    // 認識するバーコードの桁数を設定
	m_BcCtrl.SetMdBcDecode_Length(nLength);
}

#if 0
//---------------------------------------------------------------------------
void CBcDecodeVCSample1Dlg::OnChangeEditReplaceCntrl()
{
    // IDC_EDIT_REPLACE_CNTRL を設定。
    mdCHAR szReplaceCntrl[MAX_STR] = "";
	((CEdit*)GetDlgItem(IDC_EDIT_REPLACE_CNTRL))->GetWindowText(szReplaceCntrl, MAX_STR);

    // 制御コードに対する置換文字を設定
	m_BcCtrl.MdBcDecode_SetOption(nLength);
    
}
#endif

//---------------------------------------------------------------------------
// バーコードの読取方向を設定
//
// 使用しているプロパティ
//	MdBcDecode_Direction		バーコードの読取方向
//
//---------------------------------------------------------------------------
void CBcDecodeVCSample1Dlg::OnSelChangeComboDirection() 
{
	mdINT32 nResult = 0;

	nResult = ((CComboBox*)GetDlgItem(IDC_COMBO_DIRECTION))->GetCurSel();

    // バーコードの読取方向を設定
	m_BcCtrl.SetMdBcDecode_Direction(LNG_BC_DIRECTION[nResult]);
}

//---------------------------------------------------------------------------
// バーコードの種別を設定
//
// 使用しているプロパティ
//	MdBcDecode_BarType      バーコードの種別
//
//---------------------------------------------------------------------------
void CBcDecodeVCSample1Dlg::OnSelChangeComboBarType() 
{
	mdINT32 nBarType = 0;
    CComboBox* pComboBoxCheck = NULL;

    nBarType = ((CComboBox*)GetDlgItem(IDC_COMBO_BARTYPE))->GetCurSel();

    // バーコードの種別を設定
	m_BcCtrl.SetMdBcDecode_BarType(LNG_BC_BARTYPE[nBarType]);

    // 選択された種別に応じてチェック種別を更新
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

    // チェック式初期化
    m_BcCtrl.SetMdBcDecode_CheckITF(BC_CHECK_NONE);
    m_BcCtrl.SetMdBcDecode_CheckCODE39(BC_CHECK_NONE);
    m_BcCtrl.SetMdBcDecode_CheckNW7(BC_CHECK_NONE);
}

//---------------------------------------------------------------------------
// バーコードのチェック式を設定
//
// 使用しているプロパティ
//	MdBcDecode_CheckITF     ITFバーコードのチェック式
//	MdBcDecode_CheckCODE39  CODE39バーコードのチェック式
//	MdBcDecode_CheckNW7     NW-7バーコードのチェック式
//
//---------------------------------------------------------------------------
void CBcDecodeVCSample1Dlg::OnSelChangeComboCheck() 
{
    mdINT32 nBarType = 0;
	mdINT32 nCheck = 0;

    nBarType = ((CComboBox*)GetDlgItem(IDC_COMBO_BARTYPE))->GetCurSel();
	nCheck = ((CComboBox*)GetDlgItem(IDC_COMBO_CHECK))->GetCurSel();

    // チェック式初期化
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
// 入力画像頁数の取得
//
// 使用しているメソッド
//	MdBcDecode_CountPage  入力画像の頁数を取得する
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
// 「開く」ボタンの処理
//
// 使用しているメソッド
//	MdBcDecode_LoadImage	画像のロードを行う
//  MdBcDecode_GetImageDpiX 入力画像の横解像度を取得する
//
//---------------------------------------------------------------------------
void CBcDecodeVCSample1Dlg::OnButtonFileOpen() 
{	
    // 認識結果をリセット
    ((CEdit*)GetDlgItem(IDC_EDIT_VERSION))->SetWindowText("");
    ((CEdit*)GetDlgItem(IDC_EDIT_RESULT))->SetWindowText("");
    ((CListBox*)GetDlgItem(IDC_LIST_BC))->ResetContent();

    // 画像の読み込み
    mdCHAR szFileName[_MAX_PATH] = "";
    GetDlgItem(IDC_EDIT_FILENAME)->GetWindowText(szFileName, _MAX_PATH);
    mdINT32 nResult = m_BcCtrl.MdBcDecode_LoadImage( szFileName,
        ((CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_PAGE))->GetPos() );
    
    mdCHAR szDlgMsg[MAX_STR] = "";
	if(nResult == MDRC_OK)
	{
        // 解像度を取得
        mdINT32 nDpiX = m_BcCtrl.MdBcDecode_GetImageDpiX();
        mdCHAR szDpiX[MAX_STR] = "";
        _itoa(nDpiX, szDpiX, 10);
        ((CEdit*)GetDlgItem(IDC_EDIT_DPIX))->SetWindowText(szDpiX);

        sprintf( szDlgMsg,
            "画像の読み込みに成功。(%d)",
            nResult );
        MessageBox( szDlgMsg );
    }
    else
	{
		// 画像の読み込みに失敗
        sprintf( szDlgMsg,
            "画像の読み込みに失敗しました。(%d)",
            nResult );
        MessageBox( szDlgMsg );
	}
}

//---------------------------------------------------------------------------
// 「選択」ボタンの処理
//
//---------------------------------------------------------------------------
void CBcDecodeVCSample1Dlg::OnButtonFileSelect() 
{
	mdINT32 nResult = 0;
    CString filter("すべての対応ファイル (*.bmp;*.tif;*.jpg;*.png;*.pdf)|*.bmp; *.tif;*.jpg;*.png;*.pdf||");

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
            sprintf( szDlgMsg, "画像頁数：%d", nPage );
            MessageBox( szDlgMsg );
        }
	}
}

//---------------------------------------------------------------------------
// ドラッグアンドドロップ時の処理
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
        sprintf( szDlgMsg, "画像頁数：%d", nPage );
        MessageBox( szDlgMsg );
	}
	
	CDialog::OnDropFiles(hDropInfo);
}

//---------------------------------------------------------------------------
// ダイアログ作成時の処理
//
//---------------------------------------------------------------------------
int CBcDecodeVCSample1Dlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
    {
		return -1;
    }
	
	PostMessage(WM_USER_SHOWDIALOG);// ダイアログ表示完了検知用
	
	return 0;
}

//---------------------------------------------------------------------------
// ダイアログ表示完了時の処理
//
//---------------------------------------------------------------------------
LRESULT CBcDecodeVCSample1Dlg::WmUserShowDialog(UINT wParam, LPARAM lParam)
{
	mdINT32 nResult = 0;

	nResult = BcDecodeInitialize();

	return nResult;
}

//---------------------------------------------------------------------------
// ダイアログ終了時の処理
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
