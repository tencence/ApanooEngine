// 用于渲染的物体
#pragma once
#include "gl/glew.h"
#include "../buffers/buffer.h"
#include "../buffers/indexbuffer.h"
#include "../buffers/vertexarray.h"

#include "../shader/shader.h"

#include "../../maths/maths.h"

class renderable2D
{
public:
	renderable2D(vec3 position, vec2 size, vec4 color, Shader& shader);

	~renderable2D();

public:
	inline VertexArray* getVAO() const { return m_VertxArray; }
	inline IndexBuffer* getIBO() const { return m_IndexBuffer; }

	inline Shader& getShader() const { return m_Shader; }

	inline const vec3& getPosition() const { return m_Position; }
	inline const vec2& getSize() const { return m_Size; }
	inline const vec4& getColor() const { return m_Color; }

protected:
	vec3 m_Position;  // 位置
	vec2 m_Size;	  // 大小
	vec4 m_Color;	  // 颜色

	VertexArray* m_VertxArray;  // VAO
	IndexBuffer* m_IndexBuffer; // IBO

	Shader& m_Shader;
};