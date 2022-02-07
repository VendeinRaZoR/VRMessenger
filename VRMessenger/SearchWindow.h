#include "ClientCommands.h"

LRESULT CALLBACK SearchWndProc(HWND hWnd,UINT u_msg,WPARAM wParam,LPARAM lParam);

class CSearchWindow
{
public:
CSearchWindow();
~CSearchWindow();
BOOL Create(CWinSockets * c_wsSocket);
private:
	char szwClassName[256];
	char szwWindowName[256];
	HWND hWnd;
	MSG msg;
	HINSTANCE hInst;
};