/*
*  author : Ì·½õÖ¾
*  email  : apanoo@126.com
*  time   : 2015 12 09
*/

#ifndef __VEC2_H__
#define __VEC2_H__

#include <iostream>

struct vec2
{
	float x, y;
	vec2();
	vec2(const float &x, const float &y);

	vec2& add(const vec2& other); 
	vec2& subtract(const vec2& other);
	vec2& mutiply(const vec2& other);
	vec2& divide(const vec2& other);

	// ²Ù×÷·û
	friend vec2 operator+(vec2 left, const vec2& right);
	friend vec2 operator-(vec2 left, const vec2& right);
	friend vec2 operator*(vec2 left, const vec2& right);
	friend vec2 operator/(vec2 left, const vec2& right);

	bool operator==(const vec2& other);
	bool operator!=(const vec2& other);

	vec2& operator+=(const vec2& other);
	vec2& operator-=(const vec2& other);
	vec2& operator*=(const vec2& other);
	vec2& operator/=(const vec2& other);

	friend std::ostream& operator<<(std::ostream& stream, const vec2& vector);
};

#endif // !__VEC2_H__