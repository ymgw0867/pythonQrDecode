// QrDecodeVCSample1.h : QRDECODEVCSAMPLE1 アプリケーションのメイン ヘッダー ファイルです。
//

#if !defined(AFX_QRDECODEVCSAMPLE1_H__37194905_0706_447E_AD4A_613CCA0BE720__INCLUDED_)
#define AFX_QRDECODEVCSAMPLE1_H__37194905_0706_447E_AD4A_613CCA0BE720__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// メイン シンボル

/////////////////////////////////////////////////////////////////////////////
// CQrDecodeVCSample1App:
// このクラスの動作の定義に関しては QrDecodeVCSample1.cpp ファイルを参照してください。
//

class CQrDecodeVCSample1App : public CWinApp
{
public:
	CQrDecodeVCSample1App();

// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(CQrDecodeVCSample1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// インプリメンテーション

	//{{AFX_MSG(CQrDecodeVCSample1App)
		// メモ - ClassWizard はこの位置にメンバ関数を追加または削除します。
		//        この位置に生成されるコードを編集しないでください。
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_QRDECODEVCSAMPLE1_H__37194905_0706_447E_AD4A_613CCA0BE720__INCLUDED_)
