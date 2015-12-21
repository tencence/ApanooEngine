/*
 * use         : »æÖÆ·½Ê½ : draw elements!
 * vertexarray : VAO
 * buffer      : buffer data
 * indexbuffer : IBO
 */

#pragma once

#include <vector>
#include "gl/glew.h"
#include "buffer.h"

class VertexArray
{
public:
	VertexArray();
	~VertexArray();

	void addBuffer(Buffer* buffer, GLuint index);
	void bind();
	void unbind() const;


private:
	void init();

	GLuint m_ArrayID;
	std::vector<Buffer*> m_Buffers;
};
