// SoundView.h : CSoundView ���O������
//


#pragma once


class CSoundView : public CView
{
protected: // �ȱq�ǦC�ƫإ�
	CSoundView();
	DECLARE_DYNCREATE(CSoundView)

// �ݩ�
public:
	CSoundDoc* GetDocument() const;

// �@�~
public:

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
	virtual ~CSoundView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ͪ��T�������禡
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // SoundView.cpp ������������
inline CSoundDoc* CSoundView::GetDocument() const
   { return reinterpret_cast<CSoundDoc*>(m_pDocument); }
#endif

