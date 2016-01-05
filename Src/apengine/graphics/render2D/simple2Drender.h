// ∆’Õ®‰÷»æ≤„
#pragma once
#include <deque>
#include "render2D.h"
#include "staticSprite.h"

class Simple2DRender : public Render2D
{
public:
	Simple2DRender();
	~Simple2DRender();

public:
	void addChild(renderable2D* renderable) override;
	void draw() override;

private:
	std::deque<StaticSprite*> m_RenderQueue;
};
