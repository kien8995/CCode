/*
 * main.cpp
 *
 *  Created on: Jan 13, 2015
 *      Author: trankien
 */

//Dem so cac phan tich so n thanh tong cac so <= n
/**LIBRARY**/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdarg>
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

using namespace std;

/**DEFINE**/
#define u64 unsigned long long
#define ui  unsigned int
#define i64 long long
#define ld  long double
#define forle(i,a,b) for(int i = (a); i <= (int)(b); ++i)
#define forl(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define forge(i,a,b) for(int i= (a); i >= (int)(b); --i)
#define forg(i,a,b) for(int i= (a); i > (int)(b); --i)
#define forv(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); ++i)
#define rforv(i,a) for(typeof(a.rbegin()) i = a.rbegin(); i != a.rend(); ++i)
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
#define MOD 1000000007
#define INF 1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795028841971
#define fe(a, b) (fabs((a)-(b)) < EPS)
#define fl(a, b) ((a) < (b) - EPS)
#define fg(a, b) ((a) > (b) + EPS)
#define boost() ios_base::sync_with_stdio(0)
#define bufo() setvbuf(stdout, NULL, _IONBF, 0)
#define bufi() setvbuf(stdin, NULL, _IONBF, 0)

/**DEBUG**/
#define pri1d(A,n,k) FORL(i,0,n){cout << left << setw(k) << A[i];}cout << endl;
#define pri2d(A,l,c,k) FORL(i,0,l){FORL(j,0,c) cout << left << setw(k) << A[i][j] ; cout << endl;}
#define debug1(x) do { std::cout << "--> " << #x << ": " << x << std::endl; } while (0)
void debug2(const char* fmt...)
{
	va_list args;
	va_start(args, fmt);

	while (*fmt != '\0')
	{
		if (*fmt == 'd')
		{
			int i = va_arg(args, int);
			std::cout << "--> " << i << '\n';
		}
		else if (*fmt == 'c')
		{
			int c = va_arg(args, int);
			std::cout << "--> " << static_cast<char>(c) << '\n';
		}
		else if (*fmt == 's')
		{
			char* s = va_arg(args, char*);
			std::cout << "--> " << static_cast<char*>(s) << '\n';
		}
		else if (*fmt == 'f')
		{
			double d = va_arg(args, double);
			std::cout << "--> " << d << '\n';
		}
		++fmt;
	}
	va_end(args);
}

/**TYPEDEF**/
typedef pair<int, int> II;
typedef pair<int, II> PII;
typedef vector<int> VI;
typedef vector<II> VII;
typedef set<int> SI;
typedef set<string> SS;
typedef map<string, int> MSI;
typedef map<int, int> MII;

/**TEMPLATE**/
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
template<class T> T swapbit(T s, T p1, T p2, T n)
{
	T Xor = ((s >> p1) ^ (s >> p2)) & ((1U << n) - 1);
	return s ^ ((Xor << p1) | (Xor << p2));
}

/**USE FILE**/
//#define LOCAL_DEFINE
//-------------------------------------------------
//---c1: F[m][v]
int F[100][100];
//---c11: current[], next[]
int current[100], next[100];
//---c12: B[3][max]
int B[3][100];
//---c13: A[max]
int A[100];
//c21: L[max]
int L[100][100];
int n;
int cach21(int m, int v)
{
	if (L[m][v] == -1)
	{
		if (m == 0)
		{
			if (v == 0)
			{
				L[m][v] = 1;
			}
			else
			{
				L[m][v] = 0;
			}
		}
		else
		{
			if (m > v)
			{
				L[m][v] = cach21(m - 1, v);
			}
			else
			{
				L[m][v] = cach21(m - 1, v) + cach21(m, v - m);
			}
		}
	}
	return L[m][v];
}
int cach2(int m, int v)
{
	if (m == 0)
	{
		if (v == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if (m > v)
		{
			return cach2(m - 1, v);
		}
		else
		{
			return cach2(m - 1, v) + cach2(m, v - m);
		}
	}
}
int cach13()
{
	set(A, 0);
	A[0] = 1;
	forle(m,1,n)
	{
		forle(v,m,n)
		{
			A[v] += A[v - m];
		}
	}
	return A[n];
}
int cach12()
{
	set(B[1], 0);
	B[1][0] = 1;
	int x = 1, y = 2;
	forle(m,1,n)
	{
		forle(v,0,n)
		{
			if (v < m)
			{
				B[y][v] = B[x][v];
			}
			else
			{
				B[y][v] = B[x][v] + B[y][v - m];
			}
		}
		x = 3 - x;
		y = 3 - y;
	}
	return B[x][n];
}
int cach11()
{
	set(current, 0);
	current[0] = 1;
	forle(m,1,n)
	{
		forle(v,0,n)
		{
			if (v < m)
			{
				next[v] = current[v];
			}
			else
			{
				next[v] = current[v] + next[v - m];
			}
		}
		cpy(current, next);
	}
	return current[n];
}
int cach1()
{
	set(F[0], 0);
	F[0][0] = 1;
	forle(m,1,n)
	{
		forle(v,0,n)
		{
			if (v < m)
			{
				F[m][v] = F[m - 1][v];
			}
			else
			{
				F[m][v] = F[m - 1][v] + F[m][v - m];
			}
		}
	}
	return F[n][n];
}
/**MAIN FUNCTION**/
int main()
{
#ifdef LOCAL_DEFINE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	RI(n);
	//printf("%d Analyses\n", cach1());
	//printf("%d Analyses\n", cach11());
	//printf("%d Analyses\n", cach12());
	//printf("%d Analyses\n", cach13());
	//printf("%d Analyses\n", cach2(n, n));
	set(L, -1);
	printf("%d Analyses\n", cach21(n, n));
#ifdef LOCAL_DEFINE
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}
