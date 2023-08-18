//-----------------------------------------------------------------------------
// @(h) MdFOcrDef.h
//
// @(s)
//    Mediadrive FormOcr ���ʐ錾
//
//-----------------------------------------------------------------------------
#ifndef __MdFOcrDefine_DEF
#define __MdFOcrDefine_DEF
#include "MdFOcrDef_.h"

//----------------------------------------------------------------------------
#define IN              // ���͕ϐ��錾
#define OUT             // �o�͕ϐ��錾
#define INOUT           // ���o�͕ϐ��錾

//----------------------------------------------------------------------------
//////// �����^�������^�̍Ē�`
//----------------------------------------------------------------------------
typedef char*               mdSTRING;           // �o�C�g��iNUL�I�[�j
typedef const char*         mdCSTRING;          // �o�C�g��iNUL�I�[�j
typedef unsigned char       mdBYTE;             // 8bit ����(�����Ȃ�)
typedef char                mdCHAR;             // 8bit ����
typedef short               mdINT16;            // 16bit ����
typedef unsigned short      mdUINT16;           // 16bit ����(�����Ȃ�)
typedef long                mdINT32;            // 32bit ����
typedef unsigned long       mdUINT32;           // 32bit ����(�����Ȃ�)
typedef signed   __int64    mdINT64;            // 64(32)bit ����
typedef unsigned __int64    mdUINT64;           // 64(32)bit ����(�����Ȃ�)
typedef long                mdBOOL;             // =0: false, !=0: true
typedef float               mdREAL32;           // IEEE�d�l�̒P���x����
typedef double              mdREAL64;           // IEEE�d�l�̔{���x����
//typedef unsigned __int64    mdHANDLE;           // �n���h��
typedef unsigned long       mdHANDLE;           // �n���h��
typedef unsigned long       mdUSERDATA;         // ���[�U�[�f�[�^

#define mdTRUE      (-1)                        // TRUE (Basic�݊�)
#define mdFALSE     (0)                         // FALSE

//----------------------------------------------------------------------------
// �ȉ����ʃG���[�R�[�h
//----------------------------------------------------------------------------
#include "MdFOcrResultCode.h"       // �ɋL�q

#endif
