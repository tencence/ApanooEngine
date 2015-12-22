#pragma once
#include "../apengine/apengine.h"

class TextureLoader;
class ScreenShot;

class renderable2D;
class Simple2DRender;

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
	Simple2DRender* render;
	renderable2D* sprite;
};