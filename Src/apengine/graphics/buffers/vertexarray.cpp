#include "vertexarray.h"

VertexArray::VertexArray()
	: m_ArrayID(-1)
{
	
}

VertexArray::~VertexArray()
{
	for (int i = 0;i < m_Buffers.size(); i++)
	{
		delete m_Buffers[i];
	}
}

void VertexArray::addBuffer(Buffer* buffer, GLuint index)
{
	bind();
	buffer->bind();

	glEnableVertexAttribArray(index);
	glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, 0);

	buffer->unbind();
	unbind();
}

void VertexArray::bind()
{
	if (-1 == m_ArrayID)
	{
		init();
	}
	glBindVertexArray(m_ArrayID);
}

void VertexArray::unbind() const
{
	glBindVertexArray(0);
}

void VertexArray::init()
{
	glGenVertexArrays(1, &m_ArrayID);
}

