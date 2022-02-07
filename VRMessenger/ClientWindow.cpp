#include "ClientWindow.h"
#include "ClientWndCmds.h"
#include "XWND.h"
#include "XWNDGUI.h"

CGUIManager *c_clwGUIManager = new CGUIManager();

CSearchWindow g_SearchWindow;
CWinSockets g_WSocket;
struct _CLIENTINFO
{
char _usernick[256];
}_s_ClientInfo;

CClientWindow::CClientWindow()
{
}

CClientWindow::~CClientWindow()
{
}

BOOL CClientWindow::Create(CWinSockets *p_wSocket)
{
	g_WSocket = *p_wSocket;
	strcpy(_s_ClientInfo._usernick,s_ClientInfo.szusernick);
	XWNDSetWindowSize(550,400);
	XWNDSetWindowPosition(50,50,0);
	if(!XWNDCreateWindow(ClWndProc,"ClientClass","ClientWindow",true,false))
	{
		return 0;
	}
	return 1;
}
LRESULT CALLBACK ClWndProc(HWND hWnd,UINT u_msg,WPARAM wParam,LPARAM lParam)
{
	switch(u_msg)
	{
	case WM_CREATE:
		{
    WCHAR nickbar[256];
	sprintf((char*)nickbar,"Профиль : %s\n(В сети)",_s_ClientInfo._usernick);
	XWNDSetWndBackground(hWnd);
	c_clwGUIManager->InitCommonGUI(hWnd);
	c_clwGUIManager->sTreeView.CreateTreeView(10,20,60,150,280);
	c_clwGUIManager->sStatic.CreateStatic(2,BS_STANDARTSTATIC,25,15,200,45,(char*)nickbar);
	c_clwGUIManager->sButton.CreateButton(ID_BUTTON01,BS_STANDARTBUTTON,10,340,170,20,"Поиск пользователей");
		}
		break;
	case WM_COMMAND:
		{
			switch(wParam)
			{
			case ID_BUTTON01:
				{
					g_SearchWindow.Create(&g_WSocket);
				}
				break;
			}
		}
		break;
	case WM_CLOSE:
		{
PostQuitMessage(0);
		}
		break;
	case WM_DESTROY:
		{
PostQuitMessage(0);
		}
		break;
	default:
		return DefWindowProc(hWnd,u_msg,wParam,lParam);
	}
	return 0;
}