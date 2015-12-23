#include "staticSprite.h"

StaticSprite::StaticSprite(float x, float y, float width, float height, vec4& color, Shader& shader)
	: renderable2D(vec3(x, y, 0), vec2(width, height), color), m_Shader(shader)
{
	m_VertexArray = new VertexArray();

	// 指定大小
	GLfloat vertices[] =
	{
		0,           0,      0,
		0,      height,      0,
		width,  height,      0,
		width,       0,      0
	};

	// 指定颜色
	GLfloat colors[] =
	{
		color.x, color.y, color.z, color.w,
		color.x, color.y, color.z, color.w,
		color.x, color.y, color.z, color.w,
		color.x, color.y, color.z, color.w
	};

	m_VertexArray->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	m_VertexArray->addBuffer(new Buffer(colors, 4 * 4, 4), 1);

	// 索引数组
	m_Indices[0] = 0;
	m_Indices[1] = 1;
	m_Indices[2] = 2;

	m_Indices[3] = 2;
	m_Indices[4] = 3;
	m_Indices[5] = 0;
	m_IndexBuffer = new IndexBuffer(m_Indices, 6);
}

StaticSprite::~StaticSprite()
{
	delete m_VertexArray;
	delete m_IndexBuffer;
}

