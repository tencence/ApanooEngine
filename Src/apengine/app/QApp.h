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

/************************************************************************/
/* Ӧ�ó������                                                           */
/************************************************************************/
#ifndef __QAPP_H_
#define __QAPP_H_

#include <Windows.h>

class QApp
{
public:
	QApp();
	~QApp();
public:
	virtual BOOL InitInstance();
	virtual BOOL ExitInstance();
	void run();

protected:
	void* m_pMainWnd;
};

#endif // !__QAPP_H_