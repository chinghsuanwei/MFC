// SoundView.cpp : CSoundView 類別的實作
//

#include "stdafx.h"
#include "Sound.h"

#include "SoundDoc.h"
#include "SoundView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSoundView

IMPLEMENT_DYNCREATE(CSoundView, CView)

BEGIN_MESSAGE_MAP(CSoundView, CView)
	// 標準列印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CSoundView 建構/解構

CSoundView::CSoundView()
{
	// TODO: 在此加入建構程式碼

}

CSoundView::~CSoundView()
{
}

BOOL CSoundView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此經由修改 CREATESTRUCT cs 
	// 達到修改視窗類別或樣式的目的

	return CView::PreCreateWindow(cs);
}

// CSoundView 描繪

void CSoundView::OnDraw(CDC* /*pDC*/)
{
	CSoundDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此加入原生資料的描繪程式碼
}


// CSoundView 列印

BOOL CSoundView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 預設的準備列印程式碼
	return DoPreparePrinting(pInfo);
}

void CSoundView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 加入列印前額外的初始設定
}

void CSoundView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 加入列印後的清除程式碼
}


// CSoundView 診斷

#ifdef _DEBUG
void CSoundView::AssertValid() const
{
	CView::AssertValid();
}

void CSoundView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSoundDoc* CSoundView::GetDocument() const // 內嵌非偵錯版本
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSoundDoc)));
	return (CSoundDoc*)m_pDocument;
}
#endif //_DEBUG


// CSoundView 訊息處理常式
