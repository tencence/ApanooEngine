#include "sprite.h"

Sprite::Sprite(float x, float y, float width, float height, vec4& color)
	: renderable2D(vec3(x, y, 0), vec2(width, height), color)
{

}

