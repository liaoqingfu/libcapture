
// MFC_test.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include "libcapture.h"

// CMFC_testApp: 
// �йش����ʵ�֣������ MFC_test.cpp
//

class CMFC_testApp : public CWinApp
{
public:
	CMFC_testApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_testApp theApp;