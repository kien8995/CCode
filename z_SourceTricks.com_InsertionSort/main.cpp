/*
 * main.cpp
 *
 *  Created on: Dec 25, 2014
 *      Author: trankien
 */

/* Insertion sort similar to card ordering in your hand as you pick the cards one by one from the lot.
 * The idea of the sort is to go through numbers from the beginning towards end one by one.
 * At each time, check the number in question should be placed in the already visited numbers and move the numbers to make space for it.
 * When all the numbers are visited, the list should be sorted. See below example output to see the operation.
 Average and Worst case performance are O(N^2), best case is O(N) (--> nearly sorted input).
 Need not have full list during start and can start as the numbers arrive.
 Stable and in-place.
 Below example, uses swapping of numbers, but one could directly move the number in question to its place and make efficient block move of the needed numbers.
 - See more at: http://www.sourcetricks.com/2013/03/insertion-sort.html#.VJw8Cshqg */

#include <iostream>
using namespace std;
const int INPUT_SIZE = 10;
void print(int *input)
{
	for (int i = 0; i < INPUT_SIZE; i++)
		cout << input[i] << " ";
	cout << endl;
}
void insertionsort(int* input)
{
	for (int i = 1; i < INPUT_SIZE; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (input[j] < input[j - 1])
			{
				int tmp = input[j];
				input[j] = input[j - 1];
				input[j - 1] = tmp;
			}
			else
				break;
		}
		cout << "PASS: ";
		print(input);
	}
}
int main()
{
	int input[INPUT_SIZE] =
	{ 500, 700, 800, 100, 300, 200, 900, 400, 1000, 600 };
	cout << "Input: ";
	print(input);
	insertionsort(input);
	cout << "Output: ";
	print(input);
	return 0;
}
