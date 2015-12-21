#include "indexbuffer.h"

IndexBuffer::IndexBuffer(GLushort* data, GLsizei count)
	:m_Count(count),m_Data(data), m_BufferID(-1)
{

}

void IndexBuffer::bind()
{
	if (-1 == m_BufferID)
	{
		init();
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
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_Count * sizeof(GLushort), m_Data, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

