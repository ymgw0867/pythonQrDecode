#pragma once

// Microsoft Visual C++ で作成された IDispatch ラッパー クラスを生成しました。

// メモ: このファイルの内容を変更しないでください。このクラスが
//  Microsoft Visual C++ で再生成された場合、変更は上書きされます。

/////////////////////////////////////////////////////////////////////////////
// CMdqrdecodectrl1 ラッパー クラス

class CMdqrdecodectrl1 : public CWnd
{
protected:
	DECLARE_DYNCREATE(CMdqrdecodectrl1)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x641F3F12, 0x7565, 0x44D8, { 0x85, 0x14, 0x9A, 0xBE, 0x58, 0x69, 0x3F, 0x4 } };
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


// 操作
public:

// _DMdQrDecode

// Functions
//

	void AboutBox()
	{
		InvokeHelper(DISPID_ABOUTBOX, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long MdQrDecode_Initialize()
	{
		long result;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdQrDecode_Terminate()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdQrDecode_LoadImage(LPCTSTR inImageFileName, long inPage)
	{
		long result;
		static BYTE parms[] = VTS_BSTR VTS_I4 ;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_I4, (void*)&result, parms, inImageFileName, inPage);
		return result;
	}
	long MdQrDecode_DecodeRect(long inLeft, long inTop, long inWidth, long inHeight)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_I4, (void*)&result, parms, inLeft, inTop, inWidth, inHeight);
		return result;
	}
	long MdQrDecode_Decode()
	{
		long result;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdQrDecode_GetData(long inSize, long * outData)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI4 ;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_I4, (void*)&result, parms, inSize, outData);
		return result;
	}
	long MdQrDecode_GetDataSize()
	{
		long result;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	CString MdQrDecode_GetStrData()
	{
		CString result;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	long MdQrDecode_GetMode(long inModeSize, long * outMode, long * outRLData)
	{
		long result;
		static BYTE parms[] = VTS_I4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x9, DISPATCH_METHOD, VT_I4, (void*)&result, parms, inModeSize, outMode, outRLData);
		return result;
	}
	long MdQrDecode_GetModeSize()
	{
		long result;
		InvokeHelper(0xa, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdQrDecode_GetRect(long * outLeft, long * outTop, long * outWidth, long * outHeight)
	{
		long result;
		static BYTE parms[] = VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0xb, DISPATCH_METHOD, VT_I4, (void*)&result, parms, outLeft, outTop, outWidth, outHeight);
		return result;
	}
	long MdQrDecode_GetRectLeft()
	{
		long result;
		InvokeHelper(0xc, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdQrDecode_GetRectTop()
	{
		long result;
		InvokeHelper(0xd, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdQrDecode_GetRectWidth()
	{
		long result;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdQrDecode_GetRectHeight()
	{
		long result;
		InvokeHelper(0xf, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdQrDecode_GetVersion()
	{
		long result;
		InvokeHelper(0x10, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdQrDecode_GetCorrectLevel()
	{
		long result;
		InvokeHelper(0x11, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdQrDecode_GetMaskID()
	{
		long result;
		InvokeHelper(0x12, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdQrDecode_SetImage(long * inImage, long inImageWidth, long inImageHeight, long inImageWidthByte)
	{
		long result;
		static BYTE parms[] = VTS_PI4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x13, DISPATCH_METHOD, VT_I4, (void*)&result, parms, inImage, inImageWidth, inImageHeight, inImageWidthByte);
		return result;
	}
	long MdQrDecode_GetMaxCodes()
	{
		long result;
		InvokeHelper(0x14, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdQrDecode_CountPage(LPCTSTR inImageFileName)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x1b, DISPATCH_METHOD, VT_I4, (void*)&result, parms, inImageFileName);
		return result;
	}
	long MdQrDecode_GetImageSize(long * outImageWidth, long * outImageHeight, long * outImageWidthByte, long * outImageDepth)
	{
		long result;
		static BYTE parms[] = VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x1c, DISPATCH_METHOD, VT_I4, (void*)&result, parms, outImageWidth, outImageHeight, outImageWidthByte, outImageDepth);
		return result;
	}
	long MdQrDecode_GetImageWidth()
	{
		long result;
		InvokeHelper(0x1d, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdQrDecode_GetImageHeight()
	{
		long result;
		InvokeHelper(0x1e, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdQrDecode_GetImageWidthByte()
	{
		long result;
		InvokeHelper(0x1f, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdQrDecode_GetImageDepth()
	{
		long result;
		InvokeHelper(0x20, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdQrDecode_GetImageDpiX()
	{
		long result;
		InvokeHelper(0x21, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdQrDecode_GetImageDpiY()
	{
		long result;
		InvokeHelper(0x22, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdQrDecode_GetImage(long * outImage)
	{
		long result;
		static BYTE parms[] = VTS_PI4 ;
		InvokeHelper(0x23, DISPATCH_METHOD, VT_I4, (void*)&result, parms, outImage);
		return result;
	}
	long MdQrDecode_GetStruAppe(long * outIndex, long * outTotal, long * outParity)
	{
		long result;
		static BYTE parms[] = VTS_PI4 VTS_PI4 VTS_PI4 ;
		InvokeHelper(0x25, DISPATCH_METHOD, VT_I4, (void*)&result, parms, outIndex, outTotal, outParity);
		return result;
	}
	long MdQrDecode_GetStruAppeIndex()
	{
		long result;
		InvokeHelper(0x26, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdQrDecode_GetStruAppeTotal()
	{
		long result;
		InvokeHelper(0x27, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdQrDecode_GetStruAppeParity()
	{
		long result;
		InvokeHelper(0x28, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	long MdQrDecode_SetColorImage(long * inImage, long inImageWidth, long inImageHeight, long inImageWidthByte)
	{
		long result;
		static BYTE parms[] = VTS_PI4 VTS_I4 VTS_I4 VTS_I4 ;
		InvokeHelper(0x29, DISPATCH_METHOD, VT_I4, (void*)&result, parms, inImage, inImageWidth, inImageHeight, inImageWidthByte);
		return result;
	}
	long MdQrDecode_InitializeByLicense(LPCTSTR inProductId)
	{
		long result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x2b, DISPATCH_METHOD, VT_I4, (void*)&result, parms, inProductId);
		return result;
	}

// Properties
//

long GetMdQrDecode_VDpi()
{
	long result;
	GetProperty(0x15, VT_I4, (void*)&result);
	return result;
}
void SetMdQrDecode_VDpi(long propVal)
{
	SetProperty(0x15, VT_I4, propVal);
}
long GetMdQrDecode_XDpi()
{
	long result;
	GetProperty(0x16, VT_I4, (void*)&result);
	return result;
}
void SetMdQrDecode_XDpi(long propVal)
{
	SetProperty(0x16, VT_I4, propVal);
}
long GetMdQrDecode_YDpi()
{
	long result;
	GetProperty(0x17, VT_I4, (void*)&result);
	return result;
}
void SetMdQrDecode_YDpi(long propVal)
{
	SetProperty(0x17, VT_I4, propVal);
}
long GetMdQrDecode_ActiveCode()
{
	long result;
	GetProperty(0x18, VT_I4, (void*)&result);
	return result;
}
void SetMdQrDecode_ActiveCode(long propVal)
{
	SetProperty(0x18, VT_I4, propVal);
}
long GetMdQrDecode_Unit()
{
	long result;
	GetProperty(0x19, VT_I4, (void*)&result);
	return result;
}
void SetMdQrDecode_Unit(long propVal)
{
	SetProperty(0x19, VT_I4, propVal);
}
long GetMdQrDecode_LimitCodes()
{
	long result;
	GetProperty(0x1a, VT_I4, (void*)&result);
	return result;
}
void SetMdQrDecode_LimitCodes(long propVal)
{
	SetProperty(0x1a, VT_I4, propVal);
}
long GetMdQrDecode_Finder()
{
	long result;
	GetProperty(0x24, VT_I4, (void*)&result);
	return result;
}
void SetMdQrDecode_Finder(long propVal)
{
	SetProperty(0x24, VT_I4, propVal);
}
long GetMdQrDecode_ImageProc()
{
	long result;
	GetProperty(0x2a, VT_I4, (void*)&result);
	return result;
}
void SetMdQrDecode_ImageProc(long propVal)
{
	SetProperty(0x2a, VT_I4, propVal);
}


};
