// SoundDoc.h : CSoundDoc ���O������
//


#pragma once


class CSoundDoc : public CDocument
{
protected: // �ȱq�ǦC�ƫإ�
	CSoundDoc();
	DECLARE_DYNCREATE(CSoundDoc)

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
	virtual ~CSoundDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ͪ��T�������禡
protected:
	DECLARE_MESSAGE_MAP()
};


