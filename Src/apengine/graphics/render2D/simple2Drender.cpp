#include "simple2Drender.h"

Simple2DRender::Simple2DRender()
{

}

Simple2DRender::~Simple2DRender()
{

}

void Simple2DRender::submit(renderable2D* renderable)
{
	m_RenderQueue.push_back(renderable);
}

void Simple2DRender::flush()
{
	while (!m_RenderQueue.empty())
	{
		renderable2D* renderable = m_RenderQueue.front();
		renderable->getVAO()->bind();
		renderable->getIBO()->bind();

		// 移到物体对应位置
		renderable->getShader().setUniformMat4("ml_matrix", mat4::translation(renderable->getPosition())); 
		glDrawElements(GL_TRIANGLES, renderable->getIBO()->getCount(), GL_UNSIGNED_SHORT, 0);

		renderable->getIBO()->unbind();
		renderable->getVAO()->unbind();

		// 绘制后出队
		m_RenderQueue.pop_front();  
	}
}

