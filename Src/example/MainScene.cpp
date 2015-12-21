#include "MainScene.h"
#include <math.h>
#include "../apengine/maths/maths.h"
#include <iostream>
#include "../apengine/graphics/shader/shader.h"

MainScene::MainScene()
{

}

MainScene::~MainScene()
{

}

// ��ʾģʽ : ����ģʽʱ��Ҫ����
// void MainScene::ViewMode()
// {
	  //glMatrixMode(GL_PROJECTION);
	  //glLoadIdentity();
	  // ͸��ģʽ
	  // �˴�width��height��Ҫǿ��ת��Ϊfloat �� ��ΪGLWindow�н��䶨��ΪGLsizei����ǿת��������opengl�ӿ�
	  //gluPerspective(45.0f, (float)this->GetWidth() / (float)this->GetHeight(), 0.01f, 100.0f);
	  //gluOrtho2D()
	  // �����λ��
	  //gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0); 
	  // ѡ��ģʽ�۲����
	  //glMatrixMode(GL_MODELVIEW); 
	  //glLoadIdentity();
// }

// shader
static Shader shader("shader/triangles.vert", "shader/triangles.frag");

BOOL MainScene::initGL(GLvoid)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
	glClearDepth(1.0f);

	// ѡ����Ȳ��Է�
	glDepthFunc(GL_LEQUAL);

	// ������ȼ��
	glEnable(GL_DEPTH_TEST);
	
	glShadeModel(GL_SMOOTH);

	// �ϸ��͸�Ӽ���
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 

	/////////////////////////////��ʼ��////////////////////////////////////////
	
	shader.init();    // shader initial 
	shader.enable();  // enable shader

	GLfloat vertices[] =
	{
		 4, 3, 0,
		12, 3, 0,
		 4, 6, 0,
		12, 3, 0,
		12, 6, 0,
		 4, 6, 0
	};
	GLfloat ver[] = 
	{
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,

		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f
	};
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	// math
	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	shader.setUniformMat4("pr_matrix", ortho); // setuniform matrix4
	//shader.setUniformMat4("ml_matrix", mat4::rotation(45.0f, vec3(0.0f,0.0f,1.0f)));

	//////////////////////////////////////////////////////////////////////////
	return TRUE;
}



BOOL MainScene::DrawGL(GLvoid)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // �����ɫ����Ȼ���
	glLoadIdentity(); // ���õ�ǰ����
	///////////////////////////////����////////////////////////////////////////
	
	glDrawArrays(GL_TRIANGLES, 0, 6);
	
	//////////////////////////////////////////////////////////////////////////

	glFlush(); // ˢ��GL�������
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

