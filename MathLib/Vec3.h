#pragma once
struct Vec3
{
	float x, y, z;

	Vec3();
	Vec3(float _x, float _y, float _z);

	Vec3 operator+(const Vec3 &rhs) const { return Vec3{ x + rhs.x, y + rhs.y, z + rhs.z }; };
	Vec3 operator-(const Vec3 &rhs) const { return Vec3{ x - rhs.x, y - rhs.y, z - rhs.z }; };
	float operator*(const Vec3 &rhs) const { return x * rhs.x + y * rhs.y + z * rhs.z; }

	Vec3 &operator+=(const Vec3 &rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	};
	Vec3 &operator-=(const Vec3 &rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		return *this;
	};

	bool operator==(const Vec3 rhs) const
	{
		if (rhs.x >= x - 0.005f && rhs.y >= y - 0.005f && rhs.z >= z - 0.005f && rhs.x <= x + 0.005f && rhs.y <= y + 0.005f && rhs.z <= z + 0.005f)
		{
			return true;
		}
		return false;
	};
	bool operator!=(const Vec3 rhs) const
	{
		return !(rhs == *this);
	};

	Vec3 operator-() const { return Vec3{ x * -1, y * -1, z * -1 }; };

	float &operator[](size_t idx)
	{
		if (idx == 0)
		{
			return x;
		}
		if (idx == 1)
		{
			return y;
		}
		if (idx == 2)
		{
			return z;
		}
		throw "Index out of bounds.";
	};
	float operator[](size_t idx) const
	{
		if (idx == 0)
		{
			return x;
		}
		if (idx == 1)
		{
			return y;
		}
		if (idx == 2)
		{
			return z;
		}
		throw "Index out of bounds.";
	};

	operator float *() { return &x; };
	operator const float *() const { return &x; };

	float dot(const Vec3 &rhs) { return *this * rhs; };

	float angleBetween(const Vec3 &rhs) const;

	float length() const;

	Vec3 &normalize();
	Vec3 getNormalized() const;

	Vec3 &scale(const float rhs);
	Vec3 getScaled(const float rhs) const;

	Vec3 operator*(const float rhs) const { return getScaled(rhs); };
	friend Vec3 operator*(const float lhs, const Vec3 &rhs) { return Vec3{ lhs * rhs.x, lhs * rhs.y, lhs * rhs.z }; };

	Vec3 &operator*=(const float rhs) { return scale(rhs); };
	Vec3 &operator/=(const float rhs)
	{
		x /= rhs;
		y /= rhs;
		z /= rhs;
		return *this;
	};

	Vec3 cross(const Vec3 rhs)
	{
		return Vec3{ y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x };
	};
};

