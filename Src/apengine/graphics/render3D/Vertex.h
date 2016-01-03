#pragma once
#include "../../maths/maths.h"

#define VERTEX_SIZE 3

class Vertex
{
public:
	Vertex(vec3 pos)
	{
		m_Pos = pos;
	}

	// getter and setter
	vec3 getPos() { return m_Pos; }
	void setPos(vec3 pos) { m_Pos = pos; }

public:
	static int SIZE;

private:
	vec3 m_Pos;
};
