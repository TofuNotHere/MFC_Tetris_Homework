
// MainMenu.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMainMenuApp: 
// �йش����ʵ�֣������ MainMenu.cpp
//

class CMainMenuApp : public CWinApp
{
public:
	CMainMenuApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMainMenuApp theApp;