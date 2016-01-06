// ∆’Õ®‰÷»æ≤„
#pragma once
#include <deque>
#include "render2D.h"
#include "simpleSprite.h"

class Simple2DRender : public Render2D
{
public:
	Simple2DRender();
	~Simple2DRender();

public:
	void addChild(renderable2D* renderable) override;
	void render() override;

private:
	std::deque<SimpleSprite*> m_RenderQueue;
};
