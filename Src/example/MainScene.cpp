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

#include <time.h>

#define BATCH_RENDER 1 // 1 for batch render and 0 for simple render
MainScene::MainScene()
{
	
}

MainScene::~MainScene()
{

}

Shader shader("shader/triangles.vert", "shader/triangles.frag");

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
	
	// enable shader
	shader.enable();

#if BATCH_RENDER
	render = new Batch2DRender();
#else
	render = new Simple2DRender();
#endif

	// sprites
	srand(time(NULL)); // 随机种子
	for (float y = 0; y < 9; y += 0.05)
	{
		for (float x = 0; x < 16; x += 0.05)
		{
			m_sprites.push_back(new 
#if BATCH_RENDER // batch render
				Sprite
#else  // simple render
			StaticSprite
#endif
				(x, y, 0.04f, 0.04f, vec4(rand() % 1000 / 1000.0f, 0, 1, 1)
#if !BATCH_RENDER
					, shader
#endif
					));
		}
	}

	// math
	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
	shader.setUniform4f("colour", vec4(0.2f, 0.3f, 0.8f, 1.0f));

	//////////////////////////////////////////////////////////////////////////
	return TRUE;
}

BOOL MainScene::DrawGL(GLvoid)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // 清除颜色和深度缓存
	glLoadIdentity(); // 重置当前矩阵
	///////////////////////////////绘制////////////////////////////////////////

	// batch render and simple render 
#if BATCH_RENDER // batch render
	auto renderer = (Batch2DRender*)render;
	renderer->begin();
#else // simple render
	auto renderer = (Simple2DRender*)render;
#endif
	for (int i = 0;i < m_sprites.size(); i++)
	{
		renderer->addItem(m_sprites[i]);
	}
#if BATCH_RENDER
	renderer->end();
#endif
	renderer->drawItems(); // draw all items
	//////////////////////////////////////////////////////////////////////////

	glFlush(); // 刷新
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
	shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / (float)this->GetWidth()), (float)(9.0f - y * 9.0f / (float)this->GetHeight())));
	return true;
}

