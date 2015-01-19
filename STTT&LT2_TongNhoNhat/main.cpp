/*
 * main.cpp
 *
 *  Created on: Jan 11, 2015
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
#define EPS 1e-7
#define PI 3.1415926535897932384626433832795028841971
#define fe(a, b) (fabs((a)-(b)) < EPS)
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
// D A T A A N D V A R I A B L E
const char * fn = "minsum.inp";
const char * gn = "minsum.out";
const int mn = 1001;
int a[mn], b[mn];
int n;
// P R O T O T Y P E S
void Doc();
void Print(int[], int, int);
int XuLi();
void Ghi(int);
void Sort(int[], int, int);
void Run();
/**MAIN FUNCTION**/
int main()
{
#ifdef LOCAL_DEFINE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	Run();
	cout << endl;
#ifdef LOCAL_DEFINE
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}
void Run()
{
	Doc();
	cout << endl << n;
	Print(a, 1, n);
	Print(b, 1, n);
	Ghi(XuLi());
}
void Ghi(int m)
{
	ofstream g(gn);
	g << m;
	g.close();
}
int XuLi()
{
	Sort(a, 1, n);
	Sort(b, 1, n);
	cout << endl << "Sau khi sap tang ";
	Print(a, 1, n);
	Print(b, 1, n);
	int i = 1, j = n, m = 0x7fffffff, t, v;
	while (i <= n && j >= 1)
	{
		t = a[i] + b[j];
		v = abs(t);
		if (m > v)
			m = v;
		if (t == 0)
			return 0;
		if (t < 0)
			++i;
		else
			--j;
	}
// i = n+1 || j = 0
	for (; i <= n; ++i)
	{
		t = a[i] + b[1];
		v = abs(t);
		if (m > v)
			m = v;
		if (t >= 0)
			return m;
	}
	for (; j >= 1; --j)
	{
		t = a[n] + b[j];
		v = abs(t);
		if (m > v)
			m = v;
		if (t <= 0)
			return m;
	}
	return m;
}
void Sort(int a[], int d, int c)
{
	int i = d, j = c, m = a[(d + c) / 2], t;
	while (i <= j)
	{
		while (a[i] < m)
			++i;
		while (a[j] > m)
			--j;
		if (i <= j)
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
			++i;
			--j;
		}
	}
	if (d < j)
		Sort(a, d, j);
	if (i < c)
		Sort(a, i, c);
}
void Doc()
{
	ifstream f(fn);
	f >> n;
	int i;
	for (i = 1; i <= n; ++i)
		f >> a[i];
	for (i = 1; i <= n; ++i)
		f >> b[i];
	f.close();
}
void Print(int a[], int d, int c)
{
	int i;
	cout << endl;
	for (i = d; i <= c; ++i)
		cout << a[i] << " ";
}
