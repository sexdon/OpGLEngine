// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

// 如果必须将位于下面指定平台之前的平台作为目标，请修改下列定义。
// 有关不同平台对应值的最新信息，请参考 MSDN。
#ifndef WINVER				// 允许使用特定于 Windows XP 或更高版本的功能。
#define WINVER 0x0501		// 将此值更改为相应的值，以适用于 Windows 的其他版本。
#endif

#ifndef _WIN32_WINNT		// 允许使用特定于 Windows XP 或更高版本的功能。
#define _WIN32_WINNT 0x0501	// 将此值更改为相应的值，以适用于 Windows 的其他版本。
#endif						

#ifndef _WIN32_WINDOWS		// 允许使用特定于 Windows 98 或更高版本的功能。
#define _WIN32_WINDOWS 0x0410 // 将此值更改为适当的值，以指定将 Windows Me 或更高版本作为目标。
#endif

#ifndef _WIN32_IE			// 允许使用特定于 IE 6.0 或更高版本的功能。
#define _WIN32_IE 0x0600	// 将此值更改为相应的值，以适用于 IE 的其他版本。
#endif

#define WIN32_LEAN_AND_MEAN		// 从 Windows 头中排除极少使用的资料
#define _USE_MATH_DEFINES
// Windows 头文件:
#include <windows.h>
#include <commctrl.h>
#include <comdef.h>
#include <gdiplus.h>				//将GDI+头文件加入到工程中
#include <GdiPlusImaging.h>

// C 运行时头文件
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <stdio.h>
#include <math.h>


// TODO: 在此处引用程序需要的其他头文件
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/glaux.h>

#pragma comment(lib, "gdiplus.lib") //将GDI+的lib文件加入到工程中
#pragma comment(lib, "OpenGL32.Lib")
#pragma comment(lib, "GLAUX.LIB")
#pragma comment(lib, "Glu32.Lib")

using namespace Gdiplus;			//使用GDI+的命名空间