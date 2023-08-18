//-----------------------------------------------------------------------------
// @(h) MdFOcrResultCode.h
//
// @(s)
//    Mediadrive FormOcr ���ʐ錾
//
//-----------------------------------------------------------------------------
#ifndef __MdFOcrResultCode_DEF
#define __MdFOcrResultCode_DEF
#include "MdFOcrDef.h"

//----------------------------------------------------------------------------
// ���ʃR�[�h�̌^
//   ���ʃR�[�h��16�r�b�g�����t�����ŕ\�����
//   =�O:����I��
//   <�O�F�����̏ꍇ�̓G���[
//   >�O�F�����̏ꍇ�̓G���[�łȂ��߂�l�Ƃ��ď���Ԃ���
//----------------------------------------------------------------------------
#define mdRESULT            mdINT16                     // �G���[�R�[�h

//----------------------------------------------------------------------------
// �ȉ����ʃG���[�R�[�h     
//----------------------------------------------------------------------------
#define MDRC_OK                 ((mdRESULT)0)               // ����I��
#define MDRC_COMMON_ERR_BASE    ((mdRESULT)(-32000))        // ���ʃG���[�R�[�h�
#define MDRC_ERROR              (MDRC_COMMON_ERR_BASE - 0)  // �G���[
#define MDRC_MEMORY             (MDRC_COMMON_ERR_BASE - 1)  // �������s��
#define MDRC_INVALIDHANDLE      (MDRC_COMMON_ERR_BASE - 2)  // �����n���h��
#define MDRC_INVALIDPARAM       (MDRC_COMMON_ERR_BASE - 3)  // �p�����[�^�G���[
#define MDRC_INVALIDPIC         (MDRC_COMMON_ERR_BASE - 4)  // �����摜�f�[�^
#define MDRC_FILEOPEN           (MDRC_COMMON_ERR_BASE - 5)  // �t�@�C�����I�[�v���ł��Ȃ�
#define MDRC_FILEREAD           (MDRC_COMMON_ERR_BASE - 6)  // �t�@�C���ǂݎ��G���[
#define MDRC_FILEWRITE          (MDRC_COMMON_ERR_BASE - 7)  // �t�@�C���������݃G���[
#define MDRC_BINPIC             (MDRC_COMMON_ERR_BASE - 8)  // �Q�l�摜�ł͂Ȃ�
#define MDRC_CANNOT_LOAD_DLL    (MDRC_COMMON_ERR_BASE - 9)  // DLL�����[�h�ł��Ȃ�
#define MDRC_NOTIMPL            (MDRC_COMMON_ERR_BASE - 10) // API���񋟂���Ă��܂���
#define MDRC_ERR_LICENSE_PRODUCT        (MDRC_COMMON_ERR_BASE - 700) // ���C�Z���X�G���[�E�v���_�N�g
#define MDRC_ERR_LICENSE_DATE           (MDRC_COMMON_ERR_BASE - 701) // ���C�Z���X�G���[�E�L�������G���[
#define MDRC_ERR_LICENSE_MACHINE        (MDRC_COMMON_ERR_BASE - 702) // ���C�Z���X�G���[�E�}�V��ID

#endif
