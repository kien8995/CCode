/*
 * main.cpp
 *
 *  Created on: Dec 22, 2014
 *      Author: trankien
 */

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

#define U64 unsigned long long
#define I64 long long
#define LD  long double
#define FORLE(i,a,b) for(int i = (a); i <= (int)(b); ++i)
#define FORL(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define FORGE(i,a,b) for(int i= (a); i >= (int)(b); --i)
#define FORG(i,a,b) for(int i= (a); i > (int)(b); --i)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); ++i)
#define RFORV(i,a) for(typeof(a.rbegin()) i = a.rbegin(); i != a.rend(); ++i)
#define FORLEX(i,a,b,x) for(int i = (a); i <= (int)(b); i+=x)
#define FORLX(i,a,b,x) for(int i = (a); i < (int)(b); i+=x)
#define FORGEX(i,a,b,x) for(int i= (a); i >= (int)(b); i-=x)
#define FORGX(i,a,b,x) for(int i= (a); i > (int)(b); i-=x)
#define FORVX(i,a,x) for(typeof(a.begin()) i = a.begin(); i != a.end(); i+=x)
#define RFORVX(i,a,x) for(typeof(a.rbegin()) i = a.rbegin(); i != a.rend(); i+=x)
#define SET(a,c) memset(a, c, sizeof(a))
#define SETN(a,c,n) memset(a, c, n)
#define CPY(b,a) memcpy(b,a,sizeof(a))
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
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
#define eps 1e-5
#define infi 1e9
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
struct SinhVien
{
	char maSV[10];
	char hoDem[22];
	char ten[10];
	int namSinh;
	float diem;
};
struct Node
{
	SinhVien info;
	Node* next;
};
typedef Node* TRO;
//khoi tao danh sach
void initialize(TRO &L)
{
	L = NULL;
}
//kiem tra danh sach rong
bool isEmpty(TRO L)
{
	return L == NULL;
}
//nhap thong tin cho 1 sinh vien
void NhapSV(SinhVien &sv)
{
	printf("Nhap ma sinh vien: ");
	gets(sv.maSV);
	if (strcmp(sv.maSV, "***") == 0)
	{
		return;
	}
	printf("Ho dem: ");
	gets(sv.hoDem);
	printf("Ten: ");
	gets(sv.ten);
	printf("Nam sinh: ");
	scanf("%d", &sv.namSinh);
	printf("Diem: ");
	scanf("%f", &sv.diem);
}
//nhap danh sach sinh vien
void NhapDS(TRO &L)
{
	initialize(L);
	SinhVien x;
	TRO Q, P;
	int i = 0;
	do
	{
		printf("Nhap sinh vien thu %d:\n", ++i);
		NhapSV(x);
		if (strcmp(x.maSV, "***") == 0)
		{
			return;
		}
		P = new Node();
		P->info = x;
		P->next = NULL;
		if (L == NULL)
		{
			L = P;
		}
		else
		{
			Q->next = P;
		}
		Q = P;
	} while (1);
}
//hien thi danh sach sinh vien
void hienThiDS(TRO L)
{
	if (L == NULL)
	{
		printf("Danh sach rong.");
		return;
	}
	printf("%-5s | %-10s | %-25s | %-10s | %-10s\n", "STT", "Ma SV",
			"Ho va Ten", "Nam Sinh", "Diem");
	TRO Q = L;
	int i = 0;
	while (Q != NULL)
	{
		SinhVien x = Q->info;
		printf("%-5d | %-10s | %-25s | %-10d | %-2.2f\n", ++i, x.maSV,
				x.hoDem + " " + x.ten, x.namSinh, x.diem);
		Q = Q->next;
	}
}
//chieu dai cua danh sach
int length(TRO L)
{
	int n = 0;
	TRO Q = L;
	while (Q != NULL)
	{
		Q = Q->next;
		++n;
	}
	return n;
}
//xoa sinh vien dau tien trong danh sach
void xoaSVDauTien(TRO &L)
{
	if (L != NULL)
	{
		TRO Q = L;
		L = L->next;
		delete Q;
		printf("Danh sach sau khi xoa sinh vien dau.\n");
		hienThiDS(L);
		return;
	}
	printf("Danh sach rong.\n");
}
//xoa sinh vien co ma SV8089 trong danh sach
//Ham tim kiem thong tin theo maSV
TRO search(TRO L, char* maSV)
{
	TRO Q = L;
	while (Q != NULL && strcmp(Q->info.maSV, maSV) != 0)
	{
		Q = Q->next;
	}
	return Q;
}
//ham xoa nut tro boi con tro T trong danh sach
void remove(TRO &L, TRO T)
{
	TRO Q;
	if (T == L)
	{
		L = T->next;
	}
	else
	{
		Q = L;
		while (Q->next != T)
		{
			Q = Q->next;
		}
		Q->next = T->next;
	}
	delete T;
}
//xoa sinh vien co ma sv8089
void xoa_sv8089(TRO &L)
{
	//tim sv8089 trong danh sach
	TRO T = search(L, "sv8089");
	if (T == NULL)
	{
		printf("khong co sinh vien co ma sv8089 trong danh sach.");
		return;
	}
	remove(L, T);
	printf("danh sach vua xoa sv8089");
	hienThiDS(L);
}
//bo sung sinh vien moi vao vi tri k trong danh sach
//bo sung vao dau danh sach
void firstAdd(TRO &L, SinhVien x)
{
	TRO P;
	P = new Node();
	P->info = x;
	P->next = L;
	L = P;
}
//ham bo sung vao sau mot nut
void insert(TRO &L, TRO Q, SinhVien x)
{
	TRO P;
	P = new Node();
	P->info = x;
	P->next = Q->next;
}
//bo sung phan tu vao vi tri k
void boSung(TRO &L)
{
	int k;
	SinhVien x;
	//nhap cac thong tin can bo sung
	do
	{
		printf("nhap vao vi tri bo sung: ");
		scanf("%d", &k);
	} while (k < 1 || k > length(L));
	printf("nhap thong tin sinh vien can bo sung.\n");
	do
	{
		NhapSV(x);
		if (strcmp(x.maSV, "***") == 0)
		{
			printf("ma sinh vien phai khac ***, nhap lai.");
		}
	} while (strcmp(x.maSV, "***") == 0);
	//bo sung x vao vi tri k
	if (k == 1)
	{
		firstAdd(L, x);
	}
	else
	{
		//tim den nut k-1, Q tro vao nut nay
		TRO Q = L;
		int d = 1;
		while (d < k - 1)
		{
			d++;
			Q = Q->next;
		}
		//bo sung x vao sau nut tro boi Q
		insert(L, Q, x);
	}
	printf("danh sach vua duoc bo sung.\n");
	hienThiDS(L);
}
//hien thi nhung sinh vien co ten Doanh
void hienThiSVDoanh(TRO L)
{
	if (L == NULL)
	{
		printf("danh sach rong.");
		return;
	}
	printf("%-5s | %-10s | %-25s | %-10s | %-10s\n", "STT", "Ma SV",
			"Ho va Ten", "Nam Sinh", "Diem");
	TRO Q = L;
	int i = 0;
	while (Q != NULL)
	{
		SinhVien x = Q->info;
		if (strcmp(x.ten, "Doanh") == 0)
		{
			printf("%-5d | %-10s | %-25s | %-10d | %-2.2f\n", ++i, x.maSV,
					x.hoDem + " " + x.ten, x.namSinh, x.diem);
		}
		Q = Q->next;
	}
	if (i == 0)
	{
		printf("khong co sinh vien ten Doanh trong danh sach.");
	}
}
//sap xep danh sach theo chieu giam dan cua diem
void sapXepTheoDiem(TRO &L)
{
	TRO P, Q, R;
	P = L;
	while (P->next != NULL)
	{
		R = P;
		Q = P->next;
		while (Q != NULL)
		{
			if (Q->info.diem > R->info.diem)
			{
				R = Q;
			}
			Q = Q->next;
		}
		SinhVien tg = P->info;
		P->info = R->info;
		R->info = tg;
		P = P->next;
	}
	printf("danh sach giam theo chieu thu tu cua diem.\n");
	hienThiDS(L);
}
//bo sung moi va khong lam thay doi trat tu.
void boSungTheoTratTu(TRO &L)
{
	SinhVien x;
	printf("nhap thong tin sinh vien can bo sung.\n");
	do
	{
		NhapSV(x);
		if (strcmp(x.maSV, "***") == 0)
		{
			printf("ma sinh vien phai khac ***, nhap lai.\n");
		}
	} while (strcmp(x.maSV, "***") == 0);
	if (x.diem >= L->info.diem)
	{
		firstAdd(L, x);
	}
	else
	{
		//tim vi tri thich hop
		TRO Q = L;
		TRO T = Q->next;
		while (T != NULL && T->info.diem > x.diem)
		{
			Q = Q->next;
			T = T->next;
		}
		insert(L, Q, x);
	}
	printf("danh sach sau khi bo sung.\n");
	hienThiDS(L);
}
/**Main function**/
int main()
{
#ifdef LOCAL_DEFINE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	TRO L;
	NhapDS(L);
	hienThiDS(L);
	printf("chieu dai cua danh sach: %d", length(L));
	xoaSVDauTien(L);
	xoa_sv8089(L);
	boSung(L);
	hienThiSVDoanh(L);
	sapXepTheoDiem(L);
	boSungTheoTratTu(L);
#ifdef LOCAL_DEFINE
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}
