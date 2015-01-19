/*
 * main.cpp
 *
 *  Created on: Dec 25, 2014
 *      Author: trankien
 */

//http://codeforces.com/contest/499/problem/B

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

#define u64 unsigned long long
#define i64 long long
#define ld  long double
#define FORLE(i,a,b) for(int i = (a); i <= (int)(b); ++i)
#define FORL(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define FORGE(i,a,b) for(int i= (a); i >= (int)(b); --i)
#define FORG(i,a,b) for(int i= (a); i > (int)(b); --i)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); ++i)
#define RFORV(i,a) for(typeof(a.rbegin()) i = a.rbegin(); i != a.rend(); ++i)
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
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define eps 1e-5
#define INF 1e9
#define PI 2*acos(0.0)
#define debug(k,F,n) FORL(i,0,n){FORL(j,0,n) cout << setw(k) << F[i][j] ; cout << endl;}
#define _ {ios_base::sync_with_stdio(0);cin.tie(0);}
#define bufo (stdout, NULL, _IONBF, 0)
#define bufi (stdin, NULL, _IONBF, 0)

//#define LOCAL_DEFINE

using namespace std;

typedef pair<int, int> II;
typedef pair<int, II> PII;
typedef vector<int> VI;
typedef vector<II> VII;
typedef set<int> SI;
typedef set<string> SS;
typedef map<string, int> MSI;
typedef map<int, int> MII;

template<typename T>
inline string toStr(T x)
{
	stringstream st;
	st << x;
	string s;
	st >> s;
	return s;
}
template<typename T>
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

//------------------
int contains(vector<char*> str1, char ch[])
{
	FORL(i,0,str1.size())
	{
		if (str1.at(i) == ch)
		{
			return i;
		}
	}
	return -1;
}
/**Main function**/
int main()
{
#ifdef LOCAL_DEFINE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	DRII(n, m);
	string st1, st2;
	map<string, string> str;
	FORL(i,0,m)
	{
		cin >> st1 >> st2;
		str[st1] = st2;
	}
	FORL(i,0,n)
	{
		cin >> st1;
		st2 = str[st1];
		if (st1.size() <= st2.size())
		{
			cout << st1 << " ";
		}
		else
		{
			cout << st2 << " ";
		}
	}
#ifdef LOCAL_DEFINE
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}
