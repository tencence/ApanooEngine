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

/************************************************************************/
/* 应用程序基类                                                           */
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