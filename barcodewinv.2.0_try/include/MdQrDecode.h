#ifndef _MD_QR_DECODE_H
#define _MD_QR_DECODE_H
#include "MdFOcrDef.h"
//
#if 1
#ifdef MD_QR_DECODE_EXPORTS
 #define _PORT_MD_QR_DECODE __declspec(dllexport)	//DLL�쐬��
#else
 #define _PORT_MD_QR_DECODE __declspec(dllimport)	//DLL�g�p��
#endif
#else
 #define _PORT_MD_QR_DECODE
#endif
//
#ifdef __cplusplus
extern "C" {
#endif


typedef enum tagQROPTION    // �I�v�V����
{
    QR_OPTION_VDPI  = 0,    // ���z�𑜓x(�F���𑜓x)
    QR_OPTION_XDPI,         // ���z�𑜓x�w��
    QR_OPTION_YDPI,         // ���z�𑜓x�x��
    QR_OPTION_UNIT,         // �P�ʒ��ݒ�
    QR_OPTION_FINDER,       // �ʒu���o�ݒ�(���o���x��)
    QR_OPTION_BINTYPE,      // �Q�l�����

    QR_OPTION_TNO,          // �I�v�V������
#if 0
    QR_OPTION_MORE  = 1000, // �ǉ��I�v�V����(���l)
    QR_OPTION_MAXCOUNT,     // �̈撊�o�ǉ��g(�s�N�Z����)
    QR_OPTION_EXTRECT,      // QR�R�[�h�ő吔
    QR_OPTION_MORE_TNO,
#endif
} QROPTION;


typedef enum tagQRUNIT      // �P�ʒ�
{
    QR_UNIT_PIXEL = 0,      // �s�N�Z���P�ʁi1��f�j
    QR_UNIT_MM,             // MM�P�ʁi1/10mm�j

} QRUNIT;


typedef enum tagQRFINDER    // ���o���x��
{
#if 0   // >> 2009/07/09
    QR_FINDER_NORMAL = 0,   // �W��
    QR_FINDER_EXTLOW,       // �g�匟�o�E��
    QR_FINDER_EXTMIDDLE,    // �g�匟�o�E��
    QR_FINDER_EXTHIGHT,     // �g�匟�o�E��
#else
    QR_FINDER_EXTHIGH = -3, // �����ɘa�E��
    QR_FINDER_EXTMID = -2,  // �����ɘa�E��
    QR_FINDER_EXTLOW = -1,  // �����ɘa�E��
    QR_FINDER_NORMAL = 0,   // �W��
    QR_FINDER_MAGLOW = 1,   // �g�匟�o�E��
    QR_FINDER_MAGMID = 2,   // �g�匟�o�E��
    QR_FINDER_MAGHIGH = 3,  // �g�匟�o�E��
#endif  // << 2009/07/09
} QRFINDER;


typedef enum tagQRBINTYPE
{
    QR_BINTYPE_WHOLE = 0,
    QR_BINTYPE_LOCAL,

} QRBINTYPE;


//>>#######################################################################
//  QR�R�[�h�F��������������
//      �߂�l:�G���[�ԍ�
//              MDRC_OK                     ����
//              MDRC_ERR_LICENSE_PRODUCT    �v���e�N�g�`�F�b�N�G���[
//              MDRC_ERROR                  ��O�G���[
//<<#######################################################################
_PORT_MD_QR_DECODE mdRESULT MdQrDecode_Initialize(
    OUT mdHANDLE*   outHandle   // QR�R�[�h�F���n���h��
    );

//>>#######################################################################
//  QR�R�[�h�F���̏I������������
//      �߂�l:�G���[�ԍ�
//<<#######################################################################
_PORT_MD_QR_DECODE mdRESULT MdQrDecode_Terminate
    (
    IN const mdHANDLE inHandle //QR�R�[�h�F���n���h��
    );

//>>#######################################################################
//  �w��̈����QR�R�[�h��F������
//      �߂�l:>=0�̏ꍇ�͔F���o�C�g���A<0�̏ꍇ�̓G���[�ԍ�
//<<#######################################################################
_PORT_MD_QR_DECODE mdINT32 MdQrDecode_DecodeRect
    (
	IN  const mdHANDLE   inHandle,          //QR�R�[�h�F���n���h��
	IN  const mdBYTE*    inImage,           //�摜�̐擪�A�h���X
    IN        mdINT32    inImageWidth,      //�摜�̕�
	IN        mdINT32    inImageHeight,     //�摜�̍���
	IN        mdINT32    inImageWidthByte,  //�摜�̃o�C�g��
	IN        mdINT32    inLeft,            //������`���[
	IN        mdINT32    inTop,             //�@���@�@��[
	IN        mdINT32    inWidth,           //�@���@  ��
	IN        mdINT32    inHeight           //�@���@�@����
	);

//<<#######################################################################
//  �摜����QR�R�[�h��F������
//      �߂�l�F>=0 �̏ꍇ�͔F��QR �R�[�h���A<0 �̏ꍇ�̓G���[�ԍ�
//<<#######################################################################
_PORT_MD_QR_DECODE mdINT32 MdQrDecode_Decode
    (
	IN  const mdHANDLE   inHandle,          //QR�R�[�h�F���n���h��
	IN  const mdBYTE*    inImage,           //�摜�̐擪�A�h���X
    IN        mdINT32    inImageWidth,      //�摜�̕�
	IN        mdINT32    inImageHeight,     //�摜�̍���
	IN        mdINT32    inImageWidthByte,  //�摜�̃o�C�g��
	IN        mdINT16    inMaxCount,        //QR�R�[�h�ő吔
	OUT       mdINT16*   outLength          //�F���o�C�g���z��
	);

//<<#######################################################################
//  �o�[�R�[�h�F���̃I�v�V������ݒ肷��
//      �߂�l�F�G���[�ԍ�
//<<#######################################################################
_PORT_MD_QR_DECODE mdRESULT MdQrDecode_SetOption
    (
	IN  const mdHANDLE  inHandle,       // QR�R�[�h�F���n���h��
    IN        mdINT16   inOptionType,   // �I�v�V�������
    IN        mdINT32   inOptionValue   // �I�v�V�����ݒ�l
    );

//>>#######################################################################
//  �F���f�[�^���擾����
//      �߂�l:�G���[�ԍ�
//<<#######################################################################
_PORT_MD_QR_DECODE mdRESULT MdQrDecode_GetData
    (
    IN  const mdHANDLE   inHandle,      //QR�R�[�h�F���n���h��
    IN        mdINT16    inIndex,       //QR�R�[�h�C���f�b�N�X(�P�`)
    IN        mdINT32    inSize,        //�f�[�^�z��
    OUT       mdBYTE*    outData        //�f�[�^�z��
    );

//>>#######################################################################
//  ���[�h���擾����
//      �߂�l:�G���[�ԍ�
//      outMode�܂���outLength��NULL�̏ꍇ�ɔz��ioSize��Ԃ�
//      outMode����outLength��NULL�łȂ��ꍇ�Ƀ��[�h�z��ƕ������z��ɒl��Ԃ�
//      ���[�h�́u1/2/4/8/3=����/�p����/8�r�b�g�o�C�g/����/�\���I�A�ځv
//      �������̓o�C�g���ł͂Ȃ��B
//      ����/�p����/8�r�b�g�o�C�g�ł́u������=�o�C�g���v�A
//      �����ł́u������*2=�o�C�g���v
//      �\���I�A�ڂł͕s��(�Ӗ����Ȃ�)
//<<#######################################################################
_PORT_MD_QR_DECODE mdRESULT MdQrDecode_GetMode
    (
	IN  const mdHANDLE   inHandle,  //QR�R�[�h�F���n���h��
	IN        mdINT16    inIndex,   //QR�R�[�h�C���f�b�N�X(�P�`)
    INOUT     mdINT32*   ioSize,    //�z��
    OUT       mdINT32*   outMode,   //���[�h�z��
    OUT       mdINT32*   outLength  //�������z��
	);

//>>###################################################################
//  �\���I�A�ڂ��擾����
//      �߂�l:�G���[�ԍ�
//      �ʒu�A���v���Ƃ���1�I���W���ōő吔��16�ł���B
//<<###################################################################
_PORT_MD_QR_DECODE mdRESULT MdQrDecode_GetStruAppe
    (
    IN  const mdHANDLE   inHandle,  //QR�R�[�h�F���n���h��
    IN        mdINT16    inIndex,   //QR�R�[�h�C���f�b�N�X
    OUT       mdINT32*   outIndex,  //�ʒu
    OUT       mdINT32*   outTotal,  //���v��
    OUT       mdINT32*   outParity  //�p���e�B
    );

//>>#######################################################################
//  �^�Ԃ��擾����
//      �߂�l:>0�Ȃ�^�ԁA<=0�Ȃ�G���[
//      �^�Ԃ�1�`40
//<<#######################################################################
_PORT_MD_QR_DECODE mdINT32 MdQrDecode_GetVersion
    (
    IN  const mdHANDLE   inHandle,  //QR�R�[�h�F���n���h��
	IN        mdINT16    inIndex    //QR�R�[�h�C���f�b�N�X(�P�`)
    );

//>>#######################################################################
//  �F��QR�R�[�h�̈���擾����
//      �߂�l:�G���[�ԍ�
//<<#######################################################################
_PORT_MD_QR_DECODE mdINT32 MdQrDecode_GetRect
    (
	IN  const   mdHANDLE    inHandle,       //QR�R�[�h�F���n���h��
    IN          mdINT16     inIndex,        //QR�R�[�h�C���f�b�N�X(�P�`)
	OUT         mdINT32*    outLeft,        //�F����`���[
	OUT         mdINT32*    outTop,         //�@���@�@��[
	OUT         mdINT32*    outWidth,       //�@���@  ��
	OUT         mdINT32*    outHeight       //�@���@�@��
	);

//>>#######################################################################
//  �������x�����擾����
//      �߂�l:>=0�Ȃ�������x���A<0�Ȃ�G���[
//      �������x���́u0/1/2/3=L/M/Q/H�v
//<<#######################################################################
_PORT_MD_QR_DECODE mdINT32 MdQrDecode_GetCorrectLevel
    (
    IN  const mdHANDLE   inHandle,  //QR�R�[�h�F���n���h��
	IN        mdINT16    inIndex    //QR�R�[�h�C���f�b�N�X(�P�`)
    );

//>>#######################################################################
//  �}�X�NID���擾����
//      �߂�l:>=0�Ȃ�}�X�NID�A<0�Ȃ�G���[
//      �}�X�NID��0�`7
//<<#######################################################################
_PORT_MD_QR_DECODE mdINT32 MdQrDecode_GetMaskID
    (
    IN  const mdHANDLE   inHandle,  //QR�R�[�h�F���n���h��
	IN        mdINT16    inIndex    //QR�R�[�h�C���f�b�N�X(�P�`)
    );

//>>#######################################################################
//  �w��̈����QR�R�[�h��F������
//      �߂�l:>=0�̏ꍇ�͔F���o�C�g���A<0�̏ꍇ�̓G���[�ԍ�
//<<#######################################################################
_PORT_MD_QR_DECODE mdINT32 MdQrDecode_DecodeRectEx
    (
	IN  const mdHANDLE  hEngine,        // �F���G���W���n���h��
    IN  const mdHANDLE  hImage,         // �C���[�W�n���h��
	IN  const mdINT32   inLeft,         // ������`���[
	IN  const mdINT32   inTop,          // �@���@�@��[
	IN  const mdINT32   inWidth,        // �@���@  ��
	IN  const mdINT32   inHeight        // �@���@�@��
	);

//<<#######################################################################
//  �摜����QR�R�[�h��F������
//      �߂�l�F>=0 �̏ꍇ�͔F��QR �R�[�h���A<0 �̏ꍇ�̓G���[�ԍ�
//<<#######################################################################
_PORT_MD_QR_DECODE mdINT32 MdQrDecode_DecodeEx // ���֐��ǉ��i�̈撊�o�Ή��j
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
_PORT_MD_QR_DECODE mdINT32 MdQrDecode_GetType
    (
    IN  const mdHANDLE   inHandle,   //QR�R�[�h�F���n���h��
	IN        mdINT16    inIndex     //QR�R�[�h�C���f�b�N�X�@���ǉ��i�̈撊�o�Ή��j
    );

#ifdef __cplusplus
}
#endif
#endif //_MD_QR_DECODE_H
