#pragma once
#include "Vec4.h"
#include "Vec3.h"
#include <vector>

struct Mat4
{
	union
	{
		struct
		{
			Vec4 xAxis;
			Vec4 yAxis;
			Vec4 zAxis;
			Vec4 wAxis;
		};
		Vec4 axis[4];
		struct
		{
			float m1, m2, m3, m4, 
				m5, m6, m7, m8, 
				m9, m10, m11, m12,
				m13, m14, m15, m16;
		};
		struct
		{
			float m[16];
		};
		struct
		{
			float mm[4][4];
		};
	};

	Mat4();
	Mat4(float *ptr);
	Mat4(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15, float m16);

	// implicit operator to convert Mat4 into a float array
	operator float *()
	{
		return m;
	};

	// returns Vec4 objects when accessing by subscript operator
	Vec4 &operator[](const int index)
	{
		return axis[index];
	};

	// concatenates two matrices together and returns the result
	Mat4  operator*(const Mat4 &rhs) const
	{
		Mat4 temp;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					temp.mm[i][j] = mm[i][k] * rhs.mm[k][j];
				}
			}
		}
		return temp;
	};

	Mat4  operator*(const float &rhs) const
	{
		Mat4 temp;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				temp.mm[i][j] = mm[i][j] * rhs;
			}
		}
		return temp;
	};

	Vec4  operator*(const Vec4 &rhs) const
	{
		Vec4 temp;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				//temp[j] = mm[i][j] * rhs[j];
			}
		}
		return temp;
	};
	// concatenates and assigns the result to the matrix
	Mat4 &operator*=(const Mat4 &rhs)
	{
		Mat4 temp;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; j++)
				{
					temp.mm[i][j] = mm[i][k] * rhs.mm[k][j];
				}
			}
		}
		for (int i = 0; i < 16; i++)
		{
			m[i] = temp.m[i];
		}
		return temp;
	};

	// returns true if the matrices are equal
	bool operator==(const Mat4 &rhs) const
	{
		for (int i = 0; i < 4; i++)
		{
			if (axis[i] != rhs.axis[i])
			{
				return false;
			}
		}
		return true;
	};
	// returns true if the matrices are inequal
	bool operator!=(const Mat4 &rhs) const
	{
		return !(*this == rhs);
	};

	// returns a 3x3 identity matrix
	static Mat4 identity()
	{
		return Mat4{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
	};

	// updates the matrix elements with the given values
	void set(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15, float m16);

	// updates the matrix elements with the given values from the given array
	void set(float *ptr);

	// transposes the matrix
	void transpose();
	// returns a transposed copy of the matrix
	Mat4 getTranspose() const;

	static Mat4 getTranspose(Mat4 matrix);

	Mat4 getInverted() const;

	static float getDeterminant(std::vector<std::vector<float>> matrix);

	static std::vector<std::vector<float>> Minor(std::vector<std::vector<float>> matrix, int sX, int sY);

	static Mat4 getCofactor(std::vector<std::vector<float>> matrix);

	static std::vector<std::vector<float>> PosNegMtrx(int size);

	std::vector<std::vector<float>> getVector() const;

	// returns a translation matrix with the given changes for each axis
	static Mat4 translation(float x, float y, float z);

	// returns a translation matrix with the given changes for each axis
	static Mat4 translation(const Vec3 &vec);

	// returns a rotation matrix with the given rotation
	static Mat4 rotationX(float rot);
	static Mat4 rotationY(float rot);
	static Mat4 rotationZ(float rot);

	void setRotationX(float rot);
	void setRotationY(float rot);
	void setRotationZ(float rot);

	// returns a translation matrix with the given changes for each axis
	static Mat4 scale(float xScale, float yScale, float zScale);

	// returns a translation matrix with the given changes for each axis
	static Mat4 scale(const Vec3 &vec);
};