#include "MainScene2D.h"
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

#include "../apengine/graphics/render2D/group.h"

#include <time.h>
#define TEST_50K 0

MainScene2D::MainScene2D()
{
	m_Time = 0;
	m_Frames = 0;
}

MainScene2D::~MainScene2D()
{

}

Shader shader("shader/triangles.vert", "shader/triangles.frag");
Shader shader2("shader/triangles.vert", "shader/triangles.frag");

BOOL MainScene2D::initGL(GLvoid)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);

	// ѡ����Ȳ��Է�
	glDepthFunc(GL_LEQUAL);

	// ������ȼ��
	glEnable(GL_DEPTH_TEST);
	
	glShadeModel(GL_SMOOTH);

	// �ϸ��͸�Ӽ���
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 

	/////////////////////////////��ʼ��////////////////////////////////////////
	
	// shader 1
	shader.enable();
	shader.setUniform2f("light_pos", vec2(-8.0f, -3.0f));
	
	// shader 2
	shader2.enable();
	shader2.setUniform2f("light_pos", vec2(4.0f, 2.0f));

	// tile layer
	m_TileLayer = new TileLayer(&shader);
#if TEST_50K
	for (float y = -9.0f; y < 9.0f; y += 0.1f)
	{
		for (float x = -16.0f; x < 16.0f; x += 0.1f)
		{
			m_TileLayer->addChild(new Sprite(x, y, 0.09f, 0.09f, vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
		}
	}
#else
	mat4 tran = mat4::translation(vec3(-15.0f, 5.0f, 0.0f)) * mat4::rotation(45.0f, vec3(0, 0, 1));
	Group* group = new Group(tran);
	group->addChild(new Sprite(0, 0, 6, 3, vec4(1, 1, 1, 1)));
	group->addChild(new Sprite(0.5f, 0.5f, 5.0f, 2.0f, vec4(1, 0, 1, 1)));

	Group* button = new Group(mat4::translation(vec3(0.5f, 0.5f, 0.0f)));
	button->addChild(new Sprite(0, 0, 5, 2, vec4(1, 0, 1, 1)));
	button->addChild(new Sprite(0.5f, 0.5f, 3.0f, 1.0f, vec4(0.2f, 0.3f, 0.8f, 1.0f)));
	group->addChild(button);
	
	m_TileLayer->addChild(group);
#endif
	
	// layer 2
	m_layer2 = new TileLayer(&shader2);
	m_layer2->addChild(new Sprite(-2, -2, 4, 4, vec4(1, 0, 1, 1)));

	//////////////////////////////////////////////////////////////////////////
	return TRUE;
}

BOOL MainScene2D::DrawGL(GLvoid)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // �����ɫ����Ȼ���
	glLoadIdentity(); // ���õ�ǰ����
	///////////////////////////////����////////////////////////////////////////

	m_TileLayer->render();
	//m_layer2->render();

	//////////////////////////////////////////////////////////////////////////

	glFlush(); // ˢ��

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

BOOL MainScene2D::UpdateGL(GLvoid)
{
	if (keyDown(key_f1))
	{

	}

	return TRUE;
}

GLvoid MainScene2D::DestroyGL(GLvoid)
{

}

HRESULT MainScene2D::OnMouseMove(WPARAM wParam, LPARAM lParam)
{
	double x = LOWORD(lParam); // ���x����
	double y = HIWORD(lParam); // ���y����

	// shader 1
	shader.enable();
	shader.setUniform2f("light_pos", vec2((float)(x * 32.0f / (float)this->GetWidth() - 16.0f), (float)(9.0f - y * 18.0f / (float)this->GetHeight())));
	//shader.setUniform2f("light_pos", vec2(-8, -3));
	
	// shader 2
	shader2.enable();
	shader2.setUniform2f("light_pos", vec2((float)(x * 32.0f / (float)this->GetWidth() - 16.0f), (float)(9.0f - y * 18.0f / (float)this->GetHeight())));
	return true;
}
