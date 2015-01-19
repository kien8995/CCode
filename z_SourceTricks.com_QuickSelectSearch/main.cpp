/*
 * main.cpp
 *
 *  Created on: Dec 25, 2014
 *      Author: trankien
 */

/* The QuickSelect algorithm quickly finds the k-th smallest element of an unsorted array of n elements.
 *
 *It is an O(n), worst-case linear time, selection algorithm.
 *It A typical selection by sorting method would need atleast O(n log n) time.
 *It This algorithm is identical to quick sort but it does only a partial sort,
 *It since we already know which partition our desired element lies as the pivot is in final sorted position.
 *It - See more at: http://www.sourcetricks.com/2011/06/quick-select.html#.VJw_3shqg */

#include <iostream>
using namespace std;
// A simple print function
void print(int *input)
{
	for (int i = 0; i < 5; i++)
		cout << input[i] << " ";
	cout << endl;
}
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
int quick_select(int* input, int p, int r, int k)
{
	if (p == r)
		return input[p];
	int j = partition(input, p, r);
	int length = j - p + 1;
	if (length == k)
		return input[j];
	else if (k < length)
		return quick_select(input, p, j - 1, k);
	else
		return quick_select(input, j + 1, r, k - length);
}
int main()
{
	int A1[] =
	{ 100, 400, 300, 500, 200 };
	cout << "1st order element " << quick_select(A1, 0, 4, 1) << endl;
	int A2[] =
	{ 100, 400, 300, 500, 200 };
	cout << "2nd order element " << quick_select(A2, 0, 4, 2) << endl;
	int A3[] =
	{ 100, 400, 300, 500, 200 };
	cout << "3rd order element " << quick_select(A3, 0, 4, 3) << endl;
	int A4[] =
	{ 100, 400, 300, 500, 200 };
	cout << "4th order element " << quick_select(A4, 0, 4, 4) << endl;
	int A5[] =
	{ 100, 400, 300, 500, 200 };
	cout << "5th order element " << quick_select(A5, 0, 4, 5) << endl;
}
