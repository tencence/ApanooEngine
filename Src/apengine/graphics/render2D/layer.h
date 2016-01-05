#pragma once
#include "renderable2D.h"
#include "render2D.h"

class Layer
{
public:
	virtual ~Layer();
	virtual void addChild(renderable2D* renderable);
	virtual void render();
protected:
	Layer(Render2D* render, Shader* shader, mat4 projectionMatrix);
protected:
	Render2D* m_Render;						  // äÖÈ¾Æ÷
	std::vector<renderable2D*> m_Renderables; // äÖÈ¾ÁĞ±í
	Shader* m_Shader;						  // shader
	mat4 m_ProjectionMatrix;			      // ÊÓÍ¼¾ØÕó
};