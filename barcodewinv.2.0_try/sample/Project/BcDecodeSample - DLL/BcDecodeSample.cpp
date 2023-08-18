// BcDecodeSample.cpp : コンソール アプリケーション用のエントリ ポイントの定義
//

#include "stdafx.h"

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

#include "../../../include/MdBcCommon.h"
#include "../../../include/MdBcDecode.h"
#include "../../../include/MdQrDecode.h"
#pragma comment(lib,"../../../lib/MdBcCommon.lib")
#pragma comment(lib,"../../../lib/MdBcDecode.lib")
#pragma comment(lib,"../../../lib/MdQrDecode.lib")

#include "windows.h"

#define DECODE_RECT 0   // 0 - DecodeEx     画像内複数コードの読み取り
                        // 1 - DecodeRectEx 指定領域内単一コードの読み取り

#define MORE_INFO   0   // 読取結果(コード)以外の情報を取得・表示

#define L1_TEST 0       // Init外ループテスト
#define L2_TEST 0       // Init内ループテスト


#if (L1_TEST | L2_TEST)
//------------------------------------------------------------
HWND GetConsoleHwnd(void)
{
    #define MY_BUFSIZE 1024 // コンソール ウィンドウのタイトル用のバッファサイズ
    HWND hwndFound;         // 呼び出し側へ返される値
    char pszNewWindowTitle[MY_BUFSIZE];
                           // 作成されるウィンドウのタイトルが入ります
    char pszOldWindowTitle[MY_BUFSIZE]; // 元のウィンドウタイトルが入ります

    // 現在のウィンドウタイトルを取得します

    GetConsoleTitle(pszOldWindowTitle, MY_BUFSIZE);

    // 独自に、ウィンドウの新規タイトルをフォーマットします

    wsprintf(pszNewWindowTitle,"%d/%d",
             GetTickCount(),
             GetCurrentProcessId());

    // 現在のウィンドウタイトルを変更します

    SetConsoleTitle(pszNewWindowTitle);

    // ウィンドウタイトルのアップデートを確実なものにさせます

    Sleep(40);

    // ウィンドウの新規タイトルを探しにいきます

    hwndFound=FindWindow(NULL, pszNewWindowTitle);

    // 元のウィンドウタイトルへ戻します

    SetConsoleTitle(pszOldWindowTitle);

    return(hwndFound);
}
#endif

//------------------------------------------------------------
mdINT32 DecodeBC( mdHANDLE hEngine, mdHANDLE hImage )
{
	// 画像解像度の取得
    mdINT16 dpiX, dpiY;
	MdBcCommon_GetImageDPI( hImage, &dpiX, &dpiY );
    if( dpiX > 0 && dpiY > 0 )
    {
        // 認識解像度の設定
	    MdBcDecode_SetOption( hEngine, BC_OPTION_XDPI, dpiX );  // 横解像度
        MdBcDecode_SetOption( hEngine, BC_OPTION_YDPI, dpiY );  // 縦解像度
    }
    else
    {
        // 既定解像度の設定
	    MdBcDecode_SetOption( hEngine, BC_OPTION_XDPI, 300 );  // 横解像度
        MdBcDecode_SetOption( hEngine, BC_OPTION_YDPI, 300 );  // 縦解像度
    }

    // 認識処理
    mdINT32 count = 0;  // 読取結果コード数
    mdINT16 max = 100;  // 読取コード数上限
    mdINT16 len[100];   // 読取結果コード長配列

#if DECODE_RECT
	// 画像サイズの取得
    mdINT32 width, height, width_byte;
    mdINT16 depth;
	MdBcCommon_GetImageSize( hImage, &width, &height, &width_byte, &depth );

    // 指定領域内単一コードの読み取り
	len[0] = (mdINT16)MdBcDecode_DecodeRectEx( hEngine, hImage, 0 , 0 , width , height );
    if( len[0] <= 0 )
    {
        // カスタマバーコードは個別指定のみ対応
        MdBcDecode_SetOption( hEngine, BC_OPTION_BARTYPE, BC_BARTYPE_CUSTOM );
        len[0] = (mdINT16)MdBcDecode_DecodeRectEx( hEngine, hImage, 0 , 0 , width , height );
    }
	if( len[0] <= 0 )
    {
        return count;
    }
	count = 1;
#else
    // 画像内複数コードの読み取り
    count = MdBcDecode_DecodeEx( hEngine, hImage, max, len );
    if( count <= 0 )
    {
        return count;
    }
#endif

    // 画像内 検出コードのループ
	for( mdINT16 n = 1; n <= count; n++ )
    {
        // 認識結果の取得	
		char* data = new char[len[n-1]+1];
        memset( data, 0, sizeof(char) * len[n-1]+1 );				
        MdBcDecode_GetData( hEngine, n, len[n-1], (mdBYTE*)data );

        // 結果の表示
        printf( "%s",
                data );     // 認識結果

        delete [] data;

#if MORE_INFO
        // モードの取得
        mdINT32 size = 0;
        MdBcDecode_GetMode( hEngine, n, (mdINT32*)&size, NULL, NULL );            
        mdINT32* mode = new mdINT32[size];
        mdINT32* len2 = new mdINT32[size];
		memset( mode, 0, sizeof(mdINT32) * size );
		memset( len2, 0, sizeof(mdINT32) * size );
		MdBcDecode_GetMode( hEngine, n, &size, mode, len2 );

        // モード配列と文字数配列から総バイト数を計算
        mdINT32 nbyte = 0;
        for( mdINT32 i = 0; i < size; i++ )
        {
            switch( mode[i] )
            {
            case 1: // 数字
            case 2: // 英数字
            case 4: // 8ビットバイト
                nbyte += len2[i];
                break;

            case 8: // 漢字
                nbyte += (len2[i] * 2);
                break;

            default:
                break;
            }
        }

        // 種別の取得
		mdINT32 type = MdBcDecode_GetType( hEngine, n );

        // 読取位置の取得
		mdINT32 px = 0;
		mdINT32 py = 0;
		mdINT32 sx = 0;
		mdINT32 sy = 0;
		MdBcDecode_GetRect( hEngine, n, &px, &py, &sx, &sy );

        // 基本情報の表示
        printf( ", %ld, %ld, %ld, %ld, %ld, %ld",
                nbyte,      // 桁数 = len[n-1]
                type,       // 種別
                px, py,     // 左上座標(X,Y)
                sx, sy );   // 幅・高さ(W,H)

		delete [] mode;
		delete [] len2;
#endif
        printf( "\n" );
	}

    return count;
}


//------------------------------------------------------------
mdINT32 DecodeQR( mdHANDLE hEngine, mdHANDLE hImage )
{
	// 画像解像度の取得
    mdINT16 dpiX, dpiY;
	MdBcCommon_GetImageDPI( hImage, &dpiX, &dpiY );
    if( dpiX > 0 && dpiY > 0 )
    {
        // 認識解像度の設定
	    MdQrDecode_SetOption( hEngine, BC_OPTION_XDPI, dpiX );  // 横解像度
        MdQrDecode_SetOption( hEngine, BC_OPTION_YDPI, dpiY );  // 縦解像度
    }
    else
    {
        // 既定解像度の設定
	    MdQrDecode_SetOption( hEngine, BC_OPTION_XDPI, 400 );  // 横解像度
        MdQrDecode_SetOption( hEngine, BC_OPTION_YDPI, 400 );  // 縦解像度
    }

    // 認識処理
    mdINT32 count = 0;  // 読取結果コード数
    mdINT16 max = 100;   // 読取コード数上限
    mdINT16 len[100];    // 読取結果コード長配列

#if DECODE_RECT
	// 画像サイズの取得
    mdINT32 width, height, width_byte;
    mdINT16 depth;
	MdBcCommon_GetImageSize( hImage, &width, &height, &width_byte, &depth );

    // 指定領域内単一コードの読み取り
	len[0] = (mdINT16)MdQrDecode_DecodeRectEx( hEngine, hImage, 0 , 0 , width , height );
	if( len[0] <= 0 )
    {
        return count;
    }
	count = 1;
#else
    // 画像内複数コードの読み取り
    count = MdQrDecode_DecodeEx( hEngine, hImage, max, len );
    if( count <= 0 )
    {
        return count;
    }
#endif

    // 画像内 検出コードのループ
	for( mdINT16 n = 1; n <= count; n++ )
    {
        // 認識結果の取得	
		char* data = new char[len[n-1]+1];
        memset( data, 0, sizeof(char) * len[n-1]+1 );				
        MdQrDecode_GetData( hEngine, n, len[n-1], (mdBYTE*)data );

        // 結果の表示
        printf( "%s",
                data );     // 認識結果

        delete [] data;

#if MORE_INFO
        // モードの取得
        mdINT32 size = 0;
        MdQrDecode_GetMode( hEngine, n, &size, NULL, NULL );
        mdINT32* mode = new mdINT32[size];
        mdINT32* len2 = new mdINT32[size];

		memset( mode, 0, sizeof(mdINT32) * size );
		memset( len2, 0, sizeof(mdINT32) * size );
        MdQrDecode_GetMode( hEngine, n, &size, mode, len2 );

        // モード配列と文字数配列から総バイト数を計算
        mdINT32 nbyte = 0;
        for( mdINT32 i = 0; i < size; i++ )
        {
            switch( mode[i] )
            {
            case 1: // 数字
            case 2: // 英数字
            case 4: // 8ビットバイト
                nbyte += len2[i];
                break;

            case 8: // 漢字
                nbyte += (len2[i] * 2);
                break;

            default:
                break;
            }
        }

        // 種別の取得
		mdINT32 type = MdQrDecode_GetType( hEngine, n );

        // 読取位置の取得
		mdINT32 px = 0;
		mdINT32 py = 0;
		mdINT32 sx = 0;
		mdINT32 sy = 0;
		MdQrDecode_GetRect( hEngine, n, &px, &py, &sx, &sy );

        // 基本情報の表示
        printf( ", %ld, %ld, %ld, %ld, %ld, %ld",
                nbyte,      // 文字列長(バイト数) = len[n-1]
                type,       // 種別
                px, py,     // 左上座標(X,Y)
                sx, sy );   // 幅・高さ(W,H)

		delete [] mode;
		delete [] len2;
#endif

#if MORE_INFO
        // ＱＲ型番(1～40)の取得
        mdINT32 version = MdQrDecode_GetVersion( hEngine, n );

        // 構造的連接情報の取得（QRコードのみ）
        mdINT32 index = 0;
        mdINT32 total = 0;
        mdINT32 parity = 0;
        MdQrDecode_GetStruAppe( hEngine, n, &index, &total, &parity );

        // 誤り訂正レベルの取得（QRコードのみ）
        mdINT32 level = MdQrDecode_GetCorrectLevel( hEngine, n );

        // マスクＩＤの取得（QRコードのみ）
        mdINT32 mask = MdQrDecode_GetMaskID( hEngine, n );

        // ＱＲ固有情報の表示
        printf( ", %ld, %ld, %ld, %ld, %ld, %ld",
            version,    // ＱＲ型番
            index,      // 構造的連接 位置番号
            total,      // 構造的連接 合計数
            parity,     // 構造的連接 パリティ
            level,      // 誤り訂正レベル
            mask );     // マスクＩＤ
#endif    
        printf( "\n" );
    }

    return count;
}

//------------------------------------------------------------
int main( int argc, char* argv[] )
{
	if( argc < 2 )
	{
		fprintf( stderr, "引数にファイル名を指定してください\n" );
		return -1;
	}

#if (L1_TEST | L2_TEST)
    unsigned long loop = 0;
    HWND hWnd = GetConsoleHwnd();
    char title[1024];

    DWORD dwTimeSum = 0;
    DWORD dwTimeMax = 0;
    DWORD dwTimeMin = ULONG_MAX;
    SYSTEMTIME st_start;
    GetLocalTime(&st_start);
    unsigned long countSum = 0;
    SYSTEMTIME st_now;
#endif

#if L1_TEST
    while( 1 ) // Init外ループ
    {
        loop++;
#endif


	// 認識エンジンの初期化
    mdHANDLE hBC = NULL;
    mdHANDLE hQR = NULL;
	mdINT16 retBC = MdBcDecode_Initialize( &hBC );
    mdINT16 retQR = MdQrDecode_Initialize( &hQR );
    if( retBC < 0 && retQR < 0 )
    {
        fprintf( stderr, "MdBcDecode_Initialize...戻り値：%d\n", retBC );
        fprintf( stderr, "MdQrDecode_Initialize...戻り値：%d\n", retQR );
        return -1;
    }

#if 1
	// オプション設定（このサンプルの設定値は全て初期値なので省略可）
	MdBcDecode_SetOption( hBC, BC_OPTION_UNIT, BC_UNIT_PIXEL );         // 単位長
	MdBcDecode_SetOption( hBC, BC_OPTION_DIRECTION, BC_DIRECTION_ANY ); // 読取方向
	MdBcDecode_SetOption( hBC, BC_OPTION_BARTYPE, BC_BARTYPE_ANY);      // 読取種別
	MdBcDecode_SetOption( hBC, BC_OPTION_LENGTH, 0 );                   // 読取桁数
	//MdBcDecode_SetOption( hBC, BC_OPTION_CHECK_NW7, BC_CHECK_MOD16 );   // チェック式

    MdQrDecode_SetOption( hQR, QR_OPTION_UNIT, QR_UNIT_PIXEL );         // 単位長
    MdQrDecode_SetOption( hQR, QR_OPTION_FINDER, QR_FINDER_NORMAL );    // 検出レベル
#endif

#if L2_TEST
    while( 1 ) // Init内ループ
    {
        loop++;
#endif

	// ファイル内 画像数(頁数)の取得
	mdINT16 page = MdBcCommon_CountPage( argv[1] );

    // ファイル内 画像ループ
	for( mdINT16 p = 1; p <= page; p++ )
	{
		// 画像の読み込み
        mdHANDLE hImage = NULL;
        mdINT16 ret = MdBcCommon_LoadImage( argv[1], p, &hImage, 400 );
        if( ret != MDRC_OK )
        {
            continue;
        }

#if (L1_TEST | L2_TEST)
        LARGE_INTEGER nFreq, nBefore, nAfter;
        DWORD dwTime = 0;
        memset(&nFreq,   0x00, sizeof nFreq);
        memset(&nBefore, 0x00, sizeof nBefore);
        memset(&nAfter,  0x00, sizeof nAfter);
        QueryPerformanceFrequency(&nFreq);
        QueryPerformanceCounter(&nBefore);
#endif

        mdINT32 cntBC1 = 0;
        mdINT32 cntBC2 = 0;
        mdINT32 cntQR = 0;
        if( hBC != NULL )
        {
            // 一次元バーコードの認識
            MdBcDecode_SetOption( hBC, BC_OPTION_BARTYPE, BC_BARTYPE_ANY );
            cntBC1 = DecodeBC( hBC, hImage );
        
            // カスタマバーコードは個別指定のみ対応
            MdBcDecode_SetOption( hBC, BC_OPTION_BARTYPE, BC_BARTYPE_CUSTOM );
            cntBC2 = DecodeBC( hBC, hImage );
        }
        if( hQR != NULL )
        {
            // ＱＲコードの認識
            cntQR = DecodeQR( hQR, hImage );
        }
        if( cntBC1 <= 0 && cntBC2 <= 0 && cntQR <= 0 )
        {
            printf( "\n" );
        }

#if (L1_TEST | L2_TEST)
        QueryPerformanceCounter(&nAfter);
        dwTime = (DWORD)((nAfter.QuadPart - nBefore.QuadPart) * 1000 / nFreq.QuadPart);
        dwTimeSum += dwTime;
        if( dwTime > dwTimeMax ) dwTimeMax = dwTime;
        if( dwTime < dwTimeMin ) dwTimeMin = dwTime;

        if( hWnd != NULL )
        {
            GetLocalTime(&st_now);
            FILETIME	 ft_start;
            FILETIME	 ft_now;
            SystemTimeToFileTime( &st_start, &ft_start );
            SystemTimeToFileTime( &st_now, &ft_now );

            // int64にキャスト
            __int64	*	nTime1 = (__int64*)&ft_start;	
            __int64	*	nTime2 = (__int64*)&ft_now;	

            // 経過秒
            __int64	 nDiffSec = (*nTime2 - *nTime1) / 10000 / 1000;
            __int64	 nDiffHour = nDiffSec / (60*60);
            __int64	 nDiffMinute = nDiffSec / 60;
            __int64	 nDiffSecond = nDiffSec % 60;

            countSum++;
            sprintf_s( title, sizeof(title),
                "%02d:%02d:%02d from %02d:%02d:%02d, x%d, min:%d max:%d avr:%d[ms]",
                (int)nDiffHour, (int)nDiffMinute, (int)nDiffSecond,
                st_start.wHour, st_start.wMinute, st_start.wSecond,
                loop,
                dwTimeMin, dwTimeMax, dwTimeSum / ((page*(loop-1))+p) );
            SetWindowText( hWnd, title );
        }
#endif

		// 画像の解放
        if( hImage != NULL )
        {
            MdBcCommon_ReleaseImage( hImage );
            hImage = NULL;
        }
	}

#if L2_TEST
    } // Init内ループ
#endif

	// 認識エンジンの終了
    if( hBC != NULL )
    {
	    MdBcDecode_Terminate( hBC );	
        hBC = NULL;
    }
    if( hQR != NULL )
    {
        MdQrDecode_Terminate( hQR );
        hQR = NULL;
    }

#if L1_TEST
    } // Init外ループ
#endif

	return 0;
}
