#include "WinSockets.h"

class CClientMessage
{
public:
CClientMessage();
~CClientMessage();
void Command_SignUp(char * psz_strlogin,char * psz_strpassw);
void GetWinSocket(CWinSockets wc_wSocket);
struct CLIENTINFO
{
	char m_name[256];
	char m_lastname[256];
	char m_nick[256];
	char m_birthdate[256];
	char m_password[256];
	char m_email[265];
}*CLIENTINFO,s_ClientInfo;
private:
char m_szservmsg[256];
char m_szclientinfo[265];
CWinSockets g_wSocket;
};