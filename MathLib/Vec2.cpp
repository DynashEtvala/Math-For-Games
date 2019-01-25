#include "Vec2.h"
#include <corecrt_math.h>

Vec2::Vec2()
{
	x = y = 0;
}

Vec2::Vec2(float _x, float _y)
{
	x = _x;
	y = _y;
}

Vec2 Vec2::getPerpCW() const
{
	return Vec2{ y, -x };
}

Vec2 Vec2::getPerpCCW() const
{
	return Vec2{ -y, x };
}

float Vec2::angleBetween(const Vec2 &rhs) const
{
	return acosf(((*this) * rhs) / (length() * rhs.length())) * 180 / (22.0f / 7.0f);
}

float Vec2::length() const
{
	return sqrtf(x * x + y * y);
}

Vec2 &Vec2::normalize()
{
	float mag = length();
	x /= mag;
	y /= mag;
	return *this;
}

Vec2 Vec2::getNormalized() const
{
	float mag = length();
	return Vec2{ x / mag, y / mag };
}

Vec2 &Vec2::scale(const float rhs)
{
	x *= rhs;
	y *= rhs;
	return *this;
}

Vec2 Vec2::getScaled(const float rhs) const
{
	return Vec2{ x * rhs, y * rhs };
}

