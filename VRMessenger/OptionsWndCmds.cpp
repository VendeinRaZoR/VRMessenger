#include "OptionsWndCmds.h"
#include "INIReader.h"
#include "LoginWndCmds.h"
#include "XWNDGUI.h"

CGUIManager *c_oGUIManager;
CWinMessages *c_olWinMsg;
CWinSockets *c_oWinSock;
CINIFile *c_oINIReader;
CINIFile *c_uINIFile;

COptionsWndCmds::COptionsWndCmds()
{
c_oGUIManager = new CGUIManager();
c_olWinMsg = new CWinMessages();
c_oWinSock = new CWinSockets();
c_oINIReader = new CINIFile();
c_uINIFile = new CINIFile();
strcpy(szcon,"Подключение");
strcpy(szcom,"Общее");
strcpy(szreg,"Регистрация");
strcpy(szstyle,"Стили");
strcpy(szoc,"Использовать следующие настройки (IP сервера) :");
strcpy(szport,"Порт сервера :");
strcpy(szipst,"Использовать IP по умолчанию");
strcpy(szsendf,"Передавать файлы друг другу");
strcpy(szwsavech,"Сохранить изменения");
strcpy(szwclose,"Закрыть");
strcpy(szdopt1,"0");
strcpy(szdopt2,"0");
strcpy(szdefpassword,"password");
strcpy(szdemail,"E-Mail");
strcpy(szdbirthd,"дд/мм/гггг");
strcpy(szkey_options,"options");
c_oINIReader->OpenINIFile("./Options.ini");
}//InitializeVariables

COptionsWndCmds::~COptionsWndCmds()
{
	ZeroMemory(szcon,sizeof(szcon));
	ZeroMemory(szcom,sizeof(szcom));
	ZeroMemory(szreg,sizeof(szreg));
	ZeroMemory(szstyle,sizeof(szstyle));
	ZeroMemory(szoc,sizeof(szoc));
	ZeroMemory(szport,sizeof(szport));
	ZeroMemory(szipst,sizeof(szipst));
	ZeroMemory(szsendf,sizeof(szsendf));
	ZeroMemory(szwsavech,sizeof(szwsavech));
	ZeroMemory(szwclose,sizeof(szwclose));
	ZeroMemory(szdopt1,sizeof(szdopt1));
	ZeroMemory(szdopt2,sizeof(szdopt2));
	ZeroMemory(hEditBox,sizeof(hEditBox));
	ZeroMemory(hButton,sizeof(hButton));
	ZeroMemory(hCheckBox,sizeof(hCheckBox));
	ZeroMemory(hStatic,sizeof(hStatic));
	ZeroMemory(hListBox,sizeof(hListBox));
	delete c_oGUIManager;
	delete c_olWinMsg;
	delete c_oWinSock;
	delete c_oINIReader;
	delete c_uINIFile;
	c_oGUIManager = 0;
	c_olWinMsg = 0;
    c_oWinSock = 0;
	c_oINIReader = 0;
	c_uINIFile = 0;
}//ClearAll

void COptionsWndCmds::WM_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
//==================================BEGIN_WNDCOMMANDS=================================
	switch(LOWORD(id))
	{
//=================================================================
//==============================LISTBOX_BEGIN============================
//=================================================================
	case ID_LISTBOX:{
	if(SendMessage(hListBox[0],LB_GETSEL,0,0)){vPass2();}
	if(SendMessage(hListBox[0],LB_GETSEL,1,0)){vPass3();}
	if(SendMessage(hListBox[0],LB_GETSEL,2,0)){vPass4();}
	if(SendMessage(hListBox[0],LB_GETSEL,3,0)){vPass5();}}break;
//=================================================================
//==============================LISTBOX_END============================
//=================================================================
//-----------------------------------------------------------------
		case ID_BUTTON01://SaveChanges
			{
c_oINIReader->WriteChar(szkey_options, "server", szservip);
c_oINIReader->WriteChar(szkey_options, "port", szdef_port);
c_oINIReader->WriteChar(szkey_options,"ip_default",szdopt2);
c_oINIReader->WriteChar(szkey_options,"send/recieve_files",szdopt1);
			}
			break;
//-----------------------------------------------------------------
			case ID_BUTTON02://Close
			{
DestroyWindow(hwnd);
PostQuitMessage(0);
			}
			break;
//-----------------------------------------------------------------
case ID_CHECKBOX:{//DefaultIPSetup
if(Button_GetCheck(hCheckBox[0]) == BST_CHECKED){
EnableWindow(hEditBox[0],0);
EnableWindow(hStatic[0],0);
EnableWindow(hEditBox[1],0);
EnableWindow(hStatic[1],0);
strcpy(szdopt2,"1");
strcpy(szservip,"127.0.0.1");
strcpy(szdef_port,"666");}
else{
EnableWindow(hEditBox[0],1);
EnableWindow(hStatic[0],1);
EnableWindow(hEditBox[1],1);
EnableWindow(hStatic[1],1);
strcpy(szdopt2,"0");}}break;
//-----------------------------------------------------------------
case ID_CHECKBOX01:{//SendFiles
if(Button_GetCheck(hCheckBox[1]) == BST_CHECKED)
strcpy(szdopt1,"1");
else 
strcpy(szdopt1,"0");}break;
//-----------------------------------------------------------------
case ID_BUTTON03://Register
			{
nregcouner=0;
if(strcmp(szdefnick,regfield01) == 0 || strcmp("",regfield01) == 0)
{
MessageBox(0,"Введите СВОЙ ник","Ошибка",MB_ICONWARNING);
}
else
{
    nregcouner+=1;
}
if(strcmp(szdefpassword,regfield05) == 0 || strcmp("",regfield05) == 0)
{
MessageBox(0,"Введите ваш пароль","Ошибка",MB_ICONWARNING);
}
else
{
    nregcouner+=1;
}
if(strcmp(szdemail,regfield04) == 0 || strcmp("",regfield04) == 0)
{
MessageBox(0,"Введите свой E-Mail","Ошибка",MB_ICONWARNING);
}
else
{
	nregcouner+=1;
}
if(strcmp(szdbirthd,regfield06) == 0 || strcmp("",regfield06) == 0)
{
MessageBox(0,"Введите дату своего рождения","Ошибка",MB_ICONWARNING);
}
else
{
	nregcouner+=1;
}
if(nregcouner >= 4)
{
c_oWinSock->Client_Initialize();
c_oWinSock->Client_Create();
if(c_oWinSock->Client_ConnectServer(0)){
EnableWindow(hButton[3],0);
if(CreateDirectory(szuc_directory,NULL)){
c_uINIFile->OpenINIFile(szucpath);
c_uINIFile->WriteChar("UserConfigs", "usernick", regfield01);
c_uINIFile->WriteChar("UserConfigs", "userpassword", regfield05);
c_oWinSock->Client_SendMessage("-register\0");
c_oWinSock->Client_SendMessage(regfield01);
c_oWinSock->Client_SendMessage(regfield02);
c_oWinSock->Client_SendMessage(regfield03);
c_oWinSock->Client_SendMessage(regfield04);
c_oWinSock->Client_SendMessage(regfield05);
c_oWinSock->Client_SendMessage(regfield06);
c_oWinSock->Client_DestroySock();
MessageBox(0,"Вы успешно зарегестрировались ! Спасибо !","Регистрация",0);}
else{
EnableWindow(hButton[3],1);
MessageBox(0,"Такой пользователь \nуже существует","Ошибка",MB_ICONWARNING);}
c_oWinSock->Client_DestroySock();}
else{
EnableWindow(hButton[3],1);
MessageBox(0,"Ошибка отправки данных","Ошибка",MB_ICONWARNING);}}
			}
			break;
//-------------------------------ID_EDITBOX01----------------------------------
		case ID_EDITBOX01:
			{
		GetWindowText(hEditBox[0],szservip,sizeof(szservip));
			}
			break;
//----------------------------------ID_EDITBOX02-------------------------------
		case ID_EDITBOX02:
			{
        GetWindowText(hEditBox[1],szdef_port,sizeof(szdef_port));
			}
			break;
//----------------------------------ID_EDITBOX03-------------------------------
		case ID_EDITBOX03:
			{
		strcpy(szdefnick,"DefaultUser");
        GetWindowText(hEditBox[2],regfield01,sizeof(regfield01));
		sprintf(szuc_directory,"%s",regfield01);
		sprintf(szucpath,"./%s/UserCfg.ini",regfield01);
			}
			break;
//----------------------------------ID_EDITBOX04-------------------------------
		case ID_EDITBOX04:
			{
        GetWindowText(hEditBox[3],regfield02,sizeof(regfield02));
			}
			break;
//----------------------------------ID_EDITBOX05-------------------------------
		case ID_EDITBOX05:
			{
        GetWindowText(hEditBox[4],regfield03,sizeof(regfield03));
			}
			break;
//----------------------------------ID_EDITBOX06-------------------------------
		case ID_EDITBOX06:
			{
        GetWindowText(hEditBox[5],regfield04,sizeof(regfield04));
			}
			break;
//----------------------------------ID_EDITBOX07-------------------------------
	    case ID_EDITBOX07:
			{
        GetWindowText(hEditBox[6],regfield05,sizeof(regfield05));
			}
			break;
//----------------------------------ID_EDITBOX08-------------------------------
	    case ID_EDITBOX08:
			{
        GetWindowText(hEditBox[7],regfield06,sizeof(regfield06));
			}
			break;
	}
//==================================END_COMMANDS=================================
}

BOOL COptionsWndCmds::WM_OnCreate(HWND hwnd, CREATESTRUCT *lpCreateStruct)  //CheckPoint of Window and GUI
{
	c_oGUIManager->InitCommonGUI(hwnd);//InitializeGUI
	CreateGUIElement();//CreateElements
	CreateRegPanel();//CreateRegPanelElements
	SendMessage(hListBox[0],LB_ADDSTRING,0,(LPARAM)szcom);
	SendMessage(hListBox[0],LB_ADDSTRING,0,(LPARAM)szcon);
	SendMessage(hListBox[0],LB_ADDSTRING,0,(LPARAM)szreg);
	SendMessage(hListBox[0],LB_ADDSTRING,0,(LPARAM)szstyle);
	SendMessage(hListBox[0],LB_SETCURSEL,0,0);
	strcpy(szservip,c_oINIReader->GetChar(szkey_options,"server","127.0.0.1"));
	nsport = c_oINIReader->GetInt(szkey_options,"port",666);
	sprintf(szdef_port,"%.i",nsport);
	Edit_SetText(hEditBox[0],szservip);
	Edit_SetText(hEditBox[1],szdef_port);
	vPass1();
int chbst01 = SetWndCheckBoxState(hCheckBox[0],1,szkey_options,"ip_default");
if(chbst01 == BST_CHECKED){
EnableWindow(hEditBox[0],0);
EnableWindow(hStatic[0],0);
EnableWindow(hEditBox[1],0);
EnableWindow(hStatic[1],0);}
else{
EnableWindow(hEditBox[0],1);
EnableWindow(hStatic[0],1);
EnableWindow(hEditBox[1],1);
EnableWindow(hStatic[1],1);}
SetWndCheckBoxState(hCheckBox[1],0,szkey_options,"send/recieve_files");
	return 1;
}

BOOL COptionsWndCmds::CreateGUIElement()
{
	//===================ListBoxElements=========================
	hStatic[2] = c_oGUIManager->sStatic.CreateStatic(ID_STATIC,BS_STANDARTSTATIC,0,0,1000,1000,0);
	hButton[2] = c_oGUIManager->sButton.CreateButton(ID_GROUPBOX01,BS_STANDARTGROUPBOX,5,5,380,380,"Настройки");
	hListBox[0] = c_oGUIManager->sListBox.CreateListBox(ID_LISTBOX,10,25,100,200);
	hButton[0] = c_oGUIManager->sButton.CreateButton(ID_BUTTON01,BS_STANDARTBUTTON,80,350,200,25,szwsavech);
	hButton[1] = c_oGUIManager->sButton.CreateButton(ID_BUTTON02,BS_STANDARTBUTTON,290,350,80,25,szwclose);
	hCheckBox[1] = c_oGUIManager->sRadioButton.CreateRadioButton(ID_CHECKBOX01,120,40,240,40,szsendf);
	hCheckBox[0] = c_oGUIManager->sRadioButton.CreateRadioButton(ID_CHECKBOX,130,30,225,40,szipst);
	hStatic[0] = c_oGUIManager->sStatic.CreateStatic(ID_STATIC01,BS_STANDARTSTATIC,130,70,140,70,szoc);
	hStatic[1] = c_oGUIManager->sStatic.CreateStatic(ID_STATIC02,BS_STANDARTSTATIC,250,70,80,70,szport);
	hEditBox[0] = c_oGUIManager->sEditBox.CreateEditBox(ID_EDITBOX01,ES_STANDARTEDITBOX,130,145,115,24,szservip);
	hEditBox[1] = c_oGUIManager->sEditBox.CreateEditBox(ID_EDITBOX02,ES_STANDARTEDITBOX,250,145,100,24,szdef_port);
	hButton[4] = c_oGUIManager->sButton.CreateButton(ID_GROUPBOX03,BS_STANDARTGROUPBOX,115,25,250,300,"Общее");
	hButton[5] = c_oGUIManager->sButton.CreateButton(ID_GROUPBOX04,BS_STANDARTGROUPBOX,115,15,250,300,"Настройки подключения к серверу");
	//===================ListBoxElements=========================
	return 1;
}

void COptionsWndCmds::CreateRegPanel()
{
//===================RegPanel=========================
hStatic[3] = c_oGUIManager->sStatic.CreateStatic(ID_STATIC03,BS_STANDARTSTATIC,130,45,100,24,"Ваш Ник :");
hStatic[4] = c_oGUIManager->sStatic.CreateStatic(ID_STATIC04,BS_STANDARTSTATIC,130,75,140,70,"Ваше Имя :");
hStatic[5] = c_oGUIManager->sStatic.CreateStatic(ID_STATIC05,BS_STANDARTSTATIC,130,105,140,70,"Ваша Фамилия :");
hStatic[6] = c_oGUIManager->sStatic.CreateStatic(ID_STATIC06,BS_STANDARTSTATIC,130,135,140,70,"Ваш E-Mail :");
hStatic[7] = c_oGUIManager->sStatic.CreateStatic(ID_STATIC07,BS_STANDARTSTATIC,130,165,140,70,"Ваш Пароль :");
hStatic[8] = c_oGUIManager->sStatic.CreateStatic(ID_STATIC08,BS_STANDARTSTATIC,130,200,140,70,"Дата Рождения :");
hButton[2] = c_oGUIManager->sButton.CreateButton(ID_GROUPBOX02,BS_STANDARTGROUPBOX,115,25,250,300,"Регистрация на сервере");
hEditBox[2] = c_oGUIManager->sEditBox.CreateEditBox(ID_EDITBOX03,ES_STANDARTEDITBOX,210,45,140,24,"DefaultUser");
hEditBox[3] = c_oGUIManager->sEditBox.CreateEditBox(ID_EDITBOX04,ES_STANDARTEDITBOX,250,75,100,24,"Имя");
hEditBox[4] = c_oGUIManager->sEditBox.CreateEditBox(ID_EDITBOX05,ES_STANDARTEDITBOX,250,105,100,24,"Фамилия");
hEditBox[5] = c_oGUIManager->sEditBox.CreateEditBox(ID_EDITBOX06,ES_STANDARTEDITBOX,220,135,130,24,"E-Mail");
hEditBox[6] = c_oGUIManager->sEditBox.CreateEditBox(ID_EDITBOX07,ES_STANDARTEDITBOX|ES_PASSWORD,230,165,120,24,szdefpassword);
hEditBox[7] = c_oGUIManager->sEditBox.CreateEditBox(ID_EDITBOX08,ES_STANDARTEDITBOX,250,195,100,24,"дд/мм/гггг");
hButton[3] = c_oGUIManager->sButton.CreateButton(ID_BUTTON03,BS_STANDARTBUTTON,150,280,200,25,"Зарегестрироваться");
}//===================RegPanel=========================
////////////////////////////////////////////////////////
//===================CheckPasses=========================
void COptionsWndCmds::vPass1()
{
	for(int i =0;i<32;i++)
	{
	ShowWindow(hEditBox[i], SW_HIDE);	
	ShowWindow(hCheckBox[i], SW_HIDE);
	ShowWindow(hButton[i], SW_HIDE);
	}
	ShowWindow(hCheckBox[1], SW_SHOWNORMAL);
	ShowWindow(hStatic[0], SW_HIDE);
	ShowWindow(hStatic[1], SW_HIDE);
	ShowWindow(hButton[4], SW_SHOWNORMAL);
	ShowWindow(hButton[1], SW_SHOWNORMAL);
	ShowWindow(hButton[0], SW_SHOWNORMAL);
	ShowWindow(hStatic[3], SW_HIDE);
	ShowWindow(hStatic[4], SW_HIDE);
	ShowWindow(hStatic[5], SW_HIDE);
	ShowWindow(hStatic[6], SW_HIDE);
	ShowWindow(hStatic[7], SW_HIDE);
	ShowWindow(hStatic[8], SW_HIDE);
}
void COptionsWndCmds::vPass2()
{
	for(int i =0;i<32;i++)
	{
	ShowWindow(hEditBox[i], SW_HIDE);	
	ShowWindow(hCheckBox[i], SW_HIDE);
	ShowWindow(hStatic[i], SW_HIDE);
	ShowWindow(hButton[i],SW_HIDE);
			}
	ShowWindow(hButton[4], SW_SHOWNORMAL);
	ShowWindow(hCheckBox[1], SW_SHOWNORMAL);
	ShowWindow(hStatic[0], SW_HIDE);
	ShowWindow(hStatic[1], SW_HIDE);
	ShowWindow(hStatic[2], SW_SHOWNORMAL);
	ShowWindow(hButton[1], SW_SHOWNORMAL);
	ShowWindow(hButton[0], SW_SHOWNORMAL);
}
void COptionsWndCmds::vPass3()
{
	for(int i =0;i<32;i++)
	{
	ShowWindow(hEditBox[i], SW_SHOWNORMAL);	
	ShowWindow(hCheckBox[i], SW_SHOWNORMAL);
	ShowWindow(hStatic[i], SW_SHOWNORMAL);
	ShowWindow(hButton[i],SW_HIDE);
			}
	ShowWindow(hCheckBox[1], SW_HIDE);
	ShowWindow(hEditBox[2], SW_HIDE);	
	ShowWindow(hEditBox[3], SW_HIDE);
	ShowWindow(hEditBox[4], SW_HIDE);
	ShowWindow(hEditBox[5], SW_HIDE);	
	ShowWindow(hEditBox[6], SW_HIDE);
	ShowWindow(hEditBox[7], SW_HIDE);
	ShowWindow(hButton[5], SW_SHOWNORMAL);
	ShowWindow(hStatic[3], SW_HIDE);
	ShowWindow(hStatic[4], SW_HIDE);
	ShowWindow(hStatic[5], SW_HIDE);
	ShowWindow(hStatic[6], SW_HIDE);
    ShowWindow(hStatic[7], SW_HIDE);
	ShowWindow(hStatic[8], SW_HIDE);
	ShowWindow(hStatic[2], SW_SHOWNORMAL);
	ShowWindow(hButton[1], SW_SHOWNORMAL);
	ShowWindow(hButton[0], SW_SHOWNORMAL);
}
void COptionsWndCmds::vPass4()
{
for(int i =0;i<32;i++)
	{
	ShowWindow(hEditBox[i], SW_HIDE);	
	ShowWindow(hCheckBox[i], SW_HIDE);
	ShowWindow(hButton[i],SW_HIDE);
	ShowWindow(hStatic[i], SW_HIDE);
			}
	ShowWindow(hEditBox[2], SW_SHOWNORMAL);	
	ShowWindow(hEditBox[3], SW_SHOWNORMAL);
	ShowWindow(hEditBox[4], SW_SHOWNORMAL);
	ShowWindow(hEditBox[5], SW_SHOWNORMAL);	
	ShowWindow(hEditBox[6], SW_SHOWNORMAL);
	ShowWindow(hEditBox[7], SW_SHOWNORMAL);	
	ShowWindow(hButton[2], SW_SHOWNORMAL);
	ShowWindow(hButton[3], SW_SHOWNORMAL);
	ShowWindow(hStatic[3], SW_SHOWNORMAL);
	ShowWindow(hStatic[4], SW_SHOWNORMAL);
	ShowWindow(hStatic[5], SW_SHOWNORMAL);
	ShowWindow(hStatic[6], SW_SHOWNORMAL);
	ShowWindow(hStatic[7], SW_SHOWNORMAL);
	ShowWindow(hStatic[8], SW_SHOWNORMAL);
	ShowWindow(hStatic[2], SW_SHOWNORMAL);
	ShowWindow(hButton[1], SW_SHOWNORMAL);
	ShowWindow(hButton[0], SW_SHOWNORMAL);
}
void COptionsWndCmds::vPass5()
{
for(int i =0;i<32;i++)
	{
	ShowWindow(hEditBox[i], SW_HIDE);		
	ShowWindow(hCheckBox[i], SW_HIDE);
	ShowWindow(hStatic[1], SW_HIDE);
	ShowWindow(hStatic[0], SW_HIDE);
	ShowWindow(hButton[i],SW_HIDE);
			}
	ShowWindow(hStatic[3], SW_HIDE);
	ShowWindow(hStatic[4], SW_HIDE);
	ShowWindow(hStatic[5], SW_HIDE);
	ShowWindow(hStatic[6], SW_HIDE);
	ShowWindow(hStatic[7], SW_HIDE);
	ShowWindow(hStatic[8], SW_HIDE);
	ShowWindow(hStatic[2], SW_SHOWNORMAL);
	ShowWindow(hButton[1], SW_SHOWNORMAL);
	ShowWindow(hButton[0], SW_SHOWNORMAL);
}
//===================CheckPasses=========================

int COptionsWndCmds::SetWndCheckBoxState(HWND hCheckBox,int ndefstate,char *szappfrom,char* szkeyname)//SetupCheckboxStates
{
int nstate;
nstate = c_oINIReader->GetInt(szappfrom,szkeyname,ndefstate);
Button_SetCheck(hCheckBox,nstate);
return nstate;
}
//===================SetupCheckBoxes=========================