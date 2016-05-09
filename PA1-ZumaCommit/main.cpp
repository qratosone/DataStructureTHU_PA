
#include "ListNode.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
List<char> Zuma;




int main()
{
	char a[10005];
	int n, k;
	gets(a);
	scanf("%d\n", &n);
	Zuma.ZumaCreate(a, strlen(a));

	for (k = 0; k < n; k++)
	{
		int m;
		char ch;
		scanf("%d ", &m);
		do
		{
			ch = getchar();
		} while (!((ch >= 'A') && (ch <= 'Z')));

		Zuma.insert(m, ch);
		Zuma.del(m);
		Zuma.show();
	}

	return 0;
}

