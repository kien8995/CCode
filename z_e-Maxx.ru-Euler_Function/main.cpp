/*
 * main.cpp
 *
 *  Created on: Dec 14, 2014
 *      Author: trankien
 */

/*
 * Hàm số Euler tính số các số đồng nguyên tố với n
 *
 */

#include <stdio.h>

int phi(int n)
{
	int result = n;
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0)
		{
			while (n % i == 0)
			{
				n /= i;
			}
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}

//------------------
int main()
{
	int n;
	printf("nhập n: ");
	scanf("%d", &n);
	printf("từ 1 đển %d có %d số đồng nguyên tố với %d.", n, phi(n), n);
	return 0;
}

