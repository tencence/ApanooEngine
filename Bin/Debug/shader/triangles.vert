#version 330 core

layout(location = 0) in vec4 position;  // 位置
layout(location = 1) in vec2 uv;		// texture坐标
layout(location = 2) in float tid;		// texture ID
layout(location = 3) in vec4 color;	 	// 颜色

uniform mat4 pr_matrix;                 // 正交视角矩阵
uniform mat4 vw_matrix = mat4(1.0); 	// 视图矩阵
uniform mat4 ml_matrix = mat4(1.0);		// 模型矩阵

out DATA
{
	vec4  position; 
	vec2  uv;
	float tid;
	vec4  color;
} vs_out;

void main()
{
	gl_Position = pr_matrix * vw_matrix * ml_matrix * position;
	vs_out.position = ml_matrix * position;
	vs_out.uv = uv;
	vs_out.tid = tid;
	vs_out.color = color;
}