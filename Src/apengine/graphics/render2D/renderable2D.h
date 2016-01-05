// 可渲染物体
#pragma once
#include "gl/glew.h"
#include "../buffers/buffer.h"
#include "../buffers/indexbuffer.h"
#include "../buffers/vertexarray.h"

#include "../shader/shader.h"

#include "../../maths/maths.h"
#include "Render2D.h"

// 顶点结构体
struct VertexData
{
	vec3 vertex;
	// vec4 color; // 初始
	unsigned int color; // 优化
};

class renderable2D
{
public:
	renderable2D(vec3 position, vec2 size, vec4 color);

	~renderable2D();

protected:
	renderable2D() {}

public:

	// 增加渲染体
	virtual void addToParent(Render2D* render)
	{
		render->addChild(this);
	}

	inline const vec3& getPosition() const { return m_Position; }
	inline const vec2& getSize() const { return m_Size; }
	inline const vec4& getColor() const { return m_Color; }

public:
	vec3 m_Position;  // 位置
	vec2 m_Size;	  // 大小
	vec4 m_Color;	  // 颜色
};