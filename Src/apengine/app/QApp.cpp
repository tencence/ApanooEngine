/*
*  author : ̷��־
*  email  : apanoo@126.com
*  time   : 2015 12 09
*/
#include "QApp.h"

QApp::QApp()
{
	m_pMainWnd = NULL;
}

QApp::~QApp()
{
	
}

BOOL QApp::InitInstance()
{
	return true;
}

BOOL QApp::ExitInstance()
{
	return true;
}

// ��Ϣѭ��
void QApp::run()
{
	// ��Ϣѭ��
	MSG msg;
	while (::GetMessage(&msg, NULL, 0, 0))
	{
		::DispatchMessage(&msg);  // ����
		::TranslateMessage(&msg); // �ɷ�
	}
}

