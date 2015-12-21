#ifndef __SHADER_H__
#define __SHADER_H__

#include "../../utils/FileUtils.h"
#include "../../maths/maths.h"

class Shader
{
public:
	~Shader();

	Shader(const char* vertPath, const char* fragPath);

	void init();          // º”‘ÿ shader
	void enable();        // ∆Ù”√ shader 
	void diable() const;  // Ω˚”√ shader

	///////////////////////////////////drt uniform///////////////////////////////////////

	void setUniform1f(const GLchar* name, float value);
	void setUniform1i(const GLchar* name, int value);
	void setUniform2f(const GLchar* name, const vec2& vector);
	void setUniform3f(const GLchar* name, const vec3& vector);
	void setUniform4f(const GLchar* name, const vec4& vector);
	void setUniformMat4(const GLchar* name, const mat4 &matrix);

private:
	GLuint getUniformLocation(const GLchar* name);
	 
private:
	GLuint m_ShaderID;
	const char* m_VertPath;
	const char* m_FragPath;
};

#endif