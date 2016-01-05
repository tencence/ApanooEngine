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
	MainScene2D *pMainWnd = new MainScene2D();
	if (NULL == pMainWnd)
	{
		return 0; // ���ڴ���ʧ��
	}
	m_pMainWnd = (LPVOID)pMainWnd;  // ��������

	pMainWnd->CreateGlWnd("ApEngine2D", 200, 100, 960, 540); 
	pMainWnd->ShowWindow(SW_SHOW);
	pMainWnd->UpdateWindow();

	return TRUE;
}

BOOL AppDelegate::ExitInstance()
{
	if (m_pMainWnd)
	{
		delete m_pMainWnd;  // �˳�ǰ����
		m_pMainWnd = NULL;
	}
	return true;
}

