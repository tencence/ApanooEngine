#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

// �Ƕ�ת����
inline float toRadians(float degrees)
{
	return (float)(degrees * (M_PI / 180.0f));
}