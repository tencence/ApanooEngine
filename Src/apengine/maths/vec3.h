/*
*  author : Ì·½õÖ¾
*  email  : apanoo@126.com
*  time   : 2015 12 09
*/

#ifndef __VEC3_H__
#define __VEC3_H__

#include <iostream>

struct vec3
{
	float x, y, z;
	vec3();
	vec3(const float &x, const float &y, const float &z);

	vec3& add(const vec3& other); 
	vec3& subtract(const vec3& other);
	vec3& mutiply(const vec3& other);
	vec3& divide(const vec3& other);

	// ²Ù×÷·û
	friend vec3 operator+(vec3 left, const vec3& right);
	friend vec3 operator-(vec3 left, const vec3& right);
	friend vec3 operator*(vec3 left, const vec3& right);
	friend vec3 operator/(vec3 left, const vec3& right);

	bool operator==(const vec3& other);
	bool operator!=(const vec3& other);

	vec3& operator+=(const vec3& other);
	vec3& operator-=(const vec3& other);
	vec3& operator*=(const vec3& other);
	vec3& operator/=(const vec3& other);

	friend std::ostream& operator<<(std::ostream& stream, const vec3& vector);
};

#endif // !__VEC3_H__