#include "XWND.h"

#define DEFAULTPORT 666
#define DEFAULTSERVERIP "127.0.0.1"

class CWinSockets
{
public:
	CWinSockets();
	~CWinSockets();
	bool Client_Initialize();
	bool Client_Create();
	bool Client_ConnectServer(bool displaymsg);
	bool Client_SendMessage(char * szsendbuff);
	bool Client_DestroySock();
	bool Client_GetMessage(char * message);
	void Client_ConnectDefaultNoMessage();
	void Client_ConnectDefault();
	bool Client_IsConnected();
private:
	CLIENTSOCKET ws_sock;
	char sz_buff[1024];
	char sz_initerror[256];
	char sz_createerror[256];
	char sz_connecterror[256];
	char szkey_options[256];
	char SERVERADDR[256];
	sockaddr_in dest_addr;
	HOSTENT *hst;
	int nsize;
};
