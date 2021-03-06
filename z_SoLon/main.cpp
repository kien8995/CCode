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
#define setn(a,c,n) memset(a, c, n*sizeof(a)[0])
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
#define LOCAL_DEFINE
//-------------------------------------------------
#define zero '0'
typedef char* pchar;
int val(char chr)
{
	return chr - zero;
} // Giá trị tương ứng với ký tự chr biểu thị số
char chr(int num)
{
	return num + zero;
} // Ký tự tương ứng với giá trị num
int strlen(const pchar a)        // Độ dài của xâu
{
	pchar p = a;
	while (*p)
	{
		p++;
	}
	return p - a;
}
char chradd(char a, char b, int &carry)  // Cộng hai chữ số
{
	int temp = val(a) + val(b) + carry;
	carry = temp / 10;
	return chr(temp % 10);
}

pchar stradd(const pchar a, const pchar b, const pchar c) // Cộng hai số có nhiều chữ số
{
	int i = 0, carry = 0;    //Ban đầu, nhớ bằng 0
	while (a[i] && b[i])
	{
		c[i] = chradd(a[i], b[i], carry); // Cộng lần lượt từ đầu đến cuối
		i++;
	}
	if (a[i])
	{ // Nếu xâu a dài hơn xâu b
		while (a[i])
		{
			c[i] = chradd(a[i], zero, carry); // Cộng tiếp a[i] với 0
			i++;
		}
	}
	else
	{
		// Nếu xâu b dài hơn
		while (b[i])
		{
			c[i] = chradd(b[i], zero, carry); // Cộng tiếp b[i] với 0
			i++;
		}
	}
	if (carry)
	{
		c[i++] = chr(carry);            //Nếu cuối cùng mà nhớ khác 0
	}
	c[i] = 0;                    // Đặt null vào cuối
	return c;
}

char chrsub(char a, char b, int &carry)
{
	int temp = 10 + val(a) - val(b) - carry; // Cứ vay 10 rồi trừ đi (kể cả cho nhớ cũ)
	carry = 1 - temp / 10;            // Nếu sau trừ mà >= 10 thì không phải vay
	return chr(temp % 10);
}
pchar strsub(const pchar a, const pchar b, const pchar c) // Trừ số có nhiều chữ số
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
	while (i > 0 && c[--i] == zero)
		;
	c[++i] = 0;
	return c;
}

int strrcmp(const pchar a, const pchar b)
{
	int aj = strlen(a), bj = strlen(b);
	while (aj && a[--aj] == zero)
		;     //Bỏ qua các '0' ở cuối của a
	while (bj && b[--bj] == zero)
		;     //Bỏ qua các '0' ở cuối của b
	if (aj > bj)
	{
		return 1;            //Nếu xâu a dài hơn thì a > b
	}
	if (aj < bj)
	{
		return -1;            //Nếu xâu a ngắn hơn thì a < b
	}
	while (aj && a[aj] == b[aj])
	{
		aj--;    // Nếu độ dài như nhau thì tìm đến chữ số khác nhau đầu tiên
	}
	return a[aj] - b[aj]; // So sánh hai chữ số đó, cùng lắm thì so các chữ số đầu tiên.
}

pchar strcpy(const pchar dest, const pchar src) // Sao chép src vào dest
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
pchar strrev(const pchar src, const pchar dest) //Hàm trỏ tới xâu dest, là đảo ngược của xâu src
{
	strcpy(dest, src);    // Khi dest trùng với src vẫn dùng được
	int len = strlen(src);
	for (int k = 0; k < len / 2; k++)
	{
		char temp = dest[k];
		dest[k] = dest[len - k - 1];
		dest[len - k - 1] = temp;
	}
	return dest;
}

char chrmul(char a, char b, int &carry) // Nhân hai chữ số
{
	int temp = val(a) * val(b) + carry;
	carry = temp / 10;
	return chr(temp % 10);
}
pchar strmul(const pchar a, const pchar b, const pchar c) // Nhân hai số có nhiều chữ số, c=a*b
{
	int jb = 0;
	pchar temp = new char[strlen(a) + 2]; // Vùng nhớ lưu kết quả trung gian khi nhân a với
	do                    // từng chữ số của b.
	{
		int ja = 0, carry = 0;
		do                    //Lần lượt với từng chữ số của a
		{
			temp[ja] = chrmul(a[ja], b[jb], carry);  // Có tăng ja đấy nhé
			ja++;
		} while (a[ja]);

		if (carry)
		{
			temp[ja++] = chr(carry); // Cuối mỗi lượt nhân a với 1 chữ số của b
		}
		temp[ja] = 0;                // Đặt null vào temp

		if (jb == 0)
		{
			strcpy(c, temp);        // Với lượt nhân đầu tiên
		}
		else
		{
			stradd(c + jb, temp, c + jb); // Đây chính là đặt kết quả dịch 1 chữ số đó
		}
		jb++;                    // Chuyển sang chữ số kế tiếp của b
	} while (b[jb]);                // Khi xâu b vẫn còn
	delete temp;                // Giải phóng vùng nhớ lưu kết quả trung gian
	return c;                // Cho hàm trỏ tới c
}

pchar strdiv(const pchar a, const pchar b, const pchar c, const pchar r)
{
	int len = strlen(a), k = 0;
	pchar temp = new char[len + 1];     // Vùng nhớ lưu các kết quả trung gian
	strcpy(temp, a);              // Ban đầu là bản sao của a
	pchar p = temp + len - strlen(b); // Cho p trỏ tới nhóm trong a có số chữ số bằng b
	do                    // Lặp cho tới khi hạ hết các chữ số của a
	{
		c[k] = zero;            // Ban đầu đặt bằng '0' (tức = 0 lần)
		while (strrcmp(p, b) >= 0)    // Nếu còn được lần nữa
		{
			c[k]++;        // Thì cộng thêm 1
			strsub(p, b, r);        // Trừ bớt p đi 1 lần b
			strcpy(p, r);        // Cập nhật lại hiệu
		}
		p--;                 // Chuẩn bị hạ 1 chữ số của a
		k++;                 // Đã chia xong một nhóm
		c[k] = 0;                // Đặt null vào cuối
	} while (p >= temp);            // Khi chưa hết các chữ số của a

	strrev(c, c);                // Vì thương được ghi thuận nên phải dảo lại
	k = strlen(c) - 1;
	while (c[k] == zero)
	{
		k--;        // Loại bỏ '0' sinh ra vì nhóm đầu tiên có thể < b
	}
	c[++k] = 0;                // Đặt null vào cuối xâu kết quả
	delete temp;                // Xoá vùng nhớ
	return c;                // Cho hàm trỏ tới thương
}
/**MAIN FUNCTION**/
int main()
{
#ifdef LOCAL_DEFINE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	char a[] = "7650035435430002526471232732", b[] = "19153500423021";
	char c[100], r[100], da[100], db[100], dc[100];

	strrev(a, da);
	strrev(b, db);             // da và db là đảo ngược của a và b
	stradd(da, db, c);                // c = da + db
	printf("\n%s + %s = %s\n", a, b, strrev(c, c));    // Vì c là đảo ngược

	strsub(da, db, c);                // c = da – db, đừng lấy db – da nhé
	printf("\n%s - %s = %s\n", a, b, strrev(c, c));

	strmul(da, db, c);                // c = da*db
	printf("\n%s * %s = %s\n", a, b, strrev(c, c));

	strrev(c, dc);                   // Do c bị đảo ở lệnh printf(), nên đảo lại
	stradd(dc, (char*)"123", dc);                // Cộng thêm "321 vào dc
	strdiv(dc, db, da, r);                // da = dc/db <=> da = c/b đó
	strrev(da, da);
	strrev(r, r);
	strrev(dc, dc);
	printf("\n%s / %s = %s du %s\n", dc, b, da, r); // Chắc chắn dư là 321
#ifdef LOCAL_DEFINE
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}
