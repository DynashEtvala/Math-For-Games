#pragma once

struct Vec2
{
	float x, y;

	Vec2();
	Vec2(float _x, float _y);

	Vec2 operator+(const Vec2 &rhs) const { return Vec2{ x + rhs.x, y + rhs.y }; };
	Vec2 operator-(const Vec2 &rhs) const { return Vec2{ x - rhs.x, y - rhs.y }; };
	float operator*(const Vec2 &rhs) const { return x * rhs.x + y * rhs.y; }

	Vec2 &operator+=(const Vec2 &rhs)
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	};
	Vec2 &operator-=(const Vec2 &rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	};

	bool operator==(const Vec2 rhs) const 
	{
		if (rhs.x >= x - 0.000005f && rhs.y >= y - 0.000005f && rhs.x <= x + 0.000005f && rhs.y <= y + 0.000005f)
		{
			return true;
		}
		return false;
	};
	bool operator!=(const Vec2 rhs) const
	{
		return !(rhs == *this);
	};

	Vec2 operator-() const { return Vec2{ x * -1, y * -1 }; };

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
		throw "Index out of bounds.";
	};

	operator float *() { return &x; };
	operator const float *() const { return &x; };

	float dot(const Vec2 &rhs) { return *this * rhs; };

	Vec2 getPerpCW() const;
	Vec2 getPerpCCW() const;

	float angleBetween(const Vec2 &rhs) const;

	float length() const;

	Vec2 &normalize();
	Vec2 getNormalized() const;

	Vec2 &scale(const float rhs);
	Vec2 getScaled(const float rhs) const;

	Vec2 operator*(const float rhs) const { return getScaled(rhs); };
	friend Vec2 operator*(const float lhs, const Vec2 &rhs) { return Vec2{ lhs * rhs.x, lhs * rhs.y }; };

	Vec2 &operator*=(const float rhs) { return scale(rhs); };
	Vec2 &operator/=(const float rhs) 
	{
		x /= rhs;
		y /= rhs;
		return *this;
	};
};
