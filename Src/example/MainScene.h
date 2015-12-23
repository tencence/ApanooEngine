#pragma once
#include "../apengine/apengine.h"
#include <vector>

class Render2D;
class renderable2D;

class MainScene : public GLWindow
{
public:
	MainScene();
	~MainScene();

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
	Render2D* render;
	std::vector<renderable2D*> m_sprites; // ������
};