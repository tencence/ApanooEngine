#pragma once
#include "../apengine/apengine.h"

class AppDelegate : public QApp
{
public:
	AppDelegate();
	~AppDelegate();

public:

	// 初始化程序
	virtual BOOL InitInstance();

	// 退出程序
	virtual BOOL ExitInstance();
};