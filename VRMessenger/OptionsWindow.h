#include "XWND.h"

LRESULT WINAPI OptWndProc(HWND hWnd,UINT u_msg,WPARAM wParam,LPARAM lParam);

class COptionsWindow
{
public:
COptionsWindow();
~COptionsWindow();
BOOL Create();
private:
	MSG msg;
	char szwClassName[256];
	HWND hWnd;
    char szwWindowName[256];
	HINSTANCE hInst;
};