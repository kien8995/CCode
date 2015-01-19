/*
 * main.cpp
 *
 *  Created on: Dec 13, 2014
 *      Author: trankien
 */

//http://codeforces.com/problemset/problem/158/A

#include <stdio.h>
#include <algorithm>

int n, k, vt, x = 0;
int a[100];

bool isEqual(int i);

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] != 0 && (i + 1) <= k)
		{
			x++;
			vt = i;
		}
	}
	if (x != 0)
	{
		x += std::count_if(a + vt + 1, a + n, isEqual);
	}
	printf("%d", x);
	return 0;
}

inline bool isEqual(int i)
{
	return (i == a[vt]);
}
