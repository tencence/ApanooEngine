/*
*  author : ̷��־
*  email  : apanoo@126.com
*  time   : 2015 12 09
*/
#ifndef __MAT4_H__
#define __MAT4_H__

#include "vec3.h"
#include "vec4.h"
#include "mathUtils.h"

struct mat4
{
	union  // 4 * 16 �ֽ� == 4 * 4 * 4 �ֽ���elementsÿ�ĸ�Ԫ���൱�ھ����һ��
	{
		float elements[4 * 4];
		vec4 columns[4];
	};

	mat4();
	mat4(float diagonal);

	// getColum
	vec4 getCloum(int index)
	{
		index *= 4;
		return vec4(elements[index + 1], elements[index + 2], elements[index + 3], elements[index + 4]);
	}


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

	// ���
	mat4& multiply(const mat4& other);
	vec3 multiply(const vec3& vec) const;
	vec4 multiply(const vec4& vec) const; 
	// ������
	friend mat4 operator*(mat4 left, const mat4& right);
	friend vec3 operator*(const mat4& left, const vec3& right);
	friend vec4 operator*(const mat4& left, const vec4& right);
	mat4 operator*=(const mat4& other);
}; 

#endif // !__MAT4_H__
