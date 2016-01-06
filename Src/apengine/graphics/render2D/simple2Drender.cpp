#include "simple2Drender.h"

Simple2DRender::Simple2DRender()
{

}

Simple2DRender::~Simple2DRender()
{

}

void Simple2DRender::addChild(renderable2D* renderable)
{
	m_RenderQueue.push_back((SimpleSprite*)renderable);
}

void Simple2DRender::render()
{
	while (!m_RenderQueue.empty())
	{
		SimpleSprite* sprite = m_RenderQueue.front();
		sprite->getVAO()->bind();
		sprite->getIBO()->bind();

		// 移到物体对应位置
		sprite->getShader().setUniformMat4("ml_matrix", mat4::translation(sprite->getPosition()));
		glDrawElements(GL_TRIANGLES, sprite->getIBO()->getCount(), GL_UNSIGNED_INT, 0);

		sprite->getIBO()->unbind();
		sprite->getVAO()->unbind();

		// 绘制后出队
		m_RenderQueue.pop_front();  
	}
}

