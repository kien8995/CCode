/*
 * main.cpp
 *
 *  Created on: Dec 25, 2014
 *      Author: trankien
 */

/* You have plenty of assorted DoB (Date of Birth) slips, you need to sort them.
 * One way is to go through the list and place each of the slip in a month-wise column.
 * Then re-arrange inside the month column, the slips using some simple sort method.

 When the input numbers (content) are within certain range and they are uniformly distributed in that range,
 then bucket sort can be made. First we divide the range into a smaller sub-ranges called bucket or bin.
 For example if the input is between 0 to 50, divide the range into 10 sub-ranges of bucket size 5 (first bucket is 0 to 4, next one 5 to 9, etc).
 Have a some hash function to place the input numbers into one of these buckets such that always the numbers are hashed to increasing order buckets.
 In the example we just use input number divided by 5 as the hash function.

 Then starting from the lower buckets start extracting the numbers.
 If the bucket contains more than one number (mostly the case), use insertion sort method to place that number in appropriate place.
 The insertion sort works on the currnet bucket size (because lower buckets are already sorted) and hence efficiency of insertion sort should not be a concern.
 See below example output to see the operation.
 Average is O(N+k) and Worst case performance is O(N^2). k--> number of buckets
 For bucket one could use array or linkedlist. We have used a linked list which is a queue in the below example.
 Queue gives the stable sort than going with stack for example.
 If the average bucket size is huge, then have the bucket as array instead of linked list and use efficient sorting like quick sort.
 - See more at: http://www.sourcetricks.com/2013/03/bucket-sort.html#.VJw_Bshqg */

#include <iostream>
#include <queue>
using namespace std;
const int INPUT_SIZE = 20;
const int BUCKET_K = 10;
void print(int *input)
{
	for (int i = 0; i < INPUT_SIZE; i++)
		cout << input[i] << " ";
	cout << endl;
}
int hash(int n)
{
	return n / 5;
}
void doinsertionsortforbucket(int* input, int len)
{
	while (len-- > 0)
	{
		if (input[len] > input[len + 1])
		{
			int tmp = input[len];
			input[len] = input[len + 1];
			input[len + 1] = tmp;
		}
		else
			return;
	}
}
void bucketsort(int* input)
{
	queue<int> *buckets[BUCKET_K];
	for (int i = 0; i < BUCKET_K; i++)
		buckets[i] = new queue<int>;
	// Hash the input and insert the content into appropriate bucket based on hash.
	for (int i = 0; i < INPUT_SIZE; i++)
	{
		int hashValue = hash(input[i]);
		if (hashValue >= BUCKET_K)
			hashValue = BUCKET_K - 1;
		buckets[hashValue]->push(input[i]);
	}
	// extract the content from each of the buckets in order.
	// using insertion sort
	int outputidx = 0;
	for (int i = 0; i < BUCKET_K; i++)
	{
		if (buckets[i]->size() == 1)
		{
			input[outputidx++] = buckets[i]->front();
			cout << buckets[i]->front() << " | ";
			buckets[i]->pop();
		}
		if (buckets[i]->size() > 1)
		{
			while (!buckets[i]->empty())
			{
				input[outputidx] = buckets[i]->front();
				doinsertionsortforbucket(input, outputidx);
				cout << buckets[i]->front() << " ";
				buckets[i]->pop();
				outputidx++;
			}
			cout << "| ";
		}
	}
	// clear buckets.
	for (int i = 0; i < BUCKET_K; i++)
		delete buckets[i];
}
int main()
{
	int input[INPUT_SIZE] =
	{ 25, 44, 13, 34, 27, 11, 4, 9, 45, 33, 27, 28, 42, 6, 49, 31, 37, 23, 14,
			41 };
	cout << "Input: ";
	print(input);
	cout << "Bucketed list: ";
	bucketsort(input);
	cout << "\nOutput: ";
	print(input);
	return 0;
}
