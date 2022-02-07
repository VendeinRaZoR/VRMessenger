#include "ProgBase.h"

class CClientWndCmds
{
public:
CClientWndCmds();
~CClientWndCmds();
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
char usernick[256];
void WM_SetParametrName(char * _usernick);
};