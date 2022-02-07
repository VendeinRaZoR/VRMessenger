#include "XWND.h"
#include "LoginWndCmds.h"

class CLoginWindow
{
public:
	CLoginWindow();
	~CLoginWindow();
	BOOL Create();
	CWinMessages g_wMsg;
private:
	MSG msg;
	CHAR szwClassName[256];
	HWND hWnd;
    HINSTANCE hInst;
    CHAR szwWindowName[256];
};