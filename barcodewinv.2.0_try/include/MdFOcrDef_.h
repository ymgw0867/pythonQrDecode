//-----------------------------------------------------------------------------
// @(h) MdFOcrDef.h
//
// @(s)
//    À‘•ŒnˆË‘¶‚Ì’è‹` ‹¤’ÊéŒ¾
//
//-----------------------------------------------------------------------------
#define mdAPI __stdcall
#define LITTLE_ENDIAN
#ifdef _MSC_VER
//    #pragma warning( disable : 4018 )
//    #pragma warning( disable : 4244 )
//    #pragma warning( disable : 4305 )
#else
#endif

#ifdef macintosh
    #pragma longlong on
    #define __int64 long long
#else
    #ifndef _MSC_VER
        #define __int64 long long
    #endif
#endif
