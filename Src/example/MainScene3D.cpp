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

	// ѡ����Ȳ��Է�
	glDepthFunc(GL_LEQUAL);

	// ������ȼ��
	glEnable(GL_DEPTH_TEST);

	glShadeModel(GL_SMOOTH);

	// �ϸ��͸�Ӽ���
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	/////////////////////////////��ʼ��////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	return TRUE;
}

BOOL MainScene3D::DrawGL(GLvoid)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // �����ɫ����Ȼ���
	glLoadIdentity(); // ���õ�ǰ����
					  ///////////////////////////////����////////////////////////////////////////


	//////////////////////////////////////////////////////////////////////////
	glFlush(); // ˢ��
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
	double x = LOWORD(lParam); // ���x����
	double y = HIWORD(lParam); // ���y����

	return true;
}

