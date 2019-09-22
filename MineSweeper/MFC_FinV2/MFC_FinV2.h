// MFC_FinV2.h : MFC_FinV2 應用程式的主標頭檔
//
#pragma once

#ifndef __AFXWIN_H__
	#error "對 PCH 包含此檔案前先包含 'stdafx.h'"
#endif

#include "resource.h"       // 主要符號


// CMFC_FinV2App:
// 請參閱實作此類別的 MFC_FinV2.cpp
//

class CMFC_FinV2App : public CWinApp
{
public:
	CMFC_FinV2App();


// 覆寫
public:
	virtual BOOL InitInstance();

// 程式碼實作
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_FinV2App theApp;