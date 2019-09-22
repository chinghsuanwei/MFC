// SoundDoc.cpp : CSoundDoc 類別的實作
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


// CSoundDoc 建構/解構

CSoundDoc::CSoundDoc()
{
	// TODO: 在此加入一次建構程式碼

}

CSoundDoc::~CSoundDoc()
{
}

BOOL CSoundDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此加入重新初始化程式碼
	// (SDI 文件會重用此文件)

	return TRUE;
}




// CSoundDoc 序列化

void CSoundDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此加入儲存程式碼
	}
	else
	{
		// TODO: 在此加入載入程式碼
	}
}


// CSoundDoc 診斷

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


// CSoundDoc 命令
