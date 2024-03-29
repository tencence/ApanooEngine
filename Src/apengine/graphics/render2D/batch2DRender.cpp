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

// 开始添加元素
void Batch2DRender::begin()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	m_Buffer = (VertexData*)glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);
}

void Batch2DRender::addChild(renderable2D* renderable)
{
	const vec3& position = renderable->getPosition();	   // 获取位置
	const vec2& size = renderable->getSize();			   // 获取尺寸
	const vec4& color = renderable->getColor();			   // 获取颜色
	const std::vector<vec2>& uv = renderable->getUV();     // 获取纹理坐标
	const GLuint tid = renderable->getTID();               // 获取纹理ID
	
	unsigned int c = 0;
	float ts = 0.0f;
	if (tid > 0)
	{
		bool found = false;
		for (int i = 0;i < m_TextureSlots.size();i++)
		{
			if (m_TextureSlots[i] == tid)
			{
				ts = (float)(i + 1);
				found = true;
				break;
			}
		}
		if (!found) // 没找到，重新开始
		{
			if (m_TextureSlots.size() >= 32)
			{
				end();
				render();
				begin();
			}
			m_TextureSlots.push_back(tid);
			ts = (float)(m_TextureSlots.size());
		}
	}
	else {  // 采用纹理时不需要计算设置的颜色
		int r = color.x * 255.0f;
		int g = color.y * 255.0f;
		int b = color.z * 255.0f;
		int a = color.w * 255.0f;

		// 计算颜色
		c = a << 24 | b << 16 | g << 8 | r;
	}

	// point 1 : 从变换矩阵栈中的当前矩阵计算真实位置
	m_Buffer->vertex = *m_TransformationBack * position;
	m_Buffer->uv = uv[0];
	m_Buffer->tid = ts;
	m_Buffer->color = c;
	m_Buffer++;
	
	// point 2
	m_Buffer->vertex = *m_TransformationBack * vec3(position.x, position.y + size.y, position.z);
	m_Buffer->uv = uv[1];
	m_Buffer->tid = ts;
	m_Buffer->color = c;
	m_Buffer++;

	// point 3
	m_Buffer->vertex = *m_TransformationBack * vec3(position.x + size.x, position.y + size.y, position.z);
	m_Buffer->uv = uv[2];
	m_Buffer->tid = ts;
	m_Buffer->color = c;
	m_Buffer++;

	// point 4
	m_Buffer->vertex = *m_TransformationBack * vec3(position.x + size.x, position.y, position.z);
	m_Buffer->uv = uv[3];
	m_Buffer->tid = ts;
	m_Buffer->color = c;
	m_Buffer++;

	m_IndexCount += 6;
}

// 添加元素结束
void Batch2DRender::end()
{
	glUnmapBuffer(GL_ARRAY_BUFFER);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Batch2DRender::render()
{
	for (int i = 0;i < m_TextureSlots.size();i++)
	{
		glActiveTexture(GL_TEXTURE0 + i);				 // 激活纹理
		glBindTexture(GL_TEXTURE_2D, m_TextureSlots[i]);  // 绑定纹理
	}

	glBindVertexArray(m_VAO);
	m_IBO->bind();

	// 绘制
	glDrawElements(GL_TRIANGLES, m_IndexCount, GL_UNSIGNED_INT, NULL);

	m_IBO->unbind();
	glBindVertexArray(0);

	m_IndexCount = 0;
}

void Batch2DRender::init()
{
	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VBO);

	// bind vertex array
	glBindVertexArray(m_VAO);

	// bind buffer
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

	// dynamic draw
	glBufferData(GL_ARRAY_BUFFER, RENDER_BUFFER_SIZE, NULL, GL_DYNAMIC_DRAW);

	glEnableVertexAttribArray(SHADER_VERTEX_INDEX);
	glEnableVertexAttribArray(SHADER_UV_INDEX);
	glEnableVertexAttribArray(SHADER_TID_INDEX);
	glEnableVertexAttribArray(SHADER_COLOR_INDEX);

	// 顶点
	glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, RENDER_VERTEX_SIZE, (const GLvoid*)0);

	// 纹理
	glVertexAttribPointer(SHADER_UV_INDEX, 2, GL_FLOAT, GL_FALSE, RENDER_VERTEX_SIZE, (const GLvoid*)(offsetof(VertexData, VertexData::uv)));

	// 纹理id
	glVertexAttribPointer(SHADER_TID_INDEX, 1, GL_FLOAT, GL_FALSE, RENDER_VERTEX_SIZE, (const GLvoid*)(offsetof(VertexData, VertexData::tid)));

	// 颜色
	glVertexAttribPointer(SHADER_COLOR_INDEX, 4, GL_UNSIGNED_BYTE, GL_TRUE, RENDER_VERTEX_SIZE, (const GLvoid*)(offsetof(VertexData, VertexData::color)));

	// unbind buffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// 总索引
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

		offset += 4; // offset 递增
	}

	m_IBO = new IndexBuffer(indices, RENDER_INDICES_SIZE);
	glBindVertexArray(0);
}

