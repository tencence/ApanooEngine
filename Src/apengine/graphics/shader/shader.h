#ifndef __SHADER_H__
#define __SHADER_H__

#include "GL/glew.h"
#include "../../utils/FileUtils.h"

class Shader
{
public:
	~Shader();

	Shader(const char* vertPath, const char* fragPath);

	void enable() const;  // ����
	void diable() const;  // ����

private:
	GLuint load();        // ���� shader

private:
	GLuint m_ShaderID;
	const char* m_VertPath;
	const char* m_FragPath;
};

#endif