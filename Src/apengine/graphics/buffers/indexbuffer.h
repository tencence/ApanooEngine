#pragma once
#include "gl/glew.h"

class IndexBuffer
{
public:
	IndexBuffer(GLushort* data, GLsizei count);

	void bind();
	void unbind() const;

	GLuint getCount() const { return m_Count; }


private:
	void init();

	GLuint m_BufferID;
	GLuint m_Count;
	GLushort* m_Data;
};