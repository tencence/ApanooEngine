#include "MainScene2D.h"
#include <math.h>
#include <iostream>

#include "../apengine/maths/maths.h"

#include "../apengine/graphics/shader/shader.h"

#include "../apengine/graphics/render2D/simple2Drender.h"

#include "../apengine/graphics/render2D/simpleSprite.h"
#include "../apengine/graphics/render2D/batchSprite.h"

//#include "../apengine/graphics/render2D/batch2DRender.h"
#include "../apengine/graphics/render2D/tilelayer.h"

#include "../apengine/graphics/render2D/group.h"
#include "../apengine/graphics/render2D/texture.h"

#include "../apengine/utils/timer.h" // timer for fps count

#include <time.h>

MainScene2D::MainScene2D()
{

}

MainScene2D::~MainScene2D()
{
	for (int i = 0;i < 4;i++) {
		delete m_Texture[i];
	}
}

Shader shader("shader/triangles.vert", "shader/triangles.frag");

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
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);    // �����˲�
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);    // �����˲�

	/////////////////////////////��ʼ��////////////////////////////////////////
	
	// shader 1
	shader.enable();
	shader.setUniform2f("light_pos", vec2(0.0f, 0.0f));

	// tile layer
	m_TileLayer = new TileLayer(&shader);
	m_Texture[0] = new Texture("texture/basic.png");
	m_Texture[1] = new Texture("texture/last.bmp");
	m_Texture[2] = new Texture("texture/ccc.png");
	m_Texture[3] = new Texture("texture/ddd.bmp");

	for (int y = -9.0f; y < 9.0f; y ++)
	{
		for (int x = -16.0f; x < 16.0f; x ++)
		{
			if (rand() % 3 == 0) { // �޲���
				m_TileLayer->addChild(new BatchSprite(x, y, 0.9f, 0.9f, vec4(rand() % 1000 / 1000.0, rand() % 1000 / 1000.0, rand() % 1000 / 1000.0, 1)));
			}
			else { // �в���
				m_TileLayer->addChild(new BatchSprite(x, y, 0.9f, 0.9f,m_Texture[rand() % 4]));
			}
		}
	}

	GLint texIDs[] = {
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	};
	shader.enable();
	shader.setUniform1iv("textures", 10, texIDs);
	//////////////////////////////////////////////////////////////////////////
	return TRUE;
}

BOOL MainScene2D::DrawGL(GLvoid)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // �����ɫ����Ȼ���
	glLoadIdentity(); // ���õ�ǰ����
	///////////////////////////////����////////////////////////////////////////

	m_TileLayer->render();

	//////////////////////////////////////////////////////////////////////////

	glFlush(); // ˢ��

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

	return true;
}

