#pragma once
#include "../apengine/apengine.h"
#include <vector>
#include "../apengine/utils/timer.h"

class Render2D;
class renderable2D;
class TileLayer;
class Texture;

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
	TileLayer* m_TileLayer;

	Texture* m_Texture[4];
};