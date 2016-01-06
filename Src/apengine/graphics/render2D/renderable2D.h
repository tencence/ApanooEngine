// ����Ⱦ����
#pragma once
#include "gl/glew.h"
#include "../buffers/buffer.h"
#include "../buffers/indexbuffer.h"
#include "../buffers/vertexarray.h"

#include "../shader/shader.h"

#include "../../maths/maths.h"
#include "Render2D.h"

// ����ṹ��
struct VertexData
{
	vec3 vertex;
	// vec4 color; // ��ʼ
	vec2 uv;       // ��������
	unsigned int color; // �Ż�
};

class renderable2D
{
public:
	renderable2D(vec3 position, vec2 size, vec4 color);

	~renderable2D();

protected:
	renderable2D() 
	{
		setUVDefault();
	}
private:
	void setUVDefault()
	{
		m_UV.push_back(vec2(0, 0));
		m_UV.push_back(vec2(0, 1));
		m_UV.push_back(vec2(1, 1));
		m_UV.push_back(vec2(1, 0));
	}

public:

	// ������Ⱦ��
	virtual void addToParent(Render2D* render)
	{
		render->addChild(this);
	}

	inline const vec3& getPosition() const { return m_Position; }
	inline const vec2& getSize() const { return m_Size; }
	inline const vec4& getColor() const { return m_Color; }
	inline const std::vector<vec2>& getUV() { return m_UV; }

public:
	vec3 m_Position;  // λ��
	vec2 m_Size;	  // ��С
	vec4 m_Color;	  // ��ɫ
	std::vector<vec2> m_UV; // ����
};