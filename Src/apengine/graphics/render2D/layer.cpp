#include "layer.h"

Layer::Layer(Render2D* render, Shader* shader, mat4 projectionMatrix)
	: m_Render(render), m_Shader(shader), m_ProjectionMatrix(projectionMatrix)
{
	m_Shader->enable();
	m_Shader->setUniformMat4("pr_matrix", m_ProjectionMatrix); // 视图矩阵
	m_Shader->diable();
}

Layer::~Layer()
{
	delete m_Shader;
	delete m_Render;
	for (int i = 0;i < m_Renderables.size();i++)
	{
		delete m_Renderables[i];
	}
}

void Layer::addChild(renderable2D* renderable)
{
	m_Renderables.push_back(renderable);
}

void Layer::render()
{
	m_Shader->enable();

	// 遍历绘制所有item
	m_Render->begin();

	for (renderable2D* renderable:m_Renderables)
	{
		renderable->addToParent(m_Render); // 添加item
	}

	m_Render->end();
	m_Render->draw(); // 绘制item
}

