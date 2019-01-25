#pragma once
struct Vec4
{
	float x, y, z, w;

	Vec4();
	Vec4(float _x, float _y, float _z, float _w);

	Vec4 operator+(const Vec4 &rhs) const { return Vec4{ x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w }; };
	Vec4 operator-(const Vec4 &rhs) const { return Vec4{ x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w }; };
	float operator*(const Vec4 &rhs) const { return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w; }

	Vec4 &operator+=(const Vec4 &rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		w += rhs.w;
		return *this;
	};
	Vec4 &operator-=(const Vec4 &rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		w -= rhs.w;
		return *this;
	};

	bool operator==(const Vec4 rhs) const
	{
		if (rhs.x >= x - 0.005f && rhs.y >= y - 0.005f && rhs.z >= z - 0.005f && rhs.w >= w - 0.005f && rhs.x <= x + 0.005f && rhs.y <= y + 0.005f && rhs.z <= z + 0.005f && rhs.w <= w + 0.005f)
		{
			return true;
		}
		return false;
	};
	bool operator!=(const Vec4 rhs) const
	{
		return !(rhs == *this);
	};

	Vec4 operator-() const { return Vec4{ x * -1, y * -1, z * -1, w * -1 }; };

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
		if (idx == 3)
		{
			return w;
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
		if (idx == 3)
		{
			return w;
		}
		throw "Index out of bounds.";
	};

	operator float *() { return &x; };
	operator const float *() const { return &x; };

	float dot(const Vec4 &rhs) { return *this * rhs; };

	float angleBetween(const Vec4 &rhs) const;

	float length() const;

	Vec4 &normalize();
	Vec4 getNormalized() const;

	Vec4 &scale(const float rhs);
	Vec4 getScaled(const float rhs) const;

	Vec4 operator*(const float rhs) const { return getScaled(rhs); };
	friend Vec4 operator*(const float lhs, const Vec4 &rhs) { return Vec4{ lhs * rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w }; };

	Vec4 &operator*=(const float rhs) { return scale(rhs); };
	Vec4 &operator/=(const float rhs)
	{
		x /= rhs;
		y /= rhs;
		z /= rhs;
		w /= rhs;
		return *this;
	}; 
	
	Vec4 cross(const Vec4 rhs)
	{
		return Vec4{ y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x, w };
	};
};

