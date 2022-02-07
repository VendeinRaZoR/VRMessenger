#include "XWND.h"
#include "SearchWindow.h"

#define ID_LISTBOX01 0
#define ID_BUTTON01 100

LRESULT WINAPI ClWndProc(HWND hWnd,UINT u_msg,WPARAM wParam,LPARAM lParam);

class CClientWindow
{
public:
	CClientWindow();
	~CClientWindow();
	BOOL Create(CWinSockets  *p_wSocket);
	struct CLIENTINFO
	{
	char szusernick[256];
	}s_ClientInfo;
private:
	HWND hClWindow;
	HINSTANCE hClInst;
};
