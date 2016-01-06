// ����batch render���ƴ���sprite
#pragma once
#include "renderable2D.h"

class Texture;
class BatchSprite : public renderable2D
{
public:
	BatchSprite(float x, float y, float width, float height, vec4& color);
	BatchSprite(float x, float y, float width, float height, Texture* texture);
};