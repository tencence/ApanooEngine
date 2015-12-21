#include "renderable2D.h"

renderable2D::renderable2D(vec3 position, vec2 size, vec4 color, Shader& shader) 
	:m_Position(position), m_Size(size), m_Color(color), m_Shader(shader)
{
	m_VertxArray = new VertexArray();
	GLfloat vertices[] =
	{
		0, 0, 0,
		0, size.y, 0,
		size.x, size.y, 0,
		size.x, 0, 0
	};
	GLfloat colors[] =
	{
		color.x, color.y, color.z, color.w,
		color.x, color.y, color.z, color.w,
		color.x, color.y, color.z, color.w,
		color.x, color.y, color.z, color.w
	};

	m_VertxArray->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	m_VertxArray->addBuffer(new Buffer(colors, 4 * 4, 4), 1);

	GLushort indices[] = { 0, 1, 2, 2, 3, 0 };
	m_IndexBuffer = new IndexBuffer(indices, 6);
}

renderable2D::~renderable2D()
{
	delete m_VertxArray;
	delete m_IndexBuffer;
}

