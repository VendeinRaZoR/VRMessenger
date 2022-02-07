#include "XWND.h"

#define ID_STATIC 0
#define ID_STATIC01 1
#define ID_STATIC02 7
#define ID_STATIC03 22
#define ID_STATIC04 23
#define ID_STATIC05 24
#define ID_STATIC06 25
#define ID_STATIC07 26
#define ID_STATIC08 27
#define ID_EDITBOX01 2
#define ID_GROUPBOX01 3
#define ID_GROUPBOX02 12
#define ID_LISTBOX 11
#define ID_CHECKBOX 5
#define ID_CHECKBOX01 10
#define ID_BUTTON01 6
#define ID_BUTTON02 9
#define ID_EDITBOX02 8
#define ID_EDITBOX03 13
#define ID_EDITBOX04 14
#define ID_EDITBOX05 15
#define ID_EDITBOX06 17
#define ID_EDITBOX07 18
#define ID_EDITBOX08 19
#define ID_BUTTON03 16
#define ID_BUTTON04 28
#define ID_GROUPBOX03 20
#define ID_GROUPBOX04 21

using namespace std;

class COptionsWndCmds
{
public:
	COptionsWndCmds();
	~COptionsWndCmds();
void WM_OnChar(HWND hwnd, UINT ch, int cRepeat);
void WM_OnCommand(HWND hwnd, int id,HWND hwndCtl, UINT codeNotify);
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
private:
//----------------------Files---------------------------
FILE *file;
int nsport;
int nregcouner;
//----------------------Files---------------------------
private:
///-----------------------Options----------------------------
int SetWndCheckBoxState(HWND CheckBox,int ndefstate,char *szappfrom,char* szkeyname);
BOOL CreateGUIElement();
void CreateRegPanel();
HWND hListBox[32];
HWND hCheckBox[32];
HWND hEditBox[32];
HWND hStatic[32];
HWND hButton[32];
///-----------------------Options----------------------------
private:
//----------------------EnablePasses-------------------------
void vPass1();
void vPass2();
void vPass3();
void vPass4();
void vPass5();
//----------------------EnablePasses-------------------------
private:
///----------------------------------------------------------
	char szcon[256];
	char szcom[256];
	char szreg[256];
	char szstyle[256];
	char szoc[256];
	char szport[256];
	char szipst[256];
	char szsendf[256];
	char szwsavech[256];
	char szwclose[256];
	char szdopt1[256];
	char szdopt2[256];
	char szopt_defip[256];
	char szdef_port[256];
	char szservip[256];
	char szkey_options[256];
///==============================RegistrationWindowStrings=========================
	char regfield01[256];
	char regfield02[256];
	char regfield03[256];
	char regfield04[256];
	char regfield05[256];
	char regfield06[256];
	char regfield07[256];
///==============================RegistrationWindowStrings=========================
char szucpath[256];
char szuc_directory[256];
char szdefnick[256];
char szdefpassword[256];
char szdemail[256];
char szdbirthd[256];
///----------------------------------------------------------
};