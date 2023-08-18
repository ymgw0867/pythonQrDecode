//-----------------------------------------------------------------------------
// @(h) MdFOcrResultCode.h
//
// @(s)
//    Mediadrive FormOcr 共通宣言
//
//-----------------------------------------------------------------------------
#ifndef __MdFOcrResultCode_DEF
#define __MdFOcrResultCode_DEF
#include "MdFOcrDef.h"

//----------------------------------------------------------------------------
// 結果コードの型
//   結果コードは16ビット符号付整数で表される
//   =０:正常終了
//   <０：負数の場合はエラー
//   >０：整数の場合はエラーでない戻り値として情報を返せる
//----------------------------------------------------------------------------
#define mdRESULT            mdINT16                     // エラーコード

//----------------------------------------------------------------------------
// 以下共通エラーコード     
//----------------------------------------------------------------------------
#define MDRC_OK                 ((mdRESULT)0)               // 正常終了
#define MDRC_COMMON_ERR_BASE    ((mdRESULT)(-32000))        // 共通エラーコード基準
#define MDRC_ERROR              (MDRC_COMMON_ERR_BASE - 0)  // エラー
#define MDRC_MEMORY             (MDRC_COMMON_ERR_BASE - 1)  // メモリ不足
#define MDRC_INVALIDHANDLE      (MDRC_COMMON_ERR_BASE - 2)  // 無効ハンドル
#define MDRC_INVALIDPARAM       (MDRC_COMMON_ERR_BASE - 3)  // パラメータエラー
#define MDRC_INVALIDPIC         (MDRC_COMMON_ERR_BASE - 4)  // 無効画像データ
#define MDRC_FILEOPEN           (MDRC_COMMON_ERR_BASE - 5)  // ファイルがオープンできない
#define MDRC_FILEREAD           (MDRC_COMMON_ERR_BASE - 6)  // ファイル読み取りエラー
#define MDRC_FILEWRITE          (MDRC_COMMON_ERR_BASE - 7)  // ファイル書き込みエラー
#define MDRC_BINPIC             (MDRC_COMMON_ERR_BASE - 8)  // ２値画像ではない
#define MDRC_CANNOT_LOAD_DLL    (MDRC_COMMON_ERR_BASE - 9)  // DLLがロードできない
#define MDRC_NOTIMPL            (MDRC_COMMON_ERR_BASE - 10) // APIが提供されていません
#define MDRC_ERR_LICENSE_PRODUCT        (MDRC_COMMON_ERR_BASE - 700) // ライセンスエラー・プロダクト
#define MDRC_ERR_LICENSE_DATE           (MDRC_COMMON_ERR_BASE - 701) // ライセンスエラー・有効期限エラー
#define MDRC_ERR_LICENSE_MACHINE        (MDRC_COMMON_ERR_BASE - 702) // ライセンスエラー・マシンID

#endif
