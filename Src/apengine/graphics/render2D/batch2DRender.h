// 同时渲染多个物体
#pragma once
#include "render2D.h"
#include "../buffers/indexbuffer.h"

#define RENDER_MAX_SPRITES  10000
#define RENDER_VERTEX_SIZE  sizeof(VertexData)
#define RENDER_SPRITE_SIZE  RENDER_VERTEX_SIZE * 4
#define RENDER_BUFFER_SIZE  RENDER_SPRITE_SIZE * RENDER_MAX_SPRITES
#define RENDER_INDICES_SIZE RENDER_MAX_SPRITES * 6

#define SHADER_VERTEX_INDEX 0    // 顶点location
#define SHADER_COLOR_INDEX  1    // 颜色location

class Batch2DRender : public Render2D
{
public:
	Batch2DRender();
	~Batch2DRender();
	void begin();
	void addItem(renderable2D* renderable) override;
	void end();
	void drawItems() override;

private:
	void init();

private:
	GLuint m_VAO;
	GLuint m_VBO;
	IndexBuffer* m_IBO; 
	GLsizei m_IndexCount;

	VertexData* m_Buffer;
};