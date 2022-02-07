#include <winsock2.h>
#include <windows.h> 
#include <windowsx.h> 
#include <tchar.h>
#include "stdio.h"
#include <iostream>
#include "assert.h"
#include "string.h"
#include <fstream>
#include <ostream>
#include "winnt.h"
#include "commctrl.h"

#pragma once
#ifndef XWND_H
#define XWND_H

#ifndef STRICT
#define STRICT
#endif

#ifndef WINVER
#define WINVER         0x0500
#endif
#ifndef _WIN32_WINDOWS
#define _WIN32_WINDOWS 0x0500 
#endif
#ifndef _WIN32_WINNT
#define _WIN32_WINNT   0x0600
#endif

typedef SOCKET CLIENTSOCKET;

void sLogInfo(char * prgmsg,int msgtype);

#define ID_COMSTATIC 0
#define SCREENCENTER_CX GetSystemMetrics(SM_CXSCREEN)/2
#define SCREENCENTER_CY GetSystemMetrics(SM_CYSCREEN)/2

struct XWND_PARAM
{
MSG msg;
HWND *phWnd;
HWND hWnd;
HINSTANCE g_hInst;
COLORREF hwndcolor;
UINT *pX;
UINT *pY;
UINT nPosX;
UINT nPosY;
UINT *psX;
UINT *psY;
UINT nSizeX;
UINT nSizeY;
};

struct XWND_PROCMSG
{
BOOL *OnDestroy(HWND hwnd);
void *OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
BOOL *OnCreate(HWND hwnd, CREATESTRUCT *lpCreateStruct);
};

INT WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd);
BOOL WINAPI XWNDCreateWindow(WNDPROC,CHAR*,CHAR*,BOOL,BOOL);
COLORREF WINAPI XWNDSetWndBackgroundColor(UINT,UINT,UINT);
LRESULT WINAPI XWNDStaticWndProc(HWND,UINT,WPARAM,LPARAM);
HINSTANCE WINAPI XWNDGetCurrentInstance();
BOOL WINAPI XWNDSetWndBackground(HWND);//Set background only in WndProc !!! (WM_CREATE)
POINT WINAPI XWNDGetWindowSize();
BOOL WINAPI XWNDRegClass(HINSTANCE,WNDPROC ,LPCTSTR,UINT,CHAR*);
VOID WINAPI XWNDSetWindowPosition(UINT,UINT,BOOL bCenter);
VOID WINAPI XWNDGetWindowPosition(UINT*,UINT*);
VOID WINAPI XWNDSetWindowSize(UINT,UINT);
VOID WINAPI XWNDGetWindowSize(UINT&,UINT&);
VOID WINAPI XWNDGetCursorPosition(UINT&,UINT&);
VOID WINAPI XWNDSetCursorPosition(UINT,UINT);
VOID WINAPI XWNDSetWindowTitle();
VOID WINAPI XWNDGetWindowTitle();
VOID WINAPI XWNDSetWindowClassName();
VOID WINAPI XWNDGetWindowClassName();
HWND WINAPI XWNDGetWindowHandle();
VOID WINAPI XWNDSetWindowStyle();
VOID WINAPI XWNDSetCallback();
#endif