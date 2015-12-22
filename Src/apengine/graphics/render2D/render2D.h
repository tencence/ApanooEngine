// äÖÈ¾²ã»ùÀà
#pragma once
#include "gl/glew.h"
#include "../../maths/maths.h"
#include "renderable2D.h"

class Render2D 
{
public:
	Render2D ();
	~Render2D ();

protected:
	virtual void addItem(renderable2D* renderable) = 0;
	virtual void drawItems() = 0;
		 
};
