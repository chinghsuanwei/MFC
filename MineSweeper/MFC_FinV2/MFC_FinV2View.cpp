// MFC_FinV2View.cpp : CMFC_FinV2View ���O����@
//

#include "stdafx.h"
#include "MFC_FinV2.h"

#include "MFC_FinV2Doc.h"
#include "MFC_FinV2View.h"
#include "Mine.h"
#include <atlimage.h>
#include "mmsystem.h"
#pragma comment(lib, "winmm")

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_FinV2View

IMPLEMENT_DYNCREATE(CMFC_FinV2View, CView)

BEGIN_MESSAGE_MAP(CMFC_FinV2View, CView)
	// �зǦC�L�R�O
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_COMMAND(ID_32771, &CMFC_FinV2View::OnNewGame)
	ON_COMMAND(ID_32772, &CMFC_FinV2View::OnCloseGame)
END_MESSAGE_MAP()

// CMFC_FinV2View �غc/�Ѻc

CMFC_FinV2View::CMFC_FinV2View()
{
	// TODO: �b���[�J�غc�{���X
	col = 9;
	row = 9;
	baseX = 25;
	baseY = 25;
	count = 0;
	countTime =0;
	totalBomb = 10;
	countBomb = totalBomb;
	m_timer = false;
}

CMFC_FinV2View::~CMFC_FinV2View()
{
}

BOOL CMFC_FinV2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �b���g�ѭק� CREATESTRUCT cs 
	// �F��ק�������O�μ˦����ت�

	return CView::PreCreateWindow(cs);
}

// CMFC_FinV2View �yø
int CMFC_FinV2View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	Init_Bomb();
	Set_Bomb();
	Init_BombNum();
	Init_Timer();
	Init_CountBomb();

	return 0;
}

void CMFC_FinV2View::OnNewGame()
{
	count = 0;
	countTime = 0;
	totalBomb = 10;
	countBomb = totalBomb;
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			mine[i][j].CleanData();
	Set_Bomb();
	Init_BombNum();
	KillTimer(1);
	SetTimer(1,100,NULL);
	
	char str[10];
	_itoa_s(countBomb, str, 10);
	CString tmp1(str);
	bombNumEdit.SetWindowTextW(tmp1);

	_itoa_s(countTime, str, 10);
	CString tmp2(str);
	timeEdit.SetWindowTextW(tmp2);
}


void CMFC_FinV2View::OnDraw(CDC* pDC)
{
	CMFC_FinV2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	CRect rc;
	GetClientRect(&rc);
	CBrush brush(RGB(120,120,255));
	CBrush* oldbrush = pDC->SelectObject(&brush);
	pDC->Rectangle(rc);
	pDC->SelectObject(oldbrush);
}


// CMFC_FinV2View �C�L

BOOL CMFC_FinV2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �w�]���ǳƦC�L�{���X
	return DoPreparePrinting(pInfo);
}

void CMFC_FinV2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �[�J�C�L�e�B�~����l�]�w
}

void CMFC_FinV2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �[�J�C�L�᪺�M���{���X
}


// CMFC_FinV2View �E�_

#ifdef _DEBUG
void CMFC_FinV2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_FinV2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_FinV2Doc* CMFC_FinV2View::GetDocument() const // ���O�D��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_FinV2Doc)));
	return (CMFC_FinV2Doc*)m_pDocument;
}
#endif //_DEBUG

// CMFC_FinV2View �T���B�z�`��
int CMFC_FinV2View::Init_Bomb()
{
	srand ( unsigned(time(NULL)) );
	int x=0;
	int y=0;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(!mine[i][j].Create(_T(" "), WS_CHILD | WS_VISIBLE | BS_PUSHLIKE,
						CRect(baseX+x,baseY+y,baseX+x+20,baseY+y+20), this, IDC_BUTTON1+ i*9 + j))
			{
				TRACE0("Failed to create button");
				return -1;
			}
			x +=20;
			

		}
		y +=20;
		x = 0;
	}
	
	return 0;
}

void CMFC_FinV2View::Set_Bomb()
{
	int count = 0;
	int tmp1, tmp2;
	while(totalBomb > count)
	{
		tmp1 = rand() % row;
		tmp2 = rand() % col;
		if(mine[tmp1][tmp2].isbomb!=true)
		{
			mine[tmp1][tmp2].isbomb = true;
			mine[tmp1][tmp2].bombNum = -1;
			count++;
		}
	}
}
//�_�lBombNum �Ҧ��ƥ�
void CMFC_FinV2View::Init_BombNum()
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(mine[i][j].isbomb==true) continue;
			/*
				XXX << The upperlayer bombs
				XOX
				XXX
			*/

			if((i-1) >= 0)
			{
				if((j-1) >=0) if(mine[i-1][j-1].isbomb == true) mine[i][j].bombNum++;
				
				if(mine[i-1][j].isbomb == true) mine[i][j].bombNum++;
				
				if((j+1)<col) if(mine[i-1][j+1].isbomb == true) mine[i][j].bombNum++;
			}

			/*
				XXX 
				XOX << The left bomb and right bomb
				XXX
			*/
			if((j-1) >= 0) if(mine[i][j-1].isbomb == true) mine[i][j].bombNum++;
			if((j+1) < col) if(mine[i][j+1].isbomb == true) mine[i][j].bombNum++;
			
			/*
				XXX 
				XOX 
				XXX << The lowerlayer bombs
			*/
			if((i+1) < row) // bound by 3
			{
				if((j-1) >=0) if(mine[i+1][j-1].isbomb == true)mine[i][j].bombNum++;
				
				if(mine[i+1][j].isbomb == true) mine[i][j].bombNum++;
				
				if((j+1)< col) if(mine[i+1][j+1].isbomb == true)mine[i][j].bombNum++;
			}
		}
	}
}

int CMFC_FinV2View::Init_Timer()
{
		
		if(!timeBtn.Create(_T(" "), WS_CHILD | WS_VISIBLE | BS_PUSHLIKE,
					CRect(20,220,40,240), this, IDC_TIME_BUTTON))
		{
			TRACE0("Failed to create button");
			return -1;
		}

		HICON hIcon = ::LoadIcon(AfxGetResourceHandle(),
							MAKEINTRESOURCE(IDI_CLOCK));
		timeBtn.SetIcon(hIcon);
		//Draw png
		CImage m_Image;
		UINT nID = IDB_CLOCK;
		LPCTSTR sTR = _T("PNG");

		//UINT nID = IDB_BITMAP1;
		//LPCTSTR sTR = RT_BITMAP;

		HINSTANCE hInst = AfxGetResourceHandle();
		HRSRC hRsrc = ::FindResource (hInst,MAKEINTRESOURCE(nID),sTR); // type
		if (!hRsrc)
		  return FALSE;

		// load resource into memory
		DWORD len = SizeofResource(hInst, hRsrc);
		BYTE* lpRsrc = (BYTE*)LoadResource(hInst, hRsrc);
		if (!lpRsrc)
		 return FALSE;

		// Allocate global memory on which to create stream
		HGLOBAL m_hMem = GlobalAlloc(GMEM_FIXED, len);
		BYTE* pmem = (BYTE*)GlobalLock(m_hMem);
		memcpy(pmem,lpRsrc,len);
		IStream* pstm;
		CreateStreamOnHGlobal(m_hMem,FALSE,&pstm);

		// load from stream
		m_Image.Load(pstm);
		// free/release stuff
		GlobalUnlock(m_hMem);
		pstm->Release();
		FreeResource(lpRsrc);
		
		CClientDC btndc(this);
		CDC dcMem;
		dcMem.CreateCompatibleDC(&btndc);
		CPen pen(PS_SOLID, 5, RGB(0,0,0));
		CPen* oldpen = dcMem.SelectObject(&pen);
		//m_Image.Draw(btndc.m_hDC, 20, 20);
		dcMem.MoveTo(20,20);
		dcMem.LineTo(400,400);
		dcMem.SelectObject(oldpen);


		CRect rc;
		CClientDC dc(this);
		using namespace Gdiplus;
		Graphics graph(dc.m_hDC);
		
		
		CSize textSize;

		textSize = dc.GetTextExtent(_T("9999"));

		if(!timeEdit.Create( ES_RIGHT | WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(40,220,40+textSize.cx,240), 
			this, IDC_TIME_EDIT))
		{
			TRACE0("Failed to create edit");
			return -1;
		}
		
		//timeBtn.GetClientRect(&rc);

		timeEdit.ShowWindow(true);
		timeEdit.EnableWindow(false);
		timeEdit.SetWindowTextW(_T("0"));
		

		
		if(m_timer)
		{
			KillTimer(1);
			m_timer = FALSE;
		}
		else
		{
			SetTimer(1, 100, NULL);
			m_timer = TRUE;
		}

		return 0;

}

int CMFC_FinV2View::Init_CountBomb()
{
		CRect rc;
		CClientDC dc(this);
		using namespace Gdiplus;
		Graphics graph(dc.m_hDC);

		CSize textSize;
		
		textSize = dc.GetTextExtent(_T("0000"));

		if(!bombNumBtn.Create(_T(" "), WS_CHILD | WS_VISIBLE | BS_PUSHLIKE,
					CRect(160+textSize.cx,220,180+textSize.cx,240), this, IDC_BOMBNUM_BUTTON))
		{
			TRACE0("Failed to create button");
			return -1;
		}

		HICON hIcon = ::LoadIcon(AfxGetResourceHandle(),
							MAKEINTRESOURCE(IDI_BOMB));
		bombNumBtn.SetIcon(hIcon);

		if(!bombNumEdit.Create( ES_RIGHT | WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(160,220,160+textSize.cx,240), 
			this, IDC_BOMBNUM_EDIT))
		{
			TRACE0("Failed to create edit");
			return -1;
		}

		bombNumEdit.ShowWindow(true);
		bombNumEdit.EnableWindow(false);
		char str[10];
		_itoa_s(totalBomb, str, 10);
		CString cstr(str);
		bombNumEdit.SetWindowTextW(cstr);

		return 0;
}


void CMFC_FinV2View::OnTimer(UINT_PTR nIDEvent)
{	
	count++;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(mine[i][j].isbomb == true && mine[i][j].isSelected == true)
			{
				Explosion();
				KillTimer(1);
				for(int i=0;i<row;i++)
					for(int j=0;j<col;j++)
						 mine[i][j].isSelected = true;
				AfxMessageBox(_T("You Lose!!!"));
				return;
			}
			else if(mine[i][j].selected == true && mine[i][j].isSelected == true && mine[i][j].bombNum==0)
			{	
				mine[i][j].isSelected = false; // �����|�i�H���Q�i��
				Spread(-1,i,j);
				mine[i][j].selected = false;
				i = row;
				break;
			}
			// ���k��
			else if(mine[i][j].selected == true && mine[i][j].isSelected==false)
			{
				if(mine[i][j].IsFlag())
					countBomb--;
				else if(mine[i][j].IsQuetion())
					countBomb++;
				
				char str[10];
				_itoa_s(countBomb, str, 10);
				CString cstr(str);

				bombNumEdit.SetWindowTextW(cstr);
				mine[i][j].selected = false;
				i = row;
				break;
			}
		}
	}
	
	int tmpcount = totalBomb;
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			if(mine[i][j].IsFlag() && mine[i][j].isbomb == true) tmpcount--;

	if(tmpcount == 0)
	{ 
		KillTimer(1);
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				 mine[i][j].isSelected = true;
		AfxMessageBox(_T("You Win!!!"));
		return;
	}

	if(count%10==9)
	{
		if(countTime < 999)
		{
			countTime++;
			CEdit* ptr = (CEdit*) GetDlgItem(IDC_TIME_EDIT);
			
			char str[10];
			_itoa_s(countTime, str, 10);
			CString cstr(str);

			ptr->SetWindowTextW(cstr);
		}
	}

	CView::OnTimer(nIDEvent);
}

void CMFC_FinV2View::Explosion()
{
 for(int i=0;i<9;i++)
	for(int j=0;j<=i;j++)
		for(int k=i;k>=0;k--)
		{
			if(mine[j][k].isbomb==true && mine[j][k].isSelected==false)
			{
				HICON hIcon = ::LoadIcon(AfxGetResourceHandle(),
									MAKEINTRESOURCE(IDI_BOMB));
				mine[j][k].SetIcon(hIcon);
				mine[j][k].UpdateWindow();
				mine[j][k].isSelected= true;
				
				PlaySound(MAKEINTRESOURCE(IDR_BOMB), AfxGetResourceHandle(), SND_RESOURCE | SND_NODEFAULT | SND_ASYNC);
				
				Sleep(600);
			}
		}
}


//w ��ܤ��੹����a��
void CMFC_FinV2View::Spread( UINT w,int i, int j)
{
	if(mine[i][j].isSelected==false && mine[i][j].bombNum==0)
	{
		mine[i][j].isSelected=true;
		CString cstr("0");
		mine[i][j].SetWindowTextW(cstr);
		mine[i][j].SetCheck(1);
	}
	else if(mine[i][j].isSelected==false && mine[i][j].isbomb==false)
	{
		mine[i][j].isSelected=true;
		char str[10];
		_itoa_s(mine[i][j].bombNum, str, 10);
		CString cstr(str);
		mine[i][j].SetWindowTextW(cstr);
		mine[i][j].SetCheck(1);
		return;
	}
	else return;

	if(i>0 && w!= UP) Spread(DOWN,i-1,j); //���W
	if(j>0 && w!= LEFT) Spread(RIGHT,i,j-1); //����
	if(i<row-1 && w!= DOWN) Spread(UP, i+1, j); //���U
	if(j<col-1 && w!= RIGHT) Spread(LEFT,i,j+1); //���k
	if(i>0 && j>0 && w!= LEFTUP) Spread(RIGHTDOWN,i-1,j-1); //�����W 
	if(i>0 && j<col-1 && w!= RIGHTUP) Spread(LEFTDOWN,i-1,j+1); //���k�W
	if(i<row-1 && j>0 && w!= LEFTDOWN) Spread(RIGHTUP,i+1,j-1); //�����U
	if(i<row-1 && j<col-1 && w!= RIGHTDOWN) Spread(LEFTUP,i+1,j+1); //���k�U 
}

void CMFC_FinV2View::OnCloseGame()
{
	DestroyWindow();
	AfxGetApp()->m_pMainWnd->SendMessage(WM_CLOSE);
}

BOOL CMFC_FinV2View::DestroyWindow()
{
	// TODO: �b���[�J�S�w���{���X�M (��) �I�s�����O

	return CView::DestroyWindow();
}
