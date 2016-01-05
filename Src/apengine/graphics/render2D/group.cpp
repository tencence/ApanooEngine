#include "group.h"

Group::Group(mat4& transform)
	:m_TransformationMatrix(transform)
{

}

void Group::addToParent(Render2D* render)
{
	render->push(m_TransformationMatrix); // ����任֮���ټӵ�render��
	for (renderable2D* renderable:m_Renderables)
	{
		renderable->addToParent(render);
	}
	render->pop();  // �任���ջ
}

void Group::addChild(renderable2D* renderable)
{
	m_Renderables.push_back(renderable);
}

