// SoundDoc.cpp : CSoundDoc ���O����@
//

#include "stdafx.h"
#include "Sound.h"

#include "SoundDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSoundDoc

IMPLEMENT_DYNCREATE(CSoundDoc, CDocument)

BEGIN_MESSAGE_MAP(CSoundDoc, CDocument)
END_MESSAGE_MAP()


// CSoundDoc �غc/�Ѻc

CSoundDoc::CSoundDoc()
{
	// TODO: �b���[�J�@���غc�{���X

}

CSoundDoc::~CSoundDoc()
{
}

BOOL CSoundDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �b���[�J���s��l�Ƶ{���X
	// (SDI ���|���Φ����)

	return TRUE;
}




// CSoundDoc �ǦC��

void CSoundDoc::Serialize(CArchive& ar)
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


// CSoundDoc �E�_

#ifdef _DEBUG
void CSoundDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSoundDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSoundDoc �R�O
