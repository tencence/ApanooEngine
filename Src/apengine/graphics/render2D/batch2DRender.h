// ͬʱ��Ⱦ������� <- ��Ч����
#pragma once
#include "render2D.h"
#include "../buffers/indexbuffer.h"
#include "renderable2D.h"
#include <cstddef>

#define RENDER_MAX_SPRITES  60000									// ���ƾ����������
#define RENDER_VERTEX_SIZE  sizeof(VertexData)						// �������ݴ�С
#define RENDER_SPRITE_SIZE  RENDER_VERTEX_SIZE * 4					// ����ߴ�
#define RENDER_BUFFER_SIZE  RENDER_SPRITE_SIZE * RENDER_MAX_SPRITES // buffer��С
#define RENDER_INDICES_SIZE RENDER_MAX_SPRITES * 6					// ������������

#define SHADER_VERTEX_INDEX 0										// ����location
#define SHADER_UV_INDEX     1										// ����location
#define SHADER_TID_INDEX    2										// ����id location
#define SHADER_COLOR_INDEX  3										// ��ɫlocation

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