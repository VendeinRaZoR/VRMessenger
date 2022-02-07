#include "ClientWndCmds.h"
#include "ClientMessages.h"
#include "ClientWindow.h"

CClientMessage *c_ClientMessage;
CClientWindow c_ClientWindows;


CClientWndCmds::CClientWndCmds()
{
}

CClientWndCmds::~CClientWndCmds()
{
}

BOOL CClientWndCmds::WM_OnCreate(HWND hwnd, CREATESTRUCT *lpCreateStruct)
{

	return 1;
}

void CClientWndCmds::WM_OnDestroy(HWND hwnd)
{
	PostQuitMessage(0);
}

void CClientWndCmds::WM_OnQuit(HWND hwnd, int exitCode)
{
	PostQuitMessage(0);
}

void CClientWndCmds::WM_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{

}
