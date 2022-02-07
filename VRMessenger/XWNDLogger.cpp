#include "XWND.h"

using namespace std;

#define LOG_ERROR 2
#define LOG_WARNING 1
#define LOG_OK 0 

void sLogInfo(char * prgmsg,int msgtype)
{
char szrMode[256];
#ifdef RELEASE
	strcpy(szrMode,"Release");
#else 
	strcpy(szrMode,"Debug");
#endif
	SYSTEMTIME systime;
	GetSystemTime(&systime);
	ofstream of("Info.log",ios::in);
	switch(msgtype)
	{
	case LOG_OK:
		{
	of << szrMode << "[" << systime.wHour + 6 << ":" << systime.wMinute << ":" << systime.wSecond << "]" << ": " << prgmsg << "\n";
		}
		break;
	case LOG_WARNING:
		{
	of << szrMode << "[" << systime.wHour + 6 <<  ":" << systime.wMinute << ":" << systime.wSecond << "]" << ": " << "<Warning> " << prgmsg << "\n";
		}
		break;
	case LOG_ERROR:
		{
	of << szrMode << "[" << systime.wHour + 6 << ":" << systime.wMinute << ":" << systime.wSecond << "]" << ": " << "<Error> " << prgmsg << "\n";
		}
		break;
	}
	of.close();
}