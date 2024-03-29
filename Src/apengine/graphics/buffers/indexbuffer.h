#pragma once
#include "gl/glew.h"

class IndexBuffer
{
public:
	IndexBuffer(GLuint* data, GLsizei count);
	~IndexBuffer();

	void bind();
	void unbind() const;

	GLuint getCount() const { return m_Count; }


private:
	void init();

	GLuint m_BufferID;
	GLuint m_Count;
	GLuint* m_Data;
};