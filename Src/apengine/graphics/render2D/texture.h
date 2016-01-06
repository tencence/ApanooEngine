#pragma once
#include "freeimage.h"
#include <string>
#include "gl/glew.h"
#include "../../utils/ImageLoad.h"

class Texture
{
public:
	Texture(const std::string& filename);
	~Texture();

	// ������
	void bind() const;

	// �����
	void unbind() const;
	inline const unsigned int getID() const { return m_TID; }
	inline const unsigned int getWidth() { return m_Width; }
	inline const unsigned int getHeight() { return m_Height; }

private:
	// ��������
	GLuint load();

private:
	std::string m_Filename; // �ļ���
	GLuint m_TID;           //������ID
	GLsizei m_Width, m_Height;
};
