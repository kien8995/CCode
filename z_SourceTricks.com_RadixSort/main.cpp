/*
 * main.cpp
 *
 *  Created on: Dec 25, 2014
 *      Author: trankien
 */

/* Radix sort orders the contents position by position.
 * For ease of understanding here we restrict for numbers, but it should work with floats, strings, etc.
 * It is a non-comparitive sort unlike many others which need comparison.
 * The idea is: position by position, either starting from LSB or MSB, group the numbers into buckets.
 * When you move to next position again re-order them for that position, while keeping the order of the previous position re-orders.
 * Once all the positions are done, the whole list should be ordered.
 * See, below example output on how the numbers get re-ordered at each pass of position ordering.
 Worst case performance is O(kN), k is count of decimal places and N is the input size. Note that we don't take out k.
 In the below example implementation, for re-order of the numbers for each decimal places,
 instead of doing lots of swaps, we have taken a simple approach. We do two level counting,
 first occurrence of numbers for each of the possibilities (0, 1,2 ..9) and then second we use that information to find the appropriate positions for placing all the numbers.
 A temporary buffer is used to place first and then we copy back to original buffer for next level processing.
 - See more at: http://www.sourcetricks.com/2013/03/radix-sort.html#.VJw9ishqg */

#include <iostream>
using namespace std;
void print(int *input, int n)
{
	for (int i = 0; i < n; i++)
		cout << input[i] << "\t";
}
void radixsort(int *input, int n)
{
	int i;
// find the max number in the given list.
// to be used in loop termination part.
	int maxNumber = input[0];
	for (i = 1; i < n; i++)
	{
		if (input[i] > maxNumber)
			maxNumber = input[i];
	}
// run the loop for each of the decimal places
	int exp = 1;
	int *tmpBuffer = new int[n];
	while (maxNumber / exp > 0)
	{
		int decimalBucket[10] =
		{ 0 };
// count the occurences in this decimal digit.
		for (i = 0; i < n; i++)
			decimalBucket[input[i] / exp % 10]++;
// Prepare the position counters to be used for re-ordering the numbers
// for this decimal place.
		for (i = 1; i < 10; i++)
			decimalBucket[i] += decimalBucket[i - 1];
// Re order the numbers in the tmpbuffer and later copy back to original buffer.
		for (i = n - 1; i >= 0; i--)
			tmpBuffer[--decimalBucket[input[i] / exp % 10]] = input[i];
		for (i = 0; i < n; i++)
			input[i] = tmpBuffer[i];
// Move to next decimal place.
		exp *= 10;
		cout << "\nPASS : ";
		print(input, n);
	}
}
const int INPUT_SIZE = 10;
int main()
{
	int input[INPUT_SIZE] =
	{ 143, 123, 222, 186, 235, 9, 905, 428, 543, 373 };
	cout << "Input: ";
	print(input, INPUT_SIZE);
	radixsort(input, INPUT_SIZE);
	cout << "\nOutput: ";
	print(input, INPUT_SIZE);
	cout << "\n";
	return 0;
}

