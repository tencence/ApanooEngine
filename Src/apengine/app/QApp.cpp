/*
*  author : 谭锦志
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

// 消息循环
void QApp::run()
{
	// 消息循环
	MSG msg;
	while (::GetMessage(&msg, NULL, 0, 0))
	{
		::DispatchMessage(&msg);  // 翻译
		::TranslateMessage(&msg); // 派发
	}
}

