#include "texture.h"

Texture::Texture(const std::string& filename)
	: m_Filename(filename)
{
	m_TID = load(); // ����
}

Texture::~Texture()
{

}

void Texture::bind() const
{
	glBindTexture(GL_TEXTURE_2D, m_TID);
}

void Texture::unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

GLuint Texture::load()
{
	BYTE* pixels = ImageUtils::load_image(m_Filename.c_str(), &m_Width, &m_Height);

	GLuint result;
	glGenTextures(1, &result); // ��������ID
	glBindTexture(GL_TEXTURE_2D, result);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// ��������
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_Width, m_Height, 0, GL_BGR, GL_UNSIGNED_BYTE, pixels);

	glBindTexture(GL_TEXTURE_2D, 0);

	// ��������ID
	return result; 
}

