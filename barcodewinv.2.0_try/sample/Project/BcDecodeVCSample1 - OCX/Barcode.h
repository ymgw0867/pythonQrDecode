
#define STR_MAX 256
#define Number(arr) (sizeof(arr)/sizeof(arr[0]))

typedef enum tagBCDIRECTION // 読取方向
{
    BC_DIRECTION_UNKNOWN    = 0x00,  // 不明
    BC_DIRECTION_RIGHT      = 0x01,  // →
    BC_DIRECTION_LEFT       = 0x02,  // ←
    BC_DIRECTION_UP         = 0x04,  // ↑
    BC_DIRECTION_DOWN       = 0x08,  // ↓
    BC_DIRECTION_ANY        = 0x0F,  // 自動判定

} BCDIRECTION;

typedef enum tagBCBARTYPE   // バーコード種別
{
    BC_BARTYPE_UNKNOWN  = 0x00000000,
    BC_BARTYPE_JAN13    = 0x00000001,
    BC_BARTYPE_JAN8     = 0x00000002,
    BC_BARTYPE_ITF      = 0x00000010,
    BC_BARTYPE_ITFB     = 0x00000020,
    BC_BARTYPE_NW7      = 0x00000100,
    BC_BARTYPE_CODE39   = 0x00000200,
    BC_BARTYPE_CODE128  = 0x00000400,
    BC_BARTYPE_EAN128   = 0x00000800,//2011/10/28宣言忘れ
    BC_BARTYPE_CUSTOM   = 0x00001000,//2011/10/28カスタマーバーコード

    BC_BARTYPE_RSS14        = 0x00010000,
    BC_BARTYPE_RSS_LIMITED  = 0x00020000, // 予約
    BC_BARTYPE_RSS_EXPANDED = 0x00040000, // 予約

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
    "全方向",
    "←→",
    "↑↓",
    "→",
    "←",
    "↑",
    "↓"
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
    "全種",
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
    "なし",
};

const long LNG_BC_CHECK_JAN[] =
{
    BC_CHECK_MOD10W3,
};

const char STR_BC_CHECK_JAN[][STR_MAX] = 
{
    "ﾓｼﾞｭﾗｽ10 ｳｪｲﾄ3",
};

const long LNG_BC_CHECK_CODE128[] =
{
    BC_CHECK_MOD103,
};

const char STR_BC_CHECK_CODE128[][STR_MAX] = 
{
    "ﾓｼﾞｭﾗｽ103",
};

const long LNG_BC_CHECK_ITF[] =
{
    BC_CHECK_NONE,
    BC_CHECK_MOD10W3,
};

const char STR_BC_CHECK_ITF[][STR_MAX] =
{
    "なし",
    "ﾓｼﾞｭﾗｽ10 ｳｪｲﾄ3",
};

const long LNG_BC_CHECK_CODE39[] =
{
    BC_CHECK_NONE,
    BC_CHECK_MOD43,
};

const char STR_BC_CHECK_CODE39[][STR_MAX] = 
{
    "なし",
    "ﾓｼﾞｭﾗｽ43",
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
    "なし",
    "ﾓｼﾞｭﾗｽ10 ｳｪｲﾄ3",
    "ﾓｼﾞｭﾗｽ10 ｳｪｲﾄ2",
    "ﾙｰﾝｽﾞ",
    "ﾓｼﾞｭﾗｽ11",
    "加重ﾓｼﾞｭﾗｽ11",
    "ﾓｼﾞｭﾗｽ16",
    "7ﾁｪｯｸDR"
};

//2011/10/28カスタマーバーコード