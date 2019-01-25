#include "Vec4.h"
#include <corecrt_math.h>

Vec4::Vec4()
{}

Vec4::Vec4(float _x, float _y, float _z, float _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

float Vec4::angleBetween(const Vec4 &rhs) const
{
	return acosf(((*this) * rhs) / (length() * rhs.length())) * 180 / (22.0f / 7.0f);
}

float Vec4::length() const
{
	return sqrtf(x * x + y * y + z * z + w * w);
}

Vec4 &Vec4::normalize()
{
	float mag = length();
	x /= mag;
	y /= mag;
	z /= mag;
	w /= mag;
	return *this;
}
Vec4 Vec4::getNormalized() const
{
	float mag = length();
	return Vec4{ x / mag, y / mag, z / mag , w / mag };
}

Vec4 &Vec4::scale(const float rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	w *= rhs;
	return *this;
}

Vec4 Vec4::getScaled(const float rhs) const
{
	return Vec4{ x * rhs, y * rhs, z * rhs , w * rhs };
}