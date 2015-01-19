/*
 * main.cpp
 *
 *  Created on: Dec 15, 2014
 *      Author: trankien
 */

//Thuật toán Euclid tìm ước chung lớn nhất và bội chung nhỏ nhất
#include <stdio.h>
#include <algorithm>

//int gcd (int a, int b) {
//	if (b == 0)
//		return a;
//	else
//		return gcd (b, a % b);
//}

//or

int gcd1(int a, int b)
{
	return b ? gcd1(b, a % b) : a;
}

int gcd2(int a, int b)
{
	while (b)
	{
		a %= b;
		std::swap(a, b);
	}
	return a;
}

int lcm(int a, int b)
{
	return a / gcd1(a, b) * b;
}

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("ước chung lớn nhất của %d và %d là %d.\n", a, b, gcd2(a, b));
	printf("bội chung nhỏ nhất của %d và %d là %d.", a, b, lcm(a, b));
	return 0;
}

