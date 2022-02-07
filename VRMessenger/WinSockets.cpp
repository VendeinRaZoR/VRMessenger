#include "OptionsWndCmds.h"
#include "INIReader.h"
#include "WinSockets.h"

COptionsWndCmds c_OptWndCmds;
CINIFile c_wsINIFile;

CWinSockets::CWinSockets()
{
sprintf(sz_initerror,"Проблема инициализации\nподключения \n Код:%d",WSAGetLastError());
sprintf(sz_createerror,"Проблема создания подключения \n Код:%d",WSAGetLastError());
sprintf(sz_connecterror,
"Проблема подключения к серверу \nКод:%d\nВозможно сервер недоступен или отключен\n(см. настройки)",
WSAGetLastError());
strcpy(szkey_options,"options");
c_wsINIFile.OpenINIFile("./Options.ini");
}

CWinSockets::~CWinSockets()
{
}

bool CWinSockets::Client_Initialize()
{
    if(WSAStartup(0x202,(WSADATA *)&sz_buff[0]))
    {	
	MessageBox(0,sz_initerror,"Инициализация",MB_ICONERROR);
    return -1;
    }
	return 1;
}

bool CWinSockets::Client_Create()
{
    ws_sock=socket(AF_INET,SOCK_STREAM,0);
    if (ws_sock < 0)
    {
      MessageBox(0,sz_createerror,"Создание",MB_ICONERROR);
      return -1;
    }
	return 1;
}

bool CWinSockets::Client_ConnectServer(bool displaymsg)
{
	strcpy(SERVERADDR,c_wsINIFile.GetChar(szkey_options,"server",DEFAULTSERVERIP));
	u_short usport;
	usport = c_wsINIFile.GetInt(szkey_options,"port",DEFAULTPORT);
    dest_addr.sin_family=AF_INET;
    dest_addr.sin_port=htons(usport);
	if (inet_addr(SERVERADDR)!=INADDR_NONE)
      dest_addr.sin_addr.s_addr=inet_addr(SERVERADDR);
    else
      if (hst=gethostbyname(SERVERADDR))
      ((unsigned long *)&dest_addr.sin_addr)[0]=
        ((unsigned long **)hst->h_addr_list)[0][0];
      else 
      {
        closesocket(ws_sock);
        WSACleanup();
        return -1;
      }
    while(connect(ws_sock,(sockaddr *)&dest_addr,
                sizeof(dest_addr)))
    {
		if(displaymsg)
		{
      MessageBox(0,sz_connecterror,"Подлючение",MB_ICONWARNING);
		}
      return 0;
    }
	return 1;
}

bool CWinSockets::Client_SendMessage(char * szsendbuff)
{
	send(ws_sock,szsendbuff,strlen(szsendbuff)+1,0);
	return 1;
}

int bytes;
bool CWinSockets::Client_GetMessage(char * message)
{
if(recv(ws_sock,&message[0],sizeof(message)+256,0)==0)
return false;
else
return true;
}

bool CWinSockets::Client_DestroySock()
{
	if(closesocket(ws_sock)!=0)
	return true;
	else
    return false;
}

void CWinSockets::Client_ConnectDefault()
{
	Client_Initialize();
	Client_Create();
	Client_ConnectServer(1);
}

void CWinSockets::Client_ConnectDefaultNoMessage()
{
	Client_Initialize();
	Client_Create();
	Client_ConnectServer(0);
}

bool CWinSockets::Client_IsConnected()
{
	if(ws_sock != 0)
	{return 1;}
    else{return 0;}
}