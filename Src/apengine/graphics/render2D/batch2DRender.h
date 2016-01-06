// 同时渲染多个物体 <- 高效绘制
#pragma once
#include "render2D.h"
#include "../buffers/indexbuffer.h"
#include "renderable2D.h"
#include <cstddef>

#define RENDER_MAX_SPRITES  60000									// 绘制精灵个数限制
#define RENDER_VERTEX_SIZE  sizeof(VertexData)						// 顶点数据大小
#define RENDER_SPRITE_SIZE  RENDER_VERTEX_SIZE * 4					// 精灵尺寸
#define RENDER_BUFFER_SIZE  RENDER_SPRITE_SIZE * RENDER_MAX_SPRITES // buffer大小
#define RENDER_INDICES_SIZE RENDER_MAX_SPRITES * 6					// 索引数量限制

#define SHADER_VERTEX_INDEX 0										// 顶点location
#define SHADER_UV_INDEX     1										// 纹理location
#define SHADER_TID_INDEX    2										// 纹理id location
#define SHADER_COLOR_INDEX  3										// 颜色location

class Batch2DRender : public Render2D
{
public:
	Batch2DRender();
	~Batch2DRender();
	void begin() override;
	void addChild(renderable2D* renderable) override;
	void end() override;
	void render() override;

private:
	void init();

private:
	GLuint m_VAO;
	GLuint m_VBO;
	IndexBuffer* m_IBO; 
	GLsizei m_IndexCount;

	VertexData* m_Buffer;

	std::vector<GLuint> m_TextureSlots;
};