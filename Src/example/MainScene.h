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

	// 初始化
	BOOL initGL(GLvoid) override;

	// 绘制场景
	BOOL DrawGL(GLvoid) override;

	// 更新窗口消息
	BOOL UpdateGL(GLvoid) override;

	// opengl窗口销毁前的处理
	GLvoid DestroyGL(GLvoid) override;

	HRESULT OnMouseMove(WPARAM wParam, LPARAM lParam) override;

private:
	Simple2DRender* simpleRender;
	StaticSprite* static_sprite[10];
	Sprite* sprite[10];
	Batch2DRender* batchRender;
};