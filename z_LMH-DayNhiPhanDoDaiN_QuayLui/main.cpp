/*
 * main.cpp
 *
 *  Created on: Dec 21, 2014
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

#define U64 unsigned long long
#define I64 long long
#define LD  long double
#define FORLE(i,a,b) for(int i = (a); i <= (int)(b); ++i)
#define FORL(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define FORGE(i,a,b) for(int i= (a); i >= (int)(b); --i)
#define FORG(i,a,b) for(int i= (a); i > (int)(b); --i)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); ++i)
#define RFORV(i,a) for(typeof(a.rbegin()) i = a.rbegin(); i != a.rend(); ++i)
#define FORLEX(i,a,b,x) for(int i = (a); i <= (int)(b); i+=x)
#define FORLX(i,a,b,x) for(int i = (a); i < (int)(b); i+=x)
#define FORGEX(i,a,b,x) for(int i= (a); i >= (int)(b); i-=x)
#define FORGX(i,a,b,x) for(int i= (a); i > (int)(b); i-=x)
#define FORVX(i,a,x) for(typeof(a.begin()) i = a.begin(); i != a.end(); i+=x)
#define RFORVX(i,a,x) for(typeof(a.rbegin()) i = a.rbegin(); i != a.rend(); i+=x)
#define SET(a,c) memset(a, c, sizeof(a))
#define SETN(a,c,n) memset(a, c, n)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
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
#define eps 1e-5
#define infi 1e9
#define PI 2*acos(0.0)
#define debug(k,F,n) FORL(i,0,n){FORL(j,0,n) cout << setw(k) << F[i][j] ; cout << endl;}
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

//#define FILE_DEFINE
//#define TIME_DEFINE

using namespace std;

typedef pair<int, int> II;
typedef pair<int, II> PII;
typedef vector<int> VI;
typedef vector<II> VII;
typedef set<int> SI;
typedef set<string> SS;
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
void print(int a[], int n);
void attempt(int i);
int n, x[100];
//******************
int main()
{
#ifdef FILE_DEFINE
	freopen("input.inp", "rt", stdin);
	freopen("output.out", "wt", stdout);
#endif
	RI(n);
	attempt(0);
#ifdef TIME_DEFINE
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

void attempt(int i)
{
	FORLE(j,0,1)
	{
		x[i] = j;
		if (i == n - 1)
		{
			print(x, n);
		}
		else
		{
			attempt(i + 1);
		}
	}
}

inline void print(int a[], int n)
{
	FORL(i,0,n)
	{
		PRIS(a[i]);
	}
	printf("\n");
}

