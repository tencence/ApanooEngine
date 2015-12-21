#include "buffer.h"

Buffer::Buffer(GLfloat* data, GLsizei count, GLuint componentCount)
	:m_ComponentCount(componentCount)
{
	glGenBuffers(1, &m_BufferID);		        // gend
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);  // bind
	glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Buffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);  // bind
}

void Buffer::unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);           // unbind
}
