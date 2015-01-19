/*
 * main.cpp
 *
 *  Created on: Dec 26, 2014
 *      Author: trankien
 */

#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <queue>
#include <utility>
#include <valarray>
#include <vector>

#define u64 unsigned long long
#define i64 long long
#define ld  long double
#define FORLE(i,a,b) for(int i = (a); i <= (int)(b); ++i)
#define FORL(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define FORGE(i,a,b) for(int i= (a); i >= (int)(b); --i)
#define FORG(i,a,b) for(int i= (a); i > (int)(b); --i)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); ++i)
#define RFORV(i,a) for(typeof(a.rbegin()) i = a.rbegin(); i != a.rend(); ++i)
#define set(a,c) memset(a, c, sizeof(a))
#define setn(a,c,n) memset(a, c, n)
#define cpy(b,a) memcpy(b,a,sizeof(a))
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
#define RS(x) scanf("%s",x)
#define PRI(x) printf("%d\n",x)
#define PRIS(x) printf("%d ",x)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1e9+7
#define INF 1e9
#define EPS 1e-7
#define PI 3.1415926535897932384626433832795028841971
#define fe(a, b) (fabs((a)-(b)) < EPS)
#define debug(k,F,n) FORL(i,0,n){FORL(j,0,n) cout << setw(k) << F[i][j] ; cout << endl;}
#define boost ios_base::sync_with_stdio(0)
#define bufo (stdout, NULL, _IONBF, 0)
#define bufi (stdin, NULL, _IONBF, 0)

//#define LOCAL_DEFINE

using namespace std;

typedef pair<int, int> II;
typedef pair<int, II> PII;
typedef vector<int> VI;
typedef vector<II> VII;
typedef set<int> SI;
typedef set<string> SS;
typedef map<string, int> MSI;
typedef map<int, int> MII;

template<class T>
inline string toStr(T x)
{
	stringstream st;
	st << x;
	string s;
	st >> s;
	return s;
}
template<class T>
inline T toNum(const string &Text)
{
	stringstream ss(Text);
	T result;
	return ss >> result ? result : 0;
}
template<class T> T gcd(T a, T b)
{
	T r;
	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
template<class T> T lcm(T a, T b)
{
	return a / gcd(a, b) * b;
}
template<class T> T sqr(T x)
{
	return x * x;
}
template<class T> T cube(T x)
{
	return x * x * x;
}
template<class T> int getbit(T s, int i)
{
	return (s >> i) & 1;
}
template<class T> T onbit(T s, int i)
{
	return s | (T(1) << i);
}
template<class T> T offbit(T s, int i)
{
	return s & (~(T(1) << i));
}
template<class T> int cntbit(T s)
{
	return s == 0 ? 0 : cntbit(s >> 1) + (s & 1);
}

//------------------
// A utility function to get the middle index from corner indexes.
int getMid(int s, int e)
{
	return s + (e - s) / 2;
}

/*  A recursive function to get the sum of values in given range of the array.
 The following are parameters for this function.

 st    --> Pointer to segment tree
 index --> Index of current node in the segment tree. Initially 0 is
 passed as root is always at index 0
 ss & se  --> Starting and ending indexes of the segment represented by
 current node, i.e., st[index]
 qs & qe  --> Starting and ending indexes of query range */

int getSumUtil(int *st, int ss, int se, int qs, int qe, int index)
{
	// If segment of this node is a part of given range, then return the
	// sum of the segment
	if (qs <= ss && qe >= se)
	{
		return st[index];
	}

	// If segment of this node is outside the given range
	if (se < qs || ss > qe)
	{
		return 0;
	}

	// If a part of this segment overlaps with the given range
	int mid = getMid(ss, se);
	return getSumUtil(st, ss, mid, qs, qe, 2 * index + 1)
			+ getSumUtil(st, mid + 1, se, qs, qe, 2 * index + 2);
}

/* A recursive function to update the nodes which have the given index in
 their range. The following are parameters
 st, index, ss and se are same as getSumUtil()
 i    --> index of the element to be updated. This index is in input array.
 diff --> Value to be added to all nodes which have i in range */

void updateValueUtil(int *st, int ss, int se, int i, int diff, int index)
{
	// Base Case: If the input index lies outside the range of this segment
	if (i < ss || i > se)
	{
		return;
	}

	// If the input index is in range of this node, then update the value
	// of the node and its children
	st[index] += diff;
	if (se != ss)
	{
		int mid = getMid(ss, se);
		updateValueUtil(st, ss, mid, i, diff, 2 * index + 1);
		updateValueUtil(st, mid + 1, se, i, diff, 2 * index + 2);
	}
}

// The function to update a value in input array and segment tree.
// It uses updateValueUtil() to update the value in segment tree

void updateValue(int arr[], int *st, int n, int i, int new_value)
{
	// Check for erroneous input index
	if (i < 0 || i > n - 1)
	{
		printf("Invalid input.");
		return;
	}

	// Get the difference between new value and old value
	int diff = new_value - arr[i];

	// Update the value in array
	arr[i] = new_value;

	// Update the values of nodes in segment tree
	updateValueUtil(st, 0, n - 1, i, diff, 0);
}

// Return sum of elements in range from index qs (quey start) to
// qe (query end).  It mainly uses getSumUtil()
int getSum(int *st, int n, int qs, int qe)
{
	// Check for erroneous input values
	if (qs < 0 || qe > n - 1 || qs > qe)
	{
		printf("Invalid input.");
		return -1;
	}
	return getSumUtil(st, 0, n - 1, qs, qe, 0);
}

// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st

int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
	// If there is one element in array, store it in current node of
	// segment tree and return
	if (ss == se)
	{
		st[si] = arr[ss];
		return arr[ss];
	}

	// If there are more than one elements, then recur for left and
	// right subtrees and store the sum of values in this node
	int mid = getMid(ss, se);
	st[si] = constructSTUtil(arr, ss, mid, st, si * 2 + 1)
			+ constructSTUtil(arr, mid + 1, se, st, si * 2 + 2);
	return st[si];
}

/* Function to construct segment tree from given array. This function
 allocates memory for segment tree and calls constructSTUtil() to
 fill the allocated memory */

int* constructST(int arr[], int n)
{
	// Allocate memory for segment tree
	int x = (int) (ceil(log2(n))); //Height of segment tree
	int max_size = 2 * (int) pow(2, x) - 1; //Maximum size of segment tree
	int *st = new int[max_size];

	// Fill the allocated memory st
	constructSTUtil(arr, 0, n - 1, st, 0);

	// Return the constructed segment tree
	return st;
}

/**Main function**/
int main()
{
#ifdef LOCAL_DEFINE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	int arr[] =
	{ 1, 3, 5, 7, 9, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Build segment tree from given array
	int *st = constructST(arr, n);

	// Print sum of values in array from index 1 to 3
	printf("Sum of values in given range = %d\n", getSum(st, n, 1, 3));

	// Update: set arr[1] = 10 and update corresponding segment
	// tree nodes
	updateValue(arr, st, n, 1, 10);

	// Find sum after the value is updated
	printf("Updated sum of values in given range = %d\n", getSum(st, n, 1, 3));
#ifdef LOCAL_DEFINE
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}
