#include "Mine.h"

#pragma once


// CWinMine ��ܤ��

class CWinMine : public CDialog
{
	DECLARE_DYNAMIC(CWinMine)

public:
	CWinMine(CWnd* pParent = NULL);   // �зǫغc�禡
	virtual ~CWinMine();
	
// ��ܤ�����
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩
public:
	
	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
