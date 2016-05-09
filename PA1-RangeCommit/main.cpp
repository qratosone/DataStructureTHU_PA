
#include "MyVector.h"
#include <stdio.h>
#include <stdlib.h>
#define L 500005

int V[L];
void swap(int& a,int& b){
	int temp=a;
	a=b;
	b=temp;
}
int compare(const void *a, const void *b)
{
	int *pa = (int*)a;
	int *pb = (int*)b;
	return (*pa) - (*pb);
}
int main()
{
	int n, m;
	scanf("%d %d\n",&n,&m);
	MyVector<int> Points(n);
	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d",&V[i]);

	}
	qsort(V,n,sizeof(int),compare);//refer to http://www.cnblogs.com/CCBB/archive/2010/01/15/1648827.html
	Points.copyFrom(V,0,n);


	int a, b;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d",&a,&b);
		if (a>b) swap(a,b);
		int lo = Points.search(a);
		int hi = Points.search(b);
		int ans=hi-lo;


		if(Points[lo]==a)ans++;
		//if(Points[lo]<a&&b>Points.lastvalue())ans--;
		if(ans<0)ans=0;
		printf("%d\n",ans);
	}
	return 0;
}
