//-----------------------------------------------------------------------------
// @(h) MdFOcrDef.h
//
// @(s)
//    Mediadrive FormOcr 共通宣言
//
//-----------------------------------------------------------------------------
#ifndef __MdFOcrDefine_DEF
#define __MdFOcrDefine_DEF
#include "MdFOcrDef_.h"

//----------------------------------------------------------------------------
#define IN              // 入力変数宣言
#define OUT             // 出力変数宣言
#define INOUT           // 入出力変数宣言

//----------------------------------------------------------------------------
//////// 整数型＆実数型の再定義
//----------------------------------------------------------------------------
typedef char*               mdSTRING;           // バイト列（NUL終端）
typedef const char*         mdCSTRING;          // バイト列（NUL終端）
typedef unsigned char       mdBYTE;             // 8bit 整数(符号なし)
typedef char                mdCHAR;             // 8bit 整数
typedef short               mdINT16;            // 16bit 整数
typedef unsigned short      mdUINT16;           // 16bit 整数(符号なし)
typedef long                mdINT32;            // 32bit 整数
typedef unsigned long       mdUINT32;           // 32bit 整数(符号なし)
typedef signed   __int64    mdINT64;            // 64(32)bit 整数
typedef unsigned __int64    mdUINT64;           // 64(32)bit 整数(符号なし)
typedef long                mdBOOL;             // =0: false, !=0: true
typedef float               mdREAL32;           // IEEE仕様の単精度実数
typedef double              mdREAL64;           // IEEE仕様の倍精度実数
//typedef unsigned __int64    mdHANDLE;           // ハンドル
typedef unsigned long       mdHANDLE;           // ハンドル
typedef unsigned long       mdUSERDATA;         // ユーザーデータ

#define mdTRUE      (-1)                        // TRUE (Basic互換)
#define mdFALSE     (0)                         // FALSE

//----------------------------------------------------------------------------
// 以下共通エラーコード
//----------------------------------------------------------------------------
#include "MdFOcrResultCode.h"       // に記述

#endif
