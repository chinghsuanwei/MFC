// Sound.cpp : 定義應用程式的類別行為。
//

#include "stdafx.h"
#include "Sound.h"
#include "MainFrm.h"

#include "SoundDoc.h"
#include "SoundView.h"
#include "mmsystem.h"
#pragma comment(lib, "winmm")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSoundApp

BEGIN_MESSAGE_MAP(CSoundApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CSoundApp::OnAppAbout)
	// 依據文件命令的標準檔案
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// 標準列印設定命令
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
	ON_COMMAND(ID_TOMMY_EMMANNUL_ANGELINA, &CSoundApp::OnTommyEmmannulAngelina)
	ON_COMMAND(ID_TOMMY_EMMANNUL_SINCE_WE_MET, &CSoundApp::OnTommyEmmannulSinceWeMet)
	ON_UPDATE_COMMAND_UI(ID_LOOP, &CSoundApp::OnUpdateLoop)
	ON_COMMAND(ID_LOOP, &CSoundApp::OnLoop)
END_MESSAGE_MAP()


// CSoundApp 建構

CSoundApp::CSoundApp()
{
	attribute = SND_ASYNC | SND_RESOURCE;
	checked = 0x0000;
}


// 僅有的一個 CSoundApp 物件

CSoundApp theApp;


// CSoundApp 初始設定

BOOL CSoundApp::InitInstance()
{
	// 假如應用程式資訊清單指定使用 ComCtl32.dll 6 (含) 以後版本，
	// 來啟動視覺化樣式，在 Windows XP 上，則需要 InitCommonControls()。
	// 否則任何視窗的建立都將失敗。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 設定要包含所有您想要用於應用程式中的
	// 通用控制項類別。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	// 初始化 OLE 程式庫
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// 標準初始設定
	// 如果您不使用這些功能並且想減少
	// 最後完成的可執行檔大小，您可以
	// 從下列程式碼移除不需要的初始化常式，
	// 變更儲存設定值的登錄機碼
	// TODO: 您應該適度修改此字串
	// (例如，公司名稱或組織名稱)
	SetRegistryKey(_T("本機 AppWizard 所產生的應用程式"));
	LoadStdProfileSettings(4);  // 載入標準 INI 檔選項 (包含 MRU)
	// 登錄應用程式的文件範本。文件範本負責在文件、
	// 框架視窗與檢視間進行連接
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CSoundDoc),
		RUNTIME_CLASS(CMainFrame),       // 主 SDI 框架視窗
		RUNTIME_CLASS(CSoundView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);



	// 剖析標準 Shell 命令、DDE、檔案開啟舊檔的命令列
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);


	// 在命令列中指定的分派命令。如果已使用 
	// /RegServer、/Register、/Unregserver 或 /Unregister 啟動應用程式，將傳回 FALSE。
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// 僅初始化一個視窗，所以顯示並更新該視窗
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// 只有在 SDI 應用程式中有後置字元時，才呼叫 DragAcceptFiles
	// 這會發生於 ProcessShellCommand 之後
	return TRUE;
}



// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 對話方塊資料
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

// 執行對話方塊的應用程式命令
void CSoundApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


// CSoundApp 訊息處理常式


void CSoundApp::OnTommyEmmannulAngelina()
{
	PlaySound(MAKEINTRESOURCE(IDR_ANGELINA), AfxGetResourceHandle(), attribute);
}

void CSoundApp::OnTommyEmmannulSinceWeMet()
{
	PlaySound(MAKEINTRESOURCE(IDR_SINCE_WE_MET), AfxGetResourceHandle(), attribute);
}


void CSoundApp::OnUpdateLoop(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck( checked );
}

void CSoundApp::OnLoop()
{
	checked ^= 0x0001;
	if(checked > 0)
		attribute &= ~SND_LOOP;
	else
		attribute |= SND_LOOP;
}
