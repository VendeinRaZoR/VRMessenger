#include "LoginWindow.h"
#include "XWNDGUI.h"

CLoginWindow::CLoginWindow()
{
	hInst = g_wMsg.GetHInst();
	strcpy(szwClassName,"VRClass");
	strcpy(szwWindowName,"VRM Client v 0.1");
}

CLoginWindow::~CLoginWindow()
{
}

BOOL CLoginWindow::Create()
{
XWNDSetWindowSize(170,340);
XWNDSetWindowPosition(200,10,0);
if(!XWNDCreateWindow(XWNDStaticWndProc,szwClassName,szwWindowName,
true,true))
return 0;
UINT PosX;
UINT PosY;
char testch[256];
ZeroMemory(testch,sizeof(testch));
XWNDGetWindowPosition(&PosX,&PosY);
sprintf(testch,"%.u",PosX);
sLogInfo(testch,0);
return 1;
}

