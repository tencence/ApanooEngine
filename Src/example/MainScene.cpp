#include "MainScene.h"
#include <math.h>
#include <iostream>

#include "../apengine/maths/maths.h"

#include "../apengine/graphics/shader/shader.h"

#include "../apengine/graphics/buffers/buffer.h"
#include "../apengine/graphics/buffers/vertexarray.h"
#include "../apengine/graphics/buffers/indexbuffer.h"

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
Shader shader("shader/triangles.vert", "shader/triangles.frag");

#if 0
	GLfloat vertices[] =
	{
		 4, 3, 0,
		12, 3, 0,
		 4, 6, 0,
		12, 3, 0,
		12, 6, 0,
		 4, 6, 0
	};
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
#else
	GLfloat vertices[] =
	{
		0, 0, 0,
		0, 3, 0,
		8, 3, 0,
		8, 0, 0
	};
	GLushort indices[] = 
	{
		0, 1, 2,
		2, 3, 0
	};
	GLfloat colorsA[] =
	{
		1, 0, 1, 1,
		1, 0, 1, 1,
		1, 0, 1, 1,
		1, 0, 1, 1
	};
	GLfloat colorsB[] =
	{
		0.2f, 0.3f, 0.8f, 1,
		0.2f, 0.3f, 0.8f, 1,
		0.2f, 0.3f, 0.8f, 1,
		0.2f, 0.3f, 0.8f, 1
	};
	VertexArray* sprite1 = new VertexArray();
	VertexArray* sprite2 = new VertexArray();
	IndexBuffer* ibo = new IndexBuffer(indices, 6);

#endif
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
	
	shader.enable();  // enable shader

	sprite1->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite1->addBuffer(new Buffer(colorsA, 4 * 4, 4), 1);

	sprite2->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite2->addBuffer(new Buffer(colorsB, 4 * 4, 4), 1);

	// math
	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	shader.setUniformMat4("pr_matrix", ortho); // set uniform matrix4
	shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4.0f,3.0f,0.0f)));
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
#if 0
	glDrawArrays(GL_TRIANGLES, 0, 6);
#else
	sprite1->bind();
	ibo->bind();
	shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4.0f, 3.0f, 0.0f)));
	glDrawElements(GL_TRIANGLES, ibo->getCount(), GL_UNSIGNED_SHORT, 0);
	ibo->bind();
	sprite1->unbind();

	sprite2->bind();
	ibo->bind();
	shader.setUniformMat4("ml_matrix", mat4::translation(vec3(0.0f, 0.0f, 0.0f)));
	glDrawElements(GL_TRIANGLES, ibo->getCount(), GL_UNSIGNED_SHORT, 0);
	ibo->bind();
	sprite2->bind();
#endif
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

