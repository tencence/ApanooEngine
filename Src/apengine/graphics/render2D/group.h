/*
 * Group : 将精灵添加到组，在组中调整各精灵相对位置
 */
#pragma once
#include "renderable2D.h"

class Group : public renderable2D
{
public:
	Group(mat4& transform);
	void addToParent(Render2D* render) override; // 将精灵添加到layer中

	// 添加精灵到组
	void addChild(renderable2D* renderable);
private:
	std::vector<renderable2D*> m_Renderables;
	mat4 m_TransformationMatrix;
};