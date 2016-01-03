#include "MainScene3D.h"
#include <math.h>
#include <iostream>

#include "../apengine/maths/maths.h"
#include "../apengine/graphics/shader/shader.h"

#include <time.h>

MainScene3D::MainScene3D()
{
	
}

MainScene3D::~MainScene3D()
{

}

BOOL MainScene3D::initGL(GLvoid)
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

	//////////////////////////////////////////////////////////////////////////
	return TRUE;
}

BOOL MainScene3D::DrawGL(GLvoid)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // 清除颜色和深度缓存
	glLoadIdentity(); // 重置当前矩阵
					  ///////////////////////////////绘制////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////////
	glFlush(); // 刷新
	return TRUE;
}

BOOL MainScene3D::UpdateGL(GLvoid)
{
	if (keyDown(key_f1))
	{

	}

	return TRUE;
}

GLvoid MainScene3D::DestroyGL(GLvoid)
{

}

HRESULT MainScene3D::OnMouseMove(WPARAM wParam, LPARAM lParam)
{
	double x = LOWORD(lParam); // 鼠标x坐标
	double y = HIWORD(lParam); // 鼠标y坐标

	return true;
}

