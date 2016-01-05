#include "render2D.h"

Render2D::Render2D()
{
	m_TransformationStack.push_back(mat4::identity());
	m_TransformationBack = &m_TransformationStack.back();
}


