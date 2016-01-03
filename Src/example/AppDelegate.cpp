#include "AppDelegate.h"
#include "MainScene2D.h"
#include "MainScene3D.h"

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{

}

BOOL AppDelegate::InitInstance()
{
	MainScene3D *pMainWnd = new MainScene3D();
	if (NULL == pMainWnd)
	{
		return 0; // 窗口创建失败
	}
	m_pMainWnd = (LPVOID)pMainWnd;  // 保留引用

	pMainWnd->CreateGlWnd("ApEngine3D", 200, 100, 960, 540); 
	pMainWnd->ShowWindow(SW_SHOW);
	pMainWnd->UpdateWindow();

	return TRUE;
}

BOOL AppDelegate::ExitInstance()
{
	if (m_pMainWnd)
	{
		delete m_pMainWnd;  // 退出前处理
		m_pMainWnd = NULL;
	}
	return true;
}

