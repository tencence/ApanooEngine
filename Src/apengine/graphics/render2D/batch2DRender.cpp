#include "batch2DRender.h"

Batch2DRender::Batch2DRender()
{
	init();
}

Batch2DRender::~Batch2DRender()
{
	delete m_IBO;
	glDeleteBuffers(1, &m_VBO);
}

void Batch2DRender::addItem(renderable2D* renderable)
{

}

void Batch2DRender::drawItems()
{

}

void Batch2DRender::init()
{
	glGenVertexArrays(1, &m_VAO);

	// bind vertex array
	glBindVertexArray(m_VAO);

	glGenBuffers(1, &m_VBO);

	// bind buffer
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

	// dynamic draw
	glBufferData(GL_ARRAY_BUFFER, RENDER_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);

	glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
	glEnableVertexAttribArray(SHADER_COLOR_INDEX);

	// 顶点
	glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDER_VERTEX_SIZE, (const GLvoid*)0);

	// 颜色
	glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_FLOAT, GL_FALSE, RENDER_VERTEX_SIZE, (const GLvoid*)(3 * GL_FLOAT));

	// unbind buffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// 总索引
	GLushort indices[RENDER_INDICES_SIZE];
	
	int offset = 0;
	for (int i = 0; i < RENDER_INDICES_SIZE; i += 6)
	{
		indices[  i  ] = offset + 0;
		indices[i + 1] = offset + 1;
		indices[i + 2] = offset + 2;

		indices[i + 3] = offset + 2;
		indices[i + 4] = offset + 3;
		indices[i + 5] = offset + 0;

		offset += 4; // offset 递增
	}

	m_IBO = new IndexBuffer(indices, RENDER_INDICES_SIZE);
	glBindVertexArray(0);
}

