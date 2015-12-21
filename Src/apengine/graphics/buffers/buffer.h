#pragma once
#include "gl/glew.h"

class Buffer
{
public:
	Buffer(GLfloat* data, GLsizei count, GLuint componentCount);


	void bind();
	void unbind() const;

	GLuint getComponentCount() const { return m_ComponentCount; }

private:
	void init();

	GLuint m_BufferID;
	GLuint m_ComponentCount;  
	GLfloat* m_Data;
	GLuint   m_Count;
};