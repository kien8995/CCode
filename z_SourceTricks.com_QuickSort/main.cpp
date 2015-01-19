/*
 * main.cpp
 *
 *  Created on: Dec 25, 2014
 *      Author: trankien
 */

/* Quick Sort is a sorting algorithm. It is also referred as partition exchange sort.
 In the best/ average case it gives a time complexity of O(nlogn) and worst case time complexity of O(n*n).
 Can be implemented as in-place sorting without need for additional space.
 Quick Sorting involves these steps:
 Pick a pivot element from the input list.
 Perform an input partition operation based on the pivot. Move all elements less than pivot before the pivot element in the list.
 Move all elements greater than the pivot after the pivot element in the list.
 Recursively sort the left and right sub-lists of the pivot.
 - See more at: http://www.sourcetricks.com/2011/06/what-is-quick-sort-algorithm-how-to.html#.VJw84shqg */

#include <iostream>
using namespace std;
const int INPUT_SIZE = 10; // A simple print function
void print(int *input)
{
	for (int i = 0; i < INPUT_SIZE; i++)
		cout << input[i] << " ";
	cout << endl;
}
// The partition function
int partition(int* input, int p, int r)
{
	int pivot = input[r];
	while (p < r)
	{
		while (input[p] < pivot)
			p++;
		while (input[r] > pivot)
			r--;
		if (input[p] == input[r])
			p++;
		else if (p < r)
		{
			int tmp = input[p];
			input[p] = input[r];
			input[r] = tmp;
		}
	}
	return r;
}
// The quicksort recursive function
void quicksort(int* input, int p, int r)
{
	if (p < r)
	{
		int j = partition(input, p, r);
		quicksort(input, p, j - 1);
		quicksort(input, j + 1, r);
	}
}
int main()
{
	int input[INPUT_SIZE] =
	{ 500, 700, 800, 100, 300, 200, 900, 400, 1000, 600 };
	cout << "Input: ";
	print(input);
	quicksort(input, 0, 9);
	cout << "Output: ";
	print(input);
	return 0;
}
