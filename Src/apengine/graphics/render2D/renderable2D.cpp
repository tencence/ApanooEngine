#include "renderable2D.h"

renderable2D::renderable2D(vec3 position, vec2 size, vec4 color, Shader& shader) 
	:m_Position(position), m_Size(size), m_Color(color), m_Shader(shader)
{
	m_VertxArray = new VertexArray();

	// ָ����С
	GLfloat vertices[] =
	{
		     0,        0,      0,
		     0,   size.y,      0,
		size.x,   size.y,      0,
		size.x,        0,      0
	};

	// ָ����ɫ
	GLfloat colors[] =
	{
		color.x, color.y, color.z, color.w,
		color.x, color.y, color.z, color.w,
		color.x, color.y, color.z, color.w,
		color.x, color.y, color.z, color.w
	};

	m_VertxArray->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
	m_VertxArray->addBuffer(new Buffer(colors, 4 * 4, 4), 1);

	// ��������
	m_Indices[0] = 0;
	m_Indices[1] = 1;
	m_Indices[2] = 2;

	m_Indices[3] = 2;
	m_Indices[4] = 3;
	m_Indices[5] = 0;
	m_IndexBuffer = new IndexBuffer(m_Indices, 6);
}

renderable2D::~renderable2D()
{
	delete m_VertxArray;
	delete m_IndexBuffer;
}

