// MFC_FinV2View.h : CMFC_FinV2View ���O������
//
#include "Mine.h"

#pragma once


class CMFC_FinV2View : public CView
{
protected: // �ȱq�ǦC�ƫإ�
	CMFC_FinV2View();
	DECLARE_DYNCREATE(CMFC_FinV2View)

// �ݩ�
public:
	CMFC_FinV2Doc* GetDocument() const;

// �@�~
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
// �мg
public:
	virtual void OnDraw(CDC* pDC);  // �мg�H�yø���˵�
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �{���X��@
public:
	virtual ~CMFC_FinV2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ͪ��T�������禡
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnNewGame();
	afx_msg void OnCloseGame();
	virtual BOOL DestroyWindow();
};

#ifndef _DEBUG  // MFC_FinV2View.cpp ������������
inline CMFC_FinV2Doc* CMFC_FinV2View::GetDocument() const
   { return reinterpret_cast<CMFC_FinV2Doc*>(m_pDocument); }
#endif

