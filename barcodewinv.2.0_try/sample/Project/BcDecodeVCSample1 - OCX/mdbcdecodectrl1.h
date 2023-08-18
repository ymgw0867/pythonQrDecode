#pragma once

// Microsoft Visual C++ で作成された IDispatch ラッパー クラスを生成しました。

// メモ: このファイルの内容を変更しないでください。このクラスが
//  Microsoft Visual C++ で再生成された場合、変更は上書きされます。

/////////////////////////////////////////////////////////////////////////////
// CMdbcdecodectrl1 ラッパー クラス

class CMdbcdecodectrl1 : public CWnd
{
protected:
	DECLARE_DYNCREATE(CMdbcdecodectrl1)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x7843896B, 0xDEF2, 0x4361, { 0x89, 0x8F, 0xD5, 0xE4, 0xD7, 0x1B, 0xB9, 0xAD } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle,
						const RECT& rect, CWnd* pParentWnd, UINT nID, 
						CCreateContext* pContext = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); 
	}

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, 
				UINT nID, CFile* pPersist = NULL, BOOL bStorage = FALSE,
				BSTR bstrLicKey = NULL)
	{ 
		return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); 
	}

// 属性
public:
enum
{
    UNIT_PIXEL = 0,
    UNIT_MM = 1
}tagUNIT;
enum
{
    DIRECTION_RIGHT = 1,
    DIRECTION_LEFT = 2,
    DIRECTION_UP = 4,
    DIRECTION_DOWN = 8,
    DIRECTION_ANY = 15
}tagDIRECTION;
enum
{
    BARTYPE_JAN13 = 1,
    BARTYPE_JAN8 = 2,
    BARTYPE_ITF = 16,
    BARTYPE_NW7 = 256,
    BARTYPE_CODE39 = 512,
    BARTYPE_CODE128 = 1024,
    BARTYPE_ANY = -1
}tagBARTYPE;
enum
{
    CHECK_ITF_NONE = 0,
    CHECK_ITF_MOD10W3 = 1
}tagCHECK_ITF;
enum
{
    CHECK_CODE39_NONE = 0,
    CHECK_CODE39_MOD43 = 64
}tagCHECK_CODE39;
enum
{
    CHECK_NW7_NONE = 0,
    CHECK_NW7_MOD10W3 = 1,
    CHECK_NW7_MOD10W2 = 2,
    CHECK_NW7_LUHN = 4,
    CHECK_NW7_MOD11 = 8,
    CHECK_NW7_WMOD11 = 16,
    CHECK_NW7_MOD16 = 32,
    CHECK_NW7_7DR = 256
}tagCHECK_NW7;


// 操作
public:

// _DMdBcDecode

// Functions
//

	void AboutBox()
	{
		InvokeHelper(DISPID_ABOUTBOX, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long MdBcDecode_Initialize()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdBcDecode_Terminate()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdBcDecode_LoadImage(LPCTSTR inImageFileName, long inPage)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_I4, (void*)&result, parms, inImageFileName, inPage);
		return result;
	}
	long MdBcDecode_DecodeRect(long inLeft, long inTop, long inWidth, long inHeight)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_I4, (void*)&result, parms, inLeft, inTop, inWidth, inHeight);
		return result;
	}
	long MdBcDecode_Decode()
	{
		long result;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdBcDecode_GetData(long inSize, long * outData)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_I4, (void*)&result, parms, inSize, outData);
		return result;
	}
	long MdBcDecode_GetDataSize()
	{
		long result;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	CString MdBcDecode_GetStrData()
	{
		CString result;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	long MdBcDecode_GetMode(long inModeSize, long * outMode, long * outRLData)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x9, DISPATCH_METHOD, VT_I4, (void*)&result, parms, inModeSize, outMode, outRLData);
		return result;
	}
	long MdBcDecode_GetModeSize()
	{
		long result;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdBcDecode_GetRect(long * outLeft, long * outTop, long * outWidth, long * outHeight)
	{
		long result;
		static BYTE parms[] = VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_I4, (void*)&result, parms, outLeft, outTop, outWidth, outHeight);
		return result;
	}
	long MdBcDecode_GetRectLeft()
	{
		long result;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdBcDecode_GetRectTop()
	{
		long result;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdBcDecode_GetRectWidth()
	{
		long result;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdBcDecode_GetRectHeight()
	{
		long result;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdBcDecode_GetVersion()
	{
		long result;
		InvokeHelper(0x10, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdBcDecode_SetImage(long * inImage, long inImageWidth, long inImageHeight, long inImageWidthByte)
	{
		long result;
		static BYTE parms[] = VTS_PI4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_I4, (void*)&result, parms, inImage, inImageWidth, inImageHeight, inImageWidthByte);
		return result;
	}
	long MdBcDecode_GetMaxCodes()
	{
		long result;
		InvokeHelper(0x14, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdBcDecode_CountPage(LPCTSTR inImageFileName)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x1b, DISPATCH_METHOD, VT_I4, (void*)&result, parms, inImageFileName);
		return result;
	}
	long MdBcDecode_GetImageSize(long * outImageWidth, long * outImageHeight, long * outImageWidthByte, long * outImageDepth)
	{
		long result;
		static BYTE parms[] = VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x1c, DISPATCH_METHOD, VT_I4, (void*)&result, parms, outImageWidth, outImageHeight, outImageWidthByte, outImageDepth);
		return result;
	}
	long MdBcDecode_GetImageWidth()
	{
		long result;
		InvokeHelper(0x1d, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdBcDecode_GetImageHeight()
	{
		long result;
		InvokeHelper(0x1e, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdBcDecode_GetImageWidthByte()
	{
		long result;
		InvokeHelper(0x1f, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdBcDecode_GetImageDepth()
	{
		long result;
		InvokeHelper(0x20, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdBcDecode_GetImageDpiX()
	{
		long result;
		InvokeHelper(0x21, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdBcDecode_GetImageDpiY()
	{
		long result;
		InvokeHelper(0x22, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdBcDecode_GetImage(long * outImage)
	{
		long result;
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x23, DISPATCH_METHOD, VT_I4, (void*)&result, parms, outImage);
		return result;
	}
	long MdBcDecode_InitializeByLicense(LPCTSTR inProductId)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x28, DISPATCH_METHOD, VT_I4, (void*)&result, parms, inProductId);
		return result;
	}

// Properties
//

long GetMdBcDecode_Direction()
{
	long result;
	GetProperty(0x11, VT_I4, (void*)&result);
	return result;
}
void SetMdBcDecode_Direction(long propVal)
{
	SetProperty(0x11, VT_I4, propVal);
}
long GetMdBcDecode_BarType()
{
	long result;
	GetProperty(0x12, VT_I4, (void*)&result);
	return result;
}
void SetMdBcDecode_BarType(long propVal)
{
	SetProperty(0x12, VT_I4, propVal);
}
long GetMdBcDecode_VDpi()
{
	long result;
	GetProperty(0x15, VT_I4, (void*)&result);
	return result;
}
void SetMdBcDecode_VDpi(long propVal)
{
	SetProperty(0x15, VT_I4, propVal);
}
long GetMdBcDecode_XDpi()
{
	long result;
	GetProperty(0x16, VT_I4, (void*)&result);
	return result;
}
void SetMdBcDecode_XDpi(long propVal)
{
	SetProperty(0x16, VT_I4, propVal);
}
long GetMdBcDecode_YDpi()
{
	long result;
	GetProperty(0x17, VT_I4, (void*)&result);
	return result;
}
void SetMdBcDecode_YDpi(long propVal)
{
	SetProperty(0x17, VT_I4, propVal);
}
long GetMdBcDecode_ActiveCode()
{
	long result;
	GetProperty(0x18, VT_I4, (void*)&result);
	return result;
}
void SetMdBcDecode_ActiveCode(long propVal)
{
	SetProperty(0x18, VT_I4, propVal);
}
long GetMdBcDecode_Unit()
{
	long result;
	GetProperty(0x19, VT_I4, (void*)&result);
	return result;
}
void SetMdBcDecode_Unit(long propVal)
{
	SetProperty(0x19, VT_I4, propVal);
}
long GetMdBcDecode_LimitCodes()
{
	long result;
	GetProperty(0x1a, VT_I4, (void*)&result);
	return result;
}
void SetMdBcDecode_LimitCodes(long propVal)
{
	SetProperty(0x1a, VT_I4, propVal);
}
long GetMdBcDecode_Length()
{
	long result;
	GetProperty(0x24, VT_I4, (void*)&result);
	return result;
}
void SetMdBcDecode_Length(long propVal)
{
	SetProperty(0x24, VT_I4, propVal);
}
long GetMdBcDecode_CheckITF()
{
	long result;
	GetProperty(0x25, VT_I4, (void*)&result);
	return result;
}
void SetMdBcDecode_CheckITF(long propVal)
{
	SetProperty(0x25, VT_I4, propVal);
}
long GetMdBcDecode_CheckCODE39()
{
	long result;
	GetProperty(0x26, VT_I4, (void*)&result);
	return result;
}
void SetMdBcDecode_CheckCODE39(long propVal)
{
	SetProperty(0x26, VT_I4, propVal);
}
long GetMdBcDecode_CheckNW7()
{
	long result;
	GetProperty(0x27, VT_I4, (void*)&result);
	return result;
}
void SetMdBcDecode_CheckNW7(long propVal)
{
	SetProperty(0x27, VT_I4, propVal);
}


};
