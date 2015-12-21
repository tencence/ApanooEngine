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
	
	shader.enable();  // enable shader

	sprite1->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite1->addBuffer(new Buffer(colorsA, 4 * 4, 4), 1);

	sprite2->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	sprite2->addBuffer(new Buffer(colorsB, 4 * 4, 4), 1);

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

	//auto sprite = new renderable2D(vec3(1, 1, 0), vec2(3, 3), vec4(1, 0, 1, 1), shader);
	//auto render = new Simple2DRender();
	//render->submit(sprite);
	//render->flush();

	
	sprite1->bind();
	ibo->bind();
	shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4.0f, 3.0f, 0.0f)));
	glDrawElements(GL_TRIANGLES, ibo->getCount(), GL_UNSIGNED_SHORT, 0);
	ibo->unbind();
	sprite1->unbind();

	sprite2->bind();
	ibo->bind();
	shader.setUniformMat4("ml_matrix", mat4::translation(vec3(0.0f, 0.0f, 0.0f)));
	glDrawElements(GL_TRIANGLES, ibo->getCount(), GL_UNSIGNED_SHORT, 0);
	ibo->unbind();
	sprite2->unbind();
	
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
	double x = LOWORD(lParam);
	double y = HIWORD(lParam);
	shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / (float)this->GetWidth()), (float)(9.0f - y * 9.0f / (float)this->GetHeight())));
	return true;
}

