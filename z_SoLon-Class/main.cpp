/*
 * main.cpp
 *
 *  Created on: Jan 12, 2015
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
//#define LOCAL_DEFINE
//-------------------------------------------------
#define zero '0'
#define space (char)32
#define minussign '-'
// Các hàm chỉ liên quan đến kiểu (char *) pchar mà có lần mình đã post rồi
typedef char* pchar;

int strlen(const pchar a)
{
	pchar p = a;
	while (*p)
		p++;
	return p - a;
}

int val(char chr)
{
	return chr - zero;
}
char chr(int num)
{
	return num + zero;
}

char chradd(char a, char b, int &carry)
{
	int temp = val(a) + val(b) + carry;
	carry = temp / 10;
	return chr(temp % 10);
}

char chrsub(char a, char b, int &carry)
{
	int temp = 10 + val(a) - val(b) - carry;
	carry = 1 - temp / 10;
	return chr(temp % 10);
}
pchar strcpy(const pchar dest, const pchar src)
{
	int k = 0;
	while (src[k])
	{
		dest[k] = src[k];
		k++;
	}
	dest[k] = 0;
	return dest;
}

pchar strrev(const pchar src, const pchar dest)
{
	strcpy(dest, src);
	int len = strlen(src);
	for (int k = 0; k < len / 2; k++)
	{
		char temp = dest[k];
		dest[k] = dest[len - k - 1];
		dest[len - k - 1] = temp;
	}
	return dest;
}

void remzers(const pchar a)
{
	int n = 0, sign = 0, p;
	while (a[n])
	{
		n++;
	}
	if (a[n - 1] == minussign)
	{
		sign = 1;
		p = n - 2;
	}
	else
	{
		p = n - 1;
	}
	while (p > 0 && a[p] == zero)
	{
		p--;
	}
	p++;
	if (sign && p > 1)
	{
		a[p++] = minussign;
	}
	a[p++] = 0;
	a[p] = 0;
}

pchar stradd(const pchar a, const pchar b, const pchar c)
{
	int i = 0, carry = 0;
	while (a[i] && b[i])
	{
		c[i] = chradd(a[i], b[i], carry);
		i++;
	}
	if (a[i])
	{
		while (a[i])
		{
			c[i] = chradd(a[i], zero, carry);
			i++;
		}
	}
	else
	{
		while (b[i])
		{
			c[i] = chradd(b[i], zero, carry);
			i++;
		}
	}
	if (carry)
	{
		c[i++] = chr(carry);
	}
	c[i] = 0;
	c[i + 1] = 0;
	return c;
}

pchar strsub(const pchar a, const pchar b, const pchar c)
{
	int i = 0, carry = 0;
	while (a[i] && b[i])
	{
		c[i] = chrsub(a[i], b[i], carry);
		i++;
	}
	while (a[i])
	{
		c[i] = chrsub(a[i], zero, carry);
		i++;
	}
	remzers(c);
	return c;
}
char chrmul(char a, char b, int &carry)
{
	int temp = val(a) * val(b) + carry;
	carry = temp / 10;
	return chr(temp % 10);
}

pchar strmul(const pchar a, const pchar b, const pchar c)
{
	int jb = 0;
	pchar temp = new char[strlen(a) + 2];
	do
	{
		int ja = 0, carry = 0;
		do
		{
			temp[ja] = chrmul(a[ja], b[jb], carry);
			ja++;
		} while (a[ja]);

		if (carry)
		{
			temp[ja++] = chr(carry);
		}
		temp[ja] = 0;

		if (jb == 0)
		{
			strcpy(c, temp);
		}
		else
		{
			stradd(c + jb, temp, c + jb);
		}
		jb++;
	} while (b[jb]);
	delete temp;
	remzers(c);
	return c;
}

int strrcmp(const pchar a, const pchar b)
{
	int aj = strlen(a), bj = strlen(b);
	if (aj > bj)
	{
		return 1;
	}
	if (aj < bj)
	{
		return -1;
	}
	while (aj && a[aj] == b[aj])
	{
		aj--;
	}
	return a[aj] - b[aj];
}

pchar strdiv(const pchar a, const pchar b, const pchar c, const pchar r)
{
	int len = strlen(a), k = 0;
	pchar temp = new char[len + 1];
	strcpy(temp, a);
	pchar p = temp + len - strlen(b);
	do
	{
		c[k] = zero;
		while (strrcmp(p, b) >= 0)
		{
			c[k]++;
			strsub(p, b, r);
			strcpy(p, r);
		}
		p--;
		k++;
		c[k] = 0;
	} while (p >= temp);
	if (p < temp)
		p++;
	strcpy(r, p);
	remzers(r);
	strrev(c, c);
	remzers(c);
	delete temp;
	return c;
}

int max(int x, int y)
{
	return x > y ? x : y;
}
// Cài đặt lớp từ đây
class digits
{
	pchar v;
public:
	digits(int len = 2);
	digits(const digits &);
	digits(const pchar &);
	digits& operator =(const digits &);
	~digits()
	{
		delete v;
	}
	char& operator [](int k) const
	{
		return v[k];
	}

	friend int operator <(const digits &, const digits &);
	friend int operator <(const digits &, int);
	friend int operator >=(const digits &, int);
	friend int operator >(const digits &, int);
	friend int operator <=(const digits &, int);

	friend int operator >(const digits &, const digits &);
	friend int operator >=(const digits &, const digits &);
	friend int operator <=(const digits &, const digits &);
	friend int operator ==(const digits &, const digits &);
	friend int operator !=(const digits &, const digits &);
	digits operator -() const;
	friend digits operator +(const digits &, const digits &);
	friend digits operator -(const digits &a, const digits &b)
	{
		return a + -b;
	}
	friend digits operator *(const digits &, const digits &);
	friend digits operator /(const digits &, const digits &);
	friend digits operator %(digits &, digits &);

	friend digits abs(const digits &a)
	{
		return a >= 0 ? a : -a;
	}
	int len() const
	{
		return strlen(v);
	}
	friend ostream & operator <<(ostream &, const digits&);
	friend istream & operator >>(istream &, const digits&);
};

digits::digits(int len)
{
	if (len < 2)
		len = 2;
	v = new char[len + 1];
	for (int k = 0; k < len - 1; k++)
	{
		v[k] = zero;
	}
	v[len - 1] = v[len] = 0;
}

digits::digits(const digits &a)
{
	int _len = a.len();
	v = new char[_len + 2];
	strcpy(v, a.v);
	v[_len + 1] = 0;
}

digits::digits(const pchar &a)
{
	int _len = strlen(a);
	v = new char[_len + 2];
	strrev(a, v);
	v[_len + 1] = 0;
	remzers(v);
}

digits& digits::operator =(const digits &b)
{
	if (this != &b)
	{
		delete v;
		int _len = b.len();
		v = new char[_len + 2];
		v[_len + 1] = 0;
		strcpy(v, b.v);
	}
	return *this;
}

ostream & operator <<(ostream &pout, const digits &a)
{
	pchar s = new char[a.len() + 1];
	strrev(a.v, s);
	pout << s;
	return pout;
}

istream & operator >>(istream &pin, const digits &a)
{
	int n = 0, sign = 0;
	char ch;
	do
	{
		cout.flush();
		pin.get(ch);
		if (ch == minussign && n == 0 && !sign)
		{
			sign = 1;
		}
		else if (zero <= ch && ch <= '9')
		{
			a[n++] = ch;
		}
		else if (ch == '\b' && n >= 0)
		{
			if (n)
			{
				n--;
			}
			if (n == 0)
			{
				sign = 0;
			}
		}
	} while (ch != 10 || n == 0);
	cout << endl;

	a[n++] = 0;
	a[n] = 0;
	strrev(a.v, a.v);
	if (sign)
	{
		a[n - 1] = '-';
	}
	remzers(a.v);
	return pin;
}

int operator <(const digits &a, const digits &b)
{
	if (a < 0 && b >= 0)
	{
		return 1;
	}
	if (a >= 0 && b < 0)
	{
		return 0;
	}
	if (strrcmp(abs(a).v, abs(b).v) < 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int operator >(const digits &a, const digits &b)
{
	return b < a;
}
int operator >=(const digits &a, const digits &b)
{
	return !(a < b);
}
int operator <=(const digits &a, const digits &b)
{
	return !(b < a);
}
int operator ==(const digits &a, const digits &b)
{
	return a <= b && b <= a;
}
int operator !=(const digits &a, const digits &b)
{
	return !(a == b);
}
int operator <(const digits &a, int x)
{
	return a[a.len() - 1] == minussign;
}
int operator >=(const digits &a, int x)
{
	return a[a.len() - 1] != minussign;
}
int operator >(const digits &a, int x)
{
	return a[a.len() - 1] != minussign && a[0] != zero;
}
int operator <=(const digits &a, int x)
{
	return a[a.len() - 1] == minussign || a[0] == zero;
}

digits digits::operator -() const
{
	digits b(*this);
	int _len = len();
	if (b[_len - 1] == minussign)
	{
		b[_len - 1] = 0;
	}
	else
	{
		b[_len] = minussign;
	}
	return b;
}

digits operator +(const digits &a, const digits &b)
{
	if (a >= 0)
	{
		int clen = max(a.len(), b.len());
		digits c(clen + 2);
		if (b >= 0)
		{
			stradd(a.v, b.v, c.v);
			return c;
		}
		else if (a >= -b)
		{
			strsub(a.v, (-b).v, c.v);
			return c;
		}
		else
		{
			strsub((-b).v, a.v, c.v);
			return -c;
		}
	}
	else
	{
		return -(-a + -b);
	}
}

digits operator *(const digits &a, const digits &b)
{
	int clen = a.len() + b.len();
	int sign = 1;
	if (a < 0)
	{
		sign = -1;
	}
	if (b < 0)
	{
		sign = -sign;
	}
	digits c(clen + 1);
	strmul(abs(a).v, abs(b).v, c.v);
	if (sign == 1)
	{
		return c;
	}
	return -c;
}

digits operator /(const digits &a, const digits &b)
{
	if (abs(a) < abs(b))
		return digits((char*) "0");
	if (b == digits((char*) "0"))
		return digits((char*) "divide by zero");
	int sign = 1;
	if (a < 0)
	{
		sign = -1;
	}
	if (b < 0)
	{
		sign = -sign;
	}
	digits c(a.len() + 2);
	digits r(b.len() + 2);
	strdiv(abs(a).v, abs(b).v, c.v, r.v);
	if (sign == 1)
		return c;
	return -c;
}

digits operator %(digits &a, digits &b)
{
	if (abs(a) < abs(b))
	{
		return a;
	}
	if (b == digits((char*) "0"))
	{
		return digits((char*) "mod by zero");
	}
	int sign = 1;
	if (a < 0)
	{
		sign = -1;
	}
	if (b < 0)
	{
		sign = -sign;
	}
	digits c(a.len() + 2);
	digits r(b.len() + 2);
	strdiv(abs(a).v, abs(b).v, c.v, r.v);
	return r;
}
/**MAIN FUNCTION**/
int main()
{
#ifdef LOCAL_DEFINE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	digits a((char*) "17062010170620101706201017062010"), b(100);
	cout << "\na = " << a << endl;
	cout << "\nNhap so b: ";
	cin >> b;
	cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " - " << b << " = " << a - b << endl;
	cout << a << " * " << b << " = " << a * b << endl;
	cout << a << " / " << b << " = " << a / b << endl;
	cout << a << " % " << b << " = " << a % b << endl;
#ifdef LOCAL_DEFINE
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}
