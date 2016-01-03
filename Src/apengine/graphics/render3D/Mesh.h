#pragma once
#include "gl/glew.h"
#include "Vertex.h"

class Mesh
{
public:
	Mesh();
	~Mesh();

	void addVertices(Vertex* vertices, GLsizei count);

private:
	GLuint m_Vbo;
	int m_Size;
};
