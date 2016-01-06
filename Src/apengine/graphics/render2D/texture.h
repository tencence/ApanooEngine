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

	// 绑定纹理
	void bind() const;

	// 解除绑定
	void unbind() const;
	inline const unsigned int getID() const { return m_TID; }
	inline const unsigned int getWidth() { return m_Width; }
	inline const unsigned int getHeight() { return m_Height; }

private:
	// 加载纹理
	GLuint load();

private:
	std::string m_Filename; // 文件名
	GLuint m_TID;           //　文理ID
	GLsizei m_Width, m_Height;
};
