#include "ClientWindow.h"

//------------GUI parts-------------------
#define ID_EDITBOX01 3
#define ID_EDITBOX02 4
#define ID_CHECKBOX 5
#define ID_STATIC01 0
#define ID_STATIC02 6
#define ID_STATUSBAR 7
#define ID_PROGRESSBAR 8
//------------GUI parts-------------------

class CWinMessages
{
public:
	CWinMessages();
	~CWinMessages();
void WM_OnChar(HWND hwnd, UINT ch, int cRepeat);
void __stdcall WM_OnCommand(HWND hwnd, int id,HWND hwndCtl, UINT codeNotify);
void WN_OnCTLColor(HWND hwnd, HDC hdc, HWND hwndCtl, int constld);
BOOL WM_OnCreate(HWND hwnd,CREATESTRUCT FAR* lpCreateStruct);
void WM_OnDestroy(HWND hwnd);
void WM_OnGetMinMaxInfo(HWND hwnd,MINMAXINFO FAR* ipMinMaxInfo);
BOOL WM_OnInitDialog(HWND hwnd,HWND hwndFocus, LPARAM lParam);
void WM_OnKeyDown(HWND hwnd, UINT vk,BOOL fflown, int cRepeat, UINT flags);
void WM_OnKeyUp(HWND hwnd, UINT vk,BOOL fDown, int cRepeat, UINT flags);
void WM_OnKillFocus(HWND hwnd,HWND hwndNewFocus);
void WM_OnLButtonDown(HWND hwnd,BOOL fDoubleClick, int x, int y, UINT keyFlags);
void WM_OnLButtonUp(HWND hwnd, int x, int y,UINT keyFlags);
void WM_OnMouseMove(HWND hwnd, int x, int y,UINT keyFlags);
BOOL WM_OnNotify(HWND hwnd, INT idCtrl, NMHDR* pnmh);
void WM_OnPaint(HWND hwnd);
void WM_OnQuit(HWND hwnd, int exitCode);
void WM_OnRButtonDown(HWND hwnd,
BOOL ffioubleClick, int x, int y, UINT keyFlags);
void WM_OnRButtonUp(HWND hwnd, int x, int y,UINT flags);
BOOL WM_OnSetCursor(HWND hwnd,HWND hwndCursor, UINT codeHitTest, UINT msg);
void WM_OnSetFocus(HWND hwnd,HWND hwndOldFocus);
void WM_OnShowWindow(HWND hwnd, BOOL fShow,UINT status);
void WM_OnSize(HWND hwnd, UINT state,int ex, int cy);
void WM_OnSysChar(HWND hwnd, UINT ch,int cRepeat);
void WM_OnSysCommand(HWND hwnd, UINT cmd,int x, int y);
void WM_OnSysKey(HWND hwnd, UINT vk,BOOL fDown, int cRepeat, UINT flags);
void WM_OnTimer(HWND hwnd, UINT id);
void SetMainWindow(HWND Window);
HINSTANCE GetHInst();
private:
	HINSTANCE hInst;
	char szbClassName[256];
	int nTextLimit;
	char szwLoginMessage[256];
	char strlogin[256];
	char strpassw[256];
	CWinSockets c_wSocket;
private:
BOOL CreateGUIElements();
HWND hEditBox[32];
HWND hButton[32];
HWND hStatusBar[32];
HWND hProgressBar[32];
HWND hCheckBox[32];
HWND hStatic[32];
};