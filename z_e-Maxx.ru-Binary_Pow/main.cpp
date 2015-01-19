/*
 * main.cpp
 *
 *  Created on: Dec 15, 2014
 *      Author: trankien
 */

//Tính a ^ b nhanh

#include <stdio.h>

int binpow1(int a, int n)
{
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return binpow1(a, n - 1) * a;
	else
	{
		int b = binpow1(a, n / 2);
		return b * b;
	}
}

int binpow2(int a, int n)
{
	int res = 1;
	while (n)
		if (n & 1)
		{
			res *= a;
			--n;
		}
		else
		{
			a *= a;
			n >>= 1;
		}
	return res;
}

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d ^ %d = %d.", a, b, binpow1(a, b));
	return 0;
}

