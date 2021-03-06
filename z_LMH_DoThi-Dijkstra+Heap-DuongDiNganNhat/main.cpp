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
const int MAX = 10000;
const int MAXE = 100000;
int adj[MAXE + 1];	//danh sach ke dang mang
int adjCost[MAXE + 1];	//kem trong so
int h[MAX + 2];	//mang danh dau cac doan trong danh sach ke adj
int d[MAX + 1];
int trace[MAX + 1];
bool Free[MAX + 1];
int heap[MAX + 1]; //dinh luu tai nut i cua heap
int pos[MAX + 1];	//pos[v] = vi tri cua nut v trong heap (pos[heap[i]] = i;)
int n, m, s, f, nHeap;
void enter()
{
	scanf("%d %d %d %d", &n, &m, &s, &f);
	//phep dem phan phoi( Distribution couting)
	set(h, 0);
	int u, v, c;
	forle(i,1,m)
	{
		scanf("%d", &u);//ta chi can tinh ban bac ra (deg+) cua moi dinh, nen khong can doc du 3 thanh phan
		cin.ignore(MAX, '\n');
		debug1(u);
		++h[u];
	}
	forle(i,2,n)
	{
		h[i] += h[i - 1];
	}
	//den day, ta xac dinh duoc h[u] la vi tri cuoi cung cua danh sach ke dinh u trong adj
	//fseek(stdin, 0, SEEK_SET);
	//fsetpos(stdin, 0);
	//rewind(stdin);	//doc file lan 2, vao cau truc danh sach ke
	//fclose(stdin);
	fclose(stdin);
	fopen("input.inp", "r");
	rewind(stdin);

	cin.ignore(MAX, '\n');	//bo qua dong dau tien
	forle(i,1,m)
	{
		RIII(u, v, c);
		debug3("ddd", u, v, c);
		adj[h[u]] = v;	//dien v va c vao vi tri dung trong danh sach ke cua u
		adjCost[h[u]] = c;
		--h[u];
	}
	h[n + 1] = m;
}
void init()	//khoi tao d[i] = do dai duong di ngan nhat tu s toi i qua 0 canh , heap rong
{
	forle(i,1,n)
	{
		d[i] = INF;
	}
	d[s] = 0;
	set(Free, true);
	set(pos, 0);
	nHeap = 0;
}
void update(int v)	//dinh v vua duoc sua nhan, can phai chinh lai heap
{
	int parent, child;
	child = pos[v];	//child la vi tri cua v trong heap
	if (child == 0)	//neu v chua co trong heap thi heap phai bo sung 1 phan tu, va child coi nhu la cuoi cua heap
	{
		++nHeap;
		child = nHeap;
	}
	parent = child / 2;	//parent la nut cha cua child
	while (parent > 0 && d[heap[parent]] > d[v])
	{
		//neu dinh luu o nut parent uu tien kem hon v thi dinh do se bi day xuong nut con child
		heap[child] = heap[parent];	//day dinh luu trong nut cha xuong nut con
		pos[heap[child]] = child;	//ghi nhan lai vi tri moi cua dinh do
		child = parent;	//tiep tuc xet len phia nut goc
		parent = child / 2;
	}
	//thao tac "keo xuong" o tren tao ra 1 "khoang trong" tai nut child cua heap, dinh v se duoc dat vao day
	heap[child] = v;
	pos[v] = child;
}
int pop()	//lay tu heap ra dinh co nhan tu do nho nhat
{
	int r, c, v;
	int x = heap[1];	//nut goc heap chua dinh co nhan tu do nho nhat
	v = heap[nHeap];//v la dinh o nut la cuoi heap, se duoc dao len dau va vun dong
	--nHeap;
	r = 1;	//bat dau tu nut goc
	while (r * 2 <= nHeap)	//chung nao r chua phai la la
	{
		//chon c la nut cha chua dinh uu tien hon trong 2 nut con
		c = r * 2;
		if (c < nHeap && d[heap[c + 1]] < d[heap[c]])
		{
			++c;
		}
		//neu v uu tien hon ca dinh cua trong c ,thi thoat ngay
		if (d[v] <= d[heap[c]])
		{
			break;
		}
		heap[r] = heap[c];	//chuyen dinh luu o nut con c len nut cha r
		pos[heap[r]] = r;	//ghi nhan lai vi tri moi trong heap cua dinh do
		r = c; //gan nut cha = nut con, lap lai
	}
	heap[r] = v;	//dinh v se duoc dat vao nut r de bao toan cau truc heap
	pos[v] = r;
	return x;
}
void dijkstra()
{
	int u, v;
	update(s);	//dua dinh xuat phat ve goc heap
	while (nHeap != 0)	//lap cho den khi khong con dinh nao mang nhan tu do
	{
		u = pop();	//chon dinh tu do co nhan nho nhat
		if (u == f)
		{
			break;	//neu dinh do la f thi dung ngay
		}
		Free[u] = false;	//co dinh nhan dinh do
		forle(iv,h[u]+1,h[u+1])	//xet danh sach ke
		{
			v = adj[iv];
			if (Free[v] && d[v] > d[u] + adjCost[iv])
			{
				d[v] = d[u] + adjCost[iv];//toi uu hoa nhan cua cac dinh tu do ke voi u
				trace[v] = u;	//luu vet duong di
				update(v);	//to chuc lai heap
			}
		}
	}
}
void printResult()
{
	if (d[f] == INF)
	{
		printf("There is no path from %d to %d.\n", s, f);
	}
	else
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
	dijkstra();
	printResult();
#ifdef LOCAL_DEFINE
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}
