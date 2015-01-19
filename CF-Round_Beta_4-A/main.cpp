/*
 * main.cpp
 *
 *  Created on: Dec 13, 2014
 *      Author: trankien
 */

//http://codeforces.com/problemset/problem/4/A

#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	if (n % 2 == 0 && n != 2)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
	return 0;
}

