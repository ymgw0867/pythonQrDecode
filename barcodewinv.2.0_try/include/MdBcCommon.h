#ifndef _MD_BC_COMMON_H
#define _MD_BC_COMMON_H
#include "MdFOcrDef.h"
#include "windows.h"

#ifdef __cplusplus
extern "C" {
#endif


mdINT16 mdAPI MdBcCommon_CountPage(	// �擾�F�摜�t�@�C�����Ő��̎擾
    IN	const char* inFileName );       // �摜�t�@�C����

mdINT16 mdAPI MdBcCommon_CountPageEx(   // �擾�F�摜�t�@�C�����Ő��̎擾(PDF�摜�W�J�`�F�b�N�t��)
    IN	const char* inFileName );       // �摜�t�@�C����

mdRESULT mdAPI MdBcCommon_ReadFile(     // �t�@�C���̓ǂݍ���
    IN  const char* inFileName,         // �t�@�C����
    IN  mdINT16     inPage,             // �y�[�W�ԍ�(������TIFF���F�P�`)
    OUT mdHANDLE*   outHandle,          // �摜�n���h�� (=NULL:�擾���Ȃ�)
    IN  mdINT16     inDpi = 400 );      // ����𑜓x
                                        
mdRESULT mdAPI MdBcCommon_ReleaseImage( // ���:�C���X�^���X
    IN  mdHANDLE inHandle );            // �摜�f�[�^�C���X�^���X�n���h��

mdRESULT mdAPI MdBcCommon_GetImageSize( // �摜�T�C�Y���擾
    IN  mdHANDLE    inHandle,           // �摜�n���h��
    OUT mdINT32*    outImageWidth,      // �摜���h�b�g��(=NULL:�擾���Ȃ�)
    OUT mdINT32*    outImageHeight,     // �摜�c�h�b�g��(=NULL:�擾���Ȃ�)
    OUT mdINT32*    outImageWidthByte,  // �摜���o�C�g��(=NULL:�擾���Ȃ�)
    OUT mdINT16*    outImageDepth );    // �摜�r�b�g��(=NULL:�擾���Ȃ�)

mdRESULT mdAPI MdBcCommon_GetImageDPI(  // �摜�𑜓x���擾
    IN  mdHANDLE    inHandle,
    OUT mdINT16*    outDpiX,            // ���𑜓x(=NULL:�擾���Ȃ�)
    OUT mdINT16*    outDpiY );          // �c�𑜓x(=NULL:�擾���Ȃ�)

mdRESULT mdAPI MdBcCommon_GetImage(     // �摜�z����擾
    IN  mdHANDLE    inHandle,           // �摜�n���h��
    OUT mdBYTE*     outImage );         // �摜�z��


mdRESULT mdAPI MdBcCommon_LoadImage(    // �t�@�C���̓ǂݍ���
    IN  const char* inFileName,         // �t�@�C����
    IN  mdINT16     inPage,             // �y�[�W�ԍ�(������TIFF���F�P�`)
    OUT mdHANDLE*   outHandle,          // �摜�n���h�� (=NULL:�擾���Ȃ�)
	IN  mdINT16     inDefaultDpi
	);

mdRESULT mdAPI MdBcCommon_ConvertDIBToImageHandle( // �������ǂݍ���(DIB)
    IN  BITMAPINFO  *bih,               // BITMAPINFO�w�b�_
    IN  unsigned char *image,           // �摜�f�[�^
    OUT mdHANDLE*   outHandle           // �摜�n���h�� (=NULL:�擾���Ȃ�)
	);

#ifdef __cplusplus
}
#endif
#endif