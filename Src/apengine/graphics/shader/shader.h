#ifndef __SHADER_H__
#define __SHADER_H__

#include "../../utils/FileUtils.h"
#include <GL/gl.h>

#ifdef __cplusplus

#define BUFFER_OFFSET(x)  ((const void*) (x))

extern "C" {
#endif  // __cplusplus

class Shader
{
public:
	~Shader();

	Shader(const char* vertPath, const char* fragPath);

	void init();          // º”‘ÿ shader
	void enable() const;  // ∆Ù”√ shader 
	void diable() const;  // Ω˚”√ shader

private:

private:
	GLuint m_ShaderID;
	const char* m_VertPath;
	const char* m_FragPath;
};

#ifdef __cplusplus
};
#endif // __cplusplus

#endif