#include <cstdlib>
#include <iostream>

#define GLEW_STATIC
#include "GL/glew.h"

#include "shader.h"
#include <vector>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
//////////////////////////////////////////////////////////////////////////

Shader::~Shader()
{
	glDeleteProgram(m_ShaderID);
}

Shader::Shader(const char* vertPath, const char* fragPath)
: m_VertPath(vertPath), m_FragPath(fragPath)
{
	
}

void Shader::enable() const
{
	glUseProgram(m_ShaderID);
}

void Shader::diable() const
{
	glUseProgram(0);
}

void Shader::init()
{
	GLuint program = glCreateProgram();  // bug --? ±¿¿£

	GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

	std::string vertSourceString = FileUtils::ReadFile(m_VertPath);
	std::string fragSourceString = FileUtils::ReadFile(m_FragPath);

	const char* vertSource = vertSourceString.c_str();
	const char* fragSource = fragSourceString.c_str();

	glShaderSource(vertex, 1, &vertSource, NULL);
	glCompileShader(vertex);   // ±‡“Î
	GLint result;
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)    // ≤∂ªÒ±‡“Î¥ÌŒÛ–≈œ¢
	{
		GLint length;
		glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
		std::vector<char> error(length);
		glGetShaderInfoLog(vertex, length, &length, &error[0]);
		// log("error compile vertex shader");
		// log(&error[0]);
		glDeleteShader(vertex);
		return;
	}

	glShaderSource(fragment, 1, &fragSource, NULL);
	glCompileShader(fragment); // ±‡“Î
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)    // ≤∂ªÒ±‡“Î¥ÌŒÛ–≈œ¢
	{
		GLint length;
		glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
		std::vector<char> error(length);
		glGetShaderInfoLog(fragment, length, &length, &error[0]);
		// log("error compile fragment shader");
		// log(&error[0]);
		glDeleteShader(fragment);
		return;
	}

	// attach
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);

	// link
	glLinkProgram(program);
	glValidateProgram(program);

	// delete
	glDeleteShader(vertex);
	glDeleteShader(fragment);

	m_ShaderID = program;
}

//////////////////////////////////////////////////////////////////////////
#ifdef __cplusplus
}
#endif // __cplusplus