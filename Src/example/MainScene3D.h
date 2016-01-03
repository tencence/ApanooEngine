#pragma once
#include "../apengine/apengine.h"
#include <vector>
#include "../apengine/utils/timer.h"

class MainScene3D : public GLWindow
{
public:
	MainScene3D();
	~MainScene3D();

	// ��ʼ��
	BOOL initGL(GLvoid) override;

	// ���Ƴ���
	BOOL DrawGL(GLvoid) override;

	// ���´�����Ϣ
	BOOL UpdateGL(GLvoid) override;

	// opengl��������ǰ�Ĵ���
	GLvoid DestroyGL(GLvoid) override;

	HRESULT OnMouseMove(WPARAM wParam, LPARAM lParam) override;

private:

};