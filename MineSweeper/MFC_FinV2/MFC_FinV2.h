// MFC_FinV2.h : MFC_FinV2 ���ε{�����D���Y��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"       // �D�n�Ÿ�


// CMFC_FinV2App:
// �аѾ\��@�����O�� MFC_FinV2.cpp
//

class CMFC_FinV2App : public CWinApp
{
public:
	CMFC_FinV2App();


// �мg
public:
	virtual BOOL InitInstance();

// �{���X��@
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_FinV2App theApp;