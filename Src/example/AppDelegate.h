#pragma once
#include "../apengine/apengine.h"

class AppDelegate : public QApp
{
public:
	AppDelegate();
	~AppDelegate();

public:

	// ��ʼ������
	virtual BOOL InitInstance();

	// �˳�����
	virtual BOOL ExitInstance();
};