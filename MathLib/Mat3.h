#pragma once
#include "Vec3.h"
#include "Vec2.h"
#include <vector>

struct Mat3
{
	union
	{
		struct
		{
			Vec3 xAxis;
			Vec3 yAxis;
			Vec3 zAxis;
		};
		Vec3 axis[3];
		struct
		{
			float m1, m2, m3,
				m4, m5, m6,
				m7, m8, m9;
		};
		struct
		{
			float m[9];
		};
		struct
		{
			float mm[3][3];
		};
	};

	Mat3();
	Mat3(float *ptr);
	Mat3(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9);

	// implicit operator to convert mat3 into a float array
	operator float *() 
	{
		return m;
	};

	// returns vec3 objects when accessing by subscript operator
	Vec3 &operator[](const int index)
	{
		return axis[index];
	};

	// concatenates two matrices together and returns the result
	Mat3  operator*(const Mat3 &rhs) const 
	{
		Mat3 temp;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					temp.mm[i][j] = mm[i][k] * rhs.mm[k][j];
				}
			}
		}
		return temp;
	};

	Mat3  operator*(const float &rhs) const
	{
		Mat3 temp;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				temp.mm[i][j] = mm[i][j] * rhs;
			}
		}
		return temp;
	};

	Vec3  operator*(const Vec3 &rhs) const
	{
		Vec3 temp;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				//temp[j] = mm[i][j] * rhs[j];
			}
		}
		return temp;
	};
	// concatenates and assigns the result to the matrix
	Mat3 &operator*=(const Mat3 &rhs)
	{
		Mat3 temp;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; j++)
				{
					temp.mm[i][j] = mm[i][k] * rhs.mm[k][j];
				}
			}
		}
		for (int i = 0; i < 9; i++)
		{
			m[i] = temp.m[i];
		}
		return temp;
	};

	// returns true if the matrices are equal
	bool operator==(const Mat3 &rhs) const
	{
		for (int i = 0; i < 3; i++)
		{
			if (axis[i] != rhs.axis[i])
			{
				return false;
			}
		}
		return true;
	};
	// returns true if the matrices are inequal
	bool operator!=(const Mat3 &rhs) const
	{
		return !(*this == rhs);
	};

	// returns a 3x3 identity matrix
	static Mat3 identity()
	{
		return Mat3{ 1, 0, 0, 0, 1, 0, 0, 0, 1 };
	};

	// updates the matrix elements with the given values
	void set(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9);

	// updates the matrix elements with the given values from the given array
	void set(float *ptr);

	// transposes the matrix
	void transpose();
	// returns a transposed copy of the matrix
	Mat3 getTranspose() const;

	static Mat3 getTranspose(Mat3 matrix);

	Mat3 getInverted() const;

	static float getDeterminant(std::vector<std::vector<float>> matrix);

	static std::vector<std::vector<float>> Minor(std::vector<std::vector<float>> matrix, int sX, int sY);

	static Mat3 getCofactor(std::vector<std::vector<float>> matrix);

	static std::vector<std::vector<float>> PosNegMtrx(int size);

	std::vector<std::vector<float>> getVector() const;

	// returns a translation matrix with the given changes for each axis
	static Mat3 translation(float x, float y);

	// returns a translation matrix with the given changes for each axis
	static Mat3 translation(const Vec2 &vec);

	// returns a rotation matrix with the given rotation
	static Mat3 rotation(float rot);

	// returns a translation matrix with the given changes for each axis
	static Mat3 scale(float xScale, float yScale);
	void setRotationX(float rot);
	void setRotationY(float rot);
	void setRotationZ(float rot);

	// returns a translation matrix with the given changes for each axis
	static Mat3 scale(const Vec2 &vec);
};