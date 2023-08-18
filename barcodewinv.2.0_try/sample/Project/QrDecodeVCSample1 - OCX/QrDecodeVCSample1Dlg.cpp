// QrDecodeVCSample1Dlg.cpp : インプリメンテーション ファイル
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
// CQrDecodeVCSample1Dlg ダイアログ

CQrDecodeVCSample1Dlg::CQrDecodeVCSample1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CQrDecodeVCSample1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQrDecodeVCSample1Dlg)
		// メモ: この位置に ClassWizard によってメンバの初期化が追加されます。
	//}}AFX_DATA_INIT
	// メモ: LoadIcon は Win32 の DestroyIcon のサブシーケンスを要求しません。
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
// CQrDecodeVCSample1Dlg メッセージ ハンドラ

BOOL CQrDecodeVCSample1Dlg::OnInitDialog()
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
	((CComboBox*)GetDlgItem(IDC_COMBO_FINDER))->SetCurSel(3);
	
	return TRUE;  // TRUE を返すとコントロールに設定したフォーカスは失われません。
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
// もしダイアログボックスに最小化ボタンを追加するならば、アイコンを描画する
// コードを以下に記述する必要があります。MFC アプリケーションは document/view
// モデルを使っているので、この処理はフレームワークにより自動的に処理されます。

//---------------------------------------------------------------------------
void CQrDecodeVCSample1Dlg::OnPaint() 
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
HCURSOR CQrDecodeVCSample1Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//---------------------------------------------------------------------------
// QRコード認識ライブラリの初期化を行う
//
// 使用しているメソッド
//	MdQrDecode_Initialize	QRコード認識ライブラリの初期化処理を行う
//
// 使用しているプロパティ
//	MdQrDecode_LimitCodes	検出して認識するQRコードの上限数を指定する
//
//---------------------------------------------------------------------------
mdINT32 CQrDecodeVCSample1Dlg::QrDecodeInitialize()
{
    mdINT32 nResult = 0, nLimitCodes = 0;
    mdCHAR szLimitCodes[MAX_STR] = "";
    mdCHAR szErrMsg[MAX_STR] = "";

    // QRコード認識ライブラリの初期化を行います

#if 1
    // (1)HASP版（ハードウェアプロテクト）
    // (2)認証版（ソフトウェアプロテクト）

    nResult = m_QrCtrl.MdQrDecode_Initialize();

#else
    // (3)配布型・ベンダーコード

    LPCTSTR ProductId = "XXXXX";
    // TODO - "XXXX" には、商品IDファイルに記載された文字列を指定してください。

    nResult = m_QrCtrl.MdQrDecode_InitializeByLicense( ProductId );

#endif

	if(nResult != MDRC_OK)
	{
		// QRコード認識ライブラリの初期化に失敗
        sprintf( szErrMsg,
            "初期化に失敗しました。\nサンプルプログラムを終了します。(%d)",
            nResult );
        MessageBox( szErrMsg );
		CDialog::OnOK();
	}
    else
	{
		nLimitCodes = m_QrCtrl.GetMdQrDecode_LimitCodes();  // 認識するQRコードの上限数を取得
		_itoa(nLimitCodes, szLimitCodes, 10);
		((CEdit*)GetDlgItem(IDC_EDIT_LIMITCODES))->SetWindowText(szLimitCodes);
	}

	return nResult;
}

//---------------------------------------------------------------------------
// QRコード認識ライブラリの終了処理を行う
//
// 使用しているメソッド
//	MdQrDecode_Terminate	QRコード認識ライブラリの終了処理を行う
//
//---------------------------------------------------------------------------
void CQrDecodeVCSample1Dlg::QrDecodeTerminate()
{
	m_QrCtrl.MdQrDecode_Terminate();// QRコード認識ライブラリの終了処理を行います
}

//---------------------------------------------------------------------------
// QRコード認識実行
//
// 使用しているメソッド
//	MdQrDecode_LoadImage	画像のロードを行う
//	MdQrDecode_Decode		ロードした画像に対してQRコードの検出と認識を行う
//	MdQrDecode_GetRect		MdQrDecode_ActiveCodeプロパティで選択したQRコードの座標を取得
//
// 使用しているプロパティ
//	MdQrDecode_ActiveCode	認識結果を取得したいQRコード番号を指定する
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

	nResult = m_QrCtrl.MdQrDecode_LoadImage(                    // 画像の読み込み
        szFileName,
        ((CSpinButtonCtrl*)GetDlgItem(IDC_SPIN_PAGE))->GetPos() );

	if(nResult == MDRC_OK)
	{
        // 読み取り解像度をセット
        m_QrCtrl.SetMdQrDecode_XDpi( m_QrCtrl.MdQrDecode_GetImageDpiX() );
        m_QrCtrl.SetMdQrDecode_YDpi( m_QrCtrl.MdQrDecode_GetImageDpiY() );

		nResult = m_QrCtrl.MdQrDecode_Decode();					// QRコード認識(全域)
		if(nResult > 0)
		{
			for(nCode = 0; nCode < nResult; nCode ++)
			{
				m_QrCtrl.SetMdQrDecode_ActiveCode(nCode + 1);	// 対象となるQRコードを選択
				m_QrCtrl.MdQrDecode_GetRect(					// QRコードの座標と幅高さを取得
											&nLeft,
											&nTop,
											&nWidth,
											&nHeight);
				sprintf(szQrCode,
                    "QRコード %2d (%4d,%4d,%4d,%4d)",
                    nCode + 1, nLeft, nTop, nWidth, nHeight);
				pListBox->AddString(szQrCode);
			}
			pListBox->SetSel(0);
			OutputText();
		}
        else
        {   // QRコードなし
            sprintf( szErrMsg,
                "QRコードが見つかりませんでした。(%d)",
                nResult );
            MessageBox( szErrMsg );
        }
	}
    else
	{
		// 画像の読み込みに失敗
        sprintf( szErrMsg,
            "画像の読み込みに失敗しました。(%d)",
            nResult );
        MessageBox( szErrMsg );
	}
}

//---------------------------------------------------------------------------
// QRコード認識結果出力
//
// 使用しているメソッド
//	MdQrDecode_GetMaxCodes		認識したQRコードの総数を取得する
//	MdQrDecode_GetStrData		MdQrDecode_ActiveCodeプロパティで選択したQRコードの
//                              認識結果を文字列として取得する
//	MdQrDecode_GetVersion		MdQrDecode_ActiveCodeプロパティで選択したQRコードの
//                              型番を取得する
//	MdQrDecode_GetCorrectLevel	MdQrDecode_ActiveCodeプロパティで選択したQRコードの
//                              訂正レベルを取得する
//	MdQrDecode_GetMaskID		MdQrDecode_ActiveCodeプロパティで選択したQRコードの
//                              マスクIDを取得する
//
// 使用しているプロパティ
//	MdQrDecode_ActiveCode		認識結果を取得したいQRコード番号を指定する
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

	nMaxCodes = m_QrCtrl.MdQrDecode_GetMaxCodes();  // 認識したQRコード数を取得
	if(nMaxCodes > 0)
	{
		for(nCode = 0; nCode < nMaxCodes; nCode ++)
		{
			nResult = pListBox->GetSel(nCode);
			if(nResult > 0)
			{
                int stIndex, stTotal, stParity;
                mdCHAR szStInfo[MAX_STR] = "";

				m_QrCtrl.SetMdQrDecode_ActiveCode(nCode + 1);           // 対象となるQRコードを選択
                // 認識結果を取得(S-JIS)
				strResult = strResult + m_QrCtrl.MdQrDecode_GetStrData() + "\r\n";
				pEditResult->SetWindowText(strResult);                  // 認識結果を表示

				_itoa(m_QrCtrl.MdQrDecode_GetVersion(), szValue, 10);   // QRコードの型番を取得
				pEditVersion->SetWindowText(szValue);                   // QRコードの型番を表示

				// QRコードの訂正レベルの取得と表示
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

				_itoa(m_QrCtrl.MdQrDecode_GetMaskID(), szValue, 10);    // QRコードのマスクIDを取得
				pEditMaskID->SetWindowText(szValue);                    // QRコードのマスクIDを表示

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
// 認識するQRコードの上限数を設定
//
// 使用しているプロパティ
//	MdQrDecode_LimitCodes	検出して認識するQRコードの上限数を指定する
//
//---------------------------------------------------------------------------
void CQrDecodeVCSample1Dlg::OnChangeEditLimitcode() 
{
	mdINT32 nLimitCodes = 0;
	mdCHAR szLimitCodes[MAX_STR] = "";

	((CEdit*)GetDlgItem(IDC_EDIT_LIMITCODES))->GetWindowText(szLimitCodes, MAX_STR);
	nLimitCodes = atoi(szLimitCodes);

	m_QrCtrl.SetMdQrDecode_LimitCodes(nLimitCodes);		// 認識するQRコードの上限数を設定
}

//---------------------------------------------------------------------------
// QRコードの検出レベルを設定
//
// 使用しているプロパティ
//	MdQrDecode_Finder		QRコードの検出レベルを設定する
//
//---------------------------------------------------------------------------
void CQrDecodeVCSample1Dlg::OnSelChangeComboFinder() 
{
	mdINT32 nResult = 0;

	nResult = ((CComboBox*)GetDlgItem(IDC_COMBO_FINDER))->GetCurSel() - 3;

	m_QrCtrl.SetMdQrDecode_Finder(nResult);				// QRコードの検出レベルを設定
}

//---------------------------------------------------------------------------
// 入力画像頁数の取得
//
// 使用しているメソッド
//	MdQrDecode_CountPage  入力画像の頁数を取得する
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
// 「開く」ボタンの処理
//
//---------------------------------------------------------------------------
void CQrDecodeVCSample1Dlg::OnButtonFileopen() 
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

			GetDlgItem(IDC_EDIT_FILENAME)->SetWindowText(fileDlg.GetPathName());

            pEdit->GetWindowText(szFileName, _MAX_PATH);
            CountPage( szFileName );
		}
	}
}

//---------------------------------------------------------------------------
// ドラッグアンドドロップ時の処理
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
	
	PostMessage(WM_USER_SHOWDIALOG);// ダイアログ表示完了検知用
	
	return 0;
}

//---------------------------------------------------------------------------
// ダイアログ表示完了時の処理
//
//---------------------------------------------------------------------------
LRESULT CQrDecodeVCSample1Dlg::WmUserShowDialog(UINT wParam, LPARAM lParam)
{
	mdINT32 nResult = 0;

	nResult = QrDecodeInitialize();

	return nResult;
}

//---------------------------------------------------------------------------
// ダイアログ終了時の処理
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
