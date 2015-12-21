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

// 显示模式 : 立即模式时需要重载
// void MainScene::ViewMode()
// {
	  //glMatrixMode(GL_PROJECTION);
	  //glLoadIdentity();
	  // 透视模式
	  // 此处width和height需要强制转化为float ： 因为GLWindow中将其定义为GLsizei，不强转可能拉遍opengl视口
	  //gluPerspective(45.0f, (float)this->GetWidth() / (float)this->GetHeight(), 0.01f, 100.0f);
	  //gluOrtho2D()
	  // 摄像机位置
	  //gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0); 
	  // 选择模式观察矩阵
	  //glMatrixMode(GL_MODELVIEW); 
	  //glLoadIdentity();
// }

// shader
static Shader shader("shader/triangles.vert", "shader/triangles.frag");

BOOL MainScene::initGL(GLvoid)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
	glClearDepth(1.0f);

	// 选择深度测试方
	glDepthFunc(GL_LEQUAL);

	// 开启深度检测
	glEnable(GL_DEPTH_TEST);
	
	glShadeModel(GL_SMOOTH);

	// 最精细的透视计算
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 

	/////////////////////////////初始化////////////////////////////////////////
	
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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // 清除颜色和深度缓存
	glLoadIdentity(); // 重置当前矩阵
	///////////////////////////////绘制////////////////////////////////////////
	
	glDrawArrays(GL_TRIANGLES, 0, 6);
	
	//////////////////////////////////////////////////////////////////////////

	glFlush(); // 刷新GL命令队列
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

