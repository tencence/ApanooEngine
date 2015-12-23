#pragma once
#include "../apengine/apengine.h"

class StaticSprite;
class Simple2DRender;

class Batch2DRender;
class Sprite;

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
	Simple2DRender* simpleRender;
	StaticSprite* static_sprite[10];
	Sprite* sprite[10];
	Batch2DRender* batchRender;
};