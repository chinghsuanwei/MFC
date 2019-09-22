#include "Mine.h"

#pragma once


// CWinMine 對話方塊

class CWinMine : public CDialog
{
	DECLARE_DYNAMIC(CWinMine)

public:
	CWinMine(CWnd* pParent = NULL);   // 標準建構函式
	virtual ~CWinMine();
	
// 對話方塊資料
	enum { IDD = IDD_WINMINE };

public:
	int totalBomb;
	int col;
	int row;
	int baseX;
	int baseY;
	int countTime;
	bool m_timer;
	CMine mine[9][9];
	CButton	bombNumBtn;
	CEdit	bombNumEdit;
	CButton timeBtn;
	CEdit	timeEdit;


	int Init_Bomb();
	int Init_Timer();
	int Init_CountBomb();
	void Init_BombNum();
	
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援
public:
	
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
