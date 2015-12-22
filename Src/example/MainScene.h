#pragma once
#include "../apengine/apengine.h"

class TextureLoader;
class ScreenShot;

class StaticSprite;
class Simple2DRender;

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
	Simple2DRender* render;
	StaticSprite* sprite[10];
};