#include "XWND.h"
#include "XWNDGUI.h"

XWND_PARAM g_ClWndParam;
CGUIManager g_GUIManager;

BOOL WINAPI XWNDCreateWindow(WNDPROC WndProc,char *szwClassName,char *szwWindowName,BOOL defaultstyle,BOOL borderstyle)
{
	g_ClWndParam.phWnd = &g_ClWndParam.hWnd;
	if(defaultstyle)
	XWNDRegClass(g_ClWndParam.g_hInst,WndProc,(LPCSTR)szwClassName,(UINT)CreateSolidBrush(RGB(255,255,255)),szwWindowName);
	else
    XWNDRegClass(g_ClWndParam.g_hInst,WndProc,(LPCSTR)szwClassName,(UINT)CreateSolidBrush(g_ClWndParam.hwndcolor),szwWindowName);
	if(borderstyle)
	g_ClWndParam.hWnd = CreateWindowA(szwClassName,(LPCSTR)szwWindowName,WS_BORDER|WS_SYSMENU,g_ClWndParam.nPosX,g_ClWndParam.nPosY,g_ClWndParam.nSizeX,g_ClWndParam.nSizeY,0,0,g_ClWndParam.g_hInst,0);
	else
    g_ClWndParam.hWnd = CreateWindowA(szwClassName,szwWindowName,WS_STATICWINDOW,g_ClWndParam.nPosX,g_ClWndParam.nPosY,g_ClWndParam.nSizeX,g_ClWndParam.nSizeY,0,0,g_ClWndParam.g_hInst,0);
	if(g_ClWndParam.hWnd == 0){
	return 0;}
	ShowWindow(g_ClWndParam.hWnd,SW_SHOWNORMAL);
	UpdateWindow(g_ClWndParam.hWnd);
	while(GetMessageA(&g_ClWndParam.msg,0,0,0))
	{
		TranslateMessage(&g_ClWndParam.msg);
		DispatchMessage(&g_ClWndParam.msg);
	}
return 1;
}

HINSTANCE WINAPI XWNDGetCurrentInstance()
{
	return g_ClWndParam.g_hInst;
}

COLORREF WINAPI XWNDSetWndBackgroundColor(int r,int g,int b)
{
g_ClWndParam.hwndcolor = RGB(r,g,b);
return g_ClWndParam.hwndcolor;
}

BOOL WINAPI XWNDSetWndBackground(HWND hWnd)
{
g_GUIManager.InitCommonGUI(hWnd);
g_GUIManager.sStatic.CreateStatic(ID_COMSTATIC,BS_STANDARTSTATIC,0,0,SCREENCENTER_CX*2,SCREENCENTER_CY*2,NULL);
if(g_ClWndParam.hWnd == 0)
return 0;
return 1;
}

POINT WINAPI XWNDGetWindowSize()
{
	POINT g_p;
    g_p.x = g_ClWndParam.nPosX;
	g_p.y = g_ClWndParam.nPosY;
	return g_p; 
}

VOID WINAPI XWNDSetWindowPosition(UINT nX,UINT nY,BOOL bCenter=false)
{
	g_ClWndParam.pX = &g_ClWndParam.nPosX;
	g_ClWndParam.pY = &g_ClWndParam.nPosY;
	if(bCenter)
	{
	g_ClWndParam.nPosX = SCREENCENTER_CX;
    g_ClWndParam.nPosY = SCREENCENTER_CY;
	}
	else
	{
    g_ClWndParam.nPosX = nX;
    g_ClWndParam.nPosY = nY;
	}
}
VOID WINAPI XWNDGetWindowPosition(UINT *nX,UINT *nY)
{
  *nX = *g_ClWndParam.pX;
  *nY = *g_ClWndParam.pY;
}

VOID WINAPI XWNDSetWindowSize(UINT nsX,UINT nsY)
{
	g_ClWndParam.psX = &g_ClWndParam.nSizeX;
	g_ClWndParam.psY = &g_ClWndParam.nSizeY;
    g_ClWndParam.nSizeX = nsX;
    g_ClWndParam.nSizeY = nsY;
}
VOID WINAPI XWNDGetWindowSize(UINT &nsX,UINT &nsY)
{
  nsX = g_ClWndParam.nSizeX;
  nsY = g_ClWndParam.nSizeY;
}

VOID WINAPI XWNDGetCursorPosition(UINT &npX,UINT &npY)
{
  POINT p;
  GetCursorPos(&p);
  npX = p.x;
  npY = p.y;
}

HWND WINAPI XWNDGetWindowHandle()
{
	return *g_ClWndParam.phWnd;
}


BOOL WINAPI XWNDRegClass(HINSTANCE hInst,WNDPROC WndProc,LPCTSTR szName,UINT brBackground,char *szwWindowName)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc,sizeof(wc));
	wc.cbSize = sizeof(wc);
	wc.hInstance = hInst;
	wc.hbrBackground = (HBRUSH)brBackground;
	wc.lpfnWndProc = WndProc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpszMenuName = szwWindowName;
	wc.lpszClassName = szName;
	wc.hCursor = LoadCursor(NULL,IDC_ARROW);
	wc.hIcon = LoadIcon(hInst, RT_ICON);
	return RegisterClassEx(&wc)!=0;
}

VOID WINAPI XWNDSetWindowStyle()
{
	if(_WIN32_WINDOWS)
	{
	InitCommonControls();
	}
	else if(_WIN32_WINNT)
	{
	}
}