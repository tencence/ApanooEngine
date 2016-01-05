/*
 * Group : ��������ӵ��飬�����е������������λ��
 */
#pragma once
#include "renderable2D.h"

class Group : public renderable2D
{
public:
	Group(mat4& transform);
	void addToParent(Render2D* render) override; // ��������ӵ�layer��

	// ��Ӿ��鵽��
	void addChild(renderable2D* renderable);
private:
	std::vector<renderable2D*> m_Renderables;
	mat4 m_TransformationMatrix;
};