#include "MainScene.h"
#include <math.h>
#include <iostream>

#include "../apengine/maths/maths.h"

#include "../apengine/graphics/shader/shader.h"

#include "../apengine/graphics/render2D/simple2Drender.h"
#include "../apengine/graphics/render2D/renderable2D.h"

#include "../apengine/graphics/render2D/staticSprite.h"
#include "../apengine/graphics/render2D/sprite.h"

#include "../apengine/graphics/render2D/batch2DRender.h"

#include "../apengine/graphics/render2D/tilelayer.h"

#include <time.h>

MainScene::MainScene()
{
	m_Time = 0;
	m_Frames = 0;
}

MainScene::~MainScene()
{

}

Shader shader("shader/triangles.vert", "shader/triangles.frag");
Shader shader2("shader/triangles.vert", "shader/triangles.frag");

BOOL MainScene::initGL(GLvoid)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);

	// 选择深度测试方
	glDepthFunc(GL_LEQUAL);

	// 开启深度检测
	glEnable(GL_DEPTH_TEST);
	
	glShadeModel(GL_SMOOTH);

	// 最精细的透视计算
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 

	/////////////////////////////初始化////////////////////////////////////////
	
	// shader 1
	shader.enable();
	shader.setUniform2f("light_pos", vec2(-8.0f, -3.0f));
	
	// shader 2
	shader2.enable();
	shader2.setUniform2f("light_pos", vec2(4.0f, 2.0f));

	// tile layer
	m_TileLayer = new TileLayer(&shader);
	for (float y = -9.0f; y < 9.0f; y += 0.1f)
	{
		for (float x = -16.0f; x < 16.0f; x += 0.1f)
		{
			m_TileLayer->addItem(new Sprite(x, y, 0.09f, 0.09f, vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
		}
	}

	// layer 2
	m_layer2 = new TileLayer(&shader2);
	m_layer2->addItem(new Sprite(-2, -2, 4, 4, vec4(1, 0, 1, 1)));

	//////////////////////////////////////////////////////////////////////////
	return TRUE;
}

BOOL MainScene::DrawGL(GLvoid)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // 清除颜色和深度缓存
	glLoadIdentity(); // 重置当前矩阵
	///////////////////////////////绘制////////////////////////////////////////

	m_TileLayer->render();
	m_layer2->render();

	//////////////////////////////////////////////////////////////////////////

	glFlush(); // 刷新

	// timer
	m_Frames++;
	if (m_Timer.elapsed() - m_Time > 1.0f)
	{
		m_Time += 1.0f;
		int frames = m_Frames;
		m_Frames = 0;
	}

	return TRUE;
}

BOOL MainScene::UpdateGL(GLvoid)
{
	if (keyDown(key_f1))
	{

	}

	return TRUE;
}

GLvoid MainScene::DestroyGL(GLvoid)
{

}

HRESULT MainScene::OnMouseMove(WPARAM wParam, LPARAM lParam)
{
	double x = LOWORD(lParam); // 鼠标x坐标
	double y = HIWORD(lParam); // 鼠标y坐标

	// shader 1
	shader.enable();
	//shader.setUniform2f("light_pos", vec2((float)(x * 32.0f / (float)this->GetWidth() - 16.0f), (float)(9.0f - y * 18.0f / (float)this->GetHeight())));
	shader.setUniform2f("light_pos", vec2(-8, -3));
	
	// shader 2
	shader2.enable();
	shader2.setUniform2f("light_pos", vec2((float)(x * 32.0f / (float)this->GetWidth() - 16.0f), (float)(9.0f - y * 18.0f / (float)this->GetHeight())));
	return true;
}

