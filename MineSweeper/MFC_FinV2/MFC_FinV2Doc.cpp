// MFC_FinV2Doc.cpp : CMFC_FinV2Doc 類別的實作
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


// CMFC_FinV2Doc 建構/解構

CMFC_FinV2Doc::CMFC_FinV2Doc()
{
	// TODO: 在此加入一次建構程式碼

}

CMFC_FinV2Doc::~CMFC_FinV2Doc()
{
}

BOOL CMFC_FinV2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此加入重新初始化程式碼
	// (SDI 文件會重用此文件)

	return TRUE;
}




// CMFC_FinV2Doc 序列化

void CMFC_FinV2Doc::Serialize(CArchive& ar)
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


// CMFC_FinV2Doc 診斷

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


// CMFC_FinV2Doc 命令
