#include "Mat3.h"
#include <cassert>

Mat3::Mat3()
{
	for (int i = 0; i < 9; i++)
	{
		m[i] = 0;
	}
}

Mat3::Mat3(float *ptr)
{
	assert(ptr != nullptr);
	for (int i = 0; i < 9; i++)
	{
		m[i] = ptr[i];
	}
}

Mat3::Mat3(float _m1, float _m2, float _m3, float _m4, float _m5, float _m6, float _m7, float _m8, float _m9)
{
	m1 = _m1;
	m2 = _m2;
	m3 = _m3;
	m4 = _m4;
	m5 = _m5;
	m6 = _m6;
	m7 = _m7;
	m8 = _m8;
	m9 = _m9;
}

// updates the matrix elements with the given values
void Mat3::set(float _m1, float _m2, float _m3, float _m4, float _m5, float _m6, float _m7, float _m8, float _m9)
{
	m1 = _m1;
	m2 = _m2;
	m3 = _m3;
	m4 = _m4;
	m5 = _m5;
	m6 = _m6;
	m7 = _m7;
	m8 = _m8;
	m9 = _m9;
}

void Mat3::set(float *ptr)
{
	assert(ptr != nullptr);
	for (int i = 0; i < 9; i++)
	{
		m[i] = ptr[i];
	}
}

void Mat3::transpose()
{
	Mat3 temp;
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			temp.mm[i][j] = mm[j][i];
		}
	}

	for (int i = 0; i < 9; i++)
	{
		m[i] = temp.m[i];
	}
}

Mat3 Mat3::getTranspose() const
{
	Mat3 temp;
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			temp.mm[i][j] = mm[j][i];
		}
	}
	return temp;
}

Mat3 Mat3::getTranspose(Mat3 matrix)
{
	Mat3 temp;
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			temp.mm[i][j] = matrix.mm[j][i];
		}
	}
	return temp;
}

Mat3 Mat3::getInverted() const
{
	Mat3 result;

	std::vector<std::vector<float>> matrix;
	matrix.resize(3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix[i].push_back(mm[i][j]);
		}
	}

	float K = 1 / getDeterminant(matrix);
	result = getTranspose(getCofactor(matrix)) * K;
	return result;
}

float Mat3::getDeterminant(std::vector<std::vector<float>> matrix)
{
	if (matrix.size() == 1)
	{
		return matrix[0][0];
	}
	else
	{
		float result = 0;
		for (int i = 0; i < matrix.size(); i++)
		{
			if (i % 2 == 0)
			{
				result += matrix[0][i] * getDeterminant(Minor(matrix, i, 0));
			}
			else
			{
				result -= matrix[0][i] * getDeterminant(Minor(matrix, i, 0));
			}
		}
		return result;
	}
}

std::vector<std::vector<float>> Mat3::Minor(std::vector<std::vector<float>> matrix, int sX, int sY)
{
	std::vector<std::vector<float>> result;
	result.resize(matrix.size() - 1);
	for (int i = 0; i < matrix.size() - 1; i++)
	{
		result[i].resize(matrix.size() - 1);
	}
	for (int j = 0; j < matrix.size(); j++)
	{
		for (int i = 0; i < matrix.size(); i++)
		{
			if (j != sY && i != sX)
			{
				if (j > sY && i > sX)
				{
					result[j - 1, i - 1] = matrix[j, i];
				}
				else if (j > sY)
				{
					result[j - 1, i] = matrix[j, i];
				}
				else if (i > sX)
				{
					result[j, i - 1] = matrix[j, i];
				}
				else
				{
					result[j, i] = matrix[j, i];
				}
			}
		}
	}

	return result;
}

Mat3 Mat3::getCofactor(std::vector<std::vector<float>> matrix)
{
	Mat3 result;
	std::vector<std::vector<float>> posNeg = PosNegMtrx(3);
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			result.mm[j][i] = getDeterminant(Minor(matrix, i, j)) * posNeg[j][i];
		}
	}
	return result;
}

std::vector<std::vector<float>> Mat3::PosNegMtrx(int size)
{
	std::vector<std::vector<float>> result;
	result.resize(size);
	for (int i = 0; i < size; i++)
	{
		result[i].resize(size);
	}
	int current = 1;
	for (int j = 0; j < size; j++)
	{
		for (int i = 0; i < size; i++)
		{
			if (size % 2 == 0)
			{
				if ((current + j) % 2 == 1)
				{
					result[j][i] = 1;
				}
				else
				{
					result[j][i] = -1;
				}
				current++;
			}
			else
			{
				if (current % 2 == 1)
				{
					result[j][i] = 1;
				}
				else
				{
					result[j][i] = -1;
				}
				current++;
			}
		}
	}
	return result;
}


std::vector<std::vector<float>> Mat3::getVector() const
{
	std::vector<std::vector<float>> matrix;
	matrix.resize(3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix[i].push_back(mm[i][j]);
		}
	}
	return matrix;
}

// returns a translation matrix with the given changes for each axis
Mat3 Mat3::translation(float x, float y)
{
	return Mat3{ 1, 0, x, 0, 1, y, 0, 0, 1 };
}

// returns a translation matrix with the given changes for each axis
Mat3 Mat3::translation(const Vec2 &vec)
{
	return Mat3{ 1, 0, vec.x, 0, 1, vec.y, 0, 0, 1 };
}

// returns a rotation matrix with the given rotation
Mat3 Mat3::rotation(float rot)
{
	return Mat3{ cosf(rot * (22.0f / 7.0f) / 180), asinf(rot * (22.0f / 7.0f) / 180), 0, sinf(rot * (22.0f / 7.0f) / 180), cosf(rot * (22.0f / 7.0f) / 180), 0, 0, 0, 1 };
}

void Mat3::setRotationX(float rot)
{
	*this = Mat3{ 1, 0, 0, 0, cosf(rot), asinf(rot), 0, sinf(rot), cosf(rot) };
}

void Mat3::setRotationY(float rot)
{
	*this = Mat3{ cosf(rot), 0, sinf(rot), 0, 1, 0, asinf(rot), 0, cosf(rot) };
}

void Mat3::setRotationZ(float rot)
{
	*this = Mat3{ cosf(rot), asinf(rot), 0, sinf(rot), cosf(rot), 0, 0, 0, 1 };
}

// returns a translation matrix with the given changes for each axis
Mat3 Mat3::scale(float xScale, float yScale)
{
	return Mat3{ xScale, 0, 0, 0, yScale, 0, 0, 0, 1 };
}

// returns a translation matrix with the given changes for each axis
Mat3 Mat3::scale(const Vec2 &vec)
{
	return Mat3{ vec.x, 0, 0, 0, vec.y, 0, 0, 0, 1 };
}



