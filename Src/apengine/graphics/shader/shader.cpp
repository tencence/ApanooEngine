#include <cstdlib>
#include <iostream>

#define GLEW_STATIC
#include "GL/glew.h"

#include "shader.h"
#include <vector>

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

///////////////////////////////set uniform///////////////////////////////////////////
void Shader::setUniform1f(const GLchar* name, float value)
{
	glUniform1f(getUniformLocation(name), value);
}

void Shader::setUniform1i(const GLchar* name, int value)
{
	glUniform1i(getUniformLocation(name), value);
}

void Shader::setUniform2f(const GLchar* name, const vec2& vector)
{
	glUniform2f(getUniformLocation(name), vector.x, vector.y);
}

void Shader::setUniform3f(const GLchar* name, const vec3& vector)
{
	glUniform3f(getUniformLocation(name), vector.x, vector.y, vector.z);
}

void Shader::setUniform4f(const GLchar* name, const vec4& vector)
{
	glUniform4f(getUniformLocation(name), vector.x, vector.y, vector.z, vector.w);
}

void Shader::setUniformMat4(const GLchar* name, const mat4 &matrix)
{
	glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix.elements);
}

GLuint Shader::getUniformLocation(const GLchar* name)
{
	return glGetUniformLocation(m_ShaderID, name);
}

//////////////////////////////////init////////////////////////////////////////
void Shader::init()
{
	GLuint program = glCreateProgram();  

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
