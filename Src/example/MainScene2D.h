#pragma once
#include "../apengine/apengine.h"
#include <vector>
#include "../apengine/utils/timer.h"

class Render2D;
class renderable2D;
class TileLayer;

class MainScene2D : public GLWindow
{
public:
	MainScene2D();
	~MainScene2D();

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
	Timer m_Timer;
	float m_Time;
	unsigned int m_Frames;
	TileLayer* m_TileLayer;
	TileLayer* m_layer2;
};