// ∆’Õ®‰÷»æ≤„
#pragma once
#include <deque>
#include "render2D.h"

class Simple2DRender : public Render2D
{
public:
	Simple2DRender();
	~Simple2DRender();

public:
	void submit(renderable2D* renderable) override;
	void flush() override;

private:
	std::deque<renderable2D*> m_RenderQueue;
};
