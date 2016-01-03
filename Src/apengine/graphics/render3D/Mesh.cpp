#include "mesh.h"

Mesh::Mesh()
{
	glGenBuffers(1, &m_Vbo);
	m_Size = 0;
}

Mesh::~Mesh()
{

}

void Mesh::addVertices(Vertex* vertices, GLsizei count)
{
	m_Size = Vertex::SIZE * count;
	glBindBuffer(GL_ARRAY_BUFFER, m_Vbo);
	//glBufferData(GL_ARRAY_BUFFER, );
}

