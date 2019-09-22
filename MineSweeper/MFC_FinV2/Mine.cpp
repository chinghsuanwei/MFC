// Mine.cpp : 實作檔
//

#include "stdafx.h"
#include "MFC_FinV2.h"
#include "Mine.h"
#include "mmsystem.h"
#pragma comment(lib, "winmm")

// CMine

IMPLEMENT_DYNAMIC(CMine, CButton)

CMine::CMine()
{
	rightState = NONE;
	bombNum = 0;
	isbomb = false;
	isSelected = false;
	selected = false;
	m_DownColor = m_UpColor = RGB(0,0,0);
}

CMine::~CMine()
{
}


BEGIN_MESSAGE_MAP(CMine, CButton)
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_DRAWITEM()
END_MESSAGE_MAP()



// CMine 訊息處理常式

void CMine::CleanData()
{
	rightState = NONE;
	bombNum = 0;
	isbomb = false;
	isSelected = false;
	selected = false;
	m_DownColor = m_UpColor = RGB(0,0,0);
	SetIcon(NULL);
	SetWindowTextW(_T(" "));
}

void CMine::OnRButtonDown(UINT nFlags, CPoint point)
{
	if(isSelected==false)
		{
		HICON hIcon;
		selected = true;
		switch(rightState)
		{
			case NONE:
				rightState = FLAG;
				hIcon = ::LoadIcon(AfxGetResourceHandle(),
									MAKEINTRESOURCE(IDI_FLAG));	
				this->SetIcon(hIcon);
				break;
			case FLAG:
				rightState = QUETION;
				hIcon = ::LoadIcon(AfxGetResourceHandle(),
									MAKEINTRESOURCE(IDI_QUETION));
				this->SetIcon(hIcon);
				break;
			case QUETION:
				rightState = NONE;
				this->SetIcon(NULL);
				break;
		}

		CButton::OnRButtonDown(nFlags, point);
	}
}

bool CMine::IsFlag()
{
	return rightState==FLAG;
}

bool CMine::IsQuetion()
{
	return rightState==QUETION;
}

void CMine::OnLButtonDown(UINT nFlags, CPoint point)
{
	if(isSelected==false)
	{	
		this->SetCheck(1);
		selected = true;
		isSelected = true;
		if(isbomb==true)
		{
				HICON hIcon = ::LoadIcon(AfxGetResourceHandle(),
									MAKEINTRESOURCE(IDI_BOMB));
				SetIcon(hIcon);
				UpdateWindow();
				
				PlaySound(MAKEINTRESOURCE(IDR_BOMB), AfxGetResourceHandle(), SND_RESOURCE | SND_NODEFAULT | SND_ASYNC);
				Sleep(600);
		}
		else
		{
			char str[10];
			_itoa_s(bombNum, str, 10);
			CString cstr(str);

			SetWindowTextW(cstr);
		}
		
		CButton::OnLButtonDown(nFlags, point);
	}
}

void CMine::SetDownColor(COLORREF color)
{
	m_DownColor = color;
}

void CMine::SetUpColor(COLORREF color)
{
	m_UpColor = color;
}

void CMine::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
 // TODO: Add your code to draw the specified item
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);//get the DRAW DC
	VERIFY(lpDrawItemStruct->CtlType==ODT_BUTTON);

 // First get the text of the button
 // Second Redraw the text to the button
 // At the same time, Set the background of button to trasparent,
 // so that we can see the text
	 CString buffer;
	 GetWindowText(buffer);
	 int size = buffer.GetLength();
	 DrawText(lpDrawItemStruct->hDC,buffer,size,&lpDrawItemStruct->rcItem,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_TABSTOP);   //draw the text
	 SetBkMode(lpDrawItemStruct->hDC,TRANSPARENT);   //transparent

	 if (lpDrawItemStruct->itemState &ODS_SELECTED)  //action when push the button
	 {//
	  //redraw the control
	  CBrush brush(m_DownColor);  
	  dc.FillRect(&(lpDrawItemStruct->rcItem),&brush);//
	  //we draw the background, so we redraw the text again
	  DrawText(lpDrawItemStruct->hDC,buffer,size,&lpDrawItemStruct->rcItem,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_TABSTOP);   
	  SetBkMode(lpDrawItemStruct->hDC,TRANSPARENT);      
	 }
	 else                       //when button is not selected
	 {
	  CBrush brush(m_UpColor);     
	  dc.FillRect(&(lpDrawItemStruct->rcItem),&brush);//
	  //redraw text
	  DrawText(lpDrawItemStruct->hDC,buffer,size,&lpDrawItemStruct->rcItem,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_TABSTOP);    
	  SetBkMode(lpDrawItemStruct->hDC,TRANSPARENT);
	 }

	 if ((lpDrawItemStruct->itemState &ODS_SELECTED)&&(lpDrawItemStruct->itemAction &(ODA_SELECT| ODA_DRAWENTIRE)))
	 {   // select the control, highlight border
	  COLORREF fc=RGB(255-GetRValue(m_UpColor),255-GetGValue(m_UpColor), 255- GetBValue(m_UpColor));//
	  CBrush brush(fc);//
	  dc.FrameRect(&(lpDrawItemStruct->rcItem),&brush);//
	 }

	 if (!(lpDrawItemStruct->itemState & ODS_SELECTED) &&(lpDrawItemStruct->itemAction & ODA_SELECT))
	 {
	  // end selection
	  CBrush brush(m_UpColor);
	  dc.FrameRect(&lpDrawItemStruct->rcItem,&brush);//
	 }

	 dc.Detach();//


	 //CButton::OnDrawItem(nIDCtl, lpDrawItemStruct);
}
