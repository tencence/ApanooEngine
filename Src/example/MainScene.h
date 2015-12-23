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
	Render2D* render;
	std::vector<renderable2D*> m_sprites; // 精灵组
};