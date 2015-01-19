/*
 * main.cpp
 *
 *  Created on: Dec 20, 2014
 *      Author: trankien
 */

#include <stdio.h>

void printArray(int* a, int n);

int main()
{
	int n, k, i;
	scanf("%d%d", &n, &k);
	int* a = new int[k];
	for (int i = 0; i < k; i++)
	{
		*(a + i) = i + 1;
	}
	do
	{
		printArray(a, k);
		i = k - 1;
		while (i >= 0 && *(a + i) == n - k + i + 1)
		{
			i--;
		}
		if (i >= 0)
		{
			*(a + i) = *(a + i) + 1;
			for (int j = i + 1; j < k; j++)
			{
				*(a + j) = *(a + j - 1) + 1;
			}
		}
	} while (i >= 0);
	delete[] a;
	return 0;
}

inline void printArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", *(a + i));
	}
	printf("\n");
}

