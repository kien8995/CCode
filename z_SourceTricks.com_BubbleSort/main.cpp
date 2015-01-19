/*
 * main.cpp
 *
 *  Created on: Dec 25, 2014
 *      Author: trankien
 */

/* Bubble sort is a simple sorting algorithm.
 Best case time complexity is O(n) when the list is already sorted.
 Average and Worst case complexity is O(n*n). So it is not recommended for large input sets.
 Bubble sort involves these simple steps.
 Compare adjacent items and swap them if they are not in the correct order.
 Perform the above step until no exchanges are required,
 - See more at: http://www.sourcetricks.com/2011/06/bubble-sort-in-c.html#.VJw8tshqg */

#include <iostream>
using namespace std;
static int count = 0;
const int INPUT_SIZE = 10;
void print(int *input)
{
	for (int i = 0; i < INPUT_SIZE; i++)
		cout << input[i] << " ";
	cout << endl;
}
void bubblesort(int* input)
{
	count++;
	int exchanges = 0;
	for (int i = 0; i < INPUT_SIZE; i++)
	{
		if (input[i] > input[i + 1])
		{
			int tmp = input[i];
			input[i] = input[i + 1];
			input[i + 1] = tmp;
			exchanges++;
		}
	}
	if (exchanges == 0)
		return;
	cout << "Parse " << count << ":";
	print(input);
	bubblesort(input);
}
int main()
{
	int input[INPUT_SIZE] =
	{ 500, 700, 800, 100, 300, 200, 900, 400, 1000, 600 };
	cout << "Input: ";
	print(input);
	bubblesort(input);
	cout << "Output: ";
	print(input);
	return 0;
}
