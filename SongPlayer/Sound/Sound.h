// Sound.h : Sound ���ε{�����D���Y��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"       // �D�n�Ÿ�


// CSoundApp:
// �аѾ\��@�����O�� Sound.cpp
//

class CSoundApp : public CWinApp
{
public:
	CSoundApp();


// �мg
public:
	virtual BOOL InitInstance();
	int attribute;
	int checked;
// �{���X��@
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnTommyEmmannulAngelina();
	afx_msg void OnTommyEmmannulSinceWeMet();
	afx_msg void OnUpdateLoop(CCmdUI *pCmdUI);
	afx_msg void OnLoop();
};

extern CSoundApp theApp;