// ��Ⱦ�����
#pragma once
#include "gl/glew.h"
#include "../../maths/maths.h"
#include "renderable2D.h"

class Render2D 
{
public:
	Render2D ();

public:
	virtual void begin() {}
	virtual void addItem(renderable2D* renderable) = 0;
	virtual void end() {}
	virtual void drawItems() = 0;

	void push(const mat4& matrix, bool override = false)  // ��ջ
	{
		if (override)
		{
			m_TransformationStack.push_back(matrix);
		}
		else {
			m_TransformationStack.push_back(m_TransformationStack.back() * matrix);
		}
		m_TransformationBack = &m_TransformationStack.back();
	}
	void pop()
	{
		if (m_TransformationStack.size() > 1)
		{
			m_TransformationStack.pop_back();  // ��ջ
		}
		m_TransformationBack = &m_TransformationStack.back();
		// TODO: add to log
	}
protected:
	std::vector<mat4> m_TransformationStack; // �任����ջ
	const mat4* m_TransformationBack;
};
