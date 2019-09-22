#pragma once


// CMine

class CMine : public CButton
{
	DECLARE_DYNAMIC(CMine)

public:
	CMine();
	virtual ~CMine();
	void SetDownColor(COLORREF color);
	void SetUpColor(COLORREF color);
	bool IsFlag();
	bool IsQuetion();
	void CleanData();
	enum {NONE, FLAG, QUETION}rightState;
	int bombNum;
	bool isbomb;
	bool isSelected;
	bool selected;
	COLORREF m_TextColor, m_DownColor, m_UpColor;
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
};


