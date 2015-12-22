// 可渲染物体
#pragma once
#include "gl/glew.h"
#include "../buffers/buffer.h"
#include "../buffers/indexbuffer.h"
#include "../buffers/vertexarray.h"

#include "../shader/shader.h"

#include "../../maths/maths.h"

// 顶点结构体
struct VertexData
{
	vec3 vertex;
	vec4 color;
};

class renderable2D
{
public:
	renderable2D(vec3 position, vec2 size, vec4 color);

	~renderable2D();

public:

	inline const vec3& getPosition() const { return m_Position; }
	inline const vec2& getSize() const { return m_Size; }
	inline const vec4& getColor() const { return m_Color; }

public:
	vec3 m_Position;  // 位置
	vec2 m_Size;	  // 大小
	vec4 m_Color;	  // 颜色
};