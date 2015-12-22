#include "MainScene.h"
#include <math.h>
#include <iostream>

#include "../apengine/maths/maths.h"

#include "../apengine/graphics/shader/shader.h"

#include "../apengine/graphics/buffers/buffer.h"
#include "../apengine/graphics/buffers/vertexarray.h"
#include "../apengine/graphics/buffers/indexbuffer.h"

#include "../apengine/graphics/render2D/simple2Drender.h"
#include "../apengine/graphics/render2D/renderable2D.h"


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

	// ѡ����Ȳ��Է�
	glDepthFunc(GL_LEQUAL);

	// ������ȼ��
	glEnable(GL_DEPTH_TEST);
	
	glShadeModel(GL_SMOOTH);

	// �ϸ��͸�Ӽ���
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 

	/////////////////////////////��ʼ��////////////////////////////////////////
	
	// enable shader
	shader.enable();  
	
	// render layer
	render = new Simple2DRender();

	// sprites
	sprite = new renderable2D(vec3(1, 1, 0), vec2(4, 5), vec4(1, 0, 1, 1), shader);
	
	// math
	mat4 ortho = mat4::orthographic(0.0f, 8.0f, 0.0f, 6.0f, -1.0f, 1.0f);
	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
	shader.setUniform4f("colour", vec4(0.2f, 0.3f, 0.8f, 1.0f));

	//////////////////////////////////////////////////////////////////////////
	return TRUE;
}

BOOL MainScene::DrawGL(GLvoid)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // �����ɫ����Ȼ���
	glLoadIdentity(); // ���õ�ǰ����
	///////////////////////////////����////////////////////////////////////////

	render->submit(sprite);
	render->flush();

	//////////////////////////////////////////////////////////////////////////

	glFlush(); // ˢ��
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
	double x = LOWORD(lParam); // ���x����
	double y = HIWORD(lParam); // ���y����
	shader.setUniform2f("light_pos", vec2((float)(x * 8.0f / (float)this->GetWidth()), (float)(6.0f - y * 6.0f / (float)this->GetHeight())));
	return true;
}

