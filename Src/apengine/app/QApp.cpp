/*
*  author : ̷��־
*  email  : apanoo@126.com
*  time   : 2014 07 20
*  ps     : ����win32 API��װ
*			֧��win32��׼�ؼ���ȫ�Ի�
*			֧��opengl
*  �ο�    : MFCʵ�ֻ���
*  use     : �����дwindows��ͼ��Ӧ�ü����
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

