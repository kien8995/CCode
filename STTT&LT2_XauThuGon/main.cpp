/*
 * main.cpp
 *
 *  Created on: Jan 10, 2015
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

/**USE FILE**/
//#define LOCAL_DEFINE
//-------------------------------------------------
const int mn = 500;
const char BL = 32;
char C[mn]; // noi dung lenh
int M[mn]; // so lan lap
int T[mn]; // lap tu dong lenh nao
int R[mn]; // luu gia tri M
int n; // con dem dong lenh
char s[mn]; // xau thu gon
int v; // chi so duyet s
int st[mn]; // stack
int p; // chi so ngon stack st

// P R O T O T Y P E S
void KhaiTrien(char *);
void LenhDon(char);
void LenhLap();
int DocSo();
void Cach();
bool LaChuSo(char);
bool LaChuCai(char);
void Pha2();
/**MAIN FUNCTION**/
int main()
{
#ifdef LOCAL_DEFINE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	strcpy(s, " (AB3(C2D)2(C5D)0)2A3");
	KhaiTrien(s);
	cout << endl;
	//system("PAUSE");
	return 0;
#ifdef LOCAL_DEFINE
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}
bool LaChuCai(char c)
{
	return (c >= 'A') && (c <= 'Z');
}
bool LaChuSo(char c)
{
	return (c >= '0') && (c <= '9');
}
void Cach()
{
	while (s[v] == BL)
		++v;
}
int DocSo()
{
	int so = 0;
	Cach();
	if (!LaChuSo(s[v]))
	{
		return 1;
	}
	while (LaChuSo(s[v]))
	{
		so = so * 10 + int(s[v] - '0');
		++v;
	}
	return so;
}
void LenhDon(char ch)
{
	int so;
	++v;
	so = DocSo();
	if (so == 0)
	{
		return;
	}
	++n;
	C[n] = ch;
	M[n] = so;
}
void LenhLap()
{
	int so;
	++v; // bo qua dau )
	so = DocSo();
	int tu = st[p--];
	if (so == 0)
	{
		n = tu - 1;
		return;
	}
	if (so == 1)
	{
		return;
	}
	++n;
	C[n] = '#';
	M[n] = R[n] = so;
	T[n] = tu;
}
void KhaiTrien(char *s)
{
// Pha1
	p = 0;
	n = 0; // init
	for (v = 0; s[v];)
	{
		if (LaChuCai(s[v]))
		{
			LenhDon(s[v]);
		}
		else if (s[v] == '(')
		{
			st[++p] = n + 1;
			++v;
		}
		else if (s[v] == ')')
		{
			LenhLap();
		}
		else
		{
			++v;
		}
	}
	Pha2();
}
void Pha2()
{
	int i, j;
	cout << endl << s << " = ";
	i = 1;
	while (i <= n)
	{
		if (C[i] == '#')
		{
			--R[i];
			if (R[i] == 0)
			{
				R[i] = M[i];
				++i;
			}
			else
			{
				i = T[i];
			}
		}
		else
		{
			for (j = 1; j <= M[i]; ++j)
				cout << C[i];
			++i;
		}
	}
}