
#include "MyVector.h"
#include <stdint.h>
#include <stdlib.h>
#define MAXN 200002
using namespace std;
class Node
{
	public:
		int xLoca;
		int yLoca;
		Node() {}
		Node(int const& x, int const& y) { xLoca = x; yLoca = y; }
		~Node() {}
};

int cmp(const void *a, const void *b)
{
	return (*(Node*)a).xLoca > (*(Node*)b).xLoca ? 1 : -1;
}
int main() {
	long n;
	scanf("%d", &n);
	Node *p=new Node [n];
	long *A=new long [n];
	long i;
	for (i = 0; i<n; i++)
		scanf("%d%d", &p[i].xLoca, &p[i].yLoca);
	qsort(p, n, sizeof(p[0]), cmp);
	for (i = 0; i<n; i++)
		A[i] = p[i].yLoca;
	MyVector<long> sortY(A, 0, n);
	sortY.cunt = 0;
	sortY.mergeSort(0,n);
	long tmp = (n*(n - 1)) >> 1;
	long cunt = sortY.getCunt();
	printf("%ld\n", tmp-cunt );
	delete A,p;
	return 0;
}
