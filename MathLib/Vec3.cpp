#include "Vec3.h"
#include <corecrt_math.h>

Vec3::Vec3()
{}

Vec3::Vec3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

float Vec3::angleBetween(const Vec3 &rhs) const
{
	return acosf(((*this) * rhs) / (length() * rhs.length())) * 180 / (22.0f / 7.0f);
}

float Vec3::length() const
{
	return sqrtf(x * x + y * y + z * z);
}

Vec3 &Vec3::normalize()
{
	float mag = length();
	x /= mag;
	y /= mag;
	z /= mag;
	return *this;
}
Vec3 Vec3::getNormalized() const
{
	float mag = length();
	return Vec3{ x / mag, y / mag, z / mag };
}

Vec3 &Vec3::scale(const float rhs)
{
	x *= rhs;
	y *= rhs;
	z *= rhs;
	return *this;
}

Vec3 Vec3::getScaled(const float rhs) const
{
	return Vec3{ x * rhs, y * rhs, z * rhs };
}