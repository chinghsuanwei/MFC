// Sound.h : Sound 應用程式的主標頭檔
//
#pragma once

#ifndef __AFXWIN_H__
	#error "對 PCH 包含此檔案前先包含 'stdafx.h'"
#endif

#include "resource.h"       // 主要符號


// CSoundApp:
// 請參閱實作此類別的 Sound.cpp
//

class CSoundApp : public CWinApp
{
public:
	CSoundApp();


// 覆寫
public:
	virtual BOOL InitInstance();
	int attribute;
	int checked;
// 程式碼實作
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnTommyEmmannulAngelina();
	afx_msg void OnTommyEmmannulSinceWeMet();
	afx_msg void OnUpdateLoop(CCmdUI *pCmdUI);
	afx_msg void OnLoop();
};

extern CSoundApp theApp;