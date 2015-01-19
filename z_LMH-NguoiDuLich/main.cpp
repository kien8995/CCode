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
#define CPY(b,a) memcpy(b,a,sizeof(a))
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

#define FILE_DEFINE
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
const int Max = 100;
const int maxE = 10000;
const int maxC = Max * maxE;
int c[Max][Max];
int x[Max + 1];
int bestWay[Max+1];
int t[Max + 1];
bool s[Max+1];
int n, m;
int minSpending;
void input();
void init();
void attempt(int i);
void print();
//******************
int main()
{
#ifdef FILE_DEFINE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	input();
	init();
	attempt(2);
	print();
#ifdef TIME_DEFINE
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

inline void input()
{
	int a, b;
	RII(n, m);
	FORLE(i,1,n)
	{
		FORLE(j,1,n)
		{
			if (i == j)
			{
				c[i][j] = 0;
			}
			else
			{
				c[i][j] = maxC;
			}
		}
	}
	FORLE(i,1,m)
	{
		RII(a, b);
		RI(c[a][b]);
		c[b][a] = c[a][b];
	}
}

inline void init()
{
	SET(s, true);
	s[1] = false;
	x[1] = 1;
	t[1] = 0;
	minSpending = maxC;
}

inline void attempt(int i)
{
	FORLE(j,2,n)
	{
		if(s[j])
		{
			x[i] = j;
			t[i] = t[i-1] + c[x[i-1]][j];
			if(t[i]<minSpending)
			{
				if(i<n)
				{
					s[j] = false;
					attempt(i+1);
					s[j] = true;
				}
				else
				{
					if(t[n]+c[x[n]][1]<minSpending)
					{
						CPY(bestWay,x);
						minSpending = t[n] + c[x[n]][1];
					}
				}
			}
		}
	}
}

inline void print()
{
	if(minSpending==maxC)
	{
		printf("NO SOLUTION\n");
	}
	else
	{
		FORLE(i,1,n)
		{
			printf("%d->",bestWay[i]);
		}
		printf("%d\n",1);
		printf("Cost: %d\n",minSpending);
	}
}
