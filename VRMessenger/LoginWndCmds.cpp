#include "LoginWndCmds.h"
#include "DefWinButtons.h"
#include "OptionsWindow.h"
#include "WinLog.h"
#include "ClientWndCmds.h"
#include "XWND.h"
#include "XWNDGUI.h"

CGUIManager c_wGUIManager;
CClientWindow c_ClientWindow;
COptionsWindow c_OptionsWindow;

CWinMessages::CWinMessages()
{
	Buttons buttons;
	hInst = 0;
	nTextLimit = 14;
	strcpy(strlogin,"Введите Логин");
	strcpy(strpassw,"Введите Пароль");
}

CWinMessages::~CWinMessages()
{
}

void CWinMessages::WM_OnChar(HWND hwnd,UINT ch,int cRepeat)
{
}

void __stdcall CWinMessages::WM_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
switch(LOWORD(id))
{
case ID_BUTTON01:
	{
	if(strcmp(strlogin,"Введите Логин") == 0 || strcmp(strlogin,"") == 0)
	{
	MessageBox(0,"Введите Ваш Логин","Ошибка",0);
	}
	else if(strcmp(strpassw,"Введите Пароль") == 0 || strcmp(strpassw,"") == 0)
	{
    MessageBox(0,"Введите Ваш Пароль","Ошибка",0);
	}
	else
	{
		if(c_wSocket.Client_Initialize())
		{
			EnableWindow(hButton[0],0);
			EnableWindow(hEditBox[0],0);
			EnableWindow(hEditBox[1],0);
			EnableWindow(hCheckBox[0],0);
			SetWindowText(hStatusBar[0],"Инициализация подключения...");
		}
		else
		{
			SetWindowText(hStatusBar[0],"=Версия 0.1 Alpha=");
		}
		if(c_wSocket.Client_Create())
		{
			SetWindowText(hStatusBar[0],"Создание подключения...");
		}
		else
		{ 
			SetWindowText(hStatusBar[0],"=Версия 0.1 Alpha=");
		}
		char servmsg[256];
		if(c_wSocket.Client_ConnectServer(1))
		{
		c_wSocket.Client_SendMessage("-signup\0");
		c_wSocket.Client_SendMessage(strlogin);
		c_wSocket.Client_SendMessage(strpassw);
		if(!c_wSocket.Client_GetMessage(servmsg))
		{
			sLogInfo("No bytes was recved",2);
		}
		}
			    else 
		{
			c_wSocket.Client_DestroySock();
			EnableWindow(hButton[0],1);
			EnableWindow(hEditBox[0],1);
			EnableWindow(hEditBox[1],1);
			EnableWindow(hCheckBox[0],1);
			SetWindowText(hStatusBar[0],"=Версия 0.1 Alpha=");
		}
        if(strcmp(servmsg,"-suerror") == 0)
		{
		c_wSocket.Client_DestroySock();
        MessageBox(0,"Неверный Логин или Пароль","Подлючение",MB_ICONWARNING);
		EnableWindow(hButton[0],1);
	    EnableWindow(hEditBox[0],1);
		EnableWindow(hEditBox[1],1);
		EnableWindow(hCheckBox[0],1);
		SetWindowText(hStatusBar[0],"=Версия 0.1 Alpha=");
		}
		else
		{sLogInfo("System Error",1);}
		if(strcmp(servmsg,"-susuccess") == 0)
		{
		c_wSocket.Client_SendMessage("-login");
		DestroyWindow(hwnd);
		c_wSocket.Client_GetMessage(c_ClientWindow.s_ClientInfo.szusernick);
	    c_ClientWindow.Create(&c_wSocket);
		SetWindowText(hStatusBar[0],"Установка соединения...");
		}
		else
		{sLogInfo("System Error",1);}
	}
	}
break;
case ID_BUTTON02:
	{
EnableWindow(hButton[1],0);
if(!c_OptionsWindow.Create())
{
	EnableWindow(hButton[1],1);
}
	}
break;
case ID_BUTTON03:
	{
PostQuitMessage(0);
	}
break;
case ID_EDITBOX01:
{
GetWindowText(hEditBox[0],strlogin,256);
}break;
case ID_EDITBOX02:
{
GetWindowText(hEditBox[1],strpassw,256);
}break;
default:
	{
	}
}
}

BOOL CWinMessages::WM_OnCreate(HWND hwnd, CREATESTRUCT *lpCreateStruct)
{
	c_wGUIManager.InitCommonGUI(hwnd);
	XWNDSetWndBackground(hwnd);
	CreateGUIElements();
	SendMessage(hCheckBox[0],BM_SETCHECK,TRUE,0);
	SendMessage(hEditBox[0],EM_LIMITTEXT,nTextLimit,0);
	SendMessage(hEditBox[1],EM_LIMITTEXT,nTextLimit,0);
	sLogInfo("Window Created",0);
	return 1;
}

void CWinMessages::WM_OnDestroy(HWND hwnd)
{
	PostQuitMessage(0);
}

void CWinMessages::WM_OnGetMinMaxInfo(HWND hwnd, MINMAXINFO *ipMinMaxInfo)
{
}

void CWinMessages::WM_OnPaint(HWND hwnd)
{
}

HINSTANCE CWinMessages::GetHInst()
{
	return hInst;
}

void CWinMessages::WM_OnLButtonDown(HWND hwnd, BOOL ffioubleClick, int x, int y, UINT keyFlags)
{
}

BOOL CWinMessages::CreateGUIElements()
{
	hButton[3] = c_wGUIManager.sButton.CreateButton(ID_BUTTON01,BS_STANDARTGROUPBOX,3,0,155,120,"Вход");
    hEditBox[0] = c_wGUIManager.sEditBox.CreateEditBox(ID_EDITBOX01,ES_STANDARTEDITBOX,20,20,120,20,strlogin);
	hEditBox[1] = c_wGUIManager.sEditBox.CreateEditBox(ID_EDITBOX02,ES_STANDARTEDITBOX,20,55,120,20,strpassw);
	hCheckBox[1] = c_wGUIManager.sButton.CreateButton(ID_CHECKBOX,BS_STANDARTGROUPBOX,10,120,140,160,"Действие");
	hButton[0] = c_wGUIManager.sButton.CreateButton(ID_BUTTON01,BS_STANDARTBUTTON,30,140,100,30,"Подключение");
	hButton[1] = c_wGUIManager.sButton.CreateButton(ID_BUTTON02,BS_STANDARTBUTTON,30,190,100,30,"Настройки");
	hButton[2] = c_wGUIManager.sButton.CreateButton(ID_BUTTON03,BS_STANDARTBUTTON,30,240,100,30,"Выход");
	hCheckBox[0] = c_wGUIManager.sRadioButton.CreateRadioButton(ID_BUTTON04,10,80,140,20,"Запомнить пароль");
	hStatusBar[0] = c_wGUIManager.sStatusBar.CreateStatusBar(ID_STATUSBAR,0,0,1000,1000,"=Версия 0.1 Alpha=");
	return 1;
}



