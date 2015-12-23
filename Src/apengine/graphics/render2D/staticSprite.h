// 用于simple render 绘制少量sprite
#pragma once
#include "renderable2D.h"
#include "../../maths/maths.h"

class StaticSprite : public renderable2D
{
public:
	StaticSprite (float x, float y, float width, float height, vec4& color, Shader& shader);
	~StaticSprite ();

	// get VBO, IBO Shader
	inline VertexArray* getVAO() const { return m_VertexArray; }
	inline IndexBuffer* getIBO() const { return m_IndexBuffer; }
	inline Shader& getShader() const { return m_Shader; }

private:
	VertexArray* m_VertexArray;
	IndexBuffer* m_IndexBuffer;
	Shader& m_Shader;

	GLuint m_Indices[6];
};
