#include "Utils.h"

//Clipping

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a < b ? b : a;
}

int clamp(int value, int _min, int _max)
{
	return min(_max, max(_min, value));
}

//Math Operations
int abs(int val)
{
	if (val < 0)
	{
		return -val;
	}
	return val;
}

int pow(int base, int power)
{
	int hold = 1;
	if (power > 0)
	{
		for (int i = 0; i < power; i++)
		{
			hold *= base;
		}
	}
	else if (power < 0)
	{
		return -1;
	}
	return hold;
}

bool isPowerOfTwo(int val)
{
	if (val == 1)
	{
		return true;
	}
	else if (val % 2 != 0 || val <= 0)
	{
		return false;
	}
	else
	{
		while (val != 2 && val >= 2)
		{
			val /= 2;
		}
		return val == 2;
	}
}

int nextPowerOfTwo(int val)
{
	int i = 0;
	while (pow(2, i) <= val)
	{
		i++;
	}
	return pow(2, i);
}

float moveTowards(float current, float target, float maxDelta)
{
	if (target > current)
	{
		if (current + maxDelta < target)
		{
			current += maxDelta;
		}
		else
		{
			current = target;
		}
	}
	else if (target < current)
	{
		if (current - maxDelta > target)
		{
			current -= maxDelta;
		}
		else
		{
			current = target;
		}
	}
	return current;
}

//Assertions

bool assert(const char * testName, bool expression)
{
	if (expression)
	{
		std::cout << "[PASS] ";
	}
	else
	{
		std::cout << "[FAIL] ";
	}
	std::cout << testName << std::endl;
	return expression;
}

