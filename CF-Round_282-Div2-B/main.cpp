/*
 * main.cpp
 *
 *  Created on: Dec 13, 2014
 *      Author: trankien
 */

//http://codeforces.com/contest/495/problem/B
#include <stdio.h>

int div(int x, int y);

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	if (a == b)
	{
		printf("infinity\n");
	}
	else if (a < b)
	{
		printf("0\n");
	}
	else
	{
		printf("%d\n", div(a - b, b));
	}
	return 0;
}

int div(int x, int y)
{
	int retv = 0;
	for (int i = 1; i * i <= x; i++)
	{
		if (x == i * i)
		{
			if (i > y)
			{
				retv++;
			}
		}
		else if (x % i == 0)
		{
			if (i > y)
			{
				retv++;
			}
			if (x / i > y)
			{
				retv++;
			}
		}
	}
	return retv;
}
