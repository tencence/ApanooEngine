// 用于batch render绘制大量sprite
#pragma once
#include "renderable2D.h"

class Sprite : public renderable2D
{
public:
	Sprite(float x, float y, float width, float height, vec4& color);
private:
};