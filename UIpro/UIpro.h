// UIpro.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
 #include "conio.h" 


#define ui_trace cprintf

// CUIproApp:
// �йش����ʵ�֣������ UIpro.cpp
//

class CUIproApp : public CWinApp
{
public:
	CUIproApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CUIproApp theApp;