// WinMine.cpp : 實作檔
//

#include "stdafx.h"
#include "MFC_FinV2.h"
#include "WinMine.h"
#include "Mine.h"
#include <iostream>
#include <atlimage.h>

using namespace std;

// CWinMine 對話方塊

IMPLEMENT_DYNAMIC(CWinMine, CDialog)

BEGIN_MESSAGE_MAP(CWinMine, CDialog)
	ON_WM_CREATE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

CWinMine::CWinMine(CWnd* pParent /*=NULL*/)
	: CDialog(CWinMine::IDD, pParent),
	  totalBomb(10),
	  col(9),
	  row(9),
	  baseX(25),
	  baseY(25),
	  countTime(0),
	  m_timer(FALSE)
{
	
}

int CWinMine::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	Init_Bomb();
	Init_Timer();
	Init_CountBomb();
	return  0;//0 means successful
	
}

CWinMine::~CWinMine()
{
}

void CWinMine::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

int CWinMine::Init_Bomb()
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
	
	int count = 0;
	int tmp1, tmp2;
	while(totalBomb > count)
	{
		tmp1 = rand() % row;
		tmp2 = rand() % col;
		if(mine[tmp1][tmp2].isbomb!=true)
		{
			mine[tmp1][tmp2].isbomb = true;
			count++;
		}
	}
	
	Init_BombNum();
	return 0;
}

//起始BombNum 所有數目
void CWinMine::Init_BombNum()
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

int CWinMine::Init_Timer()
{
		CRect rc;
		CDC* dc = GetDC();
		using namespace Gdiplus;
		Graphics graph(dc->m_hDC);

		CSize textSize;

		
		
		if(!timeBtn.Create(_T(" "), WS_CHILD | WS_VISIBLE | BS_PUSHLIKE,
					CRect(20,220,40,240), this, IDC_TIME_BUTTON))
		{
			TRACE0("Failed to create button");
			return -1;
		}

		textSize = dc->GetTextExtent(_T("9999"));

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
			SetTimer(1, 1000, NULL);
			m_timer = TRUE;
		}

		return 0;

}

int CWinMine::Init_CountBomb()
{
		CRect rc;
		CDC* dc = GetDC();
		using namespace Gdiplus;
		Graphics graph(dc->m_hDC);

		CSize textSize;
		
		textSize = dc->GetTextExtent(_T("0000"));

		if(!bombNumBtn.Create(_T(" "), WS_CHILD | WS_VISIBLE | BS_PUSHLIKE,
					CRect(140+textSize.cx,220,160+textSize.cx,240), this, IDC_BOMBNUM_BUTTON))
		{
			TRACE0("Failed to create button");
			return -1;
		}

		

		if(!bombNumEdit.Create( ES_RIGHT | WS_CHILD | WS_VISIBLE | WS_BORDER, CRect(140,220,140+textSize.cx,240), 
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

void CWinMine::OnTimer(UINT_PTR nIDEvent)
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
	CDialog::OnTimer(nIDEvent);
}

