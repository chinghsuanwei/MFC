// MFC_FinV2Doc.h : CMFC_FinV2Doc ���O������
//


#pragma once


class CMFC_FinV2Doc : public CDocument
{
protected: // �ȱq�ǦC�ƫإ�
	CMFC_FinV2Doc();
	DECLARE_DYNCREATE(CMFC_FinV2Doc)

// �ݩ�
public:

// �@�~
public:

// �мg
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// �{���X��@
public:
	virtual ~CMFC_FinV2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ͪ��T�������禡
protected:
	DECLARE_MESSAGE_MAP()
};


