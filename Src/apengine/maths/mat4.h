/*
*  author : ̷��־
*  email  : apanoo@126.com
*  time   : 2015 12 09
*/
#ifndef __MAT4_H__
#define __MAT4_H__

#include "vec3.h"
#include "mathUtils.h"

struct mat4
{
	float elements[4 * 4];

	mat4();
	mat4(float diagonal);

	// ���
	mat4& multiply(const mat4& other);

	// ��λ����
	static mat4 identity();

	// ��������
	static mat4 orthographic(float left, float right, float bottom, float top, float near, float far);

	// ͸�Ӿ���
	static mat4 perspective(float fov, float aspectRatio, float near, float far);

	// ƽ�ƾ���
	static mat4 translation(const vec3& translation);

	// ��ת����
	static mat4 rotation(float angle, const vec3& axis);

	// ��������
	static mat4 scale(const vec3& scale);

	// ������
	friend mat4 operator*(mat4 left, const mat4& right);
	mat4 operator*=(const mat4& other);


}; 

#endif // !__MAT4_H__
