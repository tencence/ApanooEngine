#include "tilelayer.h"

TileLayer::TileLayer(Shader* shader)
	: Layer(new Batch2DRender(), shader, mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1, 1))
{

}

TileLayer::~TileLayer()
{

}

