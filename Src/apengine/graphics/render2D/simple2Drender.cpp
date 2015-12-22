#include "simple2Drender.h"

Simple2DRender::Simple2DRender()
{

}

Simple2DRender::~Simple2DRender()
{

}

void Simple2DRender::addItem(renderable2D* renderable)
{
	m_RenderQueue.push_back((StaticSprite*)renderable);
}

void Simple2DRender::drawItems()
{
	while (!m_RenderQueue.empty())
	{
		StaticSprite* sprite = m_RenderQueue.front();
		sprite->getVAO()->bind();
		sprite->getIBO()->bind();

		// 移到物体对应位置
		sprite->getShader().setUniformMat4("ml_matrix", mat4::translation(sprite->getPosition()));
		glDrawElements(GL_TRIANGLES, sprite->getIBO()->getCount(), GL_UNSIGNED_SHORT, 0);

		sprite->getIBO()->unbind();
		sprite->getVAO()->unbind();

		// 绘制后出队
		m_RenderQueue.pop_front();  
	}
}

