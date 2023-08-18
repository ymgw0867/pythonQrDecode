// BcDecodeSample.cpp : �R���\�[�� �A�v���P�[�V�����p�̃G���g�� �|�C���g�̒�`
//

#include "stdafx.h"

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

#include "../../../include/MdBcCommon.h"
#include "../../../include/MdBcDecode.h"
#include "../../../include/MdQrDecode.h"
#pragma comment(lib,"../../../lib/MdBcCommon.lib")
#pragma comment(lib,"../../../lib/MdBcDecode.lib")
#pragma comment(lib,"../../../lib/MdQrDecode.lib")

#include "windows.h"

#define DECODE_RECT 0   // 0 - DecodeEx     �摜�������R�[�h�̓ǂݎ��
                        // 1 - DecodeRectEx �w��̈���P��R�[�h�̓ǂݎ��

#define MORE_INFO   0   // �ǎ挋��(�R�[�h)�ȊO�̏����擾�E�\��

#define L1_TEST 0       // Init�O���[�v�e�X�g
#define L2_TEST 0       // Init�����[�v�e�X�g


#if (L1_TEST | L2_TEST)
//------------------------------------------------------------
HWND GetConsoleHwnd(void)
{
    #define MY_BUFSIZE 1024 // �R���\�[�� �E�B���h�E�̃^�C�g���p�̃o�b�t�@�T�C�Y
    HWND hwndFound;         // �Ăяo�����֕Ԃ����l
    char pszNewWindowTitle[MY_BUFSIZE];
                           // �쐬�����E�B���h�E�̃^�C�g��������܂�
    char pszOldWindowTitle[MY_BUFSIZE]; // ���̃E�B���h�E�^�C�g��������܂�

    // ���݂̃E�B���h�E�^�C�g�����擾���܂�

    GetConsoleTitle(pszOldWindowTitle, MY_BUFSIZE);

    // �Ǝ��ɁA�E�B���h�E�̐V�K�^�C�g�����t�H�[�}�b�g���܂�

    wsprintf(pszNewWindowTitle,"%d/%d",
             GetTickCount(),
             GetCurrentProcessId());

    // ���݂̃E�B���h�E�^�C�g����ύX���܂�

    SetConsoleTitle(pszNewWindowTitle);

    // �E�B���h�E�^�C�g���̃A�b�v�f�[�g���m���Ȃ��̂ɂ����܂�

    Sleep(40);

    // �E�B���h�E�̐V�K�^�C�g����T���ɂ����܂�

    hwndFound=FindWindow(NULL, pszNewWindowTitle);

    // ���̃E�B���h�E�^�C�g���֖߂��܂�

    SetConsoleTitle(pszOldWindowTitle);

    return(hwndFound);
}
#endif

//------------------------------------------------------------
mdINT32 DecodeBC( mdHANDLE hEngine, mdHANDLE hImage )
{
	// �摜�𑜓x�̎擾
    mdINT16 dpiX, dpiY;
	MdBcCommon_GetImageDPI( hImage, &dpiX, &dpiY );
    if( dpiX > 0 && dpiY > 0 )
    {
        // �F���𑜓x�̐ݒ�
	    MdBcDecode_SetOption( hEngine, BC_OPTION_XDPI, dpiX );  // ���𑜓x
        MdBcDecode_SetOption( hEngine, BC_OPTION_YDPI, dpiY );  // �c�𑜓x
    }
    else
    {
        // ����𑜓x�̐ݒ�
	    MdBcDecode_SetOption( hEngine, BC_OPTION_XDPI, 300 );  // ���𑜓x
        MdBcDecode_SetOption( hEngine, BC_OPTION_YDPI, 300 );  // �c�𑜓x
    }

    // �F������
    mdINT32 count = 0;  // �ǎ挋�ʃR�[�h��
    mdINT16 max = 100;  // �ǎ�R�[�h�����
    mdINT16 len[100];   // �ǎ挋�ʃR�[�h���z��

#if DECODE_RECT
	// �摜�T�C�Y�̎擾
    mdINT32 width, height, width_byte;
    mdINT16 depth;
	MdBcCommon_GetImageSize( hImage, &width, &height, &width_byte, &depth );

    // �w��̈���P��R�[�h�̓ǂݎ��
	len[0] = (mdINT16)MdBcDecode_DecodeRectEx( hEngine, hImage, 0 , 0 , width , height );
    if( len[0] <= 0 )
    {
        // �J�X�^�}�o�[�R�[�h�͌ʎw��̂ݑΉ�
        MdBcDecode_SetOption( hEngine, BC_OPTION_BARTYPE, BC_BARTYPE_CUSTOM );
        len[0] = (mdINT16)MdBcDecode_DecodeRectEx( hEngine, hImage, 0 , 0 , width , height );
    }
	if( len[0] <= 0 )
    {
        return count;
    }
	count = 1;
#else
    // �摜�������R�[�h�̓ǂݎ��
    count = MdBcDecode_DecodeEx( hEngine, hImage, max, len );
    if( count <= 0 )
    {
        return count;
    }
#endif

    // �摜�� ���o�R�[�h�̃��[�v
	for( mdINT16 n = 1; n <= count; n++ )
    {
        // �F�����ʂ̎擾	
		char* data = new char[len[n-1]+1];
        memset( data, 0, sizeof(char) * len[n-1]+1 );				
        MdBcDecode_GetData( hEngine, n, len[n-1], (mdBYTE*)data );

        // ���ʂ̕\��
        printf( "%s",
                data );     // �F������

        delete [] data;

#if MORE_INFO
        // ���[�h�̎擾
        mdINT32 size = 0;
        MdBcDecode_GetMode( hEngine, n, (mdINT32*)&size, NULL, NULL );            
        mdINT32* mode = new mdINT32[size];
        mdINT32* len2 = new mdINT32[size];
		memset( mode, 0, sizeof(mdINT32) * size );
		memset( len2, 0, sizeof(mdINT32) * size );
		MdBcDecode_GetMode( hEngine, n, &size, mode, len2 );

        // ���[�h�z��ƕ������z�񂩂瑍�o�C�g�����v�Z
        mdINT32 nbyte = 0;
        for( mdINT32 i = 0; i < size; i++ )
        {
            switch( mode[i] )
            {
            case 1: // ����
            case 2: // �p����
            case 4: // 8�r�b�g�o�C�g
                nbyte += len2[i];
                break;

            case 8: // ����
                nbyte += (len2[i] * 2);
                break;

            default:
                break;
            }
        }

        // ��ʂ̎擾
		mdINT32 type = MdBcDecode_GetType( hEngine, n );

        // �ǎ�ʒu�̎擾
		mdINT32 px = 0;
		mdINT32 py = 0;
		mdINT32 sx = 0;
		mdINT32 sy = 0;
		MdBcDecode_GetRect( hEngine, n, &px, &py, &sx, &sy );

        // ��{���̕\��
        printf( ", %ld, %ld, %ld, %ld, %ld, %ld",
                nbyte,      // ���� = len[n-1]
                type,       // ���
                px, py,     // ������W(X,Y)
                sx, sy );   // ���E����(W,H)

		delete [] mode;
		delete [] len2;
#endif
        printf( "\n" );
	}

    return count;
}


//------------------------------------------------------------
mdINT32 DecodeQR( mdHANDLE hEngine, mdHANDLE hImage )
{
	// �摜�𑜓x�̎擾
    mdINT16 dpiX, dpiY;
	MdBcCommon_GetImageDPI( hImage, &dpiX, &dpiY );
    if( dpiX > 0 && dpiY > 0 )
    {
        // �F���𑜓x�̐ݒ�
	    MdQrDecode_SetOption( hEngine, BC_OPTION_XDPI, dpiX );  // ���𑜓x
        MdQrDecode_SetOption( hEngine, BC_OPTION_YDPI, dpiY );  // �c�𑜓x
    }
    else
    {
        // ����𑜓x�̐ݒ�
	    MdQrDecode_SetOption( hEngine, BC_OPTION_XDPI, 400 );  // ���𑜓x
        MdQrDecode_SetOption( hEngine, BC_OPTION_YDPI, 400 );  // �c�𑜓x
    }

    // �F������
    mdINT32 count = 0;  // �ǎ挋�ʃR�[�h��
    mdINT16 max = 100;   // �ǎ�R�[�h�����
    mdINT16 len[100];    // �ǎ挋�ʃR�[�h���z��

#if DECODE_RECT
	// �摜�T�C�Y�̎擾
    mdINT32 width, height, width_byte;
    mdINT16 depth;
	MdBcCommon_GetImageSize( hImage, &width, &height, &width_byte, &depth );

    // �w��̈���P��R�[�h�̓ǂݎ��
	len[0] = (mdINT16)MdQrDecode_DecodeRectEx( hEngine, hImage, 0 , 0 , width , height );
	if( len[0] <= 0 )
    {
        return count;
    }
	count = 1;
#else
    // �摜�������R�[�h�̓ǂݎ��
    count = MdQrDecode_DecodeEx( hEngine, hImage, max, len );
    if( count <= 0 )
    {
        return count;
    }
#endif

    // �摜�� ���o�R�[�h�̃��[�v
	for( mdINT16 n = 1; n <= count; n++ )
    {
        // �F�����ʂ̎擾	
		char* data = new char[len[n-1]+1];
        memset( data, 0, sizeof(char) * len[n-1]+1 );				
        MdQrDecode_GetData( hEngine, n, len[n-1], (mdBYTE*)data );

        // ���ʂ̕\��
        printf( "%s",
                data );     // �F������

        delete [] data;

#if MORE_INFO
        // ���[�h�̎擾
        mdINT32 size = 0;
        MdQrDecode_GetMode( hEngine, n, &size, NULL, NULL );
        mdINT32* mode = new mdINT32[size];
        mdINT32* len2 = new mdINT32[size];

		memset( mode, 0, sizeof(mdINT32) * size );
		memset( len2, 0, sizeof(mdINT32) * size );
        MdQrDecode_GetMode( hEngine, n, &size, mode, len2 );

        // ���[�h�z��ƕ������z�񂩂瑍�o�C�g�����v�Z
        mdINT32 nbyte = 0;
        for( mdINT32 i = 0; i < size; i++ )
        {
            switch( mode[i] )
            {
            case 1: // ����
            case 2: // �p����
            case 4: // 8�r�b�g�o�C�g
                nbyte += len2[i];
                break;

            case 8: // ����
                nbyte += (len2[i] * 2);
                break;

            default:
                break;
            }
        }

        // ��ʂ̎擾
		mdINT32 type = MdQrDecode_GetType( hEngine, n );

        // �ǎ�ʒu�̎擾
		mdINT32 px = 0;
		mdINT32 py = 0;
		mdINT32 sx = 0;
		mdINT32 sy = 0;
		MdQrDecode_GetRect( hEngine, n, &px, &py, &sx, &sy );

        // ��{���̕\��
        printf( ", %ld, %ld, %ld, %ld, %ld, %ld",
                nbyte,      // ������(�o�C�g��) = len[n-1]
                type,       // ���
                px, py,     // ������W(X,Y)
                sx, sy );   // ���E����(W,H)

		delete [] mode;
		delete [] len2;
#endif

#if MORE_INFO
        // �p�q�^��(1�`40)�̎擾
        mdINT32 version = MdQrDecode_GetVersion( hEngine, n );

        // �\���I�A�ڏ��̎擾�iQR�R�[�h�̂݁j
        mdINT32 index = 0;
        mdINT32 total = 0;
        mdINT32 parity = 0;
        MdQrDecode_GetStruAppe( hEngine, n, &index, &total, &parity );

        // ���������x���̎擾�iQR�R�[�h�̂݁j
        mdINT32 level = MdQrDecode_GetCorrectLevel( hEngine, n );

        // �}�X�N�h�c�̎擾�iQR�R�[�h�̂݁j
        mdINT32 mask = MdQrDecode_GetMaskID( hEngine, n );

        // �p�q�ŗL���̕\��
        printf( ", %ld, %ld, %ld, %ld, %ld, %ld",
            version,    // �p�q�^��
            index,      // �\���I�A�� �ʒu�ԍ�
            total,      // �\���I�A�� ���v��
            parity,     // �\���I�A�� �p���e�B
            level,      // ���������x��
            mask );     // �}�X�N�h�c
#endif    
        printf( "\n" );
    }

    return count;
}

//------------------------------------------------------------
int main( int argc, char* argv[] )
{
	if( argc < 2 )
	{
		fprintf( stderr, "�����Ƀt�@�C�������w�肵�Ă�������\n" );
		return -1;
	}

#if (L1_TEST | L2_TEST)
    unsigned long loop = 0;
    HWND hWnd = GetConsoleHwnd();
    char title[1024];

    DWORD dwTimeSum = 0;
    DWORD dwTimeMax = 0;
    DWORD dwTimeMin = ULONG_MAX;
    SYSTEMTIME st_start;
    GetLocalTime(&st_start);
    unsigned long countSum = 0;
    SYSTEMTIME st_now;
#endif

#if L1_TEST
    while( 1 ) // Init�O���[�v
    {
        loop++;
#endif


	// �F���G���W���̏�����
    mdHANDLE hBC = NULL;
    mdHANDLE hQR = NULL;
	mdINT16 retBC = MdBcDecode_Initialize( &hBC );
    mdINT16 retQR = MdQrDecode_Initialize( &hQR );
    if( retBC < 0 && retQR < 0 )
    {
        fprintf( stderr, "MdBcDecode_Initialize...�߂�l�F%d\n", retBC );
        fprintf( stderr, "MdQrDecode_Initialize...�߂�l�F%d\n", retQR );
        return -1;
    }

#if 1
	// �I�v�V�����ݒ�i���̃T���v���̐ݒ�l�͑S�ď����l�Ȃ̂ŏȗ��j
	MdBcDecode_SetOption( hBC, BC_OPTION_UNIT, BC_UNIT_PIXEL );         // �P�ʒ�
	MdBcDecode_SetOption( hBC, BC_OPTION_DIRECTION, BC_DIRECTION_ANY ); // �ǎ����
	MdBcDecode_SetOption( hBC, BC_OPTION_BARTYPE, BC_BARTYPE_ANY);      // �ǎ���
	MdBcDecode_SetOption( hBC, BC_OPTION_LENGTH, 0 );                   // �ǎ挅��
	//MdBcDecode_SetOption( hBC, BC_OPTION_CHECK_NW7, BC_CHECK_MOD16 );   // �`�F�b�N��

    MdQrDecode_SetOption( hQR, QR_OPTION_UNIT, QR_UNIT_PIXEL );         // �P�ʒ�
    MdQrDecode_SetOption( hQR, QR_OPTION_FINDER, QR_FINDER_NORMAL );    // ���o���x��
#endif

#if L2_TEST
    while( 1 ) // Init�����[�v
    {
        loop++;
#endif

	// �t�@�C���� �摜��(�Ő�)�̎擾
	mdINT16 page = MdBcCommon_CountPage( argv[1] );

    // �t�@�C���� �摜���[�v
	for( mdINT16 p = 1; p <= page; p++ )
	{
		// �摜�̓ǂݍ���
        mdHANDLE hImage = NULL;
        mdINT16 ret = MdBcCommon_LoadImage( argv[1], p, &hImage, 400 );
        if( ret != MDRC_OK )
        {
            continue;
        }

#if (L1_TEST | L2_TEST)
        LARGE_INTEGER nFreq, nBefore, nAfter;
        DWORD dwTime = 0;
        memset(&nFreq,   0x00, sizeof nFreq);
        memset(&nBefore, 0x00, sizeof nBefore);
        memset(&nAfter,  0x00, sizeof nAfter);
        QueryPerformanceFrequency(&nFreq);
        QueryPerformanceCounter(&nBefore);
#endif

        mdINT32 cntBC1 = 0;
        mdINT32 cntBC2 = 0;
        mdINT32 cntQR = 0;
        if( hBC != NULL )
        {
            // �ꎟ���o�[�R�[�h�̔F��
            MdBcDecode_SetOption( hBC, BC_OPTION_BARTYPE, BC_BARTYPE_ANY );
            cntBC1 = DecodeBC( hBC, hImage );
        
            // �J�X�^�}�o�[�R�[�h�͌ʎw��̂ݑΉ�
            MdBcDecode_SetOption( hBC, BC_OPTION_BARTYPE, BC_BARTYPE_CUSTOM );
            cntBC2 = DecodeBC( hBC, hImage );
        }
        if( hQR != NULL )
        {
            // �p�q�R�[�h�̔F��
            cntQR = DecodeQR( hQR, hImage );
        }
        if( cntBC1 <= 0 && cntBC2 <= 0 && cntQR <= 0 )
        {
            printf( "\n" );
        }

#if (L1_TEST | L2_TEST)
        QueryPerformanceCounter(&nAfter);
        dwTime = (DWORD)((nAfter.QuadPart - nBefore.QuadPart) * 1000 / nFreq.QuadPart);
        dwTimeSum += dwTime;
        if( dwTime > dwTimeMax ) dwTimeMax = dwTime;
        if( dwTime < dwTimeMin ) dwTimeMin = dwTime;

        if( hWnd != NULL )
        {
            GetLocalTime(&st_now);
            FILETIME	 ft_start;
            FILETIME	 ft_now;
            SystemTimeToFileTime( &st_start, &ft_start );
            SystemTimeToFileTime( &st_now, &ft_now );

            // int64�ɃL���X�g
            __int64	*	nTime1 = (__int64*)&ft_start;	
            __int64	*	nTime2 = (__int64*)&ft_now;	

            // �o�ߕb
            __int64	 nDiffSec = (*nTime2 - *nTime1) / 10000 / 1000;
            __int64	 nDiffHour = nDiffSec / (60*60);
            __int64	 nDiffMinute = nDiffSec / 60;
            __int64	 nDiffSecond = nDiffSec % 60;

            countSum++;
            sprintf_s( title, sizeof(title),
                "%02d:%02d:%02d from %02d:%02d:%02d, x%d, min:%d max:%d avr:%d[ms]",
                (int)nDiffHour, (int)nDiffMinute, (int)nDiffSecond,
                st_start.wHour, st_start.wMinute, st_start.wSecond,
                loop,
                dwTimeMin, dwTimeMax, dwTimeSum / ((page*(loop-1))+p) );
            SetWindowText( hWnd, title );
        }
#endif

		// �摜�̉��
        if( hImage != NULL )
        {
            MdBcCommon_ReleaseImage( hImage );
            hImage = NULL;
        }
	}

#if L2_TEST
    } // Init�����[�v
#endif

	// �F���G���W���̏I��
    if( hBC != NULL )
    {
	    MdBcDecode_Terminate( hBC );	
        hBC = NULL;
    }
    if( hQR != NULL )
    {
        MdQrDecode_Terminate( hQR );
        hQR = NULL;
    }

#if L1_TEST
    } // Init�O���[�v
#endif

	return 0;
}
