// Sound.cpp : �w�q���ε{�������O�欰�C
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
	// �̾ڤ��R�O���з��ɮ�
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// �зǦC�L�]�w�R�O
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
	ON_COMMAND(ID_TOMMY_EMMANNUL_ANGELINA, &CSoundApp::OnTommyEmmannulAngelina)
	ON_COMMAND(ID_TOMMY_EMMANNUL_SINCE_WE_MET, &CSoundApp::OnTommyEmmannulSinceWeMet)
	ON_UPDATE_COMMAND_UI(ID_LOOP, &CSoundApp::OnUpdateLoop)
	ON_COMMAND(ID_LOOP, &CSoundApp::OnLoop)
END_MESSAGE_MAP()


// CSoundApp �غc

CSoundApp::CSoundApp()
{
	attribute = SND_ASYNC | SND_RESOURCE;
	checked = 0x0000;
}


// �Ȧ����@�� CSoundApp ����

CSoundApp theApp;


// CSoundApp ��l�]�w

BOOL CSoundApp::InitInstance()
{
	// ���p���ε{����T�M����w�ϥ� ComCtl32.dll 6 (�t) �H�᪩���A
	// �ӱҰʵ�ı�Ƽ˦��A�b Windows XP �W�A�h�ݭn InitCommonControls()�C
	// �_�h����������إ߳��N���ѡC
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// �]�w�n�]�t�Ҧ��z�Q�n�Ω����ε{������
	// �q�α�����O�C
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	// ��l�� OLE �{���w
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// �зǪ�l�]�w
	// �p�G�z���ϥγo�ǥ\��åB�Q���
	// �̫᧹�����i�����ɤj�p�A�z�i�H
	// �q�U�C�{���X�������ݭn����l�Ʊ`���A
	// �ܧ��x�s�]�w�Ȫ��n�����X
	// TODO: �z���ӾA�׭ק惡�r��
	// (�Ҧp�A���q�W�٩β�´�W��)
	SetRegistryKey(_T("���� AppWizard �Ҳ��ͪ����ε{��"));
	LoadStdProfileSettings(4);  // ���J�з� INI �ɿﶵ (�]�t MRU)
	// �n�����ε{�������d���C���d���t�d�b���B
	// �ج[�����P�˵����i��s��
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CSoundDoc),
		RUNTIME_CLASS(CMainFrame),       // �D SDI �ج[����
		RUNTIME_CLASS(CSoundView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);



	// ��R�з� Shell �R�O�BDDE�B�ɮ׶}�����ɪ��R�O�C
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);


	// �b�R�O�C�����w�������R�O�C�p�G�w�ϥ� 
	// /RegServer�B/Register�B/Unregserver �� /Unregister �Ұ����ε{���A�N�Ǧ^ FALSE�C
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// �Ȫ�l�Ƥ@�ӵ����A�ҥH��ܨç�s�ӵ���
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// �u���b SDI ���ε{��������m�r���ɡA�~�I�s DragAcceptFiles
	// �o�|�o�ͩ� ProcessShellCommand ����
	return TRUE;
}



// �� App About �ϥ� CAboutDlg ��ܤ��

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ��ܤ�����
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

// �{���X��@
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

// �����ܤ�������ε{���R�O
void CSoundApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


// CSoundApp �T���B�z�`��


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
