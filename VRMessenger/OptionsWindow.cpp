#include "OptionsWindow.h"
#include "OptionsWndCmds.h"
#include "XWND.h"
#include "XWNDGUI.h"

COptionsWndCmds *c_OptWndCmd;

COptionsWindow::COptionsWindow()
{
	c_OptWndCmd = new COptionsWndCmds();
	strcpy(szwClassName,"CWndOptions");
	strcpy(szwWindowName,"Настройки");
}

COptionsWindow::~COptionsWindow()
{
	delete c_OptWndCmd;
	c_OptWndCmd = 0;
}

BOOL COptionsWindow::Create()
{
	XWNDSetWindowSize(400,430);
	XWNDSetWindowPosition(250,250,0);
	if(!XWNDCreateWindow(OptWndProc,szwClassName,szwWindowName,true,false))
	{
		return 0;
	}
	return 1;
}

LRESULT WINAPI OptWndProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_DESTROY:
		{
			PostQuitMessage(0);
		}
		break;
		HANDLE_MSG(hWnd,WM_CREATE,c_OptWndCmd->WM_OnCreate);
		HANDLE_MSG(hWnd,WM_COMMAND,c_OptWndCmd->WM_OnCommand);
	default:
		return DefWindowProc(hWnd,uMsg,wParam,lParam);
	}
	return 0;
}