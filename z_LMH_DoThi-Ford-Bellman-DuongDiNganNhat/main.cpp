/*
 * main.cpp
 *
 *  Created on: Jan 17, 2015
 *      Author: trankien
 */

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
#define boost() {ios_base::sync_with_stdio(0);cin.tie(0);}
#define bufo() setvbuf(stdout, NULL, _IONBF, 0)
#define bufi() setvbuf(stdin, NULL, _IONBF, 0)

/**DEBUG**/
#define debug1d(A,s,n,k) forle(i,s,n){std::cerr << left << setw(k) << A[i];}std::cerr << '\n';
#define debug2d(A,s,l,c,k) forle(i,s,l){forle(j,s,c) std::cerr << left << setw(k) << A[i][j] ; std::cerr << '\n';}
#define debugv(x) {std::cerr << "--> " << #x << " = "; forv(it, (x)) std::cerr << *it << ", " ; std::cerr << '\n';}
#define debug1(x) do { std::cerr << "--> " << #x << " = " << x << '\n'; } while (0)
#define debug2(...) fprintf(stderr, __VA_ARGS__)
void debug3(const char* fmt...)
{
	va_list args;
	va_start(args, fmt);

	while (*fmt != '\0')
	{
		if (*fmt == 'd')
		{
			int i = va_arg(args, int);
			std::cerr << "--> " << i << '\n';
		}
		else if (*fmt == 'c')
		{
			int c = va_arg(args, int);
			std::cerr << "--> " << static_cast<char>(c) << '\n';
		}
		else if (*fmt == 's')
		{
			char* s = va_arg(args, char*);
			std::cerr << "--> " << static_cast<char*>(s) << '\n';
		}
		else if (*fmt == 'f')
		{
			double d = va_arg(args, double);
			std::cerr << "--> " << d << '\n';
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
typedef map<string, string> MSS;
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
#define LOCAL_DEFINE
//-------------------------------------------------
const int MAX = 1000;
const int MAXEC = 1000;
int c[MAX + 1][MAX + 1];
int d[MAX + 1];
int trace[MAX + 1];
int n, m, s, f;
void enter()	//nhap do thi, do thi khong duoc co chu trinh am
{
	scanf("%d %d %d %d", &n, &m, &s, &f);
	forle(u,1,n)
	{
		forle(v,1,n)
		{
			if (u == v)
			{
				c[u][v] = 0;
			}
			else
			{
				c[u][v] = INF;
			}
		}
	}
	int u, v;
	forle(i,1,m)
	{
		RII(u, v);
		RI(c[u][v]);
	}
}
void init()
{
	forle(i,1,n)
	{
		d[i] = INF;
	}
	d[s] = 0;
}
void fordBellman()
{
	bool stop;
	int countLoop;
	for (countLoop = 1; countLoop <= n - 1; ++countLoop)
	{
		stop = true;
		forle(u,1,n)
		{
			forle(v,1,n)
			{
				if (d[v] > d[u] + c[u][v])//neu ton tai d[v] > d[u] + c[u][v] thi toi uu lai d[v]
				{
					d[v] = d[u] + c[u][v];
					trace[v] = u;	//luu vet duong di
					stop = false;
				}
			}
		}
		if (stop)//thuat toan dung lai khi khong toi uu duoc d[v] nua, hay da lap du n-1 lan
		{
			break;
		}
	}
}
void printResult()	//in duong di tu s toi f
{
	if (d[f] == INF)
	{
		printf("There is no path from %d to %d.\n", s, f);
	}
	else	//truy vet duong di
	{
		printf("Distance from %d to %d: %d\n", s, f, d[f]);
		while (f != s)
		{
			printf("%d <- ", f);
			f = trace[f];
		}
		printf("%d\n", s);
	}
}
/**MAIN FUNCTION**/
int main()
{
#ifdef LOCAL_DEFINE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	enter();
	init();
	fordBellman();
	printResult();
#ifdef LOCAL_DEFINE
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}
