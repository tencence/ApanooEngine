#include "batchSprite.h"
#include "texture.h"

BatchSprite::BatchSprite(float x, float y, float width, float height, vec4& color)
	: renderable2D(vec3(x, y, 0), vec2(width, height), color)
{

}

BatchSprite::BatchSprite(float x, float y, float width, float height, Texture* texture)
	: renderable2D(vec3(x, y, 0), vec2(width, height), vec4(1, 0, 1, 1))
{
	m_Texture = texture;
}

