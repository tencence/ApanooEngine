/************************************************************************/
/* time   : 2015-12-02                                                  */
/* author : ̷��־                                                       */
/* email  : apanoo@126.com                                              */
/************************************************************************/

#define WIN32_LEAN_AND_MEAN
#include "Main.h"
#include "AppDelegate.h"

// WinMain ��ں���

AppDelegate theApp;  // ȫ�ֱ���

int WINAPI WinMain(	HINSTANCE	hInstance,				// Instance
						HINSTANCE	hPrevInstance,		// Previous Instance
						LPSTR		lpCmdLine,			// Command line params
						int			nShowCmd)			// Window show state
{
	theApp.InitInstance();  
	theApp.run();		    
	theApp.ExitInstance();

	return true;
}