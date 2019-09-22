// MFC_FinV2Doc.h : CMFC_FinV2Doc 類別的介面
//


#pragma once


class CMFC_FinV2Doc : public CDocument
{
protected: // 僅從序列化建立
	CMFC_FinV2Doc();
	DECLARE_DYNCREATE(CMFC_FinV2Doc)

// 屬性
public:

// 作業
public:

// 覆寫
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// 程式碼實作
public:
	virtual ~CMFC_FinV2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 產生的訊息對應函式
protected:
	DECLARE_MESSAGE_MAP()
};


