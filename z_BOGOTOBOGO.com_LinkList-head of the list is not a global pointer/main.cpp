/*
 * main.cpp
 *
 *  Created on: Dec 23, 2014
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
struct Node
{
	int data;
	Node *next;
};
//only for 1st Node
void initNode(Node *head, int n)
{
	head->data = n;
	head->next = NULL;
}

//appending
void addNode(Node *head, int n)
{
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = NULL;

	Node *cur = head;
	while (cur)
	{
		if (cur->next == NULL)
		{
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
}

void insertFront(Node **head, int n)
{
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = *head;
	*head = newNode;
}

Node* searchNode(Node *head, int n)
{
	Node *cur = head;
	while (cur)
	{
		if (cur->data == n)
		{
			return cur;
		}
		cur = cur->next;
	}
	printf("No node %d in list.", n);
}

bool deleteNode(Node **head, Node *ptrDel)
{
	Node *cur = *head;
	if (ptrDel == *head)
	{
		*head = cur->next;
		delete ptrDel;
		return true;
	}
	while (cur)
	{
		if (cur->next == ptrDel)
		{
			cur->next = ptrDel->next;
			delete ptrDel;
			return true;
		}
	}
	return false;
}

//reverse the list
Node* reverse(Node **head)
{
	Node *parent = *head;
	Node *me = parent->next;
	Node *child = me->next;

	//make parent as tail
	parent->next = NULL;
	while (child)
	{
		me->next = parent;
		parent = me;
		me = child;
		child = child->next;
	}
	me->next = parent;
	*head = me;
	return *head;
}

//creating a copy of link list
void copyLinkList(Node *node, Node **pNew)
{
	if (node != NULL)
	{
		*pNew = new Node;
		(*pNew)->data = node->data;
		(*pNew)->next = NULL;
		copyLinkList(node->next, &((*pNew)->next));
	}
}

/* Compare two linked list */
/* return value: same(1), different(0) */
int compareLinkList(Node *node1, Node *node2)
{
	static int flag;

	/* both lists are NULL */
	if (node1 == NULL && node2 == NULL)
	{
		flag = 1;
	}
	else
	{
		if (node1 == NULL || node2 == NULL)
		{
			flag = 0;
		}
		else if (node1->data != node2->data)
		{
			flag = 0;
		}
		else
		{
			compareLinkList(node1->next, node2->next);
		}
	}
	return flag;
}

void deleteLinkList(Node **node)
{
	Node *tmpNode;
	while (*node)
	{
		tmpNode = *node;
		*node = tmpNode->next;
		delete tmpNode;
	}
}

void display(Node *head)
{
	Node *list = head;
	while (list)
	{
		cout << list->data << " ";
		list = list->next;
	}
	cout << endl;
	cout << endl;
}
/**Main function**/
int main()
{
#ifdef LOCAL_DEFINE
	freopen("input.inp", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	Node *newHead;
	Node *head = new Node;
	initNode(head, 10);
	display(head);

	addNode(head, 20);
	display(head);

	addNode(head, 30);
	display(head);

	addNode(head, 35);
	display(head);

	addNode(head, 40);
	display(head);

	insertFront(&head, 5);
	display(head);

	int numDel = 5;
	Node *ptrDelete = searchNode(head, numDel);
	if (deleteNode(&head, ptrDelete))
		cout << "Node " << numDel << " deleted!\n";
	display(head);

	cout << "The list is reversed\n";
	reverse(&head);
	display(head);

	cout << "The list is copied\n";
	copyLinkList(head, &newHead);
	display(newHead);

	cout << "Comparing the two lists...\n";
	cout << "Are the two lists same?\n";
	if (compareLinkList(head, newHead))
		cout << "Yes, they are same!\n";
	else
		cout << "No, they are different!\n";
	cout << endl;

	numDel = 35;
	ptrDelete = searchNode(newHead, numDel);
	if (deleteNode(&newHead, ptrDelete))
	{
		cout << "Node " << numDel << " deleted!\n";
		cout << "The new list after the delete is\n";
		display(newHead);
	}
	cout << "Comparing the two lists again...\n";
	cout << "Are the two lists same?\n";
	if (compareLinkList(head, newHead))
		cout << "Yes, they are same!\n";
	else
		cout << "No, they are different!\n";

	cout << endl;
	cout << "Deleting the copied list\n";
	deleteLinkList(&newHead);
	display(newHead);
	return 0;
#ifdef LOCAL_DEFINE
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}
