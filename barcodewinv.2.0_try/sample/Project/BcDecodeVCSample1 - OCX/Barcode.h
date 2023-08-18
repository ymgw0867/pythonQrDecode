
#define STR_MAX 256
#define Number(arr) (sizeof(arr)/sizeof(arr[0]))

typedef enum tagBCDIRECTION // �ǎ����
{
    BC_DIRECTION_UNKNOWN    = 0x00,  // �s��
    BC_DIRECTION_RIGHT      = 0x01,  // ��
    BC_DIRECTION_LEFT       = 0x02,  // ��
    BC_DIRECTION_UP         = 0x04,  // ��
    BC_DIRECTION_DOWN       = 0x08,  // ��
    BC_DIRECTION_ANY        = 0x0F,  // ��������

} BCDIRECTION;

typedef enum tagBCBARTYPE   // �o�[�R�[�h���
{
    BC_BARTYPE_UNKNOWN  = 0x00000000,
    BC_BARTYPE_JAN13    = 0x00000001,
    BC_BARTYPE_JAN8     = 0x00000002,
    BC_BARTYPE_ITF      = 0x00000010,
    BC_BARTYPE_ITFB     = 0x00000020,
    BC_BARTYPE_NW7      = 0x00000100,
    BC_BARTYPE_CODE39   = 0x00000200,
    BC_BARTYPE_CODE128  = 0x00000400,
    BC_BARTYPE_EAN128   = 0x00000800,//2011/10/28�錾�Y��
    BC_BARTYPE_CUSTOM   = 0x00001000,//2011/10/28�J�X�^�}�[�o�[�R�[�h

    BC_BARTYPE_RSS14        = 0x00010000,
    BC_BARTYPE_RSS_LIMITED  = 0x00020000, // �\��
    BC_BARTYPE_RSS_EXPANDED = 0x00040000, // �\��

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

} BCCHECK;

const long LNG_BC_DIRECTION[] =
{
    BC_DIRECTION_ANY,
    BC_DIRECTION_RIGHT | BC_DIRECTION_LEFT,
    BC_DIRECTION_UP | BC_DIRECTION_DOWN,
    BC_DIRECTION_RIGHT,
    BC_DIRECTION_LEFT,
    BC_DIRECTION_UP,
    BC_DIRECTION_DOWN
};

const char STR_BC_DIRECTION[][STR_MAX] =
{
    "�S����",
    "����",
    "����",
    "��",
    "��",
    "��",
    "��"
};

const long LNG_BC_BARTYPE[] =
{
    BC_BARTYPE_ANY,
    BC_BARTYPE_JAN13,
    BC_BARTYPE_JAN8,
    BC_BARTYPE_ITF,
    BC_BARTYPE_NW7,
    BC_BARTYPE_CODE39,
    BC_BARTYPE_CODE128,
    BC_BARTYPE_CUSTOM,
    BC_BARTYPE_RSS14
};

const char STR_BC_BARTYPE[][STR_MAX] =
{
    "�S��",
    "JAN-13",
    "JAN-8",
    "ITF",
    "NW-7",
    "CODE39",
    "CODE128",
	"CUSTOM",
    "RSS14"
};

const long LNG_BC_CHECK_ANY[] =
{
    BC_CHECK_NONE,
};

const char STR_BC_CHECK_ANY[][STR_MAX] =
{
    "�Ȃ�",
};

const long LNG_BC_CHECK_JAN[] =
{
    BC_CHECK_MOD10W3,
};

const char STR_BC_CHECK_JAN[][STR_MAX] = 
{
    "Ӽޭ׽10 ����3",
};

const long LNG_BC_CHECK_CODE128[] =
{
    BC_CHECK_MOD103,
};

const char STR_BC_CHECK_CODE128[][STR_MAX] = 
{
    "Ӽޭ׽103",
};

const long LNG_BC_CHECK_ITF[] =
{
    BC_CHECK_NONE,
    BC_CHECK_MOD10W3,
};

const char STR_BC_CHECK_ITF[][STR_MAX] =
{
    "�Ȃ�",
    "Ӽޭ׽10 ����3",
};

const long LNG_BC_CHECK_CODE39[] =
{
    BC_CHECK_NONE,
    BC_CHECK_MOD43,
};

const char STR_BC_CHECK_CODE39[][STR_MAX] = 
{
    "�Ȃ�",
    "Ӽޭ׽43",
};

const long LNG_BC_CHECK_NW7[] =
{
    BC_CHECK_NONE,
    BC_CHECK_MOD10W3,
    BC_CHECK_MOD10W2,
    BC_CHECK_LUHN,
    BC_CHECK_MOD11,
    BC_CHECK_WMOD11,
    BC_CHECK_MOD16,
    BC_CHECK_7DR,
};

const char STR_BC_CHECK_NW7[][STR_MAX] = 
{
    "�Ȃ�",
    "Ӽޭ׽10 ����3",
    "Ӽޭ׽10 ����2",
    "ٰݽ�",
    "Ӽޭ׽11",
    "���dӼޭ׽11",
    "Ӽޭ׽16",
    "7����DR"
};

//2011/10/28�J�X�^�}�[�o�[�R�[�h