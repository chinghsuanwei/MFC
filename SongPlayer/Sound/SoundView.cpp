// SoundView.cpp : CSoundView ���O����@
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
	// �зǦC�L�R�O
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CSoundView �غc/�Ѻc

CSoundView::CSoundView()
{
	// TODO: �b���[�J�غc�{���X

}

CSoundView::~CSoundView()
{
}

BOOL CSoundView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �b���g�ѭק� CREATESTRUCT cs 
	// �F��ק�������O�μ˦����ت�

	return CView::PreCreateWindow(cs);
}

// CSoundView �yø

void CSoundView::OnDraw(CDC* /*pDC*/)
{
	CSoundDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �b���[�J��͸�ƪ��yø�{���X
}


// CSoundView �C�L

BOOL CSoundView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �w�]���ǳƦC�L�{���X
	return DoPreparePrinting(pInfo);
}

void CSoundView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �[�J�C�L�e�B�~����l�]�w
}

void CSoundView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �[�J�C�L�᪺�M���{���X
}


// CSoundView �E�_

#ifdef _DEBUG
void CSoundView::AssertValid() const
{
	CView::AssertValid();
}

void CSoundView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSoundDoc* CSoundView::GetDocument() const // ���O�D��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSoundDoc)));
	return (CSoundDoc*)m_pDocument;
}
#endif //_DEBUG


// CSoundView �T���B�z�`��
