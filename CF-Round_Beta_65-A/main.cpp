/*
 * main.cpp
 *
 *  Created on: Dec 15, 2014
 *      Author: trankien
 */

//http://codeforces.com/problemset/problem/71/A

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

#define ULL unsigned long long
#define LL long long
#define FORLE(i,a,b) for(int i = (a); i <= (int)(b); i++)
#define FORL(i,a,b) for(int i = (a); i < (int)(b); i++)
#define FORGE(i,a,b) for(int i= (a); i >= (int)(b); i--)
#define FORG(i,a,b) for(int i= (a); i > (int)(b); i--)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define SET(a,c) memset(a, c, sizeof(a))
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define eps 1e-5
#define infi 1e9
#define PI 2*acos(0.0)
#define debug(k,F,n) FOR(i,1,n){FOR(j,1,n) cout << setw(k) << F[i][j] ; cout << endl;}

using namespace std;

typedef pair<int, int> II;
typedef pair<int, II> PII;
typedef vector<int> VI;
typedef vector<II> VII;
typedef set<int> SI;
typedef map<string, int> MSI;
typedef map<int, int> MII;

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

//------------------
int main()
{
	int t;
	scanf("%d", &t);
	//fflush(stdin);
	while (t > 0)
	{
		//fflush(stdout);
		char ch[100] = "";
		scanf("%s", ch);
		int n = strlen(ch);
		if (n <= 10)
		{
			printf("%s\n", ch);
		}
		else
		{
			printf("%c%d%c\n", ch[0], n - 2, ch[n - 1]);
		}
		--t;
	}
	return 0;
}

