// MFC_FinV2Doc.cpp : CMFC_FinV2Doc ���O����@
//

#include "stdafx.h"
#include "MFC_FinV2.h"

#include "MFC_FinV2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_FinV2Doc

IMPLEMENT_DYNCREATE(CMFC_FinV2Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFC_FinV2Doc, CDocument)
END_MESSAGE_MAP()


// CMFC_FinV2Doc �غc/�Ѻc

CMFC_FinV2Doc::CMFC_FinV2Doc()
{
	// TODO: �b���[�J�@���غc�{���X

}

CMFC_FinV2Doc::~CMFC_FinV2Doc()
{
}

BOOL CMFC_FinV2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �b���[�J���s��l�Ƶ{���X
	// (SDI ���|���Φ����)

	return TRUE;
}




// CMFC_FinV2Doc �ǦC��

void CMFC_FinV2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �b���[�J�x�s�{���X
	}
	else
	{
		// TODO: �b���[�J���J�{���X
	}
}


// CMFC_FinV2Doc �E�_

#ifdef _DEBUG
void CMFC_FinV2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFC_FinV2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFC_FinV2Doc �R�O
