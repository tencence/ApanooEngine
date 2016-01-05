#include "group.h"

Group::Group(mat4& transform)
	:m_TransformationMatrix(transform)
{

}

void Group::addToParent(Render2D* render)
{
	render->push(m_TransformationMatrix); // 精灵变换之后再加到render中
	for (renderable2D* renderable:m_Renderables)
	{
		renderable->addToParent(render);
	}
	render->pop();  // 变换后出栈
}

void Group::addChild(renderable2D* renderable)
{
	m_Renderables.push_back(renderable);
}

