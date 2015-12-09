/*
*  author : 谭锦志
*  email  : apanoo@126.com
*  time   : 2014 07 20
*  ps     : 基于win32 API封装
*			支持win32标准控件完全自绘
*			支持opengl
*  参考    : MFC实现机制
*  use     : 方便编写windows下图形应用及插件
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

