#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a[1600000];
char pint[3200000][5];
int n,m;
int pos_a=0,pos_s=0,pos_pint=0;

typedef struct{
	int *base;
	int *top;
	int stacksize;
}sqStack;
void initStack(sqStack *s)
{
	s->base = (int*)malloc((m+1)*sizeof(int));
	if(!s->base)exit(0);
	s->top = s->base;
	s->stacksize = m;
}
void Push(sqStack *s,int e)
{
	*(s->top) = e;
	s->top++;
	pos_s++;
	strcpy(pint[pos_pint++],"push");
}
void Pop(sqStack *s,int *e)
{
	if(s->top == s->base)return;
	*e = *--(s->top);
	pos_s--;
	strcpy(pint[pos_pint++],"pop");
}
int StackLen(sqStack s)
{
	return (s.top - s.base);
}
int main()
{
	int i=0,j=0;
	sqStack s;
	int temp_top;
	
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	while(i<n){scanf("%d",a+i);i++;}
	initStack(&s);
	for(i=1;pos_a<n;)
	{
		//printf("%d %d\n",i,a[pos_a]);
		if(i<a[pos_a])
		{
			if(m<pos_s+1)break;
			Push(&s,i);
			i++;
		}
		else if(i>a[pos_a])
		{
			Pop(&s,&temp_top);
			while(temp_top==a[pos_a]&&pos_s)
			{
				pos_a++;
				if(temp_top>a[pos_a])Pop(&s,&temp_top);
			}
			if(a[pos_a]<temp_top)break;
			if(i>n||!pos_s)pos_a++; 
		}
		else
		{
			if(m<pos_s+1)break;
			Push(&s,i);
			Pop(&s,&temp_top);
			pos_a++;i++;
		}
		
	}
	
	if(pos_a!=n)printf("No\n");
	else
	{
		i=0;
		while(i<pos_pint)
		puts(pint[i++]);
	}
	return 0;
}