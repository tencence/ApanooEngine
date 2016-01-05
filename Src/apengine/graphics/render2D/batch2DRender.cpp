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

// ��ʼ���Ԫ��
void Batch2DRender::begin()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	m_Buffer = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
}

void Batch2DRender::addItem(renderable2D* renderable)
{
	const vec3& position = renderable->getPosition();
	const vec2& size = renderable->getSize();
	const vec4& color = renderable->getColor();
	
	int r = color.x * 255.0f;
	int g = color.y * 255.0f;
	int b = color.z * 255.0f;
	int a = color.w * 255.0f;

	// ������ɫ
	unsigned int c = a << 24 | b << 16 | g << 8 | r;

	// point 1 : �ӱ任����ջ�еĵ�ǰ���������ʵλ��
	m_Buffer->vertex = *m_TransformationBack * position;
	m_Buffer->color = c;
	m_Buffer++;
	
	// point 2
	m_Buffer->vertex = *m_TransformationBack * vec3(position.x, position.y + size.y, position.z);
	m_Buffer->color = c;
	m_Buffer++;

	// point 3
	m_Buffer->vertex = *m_TransformationBack * vec3(position.x + size.x, position.y + size.y, position.z);
	m_Buffer->color = c;
	m_Buffer++;

	// point 4
	m_Buffer->vertex = *m_TransformationBack * vec3(position.x + size.x, position.y, position.z);
	m_Buffer->color = c;
	m_Buffer++;

	m_IndexCount += 6;
}

// ���Ԫ�ؽ���
void Batch2DRender::end()
{
	glUnmapBuffer(GL_ARRAY_BUFFER);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Batch2DRender::drawItems()
{
	glBindVertexArray(m_VAO);
	m_IBO->bind();

	// ����
	glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_INT, NULL);

	m_IBO->unbind();
	glBindVertexArray(0);

	m_IndexCount = 0;
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

	// ����
	glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDER_VERTEX_SIZE, (const GLvoid*)0);

	// ��ɫ
	glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_UNSIGNED_BYTE, GL_TRUE, RENDER_VERTEX_SIZE, (const GLvoid*)(offsetof(VertexData, VertexData::color)));

	// unbind buffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// ������
	GLuint* indices = new GLuint[RENDER_INDICES_SIZE];
	
	int offset = 0;
	for (int i = 0; i < RENDER_INDICES_SIZE; i += 6)
	{
		indices[  i  ] = offset + 0;
		indices[i + 1] = offset + 1;
		indices[i + 2] = offset + 2;

		indices[i + 3] = offset + 2;
		indices[i + 4] = offset + 3;
		indices[i + 5] = offset + 0;

		offset += 4; // offset ����
	}

	m_IBO = new IndexBuffer(indices, RENDER_INDICES_SIZE);
	glBindVertexArray(0);
}

