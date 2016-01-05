// 渲染层基类
#pragma once
#include "gl/glew.h"
#include "../../maths/maths.h"
#include <vector>

class renderable2D;
class Render2D 
{
public:
	Render2D()
	{
		m_TransformationStack.push_back(mat4::identity());
		m_TransformationBack = &m_TransformationStack.back();
	}

public:
	virtual void begin() {}
	virtual void addChild(renderable2D* renderable) = 0;
	virtual void end() {}
	virtual void draw() = 0;

	void push(const mat4& matrix, bool override = false)  // 入栈
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
			m_TransformationStack.pop_back();  // 出栈
		}
		m_TransformationBack = &m_TransformationStack.back();
		// TODO: add to log
	}
protected:
	std::vector<mat4> m_TransformationStack; // 变换矩阵栈
	const mat4* m_TransformationBack;
};
