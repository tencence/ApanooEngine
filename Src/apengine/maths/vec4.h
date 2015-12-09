/*
*  author : Ì·½õÖ¾
*  email  : apanoo@126.com
*  time   : 2015 12 09
*/

#ifndef __VEC4_H__
#define __VEC4_H__

#include <iostream>

struct vec4
{
	float x, y, z, w;
	vec4();
	vec4(const float &x, const float &y, const float &z, const float &w);

	vec4& add(const vec4& other);
	vec4& subtract(const vec4& other);
	vec4& mutiply(const vec4& other);
	vec4& divide(const vec4& other);

	// ²Ù×÷·û
	friend vec4& operator+(vec4 left, const vec4& right);
	friend vec4& operator-(vec4 left, const vec4& right);
	friend vec4& operator*(vec4 left, const vec4& right);
	friend vec4& operator/(vec4 left, const vec4& right);

	bool operator==(const vec4& other);
	bool operator!=(const vec4& other);

	vec4& operator+=(const vec4& other);
	vec4& operator-=(const vec4& other);
	vec4& operator*=(const vec4& other);
	vec4& operator/=(const vec4& other);

	friend std::ostream& operator<<(std::ostream& stream, const vec4& vector);
};

#endif // !__VEC4_H__