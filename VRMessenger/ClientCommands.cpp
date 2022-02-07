#include "ClientCommands.h"
#include "XWNDGUI.h"

CClientMessage::CClientMessage()
{ 
}

CClientMessage::~CClientMessage()
{
}

void CClientMessage::Command_SignUp(char * psz_strlogin,char * psz_strpassw)
{
}

void CClientMessage::GetWinSocket(CWinSockets wc_wSocket)
{
	g_wSocket = wc_wSocket;
}
