/*
 * main.cpp
 *
 *  Created on: Dec 25, 2014
 *      Author: trankien
 */

/* Counting sort works when the input is known to be withing a range.

 Create an array of size of input range.
 Go through each of the numbers in the input and increment the appropriate array value (input number is mapped as the index to array).
 Now overwrite the original input list with key values in the array and repeating as many times as that index counter holds.
 Best, Average and Worst case performance is O(N).
 Not a comparison sort.
 - See more at: http://www.sourcetricks.com/2013/03/counting-sort.html#.VJw-hshqg */

#include <iostream>
using namespace std;
const int INPUT_SIZE = 20;
const int BUCKET_K = 10;
void print(int *input)
{
    for (int i = 0; i < INPUT_SIZE; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
}
void countingsort(int *input)
{
    int CountArr[BUCKET_K] =
    { 0 };
    for (int i = 0; i < INPUT_SIZE; i++)
    {
        CountArr[input[i]]++;
    }
    int outputindex = 0;
    for (int j = 0; j < BUCKET_K; j++)
    {
        while (CountArr[j]--)
        {
            input[outputindex++] = j;
        }
    }
}
int main()
{
    int input[INPUT_SIZE] =
    { 2, 4, 6, 4, 7, 1, 4, 9, 5, 3, 7, 2, 2, 6, 9, 3, 7, 3, 4, 4 };
    cout << "Input: ";
    print(input);
    countingsort(input);
    cout << "Output: ";
    print(input);
    return 0;
}
