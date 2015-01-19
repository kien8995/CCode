/*
 * main.cpp
 *
 *  Created on: Dec 25, 2014
 *      Author: trankien
 */

/* Selection sort is like: you have face up cards and you can see all at a time.
 * First pick up the maximum numbered card, and then choose the next best maximum number and keeping them in hand in order.
 * Continue till all the cards exhausted. So the idea is (for increasing order sort),
 * scan through the list of numbers and find the maximum and swap it to the last number.
 * Now scan through remaining numbers excluding the last one to find the next best maximum.
 * And now swap with the last number of the remaining numbers.
 * Continue till all the numbers are done.
 * See below example output to see the operation.
 Best, Average and Worst case performance are O(N^2).
 In-place and can be implemented as Stable.
 - See more at: http://www.sourcetricks.com/2013/03/selection-sort.html#.VJw9Sshqg */

#include <iostream>
using namespace std;
const int INPUT_SIZE = 10;
void print(int *input)
{
	for (int i = 0; i < INPUT_SIZE; i++)
		cout << input[i] << " ";
	cout << endl;
}
void selectionsort(int* input)
{
	for (int i = INPUT_SIZE - 1; i > 0; i--)
	{
		//identify which is the max from the remaining numbers.
		int maxPos = 0;
		for (int j = 1; j <= i; j++)
		{
			if (input[maxPos] < input[j])
			{
				maxPos = j;
			}
		}
		// Swap it with the last of the remaining numbers.
		int tmp = input[maxPos];
		input[maxPos] = input[i];
		input[i] = tmp;
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
	selectionsort(input);
	cout << "Output: ";
	print(input);
	return 0;
}
