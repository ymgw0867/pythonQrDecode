#ifndef _MD_BC_COMMON_H
#define _MD_BC_COMMON_H
#include "MdFOcrDef.h"
#include "windows.h"

#ifdef __cplusplus
extern "C" {
#endif


mdINT16 mdAPI MdBcCommon_CountPage(	// 取得：画像ファイル内頁数の取得
    IN	const char* inFileName );       // 画像ファイル名

mdINT16 mdAPI MdBcCommon_CountPageEx(   // 取得：画像ファイル内頁数の取得(PDF画像展開チェック付き)
    IN	const char* inFileName );       // 画像ファイル名

mdRESULT mdAPI MdBcCommon_ReadFile(     // ファイルの読み込み
    IN  const char* inFileName,         // ファイル名
    IN  mdINT16     inPage,             // ページ番号(複数頁TIFF時：１～)
    OUT mdHANDLE*   outHandle,          // 画像ハンドル (=NULL:取得しない)
    IN  mdINT16     inDpi = 400 );      // 既定解像度
                                        
mdRESULT mdAPI MdBcCommon_ReleaseImage( // 解放:インスタンス
    IN  mdHANDLE inHandle );            // 画像データインスタンスハンドル

mdRESULT mdAPI MdBcCommon_GetImageSize( // 画像サイズを取得
    IN  mdHANDLE    inHandle,           // 画像ハンドル
    OUT mdINT32*    outImageWidth,      // 画像横ドット数(=NULL:取得しない)
    OUT mdINT32*    outImageHeight,     // 画像縦ドット数(=NULL:取得しない)
    OUT mdINT32*    outImageWidthByte,  // 画像横バイト数(=NULL:取得しない)
    OUT mdINT16*    outImageDepth );    // 画像ビット数(=NULL:取得しない)

mdRESULT mdAPI MdBcCommon_GetImageDPI(  // 画像解像度を取得
    IN  mdHANDLE    inHandle,
    OUT mdINT16*    outDpiX,            // 横解像度(=NULL:取得しない)
    OUT mdINT16*    outDpiY );          // 縦解像度(=NULL:取得しない)

mdRESULT mdAPI MdBcCommon_GetImage(     // 画像配列を取得
    IN  mdHANDLE    inHandle,           // 画像ハンドル
    OUT mdBYTE*     outImage );         // 画像配列


mdRESULT mdAPI MdBcCommon_LoadImage(    // ファイルの読み込み
    IN  const char* inFileName,         // ファイル名
    IN  mdINT16     inPage,             // ページ番号(複数頁TIFF時：１～)
    OUT mdHANDLE*   outHandle,          // 画像ハンドル (=NULL:取得しない)
	IN  mdINT16     inDefaultDpi
	);

mdRESULT mdAPI MdBcCommon_ConvertDIBToImageHandle( // メモリ読み込み(DIB)
    IN  BITMAPINFO  *bih,               // BITMAPINFOヘッダ
    IN  unsigned char *image,           // 画像データ
    OUT mdHANDLE*   outHandle           // 画像ハンドル (=NULL:取得しない)
	);

#ifdef __cplusplus
}
#endif
#endif