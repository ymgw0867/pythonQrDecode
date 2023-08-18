#ifndef _MD_QR_DECODE_H
#define _MD_QR_DECODE_H
#include "MdFOcrDef.h"
//
#if 1
#ifdef MD_QR_DECODE_EXPORTS
 #define _PORT_MD_QR_DECODE __declspec(dllexport)	//DLL作成時
#else
 #define _PORT_MD_QR_DECODE __declspec(dllimport)	//DLL使用時
#endif
#else
 #define _PORT_MD_QR_DECODE
#endif
//
#ifdef __cplusplus
extern "C" {
#endif


typedef enum tagQROPTION    // オプション
{
    QR_OPTION_VDPI  = 0,    // 仮想解像度(認識解像度)
    QR_OPTION_XDPI,         // 仮想解像度Ｘ個別
    QR_OPTION_YDPI,         // 仮想解像度Ｙ個別
    QR_OPTION_UNIT,         // 単位長設定
    QR_OPTION_FINDER,       // 位置検出設定(検出レベル)
    QR_OPTION_BINTYPE,      // ２値化種別

    QR_OPTION_TNO,          // オプション数
#if 0
    QR_OPTION_MORE  = 1000, // 追加オプション(仮値)
    QR_OPTION_MAXCOUNT,     // 領域抽出追加枠(ピクセル幅)
    QR_OPTION_EXTRECT,      // QRコード最大数
    QR_OPTION_MORE_TNO,
#endif
} QROPTION;


typedef enum tagQRUNIT      // 単位長
{
    QR_UNIT_PIXEL = 0,      // ピクセル単位（1画素）
    QR_UNIT_MM,             // MM単位（1/10mm）

} QRUNIT;


typedef enum tagQRFINDER    // 検出レベル
{
#if 0   // >> 2009/07/09
    QR_FINDER_NORMAL = 0,   // 標準
    QR_FINDER_EXTLOW,       // 拡大検出・弱
    QR_FINDER_EXTMIDDLE,    // 拡大検出・中
    QR_FINDER_EXTHIGHT,     // 拡大検出・強
#else
    QR_FINDER_EXTHIGH = -3, // 条件緩和・強
    QR_FINDER_EXTMID = -2,  // 条件緩和・中
    QR_FINDER_EXTLOW = -1,  // 条件緩和・弱
    QR_FINDER_NORMAL = 0,   // 標準
    QR_FINDER_MAGLOW = 1,   // 拡大検出・弱
    QR_FINDER_MAGMID = 2,   // 拡大検出・中
    QR_FINDER_MAGHIGH = 3,  // 拡大検出・強
#endif  // << 2009/07/09
} QRFINDER;


typedef enum tagQRBINTYPE
{
    QR_BINTYPE_WHOLE = 0,
    QR_BINTYPE_LOCAL,

} QRBINTYPE;


//>>#######################################################################
//  QRコード認識を初期化する
//      戻り値:エラー番号
//              MDRC_OK                     成功
//              MDRC_ERR_LICENSE_PRODUCT    プロテクトチェックエラー
//              MDRC_ERROR                  例外エラー
//<<#######################################################################
_PORT_MD_QR_DECODE mdRESULT MdQrDecode_Initialize(
    OUT mdHANDLE*   outHandle   // QRコード認識ハンドル
    );

//>>#######################################################################
//  QRコード認識の終了処理をする
//      戻り値:エラー番号
//<<#######################################################################
_PORT_MD_QR_DECODE mdRESULT MdQrDecode_Terminate
    (
    IN const mdHANDLE inHandle //QRコード認識ハンドル
    );

//>>#######################################################################
//  指定領域内のQRコードを認識する
//      戻り値:>=0の場合は認識バイト数、<0の場合はエラー番号
//<<#######################################################################
_PORT_MD_QR_DECODE mdINT32 MdQrDecode_DecodeRect
    (
	IN  const mdHANDLE   inHandle,          //QRコード認識ハンドル
	IN  const mdBYTE*    inImage,           //画像の先頭アドレス
    IN        mdINT32    inImageWidth,      //画像の幅
	IN        mdINT32    inImageHeight,     //画像の高さ
	IN        mdINT32    inImageWidthByte,  //画像のバイト幅
	IN        mdINT32    inLeft,            //処理矩形左端
	IN        mdINT32    inTop,             //　↑　　上端
	IN        mdINT32    inWidth,           //　↑　  幅
	IN        mdINT32    inHeight           //　↑　　高さ
	);

//<<#######################################################################
//  画像内のQRコードを認識する
//      戻り値：>=0 の場合は認識QR コード数、<0 の場合はエラー番号
//<<#######################################################################
_PORT_MD_QR_DECODE mdINT32 MdQrDecode_Decode
    (
	IN  const mdHANDLE   inHandle,          //QRコード認識ハンドル
	IN  const mdBYTE*    inImage,           //画像の先頭アドレス
    IN        mdINT32    inImageWidth,      //画像の幅
	IN        mdINT32    inImageHeight,     //画像の高さ
	IN        mdINT32    inImageWidthByte,  //画像のバイト幅
	IN        mdINT16    inMaxCount,        //QRコード最大数
	OUT       mdINT16*   outLength          //認識バイト数配列
	);

//<<#######################################################################
//  バーコード認識のオプションを設定する
//      戻り値：エラー番号
//<<#######################################################################
_PORT_MD_QR_DECODE mdRESULT MdQrDecode_SetOption
    (
	IN  const mdHANDLE  inHandle,       // QRコード認識ハンドル
    IN        mdINT16   inOptionType,   // オプション種別
    IN        mdINT32   inOptionValue   // オプション設定値
    );

//>>#######################################################################
//  認識データを取得する
//      戻り値:エラー番号
//<<#######################################################################
_PORT_MD_QR_DECODE mdRESULT MdQrDecode_GetData
    (
    IN  const mdHANDLE   inHandle,      //QRコード認識ハンドル
    IN        mdINT16    inIndex,       //QRコードインデックス(１～)
    IN        mdINT32    inSize,        //データ配列長
    OUT       mdBYTE*    outData        //データ配列
    );

//>>#######################################################################
//  モードを取得する
//      戻り値:エラー番号
//      outModeまたはoutLengthがNULLの場合に配列数ioSizeを返す
//      outModeかつoutLengthがNULLでない場合にモード配列と文字数配列に値を返す
//      モードは「1/2/4/8/3=数字/英数字/8ビットバイト/漢字/構造的連接」
//      文字数はバイト数ではない。
//      数字/英数字/8ビットバイトでは「文字数=バイト数」、
//      漢字では「文字数*2=バイト数」
//      構造的連接では不定(意味がない)
//<<#######################################################################
_PORT_MD_QR_DECODE mdRESULT MdQrDecode_GetMode
    (
	IN  const mdHANDLE   inHandle,  //QRコード認識ハンドル
	IN        mdINT16    inIndex,   //QRコードインデックス(１～)
    INOUT     mdINT32*   ioSize,    //配列数
    OUT       mdINT32*   outMode,   //モード配列
    OUT       mdINT32*   outLength  //文字数配列
	);

//>>###################################################################
//  構造的連接を取得する
//      戻り値:エラー番号
//      位置、合計数ともに1オリジンで最大数は16である。
//<<###################################################################
_PORT_MD_QR_DECODE mdRESULT MdQrDecode_GetStruAppe
    (
    IN  const mdHANDLE   inHandle,  //QRコード認識ハンドル
    IN        mdINT16    inIndex,   //QRコードインデックス
    OUT       mdINT32*   outIndex,  //位置
    OUT       mdINT32*   outTotal,  //合計数
    OUT       mdINT32*   outParity  //パリティ
    );

//>>#######################################################################
//  型番を取得する
//      戻り値:>0なら型番、<=0ならエラー
//      型番は1～40
//<<#######################################################################
_PORT_MD_QR_DECODE mdINT32 MdQrDecode_GetVersion
    (
    IN  const mdHANDLE   inHandle,  //QRコード認識ハンドル
	IN        mdINT16    inIndex    //QRコードインデックス(１～)
    );

//>>#######################################################################
//  認識QRコード領域を取得する
//      戻り値:エラー番号
//<<#######################################################################
_PORT_MD_QR_DECODE mdINT32 MdQrDecode_GetRect
    (
	IN  const   mdHANDLE    inHandle,       //QRコード認識ハンドル
    IN          mdINT16     inIndex,        //QRコードインデックス(１～)
	OUT         mdINT32*    outLeft,        //認識矩形左端
	OUT         mdINT32*    outTop,         //　↑　　上端
	OUT         mdINT32*    outWidth,       //　↑　  幅
	OUT         mdINT32*    outHeight       //　↑　　高
	);

//>>#######################################################################
//  訂正レベルを取得する
//      戻り値:>=0なら訂正レベル、<0ならエラー
//      訂正レベルは「0/1/2/3=L/M/Q/H」
//<<#######################################################################
_PORT_MD_QR_DECODE mdINT32 MdQrDecode_GetCorrectLevel
    (
    IN  const mdHANDLE   inHandle,  //QRコード認識ハンドル
	IN        mdINT16    inIndex    //QRコードインデックス(１～)
    );

//>>#######################################################################
//  マスクIDを取得する
//      戻り値:>=0ならマスクID、<0ならエラー
//      マスクIDは0～7
//<<#######################################################################
_PORT_MD_QR_DECODE mdINT32 MdQrDecode_GetMaskID
    (
    IN  const mdHANDLE   inHandle,  //QRコード認識ハンドル
	IN        mdINT16    inIndex    //QRコードインデックス(１～)
    );

//>>#######################################################################
//  指定領域内のQRコードを認識する
//      戻り値:>=0の場合は認識バイト数、<0の場合はエラー番号
//<<#######################################################################
_PORT_MD_QR_DECODE mdINT32 MdQrDecode_DecodeRectEx
    (
	IN  const mdHANDLE  hEngine,        // 認識エンジンハンドル
    IN  const mdHANDLE  hImage,         // イメージハンドル
	IN  const mdINT32   inLeft,         // 処理矩形左端
	IN  const mdINT32   inTop,          // 　↑　　上端
	IN  const mdINT32   inWidth,        // 　↑　  幅
	IN  const mdINT32   inHeight        // 　↑　　高
	);

//<<#######################################################################
//  画像内のQRコードを認識する
//      戻り値：>=0 の場合は認識QR コード数、<0 の場合はエラー番号
//<<#######################################################################
_PORT_MD_QR_DECODE mdINT32 MdQrDecode_DecodeEx // ←関数追加（領域抽出対応）
    (
	IN  const mdHANDLE  hEngine,        // 認識エンジンハンドル
    IN  const mdHANDLE  hImage,         // イメージハンドル
	IN  const mdINT16   inMaxCount,     // バーコード最大数
	OUT mdINT16*        outLength       // 認識バイト数配列
    );

//>>#######################################################################
//  種別を取得する
//      戻り値:>0なら型番、<=0ならエラー
//              MDRC_OK                     成功
//              MDRC_INVALIDHANDLE          無効ハンドル
//              MDRC_INVALIDPARAM           パラメータエラー
//              MDRC_ERROR                  結果取得に失敗
//              MDRC_ERROR                  その他のエラー
//      型番は1～40
//<<#######################################################################
_PORT_MD_QR_DECODE mdINT32 MdQrDecode_GetType
    (
    IN  const mdHANDLE   inHandle,   //QRコード認識ハンドル
	IN        mdINT16    inIndex     //QRコードインデックス　←追加（領域抽出対応）
    );

#ifdef __cplusplus
}
#endif
#endif //_MD_QR_DECODE_H
