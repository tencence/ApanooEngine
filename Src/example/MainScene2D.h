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
	Timer m_Timer;
	float m_Time;
	unsigned int m_Frames;
	TileLayer* m_TileLayer;
	TileLayer* m_layer2;
};