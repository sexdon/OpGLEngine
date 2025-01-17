/*****************************************************************************************************************
**
**	OpenGL Game Development
**	EX2_1.CPP (Example 2.1)
**
**	Copyright:	2003, Chris Seddon. 
**	Written by: Don Flack
**	Date:		Mar 3, 2009
**
******************************************************************************************************************/

/* Headers *******************************************************************************************************/
#include "stdafx.h"



//OPENGL CLASS*******************************************
class RASTER
{
	public:
		HGLRC	glrc;
		HDC		hDC;

		RASTER();
		~RASTER();

		bool Init(HWND hWnd,unsigned char color_bits = 24,unsigned char depth_bits = 32);
		bool Release(HWND hwnd);
};

/*RASTER************************************************/

RASTER::RASTER()
{
	this->glrc = NULL;
	this->hDC  = NULL;
}

RASTER::~RASTER(){}

bool RASTER::Init(HWND hWnd, unsigned char color_bits, unsigned char depth_bits)
{
	PIXELFORMATDESCRIPTOR pfd;
	int PixelFormat;

	hDC = GetDC(hWnd);
	if (hDC == NULL)
	{		
		MessageBoxA(hWnd, "Error: Can't Get Device Context for Window", "ERROR", MB_OK | MB_ICONERROR);
		return (false);							
	}

	/* Original Method
	pfd.nSize			= sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion		= 1;
	pfd.dwFlags			= PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType		= PFD_TYPE_RGBA;
	pfd.cColorBits		= color_bits;
	pfd.cRedBits		= 0;
	pfd.cRedShift		= 0;
	pfd.cGreenBits		= 0;
	pfd.cGreenShift		= 0;
	pfd.cBlueBits		= 0; 
	pfd.cBlueShift		= 0; 
	pfd.cAlphaBits		= 0; 
	pfd.cAlphaShift		= 0;
	pfd.cAccumBits		= 0;
	pfd.cAccumRedBits	= 0; 
	pfd.cAccumGreenBits	= 0; 
	pfd.cAccumBlueBits	= 0; 
	pfd.cAccumAlphaBits	= 0;
	pfd.cDepthBits		= depth_bits; 
	pfd.cStencilBits	= 0;
	pfd.cAuxBuffers		= 0;
	pfd.iLayerType		= 0;
	pfd.bReserved		= 0;
	pfd.dwLayerMask		= 0;
	pfd.dwVisibleMask	= 0;
	pfd.dwDamageMask	= 0;
	*/

	memset (&pfd, 0, sizeof(pfd));
	pfd.nSize		= sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion	= 1;
	pfd.dwFlags		= PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.cColorBits	= color_bits;
	pfd.cDepthBits	= depth_bits;

	PixelFormat = ChoosePixelFormat(hDC, &pfd);
	if (PixelFormat == 0)
	{	
		MessageBoxA(hWnd, "Error: Can't Choose Pixel Format", "ERROR", MB_OK | MB_ICONERROR);
		ReleaseDC (hWnd, hDC);
		hDC = NULL;
		return (false);							
	}

	if (SetPixelFormat(hDC, PixelFormat, &pfd) == 0)	
	{
		MessageBoxA(hWnd, "Error: Can't Set The Pixel Format", "ERROR", MB_OK | MB_ICONERROR);
		ReleaseDC (hWnd, hDC);
		hDC = NULL;
		return (false);								
	}

	glrc = wglCreateContext(hDC);
	if (glrc == NULL)
	{
		MessageBoxA(hWnd, "Error: Can't Create GL Context", "ERROR", MB_OK | MB_ICONERROR);
		ReleaseDC (hWnd, hDC);
		hDC = NULL;
		return (false);								
	}

	if (!wglMakeCurrent(hDC, glrc))					
	{
		MessageBoxA(hWnd, "Error: Can't Make Current GL Context", "ERROR", MB_OK | MB_ICONERROR);
		wglDeleteContext(glrc);
		ReleaseDC (hWnd, hDC);
		glrc	= NULL;
		hDC		= NULL;

		return (false);								
	}

	return (true);

}


/* Release ********************************************************************************************************/
bool RASTER::Release(HWND hWnd)
{
	if (hDC == NULL || glrc == NULL) return (false);

	if (wglMakeCurrent(NULL, NULL) == false)					
	{
		MessageBoxA(hWnd, "Error: Release Of DC And RC Failed.", "Release Error", MB_OK | MB_ICONERROR);
		return (false);
	}

	if (wglDeleteContext(glrc) == false)						
	{
		MessageBoxA(hWnd, "Error: Release Rendering Context Failed.", "Release Error", MB_OK | MB_ICONERROR);
		return (false);
	}
	glrc	= NULL;

	if (ReleaseDC(hWnd, hDC) == false)					
	{		
		MessageBoxA(hWnd, "Error: Release Device Context Failed.", "Release Error", MB_OK | MB_ICONERROR);		
		return (false);
	}
	hDC		= NULL;	

	return (true);
}