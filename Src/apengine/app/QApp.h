/*
*  author : 谭锦志
*  email  : apanoo@126.com
*  time   : 2015 12 09
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