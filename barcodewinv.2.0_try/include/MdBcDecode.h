#ifndef _MD_BC_DECODE_H
#define _MD_BC_DECODE_H
#include "MdFOcrDef.h"
//
#if 1
#ifdef MD_BC_DECODE_EXPORTS
 #define _PORT_MD_BC_DECODE __declspec(dllexport)	//DLL�쐬��
#else
 #define _PORT_MD_BC_DECODE __declspec(dllimport)	//DLL�g�p��
#endif
#else // �G�N�X�|�[�g���Ȃ�
 #define _PORT_MD_BC_DECODE
#endif
//
#ifdef __cplusplus
extern "C" {
#endif


typedef enum tagBCOPTION    // �I�v�V����
{
    BC_OPTION_VDPI,         // ���z�𑜓x
    BC_OPTION_XDPI,         // �摜�𑜓x�w
    BC_OPTION_YDPI,         // �摜�𑜓x�x
    BC_OPTION_CHARPOS,      // �ް����������ʒu
    BC_OPTION_UNIT,         // �P��
    BC_OPTION_DIRECTION,    // �ǎ����
    BC_OPTION_BARTYPE,      // ���
    BC_OPTION_LENGTH,       // ����
    BC_OPTION_JANPREFIX,    // ���̨�����׸�1����(JAN13�̂�)
    BC_OPTION_CHECK_JAN,    // JAN������
    BC_OPTION_CHECK_ITF,    // ITF������
    BC_OPTION_CHECK_CODE39, // Code39������
    BC_OPTION_CHECK_NW7,    // NW-7������
    BC_OPTION_CHECK_CODE128,// Code128������
    BC_OPTION_REPLACE_CNTRL,// ���䕶�����\���s�����̒u������
    BC_OPTION_BINTYPE,      // �Q�l�����
    BC_OPTION_NOISE_SIZE,   // �m�C�Y����
    BC_OPTION_HOLE_SIZE,    // ������
    BC_OPTION_LENGTH_MIN_ITF, // ITF�ŏ�����

    BC_OPTION_TNO,          // �I�v�V������

} BCOPTION;

typedef enum tagBCUNIT  // �P�ʒ�
{
    BC_UNIT_PIXEL,  // 1 pixel
    BC_UNIT_MM,     // 0.1mm

} BCUNIT;

typedef enum tagBCDIRECTION // �ǎ����
{
    BC_DIRECTION_UNKNOWN    = 0x00,  // �s��
    BC_DIRECTION_RIGHT      = 0x01,  // ��
    BC_DIRECTION_LEFT       = 0x02,  // ��
    BC_DIRECTION_UP         = 0x04,  // ��
    BC_DIRECTION_DOWN       = 0x08,  // ��
    BC_DIRECTION_ANY        = 0x0F,  // ��������
    BC_DIRECTION_HORIZONTAL = (BC_DIRECTION_RIGHT | BC_DIRECTION_LEFT),
    BC_DIRECTION_VERTICAL   = (BC_DIRECTION_UP | BC_DIRECTION_DOWN),
} BCDIRECTION;

typedef enum tagBCBARTYPE   // �o�[�R�[�h���
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
    BC_BARTYPE_CUSTOM	= 0x00001000,   // �J�X�^�}�o�[�R�[�h
    BC_BARTYPE_RSS14        = 0x00010000,
    BC_BARTYPE_RSS_LIMITED  = 0x00010001,
    BC_BARTYPE_RSS_EXPANDED = 0x00010002,
    BC_BARTYPE_ANY      = 0xFFFFFFFF,

} BCBARTYPE;

typedef enum tagBCCHECK     // �`�F�b�N�����
{
    BC_CHECK_NONE        = 0x00000000,  // �Ȃ�
    BC_CHECK_MOD10W3     = 0x00000001,  // Ӽޭ׽10 ����3
    BC_CHECK_MOD10W2     = 0x00000002,  // Ӽޭ׽10 ����2
    BC_CHECK_LUHN        = 0x00000004,  // ���[���Y
    BC_CHECK_MOD11       = 0x00000008,  // Ӽޭ׽11
    BC_CHECK_WMOD11      = 0x00000010,  // ���dӼޭ׽11
    BC_CHECK_MOD16       = 0x00000020,  // Ӽޭ׽16
    BC_CHECK_MOD43       = 0x00000040,  // Ӽޭ׽43
    BC_CHECK_MOD103      = 0x00000080,  // Ӽޭ׽103
    BC_CHECK_7DR         = 0x00000100,  // 7����DR
    BC_CHECK_ANY         = 0xFFFFFFFF,  // ���ꂩ

} BCCHECK;

typedef enum tagBCCHARPOS   // �����ʒu
{
    BC_CHARPOS_NONE     = 0x00, // �Ȃ�
    BC_CHARPOS_FLOOR    = 0x01, // ����
    BC_CHARPOS_CEIL     = 0x02, // �㕔
    BC_CHARPOS_BOTH     = 0x0F, // �㉺

} BCCHARPOS;


typedef enum tagBCBINTYPE
{
    BC_BINTYPE_WHOLE = 0,
    BC_BINTYPE_LOCAL,

} BCBINTYPE;


//#define MDRC_BCR_ERR_BASE   ((mdRESULT)(-10000))
//#define MDRC_CHECKDIGIT     (MDRC_BCR_ERR_BASE - 1)

//>>#######################################################################
//  �o�[�R�[�h�F��������������
//      �߂�l:�G���[�ԍ�
//              MDRC_OK                     ����
//              MDRC_ERR_LICENSE_PRODUCT    �v���e�N�g�`�F�b�N�G���[
//              MDRC_ERROR                  ��O�G���[
//<<#######################################################################
_PORT_MD_BC_DECODE mdRESULT MdBcDecode_Initialize(
    OUT mdHANDLE*   outHandle   // �o�[�R�[�h�F���n���h��
    );

//>>#######################################################################
//  �o�[�R�[�h�F���̏I������������
//      �߂�l:�G���[�ԍ�
//<<#######################################################################
_PORT_MD_BC_DECODE mdRESULT MdBcDecode_Terminate
    (
    IN const mdHANDLE inHandle //�o�[�R�[�h�F���n���h��
    );

//>>#######################################################################
//  �w��̈���̃o�[�R�[�h��F������
//      �߂�l:>=0�̏ꍇ�͔F���o�C�g���A<0�̏ꍇ�̓G���[�ԍ�
//<<#######################################################################
_PORT_MD_BC_DECODE mdINT32 MdBcDecode_DecodeRect
    (
	IN  const mdHANDLE   inHandle,          //�o�[�R�[�h�F���n���h��
	IN  const mdBYTE*    inImage,           //�摜�̐擪�A�h���X
    IN  const mdINT32    inImageWidth,      //�摜�̕�
	IN  const mdINT32    inImageHeight,     //�摜�̍���
	IN  const mdINT32    inImageWidthByte,  //�摜�̃o�C�g��
	IN  const mdINT32    inLeft,            //������`���[
	IN  const mdINT32    inTop,             //�@���@�@��[
	IN  const mdINT32    inWidth,           //�@���@  ��
	IN  const mdINT32    inHeight           //�@���@�@����
	);

//<<#######################################################################
//  �摜���̃o�[�R�[�h��F������
//      �߂�l�F>=0 �̏ꍇ�͔F���o�[�R�[�h���A<0 �̏ꍇ�̓G���[�ԍ�
//<<#######################################################################
_PORT_MD_BC_DECODE mdINT32 MdBcDecode_Decode
    (
	IN  const mdHANDLE   inHandle,          //�o�[�R�[�h�F���n���h��
	IN  const mdBYTE*    inImage,           //�摜�̐擪�A�h���X
    IN  const mdINT32    inImageWidth,      //�摜�̕�
	IN  const mdINT32    inImageHeight,     //�摜�̍���
	IN  const mdINT32    inImageWidthByte,  //�摜�̃o�C�g��
	IN  const mdINT16    inMaxCount,        //�o�[�R�[�h�ő吔
	OUT mdINT16*         outLength          //�F���o�C�g���z��
	);

//<<#######################################################################
//  �o�[�R�[�h�F���̃I�v�V������ݒ肷��
//      �߂�l�F�G���[�ԍ�
//<<#######################################################################
_PORT_MD_BC_DECODE mdRESULT MdBcDecode_SetOption
    (
	IN  const mdHANDLE  inHandle,      //�o�[�R�[�h�F���n���h��
    IN  const mdINT16   inOptionType,   // �I�v�V�������
    IN  const mdINT32   inOptionValue   // �I�v�V�����ݒ�l
    );

//>>#######################################################################
//  �F���f�[�^���擾����
//      �߂�l:�G���[�ԍ�
//<<#######################################################################
_PORT_MD_BC_DECODE mdRESULT MdBcDecode_GetData
    (
    IN  const mdHANDLE   inHandle,      //�o�[�R�[�h�F���n���h��
    IN  const mdINT16    inIndex,       //�o�[�R�[�h�C���f�b�N�X(�P�`)
    IN  const mdINT32    inSize,        //�f�[�^�z��
    OUT mdBYTE*          outData        //�f�[�^�z��
    );

//>>#######################################################################
//  ���[�h���擾����
//      �߂�l:�G���[�ԍ�
//      outMode�܂���outLength��NULL�̏ꍇ�ɔz��ioSize��Ԃ�
//      outMode����outLength��NULL�łȂ��ꍇ�Ƀ��[�h�z��ƕ������z��ɒl��Ԃ�
//      ���[�h�́u1/2/4/8=����/�p����/8�r�b�g�o�C�g/�����v
//      �������̓o�C�g���ł͂Ȃ��B����/�p����/8�r�b�g�o�C�g�ł́u������=�o�C�g���v�A�����ł́u������*2=�o�C�g���v
//<<#######################################################################
_PORT_MD_BC_DECODE mdRESULT MdBcDecode_GetMode
    (
	IN  const mdHANDLE   inHandle,  //�o�[�R�[�h�F���n���h��
	IN  const mdINT16    inIndex,   //�o�[�R�[�h�C���f�b�N�X(�P�`)
    INOUT     mdINT32*   ioSize,    //�z��
    OUT       mdINT32*   outMode,   //���[�h�z��
    OUT       mdINT32*   outLength  //�������z��
	);

//>>#######################################################################
//  �F���o�[�R�[�h��ʂ��擾����
//      �߂�l:BCBARTYPE ���Q��
//<<#######################################################################
_PORT_MD_BC_DECODE mdINT32 MdBcDecode_GetVersion
    (
    IN  const mdHANDLE   inHandle,  //�o�[�R�[�h�F���n���h��
	IN  const mdINT16    inIndex    //�o�[�R�[�h�C���f�b�N�X(�P�`)
    );

//>>#######################################################################
//  �F���o�[�R�[�h�̈���擾����
//      �߂�l:�G���[�ԍ�
//<<#######################################################################
_PORT_MD_BC_DECODE mdINT32 MdBcDecode_GetRect
    (
	IN  const   mdHANDLE    inHandle,       //�o�[�R�[�h�F���n���h��
    IN  const   mdINT16     inIndex,        //�o�[�R�[�h�C���f�b�N�X(�P�`)
	OUT         mdINT32*    outLeft,        //�F����`���[
	OUT         mdINT32*    outTop,         //�@���@�@��[
	OUT         mdINT32*    outWidth,       //�@���@  ��
	OUT         mdINT32*    outHeight       //�@���@�@����
	);

//>>#######################################################################
//  �w��̈���̃o�[�R�[�h��F������
//      �߂�l:>=0�̏ꍇ�͔F���o�C�g���A<0�̏ꍇ�̓G���[�ԍ�
//<<#######################################################################
_PORT_MD_BC_DECODE mdINT32 MdBcDecode_DecodeRectEx
    (
	IN  const mdHANDLE  hEngine,        // �F���G���W���n���h��
    IN  const mdHANDLE  hImage,         // �C���[�W�n���h��
	IN  const mdINT32   inLeft,         // ������`���[
	IN  const mdINT32   inTop,          // �@���@�@��[
	IN  const mdINT32   inWidth,        // �@���@  ��
	IN  const mdINT32   inHeight        // �@���@�@��
	);

//<<#######################################################################
//  �摜���̃o�[�R�[�h��F������
//      �߂�l�F>=0 �̏ꍇ�͔F���o�[�R�[�h���A<0 �̏ꍇ�̓G���[�ԍ�
//<<#######################################################################
_PORT_MD_BC_DECODE mdINT32 MdBcDecode_DecodeEx
    (
	IN  const mdHANDLE  hEngine,        // �F���G���W���n���h��
    IN  const mdHANDLE  hImage,         // �C���[�W�n���h��
	IN  const mdINT16   inMaxCount,     // �o�[�R�[�h�ő吔
	OUT mdINT16*        outLength       // �F���o�C�g���z��
	);

//>>#######################################################################
//  ��ʂ��擾����
//      �߂�l:>0�Ȃ�^�ԁA<=0�Ȃ�G���[
//              MDRC_OK                     ����
//              MDRC_INVALIDHANDLE          �����n���h��
//              MDRC_INVALIDPARAM           �p�����[�^�G���[
//              MDRC_ERROR                  ���ʎ擾�Ɏ��s
//              MDRC_ERROR                  ���̑��̃G���[
//      �^�Ԃ�1�`40
//<<#######################################################################
_PORT_MD_BC_DECODE mdINT32 MdBcDecode_GetType
    (
    IN  const mdHANDLE   inHandle,   //�o�[�R�[�h�F���n���h��
	IN  const mdINT16    inIndex     //�o�[�R�[�h�C���f�b�N�X�@���ǉ��i�̈撊�o�Ή��j
    );


#ifdef __cplusplus
}
#endif
#endif //_MD_BC_DECODE_H
