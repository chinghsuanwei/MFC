// SoundView.h : CSoundView 類別的介面
//


#pragma once


class CSoundView : public CView
{
protected: // 僅從序列化建立
	CSoundView();
	DECLARE_DYNCREATE(CSoundView)

// 屬性
public:
	CSoundDoc* GetDocument() const;

// 作業
public:

// 覆寫
public:
	virtual void OnDraw(CDC* pDC);  // 覆寫以描繪此檢視
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 程式碼實作
public:
	virtual ~CSoundView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 產生的訊息對應函式
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // SoundView.cpp 中的偵錯版本
inline CSoundDoc* CSoundView::GetDocument() const
   { return reinterpret_cast<CSoundDoc*>(m_pDocument); }
#endif

