/*
 * main.cpp
 *
 *  Created on: Dec 26, 2014
 *      Author: trankien
 */

// A simple O(n^3) program for Pascal's Triangle
#include <stdio.h>

// See http://www.geeksforgeeks.org/archives/25621 for details of this function
int binomialCoeff(int n, int k);

// Function to print first n lines of Pascal's Triangle
void printPascal(int n)
{
	// Iterate through every line and print entries in it
	for (int line = 0; line < n; line++)
	{
		// Every line has number of integers equal to line number
		for (int i = 0; i <= line; i++)
			printf("%d ", binomialCoeff(line, i));
		printf("\n");
	}
}

// See http://www.geeksforgeeks.org/archives/25621 for details of this function
int binomialCoeff(int n, int k)
{
	int res = 1;
	if (k > n - k)
		k = n - k;
	for (int i = 0; i < k; ++i)
	{
		res *= (n - i);
		res /= (i + 1);
	}
	return res;
}

// Driver program to test above function
int main()
{
	int n = 7;
	printPascal(n);
	return 0;
}
