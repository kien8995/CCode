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
char s[mn]; // bieu thuc
char c[mn]; //ngan xep phep toan va dau (
int ic; // con trỏ ngăn xếp c
int v[mn]; //ngan xep tinh toan
int iv; // con trỏ ngăn xếp v
int kq; // ket qua
int n; // len – số ki tự trong biểu thức

// Khai báo các hàm
int XuLi();
bool LaBien(char c); // kiem tra c la bien ?
bool LaPhepToan(char c); // kiem tra c la phep toan +, –, *, / ?
void XuLiPhepToan(char pt);
void XuLiNgoac();
int Bac(char pt); // Bac cua phep toan +, – (1), *, / (2)
int Val(char c); // Tinh tri cua bien c
void Tinh(char pt); // thuc hien phep toan pt
/**MAIN FUNCTION**/
int main()
{
#ifdef LOCAL_DEFINE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	strcpy(s, "(b+c)*(e-b) + (y-x)");
	cout << endl << " input: " << s;
	kq = XuLi();
	cout << endl << endl << " Dap so: " << kq << endl;
	cout << endl << endl << " Finish." << endl;
	//cin.get();
	return 0;
#ifdef LOCAL_DEFINE
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}

int XuLi()
{
	ic = 0;
	c[ic] = '#';
	n = strlen(s);
	iv = -1;
	int i;
	for (i = 0; i < n; ++i)
	{
		if (LaBien(s[i]))
		{
			v[++iv] = Val(s[i]);
		}
		else if (s[i] == '(')
		{
			c[++ic] = '(';
		}
		else if (s[i] == ')')
		{
			XuLiNgoac();
		}
		else if (LaPhepToan(s[i]))
		{
			XuLiPhepToan(s[i]);
		}
	}
	while (LaPhepToan(c[ic]))
	{
		Tinh(c[ic]);
		--ic;
	}
	return v[iv];
}
// Val('A') = 0; Val('B') = 1; . . .
int Val(char c)
{
	return (int) (c - 'a');
}
int Bac(char pt)
{
	if (pt == '+' || pt == '-')
	{
		return 1;
	}
	else if (pt == '*' || pt == '/')
	{
		return 2;
	}
	else
	{
		return 0;
	}
}
bool LaBien(char c)
{
	return (c >= 'a' && c <= 'z');
}
bool LaPhepToan(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}
void XuLiPhepToan(char pt)
{
	while (Bac(c[ic]) >= Bac(pt))
	{
		Tinh(c[ic]);
		--ic;
	}
	c[++ic] = pt;
}
void XuLiNgoac()
{
	while (c[ic] != '(')
	{
		Tinh(c[ic]);
		--ic;
	}
	--ic; // bo dau '('
}
void Tinh(char pt)
{ // Thuc hien phép toan pt
	switch (pt)
	{
	case '+':
		v[iv - 1] = v[iv - 1] + v[iv];
		--iv;
		break;
	case '-':
		v[iv - 1] = v[iv - 1] - v[iv];
		--iv;
		break;
	case '*':
		v[iv - 1] = v[iv - 1] * v[iv];
		--iv;
		break;
	case '/':
		v[iv - 1] = v[iv - 1] / v[iv];
		--iv;
		break;
	}
}
