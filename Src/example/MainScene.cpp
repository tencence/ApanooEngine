#include "MainScene.h"
#include <math.h>

MainScene::MainScene()
{

}

MainScene::~MainScene()
{

}

// ��ʾģʽ
void MainScene::ViewMode()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// ͸��ģʽ
	// �˴�width��height��Ҫǿ��ת��Ϊfloat �� ��ΪGLWindow�н��䶨��ΪGLsizei����ǿת��������opengl�ӿ�
	gluPerspective(45.0f, (float)this->GetWidth() / (float)this->GetHeight(), 0.01f, 100.0f);

	// �����λ��
	gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0); 

	// ѡ��ģʽ�۲����
	glMatrixMode(GL_MODELVIEW); 

	glLoadIdentity();
}

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
	
	
	//////////////////////////////////////////////////////////////////////////
	return TRUE;
}

BOOL MainScene::DrawGL(GLvoid)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // �����ɫ����Ȼ���
	glLoadIdentity(); // ���õ�ǰ����
	///////////////////////////////����////////////////////////////////////////
	
	
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

