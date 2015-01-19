/*
 * main.cpp
 *
 *  Created on: Dec 26, 2014
 *      Author: trankien
 */

#include<stdio.h>

// Maximum number of digits in output
#define MAX 50

// prints the smallest number whose digits multiply to n
void findSmallest(int n)
{
	int i, j = 0;
	int res[MAX]; // To sore digits of result in reverse order

	// Case 1: If number is smaller than 10
	if (n < 10)
	{
		printf("%d", n + 10);
		return;
	}

	// Case 2: Start with 9 and try every possible digit
	for (i = 9; i > 1; i--)
	{
		// If current digit divides n, then store all
		// occurrences of current digit in res
		while (n % i == 0)
		{
			n = n / i;
			res[j] = i;
			j++;
		}
	}

	// If n could not be broken in form of digits (prime factors of n
	// are greater than 9)
	if (n > 10)
	{
		printf("Not possible");
		return;
	}

	// Print the result array in reverse order
	for (i = j - 1; i >= 0; i--)
		printf("%d", res[i]);
}

// Driver program to test above function
int main()
{
	findSmallest(7);
	printf("\n");

	findSmallest(36);
	printf("\n");

	findSmallest(13);
	printf("\n");

	findSmallest(100);
	return 0;
}
