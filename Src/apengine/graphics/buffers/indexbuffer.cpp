#include "indexbuffer.h"

IndexBuffer::IndexBuffer(GLuint* data, GLsizei count)
	:m_Count(count),m_Data(data)
{
	m_BufferID = 0;
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &m_BufferID);
}

void IndexBuffer::bind()
{
	if (0 == m_BufferID)
	{
		init(); // 待改进：迁移到构造方法出现错误
	}
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
}

void IndexBuffer::unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void IndexBuffer::init()
{
	glGenBuffers(1, &m_BufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Count * sizeof(GLuint), m_Data, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

