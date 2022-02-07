#include "XWND.h"
#include "LoginWindow.h"

CLoginWindow  *cw_LoginWnd;

INT WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd)
{
    cw_LoginWnd = new CLoginWindow();
	XWNDSetWindowStyle();
	cw_LoginWnd->Create();//Start Application
	delete cw_LoginWnd;
	cw_LoginWnd = 0;
  	return S_OK;
}

LRESULT WINAPI XWNDStaticWndProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_CREATE:
		cw_LoginWnd->g_wMsg.WM_OnCreate(hWnd,0);
		break;
	case WM_DESTROY:
		cw_LoginWnd->g_wMsg.WM_OnDestroy(hWnd);
		break;
	case WM_COMMAND:
		cw_LoginWnd->g_wMsg.WM_OnCommand(hWnd,wParam,0,0);
	}
	return DefWindowProc( hWnd, uMsg, wParam, lParam ); 
}


