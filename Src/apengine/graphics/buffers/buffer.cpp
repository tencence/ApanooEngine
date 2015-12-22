#include "buffer.h"

Buffer::Buffer(GLfloat* data, GLsizei count, GLuint componentCount)
	:m_ComponentCount(componentCount),m_Data(data),m_Count(count)
{
	m_BufferID = 0;
}

Buffer::~Buffer()
{
	glDeleteBuffers(1, &m_BufferID);
}

void Buffer::init()
{
	glGenBuffers(1, &m_BufferID);		        // gend
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);  // bind
	glBufferData(GL_ARRAY_BUFFER, m_Count * sizeof(GLfloat), m_Data, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Buffer::bind()
{
	if (0 == m_BufferID)
	{
		init(); // 待改进：迁移到构造方法出现错误
	}
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);  // bind
}

void Buffer::unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);           // unbind
}
