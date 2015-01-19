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
const char * fn = "autum.inp";
const char * gn = "autum.out";
const int mn = 201; // so nguoi va so qua toi da
int a[mn]; // a[i] = j: em i nhan qua j
int b[mn]; // b[j] = i: qua j trong tay em i
int t[mn]; // t[j] = i : em j nhuong qua cho ban i
int c[mn][mn]; // c[i][j] = 1: i thich qua j
int n; // so em nho
int m; // so qua
int st[mn]; // stack
int p; // con tro stack
// P R O T O T Y P E S
int main();
void Doc();
void Print();
int Par();
int Xep(int);
void Update(int, int);
void PrintArray(int[], int, int);
void Ghi(int);
/**MAIN FUNCTION**/
int main()
{
#ifdef LOCAL_DEFINE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	Doc();
	Print();
	int v = Par();
	Ghi(v);
	cout << endl << "Xep duoc " << v << " em.";
	PrintArray(a, 1, n);
	cout << endl;
#ifdef LOCAL_DEFINE
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}
void Ghi(int v)
{
	ofstream g(gn);
	g << v << endl;
	for (int i = 1; i <= n; ++i)
		if (a[i] > 0)
			g << i << " " << a[i] << endl;
	g.close();
}
void PrintArray(int a[], int d, int c)
{
	int i;
	cout << endl;
	for (i = d; i <= c; ++i)
		cout << a[i] << " ";
}
void Update(int i, int j)
{
	int c;
	do
	{
		c = a[i]; // i bo qua c xuong
		a[i] = j;
		b[j] = i; // i nhan qua moi j
		i = t[i];
		j = c; // chuyen qua nguoi khac
	} while (c > 0);
}
int Xep(int i)
{ // tim qua cho em i
	memset(t, 0, sizeof(t));
	int j;
	p = 0;
	st[++p] = i;
	t[i] = i;
	while (p > 0)
	{
		i = st[p--]; // lay ngon stack
		for (j = 1; j <= m; ++j)
		{ // duyet cac mon qua
			if (c[i][j] > 0)
			{ // i thich qua j
				if (b[j] == 0)
				{ // qua j chua chia
					Update(i, j);
					return 1;
				}
				if (t[b[j]] == 0)
				{ //b[j] chua co trong danh sach
					st[++p] = b[j];
					t[b[j]] = i; // nap
				}
			}
		}
	}
	return 0; // Khong chon duoc qua cho em i
}
int Par()
{ // Cap ghep
	int v = 0, i;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	for (i = 1; i <= n; ++i)
		v += Xep(i);
	return v;
}
void Print()
{ // Hien thi ma tran c
	cout << endl << n << " " << m << endl;
	int i, j;
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= m; ++j)
			cout << c[i][j] << " ";
		cout << endl;
	}
}
void Doc()
{
	memset(c, sizeof(c), 0);
	ifstream f(fn);
	f >> n >> m;
	int i, j, k, r;
	for (i = 1; i <= n; ++i)
	{
		f >> k;
		for (r = 1; r <= k; ++r)
		{
			f >> j;
			c[i][j] = 1;
		}
	}
	f.close();
}
