/*
 * main.cpp
 *
 *  Created on: Dec 16, 2014
 *      Author: trankien
 */

//http://codeforces.com/problemset/problem/118/A
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
#define FORLEX(i,a,b,x) for(int i = (a); i <= (int)(b); i+=x)
#define FORLX(i,a,b,x) for(int i = (a); i < (int)(b); i+=x)
#define FORGEX(i,a,b,x) for(int i= (a); i >= (int)(b); i-=x)
#define FORGX(i,a,b,x) for(int i= (a); i > (int)(b); i-=x)
#define FORVX(i,a,x) for(typeof(a.begin()) i = a.begin(); i != a.end(); i+=x)
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
char toLowerCase(char ch);
//******************
int main()
{
	string str;
	string::iterator it;
	getline(cin, str);
	//transform(str.begin(), str.end(), str.begin(), ::towlower);
	transform(str.begin(), str.end(), str.begin(), toLowerCase);
	LABEL: FORL(i,0,str.size())
	{
		if (str[i] == 'a' || str[i] == 'o' || str[i] == 'y' || str[i] == 'e'
				|| str[i] == 'u' || str[i] == 'i')
		{
			it = str.begin() + i;
			str.erase(it);
			goto LABEL;
		}
	}
	for (int i = 0; i < (int) str.size(); i += 2)
	{
		it = str.begin();
		str.insert(it + i, 1, '.');
	}
	cout << str;
	return 0;
}

char toLowerCase(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
	{
		return (ch + 32);
	}
	return ch;
}
