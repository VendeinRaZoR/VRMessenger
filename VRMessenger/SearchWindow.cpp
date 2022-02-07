#include "SearchWindow.h"
#include "XWND.h"
#include "XWNDGUI.h"

#define ID_BUTTON01 0
#define ID_BUTTON02 4
#define ID_EDITBOX01 2
#define ID_LISTBOX01 3

CGUIManager *c_schwGUIManager;
CClientMessage * c_ClientMessages;
HWND hEditBox[32];
HWND hButton[32];
HWND hListBox[32];
CWinSockets csw_wsSocket;

CSearchWindow::CSearchWindow()
{
	c_schwGUIManager = new CGUIManager();
	strcpy(szwClassName,"SearchwClass");
	strcpy(szwWindowName,"Поиск пользователей");
}

CSearchWindow::~CSearchWindow()
{
}

BOOL CSearchWindow::Create(CWinSockets * c_wsSocket)
{
	csw_wsSocket = *c_wsSocket;
	XWNDSetWindowSize(300,200);
	if(XWNDCreateWindow(SearchWndProc,szwClassName,szwWindowName,true,true))
	{
		return 0;
	}
	return 1;
}

LRESULT CALLBACK SearchWndProc(HWND hWnd,UINT u_msg,WPARAM wParam,LPARAM lParam)
{
	switch(u_msg)
	{
	case WM_CREATE:
		{
	c_schwGUIManager->InitCommonGUI(hWnd);
	XWNDSetWndBackground(hWnd);
	hButton[0] = c_schwGUIManager->sButton.CreateButton(ID_BUTTON01,BS_STANDARTBUTTON,70,40,150,30,"Найти пользователя");
	hEditBox[0] = c_schwGUIManager->sEditBox.CreateEditBox(ID_EDITBOX01,ES_STANDARTEDITBOX,55,20,180,20,"Имя пользователя");
	hListBox[0] = c_schwGUIManager->sListBox.CreateListBox(ID_LISTBOX01,20,80,250,50);
	hButton[1] = c_schwGUIManager->sButton.CreateButton(ID_BUTTON02,BS_STANDARTBUTTON,100,140,170,25,"Добавить пользователя");
	EnableWindow(hButton[1],0);
		}
		break;
	case WM_DESTROY:
	PostQuitMessage(0);
	break;
	case WM_COMMAND:
		{
switch(wParam)
{
case ID_EDITBOX01:
	{
	}
 break;
case ID_BUTTON01:
	{
		char szlbstr[256];
		char szblbstr[256];
		GetWindowText(hEditBox[0],szlbstr,50);
		if(strcmp(szlbstr,"")==0)
		{
			csw_wsSocket.Client_SendMessage("-user_search_all");
		}
		if(strcmp(szlbstr,"Имя пользователя")==0)
		{
			MessageBox(0,"Введите имя пользователя","Ошибка",MB_ICONWARNING);
		}
		else
		{
			sprintf(szblbstr,"-user_search %s",szlbstr);
			csw_wsSocket.Client_SendMessage(szblbstr);
		}
	}
		}break;
	case ID_BUTTON02:
		{
		}
		break;
	case ID_LISTBOX01:
		{
		}
		break;
	default:
		return DefWindowProc(hWnd,u_msg,wParam,lParam);
	}
	}
	return 0;
}