#ifndef _MD_BC_DECODE_H
#define _MD_BC_DECODE_H
#include "MdFOcrDef.h"
//
#if 1
#ifdef MD_BC_DECODE_EXPORTS
 #define _PORT_MD_BC_DECODE __declspec(dllexport)	//DLL作成時
#else
 #define _PORT_MD_BC_DECODE __declspec(dllimport)	//DLL使用時
#endif
#else // エクスポートしない
 #define _PORT_MD_BC_DECODE
#endif
//
#ifdef __cplusplus
extern "C" {
#endif


typedef enum tagBCOPTION    // オプション
{
    BC_OPTION_VDPI,         // 仮想解像度
    BC_OPTION_XDPI,         // 画像解像度Ｘ
    BC_OPTION_YDPI,         // 画像解像度Ｙ
    BC_OPTION_CHARPOS,      // ﾃﾞｰﾀ文字列印刷位置
    BC_OPTION_UNIT,         // 単位
    BC_OPTION_DIRECTION,    // 読取方向
    BC_OPTION_BARTYPE,      // 種別
    BC_OPTION_LENGTH,       // 桁数
    BC_OPTION_JANPREFIX,    // ﾌﾟﾘﾌｨｯｸｽｷｬﾗｸﾀ1桁目(JAN13のみ)
    BC_OPTION_CHECK_JAN,    // JANﾁｪｯｸ式
    BC_OPTION_CHECK_ITF,    // ITFﾁｪｯｸ式
    BC_OPTION_CHECK_CODE39, // Code39ﾁｪｯｸ式
    BC_OPTION_CHECK_NW7,    // NW-7ﾁｪｯｸ式
    BC_OPTION_CHECK_CODE128,// Code128ﾁｪｯｸ式
    BC_OPTION_REPLACE_CNTRL,// 制御文字等表示不可文字の置き換え
    BC_OPTION_BINTYPE,      // ２値化種別
    BC_OPTION_NOISE_SIZE,   // ノイズ除去
    BC_OPTION_HOLE_SIZE,    // 穴埋め
    BC_OPTION_LENGTH_MIN_ITF, // ITF最小桁数

    BC_OPTION_TNO,          // オプション数

} BCOPTION;

typedef enum tagBCUNIT  // 単位長
{
    BC_UNIT_PIXEL,  // 1 pixel
    BC_UNIT_MM,     // 0.1mm

} BCUNIT;

typedef enum tagBCDIRECTION // 読取方向
{
    BC_DIRECTION_UNKNOWN    = 0x00,  // 不明
    BC_DIRECTION_RIGHT      = 0x01,  // →
    BC_DIRECTION_LEFT       = 0x02,  // ←
    BC_DIRECTION_UP         = 0x04,  // ↑
    BC_DIRECTION_DOWN       = 0x08,  // ↓
    BC_DIRECTION_ANY        = 0x0F,  // 自動判定
    BC_DIRECTION_HORIZONTAL = (BC_DIRECTION_RIGHT | BC_DIRECTION_LEFT),
    BC_DIRECTION_VERTICAL   = (BC_DIRECTION_UP | BC_DIRECTION_DOWN),
} BCDIRECTION;

typedef enum tagBCBARTYPE   // バーコード種別
{
    BC_BARTYPE_UNKNOWN  = 0x00000000,
    BC_BARTYPE_JAN13    = 0x00000001,   // JAN13
    BC_BARTYPE_JAN8     = 0x00000002,   // JAN8
    BC_BARTYPE_ITF      = 0x00000010,   // ITF
    BC_BARTYPE_ITFB     = 0x00000020,   
    BC_BARTYPE_NW7      = 0x00000100,   // NW-7
    BC_BARTYPE_CODE39   = 0x00000200,   // CODE39
    BC_BARTYPE_CODE128  = 0x00000400,   // CODE128
    BC_BARTYPE_EAN128	= 0x00000800,   
    BC_BARTYPE_CUSTOM	= 0x00001000,   // カスタマバーコード
    BC_BARTYPE_RSS14        = 0x00010000,
    BC_BARTYPE_RSS_LIMITED  = 0x00010001,
    BC_BARTYPE_RSS_EXPANDED = 0x00010002,
    BC_BARTYPE_ANY      = 0xFFFFFFFF,

} BCBARTYPE;

typedef enum tagBCCHECK     // チェック式種別
{
    BC_CHECK_NONE        = 0x00000000,  // なし
    BC_CHECK_MOD10W3     = 0x00000001,  // ﾓｼﾞｭﾗｽ10 ｳｪｲﾄ3
    BC_CHECK_MOD10W2     = 0x00000002,  // ﾓｼﾞｭﾗｽ10 ｳｪｲﾄ2
    BC_CHECK_LUHN        = 0x00000004,  // ルーンズ
    BC_CHECK_MOD11       = 0x00000008,  // ﾓｼﾞｭﾗｽ11
    BC_CHECK_WMOD11      = 0x00000010,  // 加重ﾓｼﾞｭﾗｽ11
    BC_CHECK_MOD16       = 0x00000020,  // ﾓｼﾞｭﾗｽ16
    BC_CHECK_MOD43       = 0x00000040,  // ﾓｼﾞｭﾗｽ43
    BC_CHECK_MOD103      = 0x00000080,  // ﾓｼﾞｭﾗｽ103
    BC_CHECK_7DR         = 0x00000100,  // 7ﾁｪｯｸDR
    BC_CHECK_ANY         = 0xFFFFFFFF,  // 何れか

} BCCHECK;

typedef enum tagBCCHARPOS   // 文字位置
{
    BC_CHARPOS_NONE     = 0x00, // なし
    BC_CHARPOS_FLOOR    = 0x01, // 下部
    BC_CHARPOS_CEIL     = 0x02, // 上部
    BC_CHARPOS_BOTH     = 0x0F, // 上下

} BCCHARPOS;


typedef enum tagBCBINTYPE
{
    BC_BINTYPE_WHOLE = 0,
    BC_BINTYPE_LOCAL,

} BCBINTYPE;


//#define MDRC_BCR_ERR_BASE   ((mdRESULT)(-10000))
//#define MDRC_CHECKDIGIT     (MDRC_BCR_ERR_BASE - 1)

//>>#######################################################################
//  バーコード認識を初期化する
//      戻り値:エラー番号
//              MDRC_OK                     成功
//              MDRC_ERR_LICENSE_PRODUCT    プロテクトチェックエラー
//              MDRC_ERROR                  例外エラー
//<<#######################################################################
_PORT_MD_BC_DECODE mdRESULT MdBcDecode_Initialize(
    OUT mdHANDLE*   outHandle   // バーコード認識ハンドル
    );

//>>#######################################################################
//  バーコード認識の終了処理をする
//      戻り値:エラー番号
//<<#######################################################################
_PORT_MD_BC_DECODE mdRESULT MdBcDecode_Terminate
    (
    IN const mdHANDLE inHandle //バーコード認識ハンドル
    );

//>>#######################################################################
//  指定領域内のバーコードを認識する
//      戻り値:>=0の場合は認識バイト数、<0の場合はエラー番号
//<<#######################################################################
_PORT_MD_BC_DECODE mdINT32 MdBcDecode_DecodeRect
    (
	IN  const mdHANDLE   inHandle,          //バーコード認識ハンドル
	IN  const mdBYTE*    inImage,           //画像の先頭アドレス
    IN  const mdINT32    inImageWidth,      //画像の幅
	IN  const mdINT32    inImageHeight,     //画像の高さ
	IN  const mdINT32    inImageWidthByte,  //画像のバイト幅
	IN  const mdINT32    inLeft,            //処理矩形左端
	IN  const mdINT32    inTop,             //　↑　　上端
	IN  const mdINT32    inWidth,           //　↑　  幅
	IN  const mdINT32    inHeight           //　↑　　高さ
	);

//<<#######################################################################
//  画像内のバーコードを認識する
//      戻り値：>=0 の場合は認識バーコード数、<0 の場合はエラー番号
//<<#######################################################################
_PORT_MD_BC_DECODE mdINT32 MdBcDecode_Decode
    (
	IN  const mdHANDLE   inHandle,          //バーコード認識ハンドル
	IN  const mdBYTE*    inImage,           //画像の先頭アドレス
    IN  const mdINT32    inImageWidth,      //画像の幅
	IN  const mdINT32    inImageHeight,     //画像の高さ
	IN  const mdINT32    inImageWidthByte,  //画像のバイト幅
	IN  const mdINT16    inMaxCount,        //バーコード最大数
	OUT mdINT16*         outLength          //認識バイト数配列
	);

//<<#######################################################################
//  バーコード認識のオプションを設定する
//      戻り値：エラー番号
//<<#######################################################################
_PORT_MD_BC_DECODE mdRESULT MdBcDecode_SetOption
    (
	IN  const mdHANDLE  inHandle,      //バーコード認識ハンドル
    IN  const mdINT16   inOptionType,   // オプション種別
    IN  const mdINT32   inOptionValue   // オプション設定値
    );

//>>#######################################################################
//  認識データを取得する
//      戻り値:エラー番号
//<<#######################################################################
_PORT_MD_BC_DECODE mdRESULT MdBcDecode_GetData
    (
    IN  const mdHANDLE   inHandle,      //バーコード認識ハンドル
    IN  const mdINT16    inIndex,       //バーコードインデックス(１～)
    IN  const mdINT32    inSize,        //データ配列長
    OUT mdBYTE*          outData        //データ配列
    );

//>>#######################################################################
//  モードを取得する
//      戻り値:エラー番号
//      outModeまたはoutLengthがNULLの場合に配列数ioSizeを返す
//      outModeかつoutLengthがNULLでない場合にモード配列と文字数配列に値を返す
//      モードは「1/2/4/8=数字/英数字/8ビットバイト/漢字」
//      文字数はバイト数ではない。数字/英数字/8ビットバイトでは「文字数=バイト数」、漢字では「文字数*2=バイト数」
//<<#######################################################################
_PORT_MD_BC_DECODE mdRESULT MdBcDecode_GetMode
    (
	IN  const mdHANDLE   inHandle,  //バーコード認識ハンドル
	IN  const mdINT16    inIndex,   //バーコードインデックス(１～)
    INOUT     mdINT32*   ioSize,    //配列数
    OUT       mdINT32*   outMode,   //モード配列
    OUT       mdINT32*   outLength  //文字数配列
	);

//>>#######################################################################
//  認識バーコード種別を取得する
//      戻り値:BCBARTYPE を参照
//<<#######################################################################
_PORT_MD_BC_DECODE mdINT32 MdBcDecode_GetVersion
    (
    IN  const mdHANDLE   inHandle,  //バーコード認識ハンドル
	IN  const mdINT16    inIndex    //バーコードインデックス(１～)
    );

//>>#######################################################################
//  認識バーコード領域を取得する
//      戻り値:エラー番号
//<<#######################################################################
_PORT_MD_BC_DECODE mdINT32 MdBcDecode_GetRect
    (
	IN  const   mdHANDLE    inHandle,       //バーコード認識ハンドル
    IN  const   mdINT16     inIndex,        //バーコードインデックス(１～)
	OUT         mdINT32*    outLeft,        //認識矩形左端
	OUT         mdINT32*    outTop,         //　↑　　上端
	OUT         mdINT32*    outWidth,       //　↑　  幅
	OUT         mdINT32*    outHeight       //　↑　　高さ
	);

//>>#######################################################################
//  指定領域内のバーコードを認識する
//      戻り値:>=0の場合は認識バイト数、<0の場合はエラー番号
//<<#######################################################################
_PORT_MD_BC_DECODE mdINT32 MdBcDecode_DecodeRectEx
    (
	IN  const mdHANDLE  hEngine,        // 認識エンジンハンドル
    IN  const mdHANDLE  hImage,         // イメージハンドル
	IN  const mdINT32   inLeft,         // 処理矩形左端
	IN  const mdINT32   inTop,          // 　↑　　上端
	IN  const mdINT32   inWidth,        // 　↑　  幅
	IN  const mdINT32   inHeight        // 　↑　　高
	);

//<<#######################################################################
//  画像内のバーコードを認識する
//      戻り値：>=0 の場合は認識バーコード数、<0 の場合はエラー番号
//<<#######################################################################
_PORT_MD_BC_DECODE mdINT32 MdBcDecode_DecodeEx
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
_PORT_MD_BC_DECODE mdINT32 MdBcDecode_GetType
    (
    IN  const mdHANDLE   inHandle,   //バーコード認識ハンドル
	IN  const mdINT16    inIndex     //バーコードインデックス　←追加（領域抽出対応）
    );


#ifdef __cplusplus
}
#endif
#endif //_MD_BC_DECODE_H
