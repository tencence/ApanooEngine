#pragma once
#include "gl/glew.h"

class IndexBuffer
{
public:
	IndexBuffer(GLushort* data, GLsizei count);

	void bind() const;
	void unbind() const;

	GLuint getCount() const { return m_Count; }

private:
	GLuint m_BufferID;
	GLuint m_Count;
};