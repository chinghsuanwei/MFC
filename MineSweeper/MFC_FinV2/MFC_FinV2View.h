// MFC_FinV2View.h : CMFC_FinV2View 類別的介面
//
#include "Mine.h"

#pragma once


class CMFC_FinV2View : public CView
{
protected: // 僅從序列化建立
	CMFC_FinV2View();
	DECLARE_DYNCREATE(CMFC_FinV2View)

// 屬性
public:
	CMFC_FinV2Doc* GetDocument() const;

// 作業
public:
public:
	int totalBomb;
	int col;
	int row;
	int baseX;
	int baseY;
	int count;
	int countTime;
	int countBomb;
	bool m_timer;
	CMine mine[9][9];
	CButton	bombNumBtn;
	CEdit	bombNumEdit;
	CButton timeBtn;
	CEdit	timeEdit;
	enum {LEFT, RIGHT, UP, DOWN, LEFTDOWN, LEFTUP, RIGHTDOWN, RIGHTUP}direction;

	int Init_Bomb();
	void Set_Bomb();
	int Init_Timer();
	int Init_CountBomb();
	void Init_BombNum();
	void Explosion();
	void Spread(UINT w, int i, int j);
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
	virtual ~CMFC_FinV2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 產生的訊息對應函式
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnNewGame();
	afx_msg void OnCloseGame();
	virtual BOOL DestroyWindow();
};

#ifndef _DEBUG  // MFC_FinV2View.cpp 中的偵錯版本
inline CMFC_FinV2Doc* CMFC_FinV2View::GetDocument() const
   { return reinterpret_cast<CMFC_FinV2Doc*>(m_pDocument); }
#endif

