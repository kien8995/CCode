/*
 * main.cpp
 *
 *  Created on: Jan 13, 2015
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
#define LOCAL_DEFINE
//-------------------------------------------------
const int MAX = 100;
char X[2 * MAX], Y[2 * MAX];
int F[MAX + 2][MAX + 2];
int m, n;
void enter()
{
	RI(m);
	forle(i,1,m)
	{
		scanf("%1c", &X[i]);
	}
	RI(n);
	forle(i,1,n)
	{
		scanf("%1c", &Y[i]);
	}
}
int min3(int a, int b, int c)
{
	return (a < b ? min(a, c) : min(b, c));
}
void optimize()
{
	//khoi tao vien cho bang phuong an
//	forle(i,1,m+1)
//	{
//		F[i][0] = MAX + 1;
//	}
//	forle(j,1,n+1)
//	{
//		F[0][j] = MAX + 1;
//	}
	//luu co so quy hoach dong
	forle(j,0,n)
	{
		F[0][j] = j;
	}
	forle(i,1,m)
	{
		F[i][0] = i;
	}
	//dung cong thuc truy hoi tinh toan bang phuong an
	forle(i,1,m)
	{
		forle(j,1,n)
		{
			if (X[i] == X[j])
			{
				F[i][j] = F[i - 1][j - 1];
			}
			else
			{
				F[i][j] = min3(F[i][j - 1], F[i - 1][j - 1], F[i - 1][j]) + 1;
			}
		}
	}
}
void Insert(char c, char* x, int z)
{
	int len = strlen(x);
	forg(i,len+1,z+1)
	{
		x[i] = x[i - 1];
	}
	x[z + 1] = c;
	x[len + 2] = '\0';
}
void Delete(char* x, int z, int k)
{
	int len = strlen(x);
	int i = 0;
	while (len > 0)
	{
		x[z + i] = x[z + k + i];
		--len;
		++i;
	}
}
void trace()	//truy vet
{
	PRI(F[m][n]);	//so it nhat cac phep bien doi can thuc hien
	while (m != 0 && n != 0)
	{
		if (X[m] == Y[n])	//2 ky tu cuoi giong nhau
		{
			--m;	//chi viec truy cheo len tren bang phuong an
			--n;
		}
		else	//tai day can 1 phep bien doi
		{
			printf("%s -> ", X);	// in ra xau x
			if (F[m][n] == F[m][n - 1] + 1)	//neu day la phep chen
			{
				printf("Insert(%d, %c)", m, Y[n]);
				Insert(Y[n], X, m + 1);
				--n;	//truy sang phai
			}
			else
			{
				if (F[m][n] == F[m - 1][n - 1] + 1)	//neu day la phep thay
				{
					printf("replace(%d, %c)", m, Y[n]);
					X[m] = Y[n];
					--m;
					--n;	//cheo len tren
				}
				else	//neu day la phep xoa
				{
					printf("Delete(%d)", m);
					Delete(X, m, 1);
					--m;	//truy len tren
				}
			}
		}
		printf(" -> %s\n", X);
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
	optimize();
	trace();
#ifdef LOCAL_DEFINE
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}
