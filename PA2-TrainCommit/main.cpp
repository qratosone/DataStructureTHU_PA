#include "Stack.h"
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int main()
{
    Stack<int> S;
    int n, m;
    scanf("%d%d",&n,&m);
    int *A=new int[n];
    int k;
    int temp_pop;
    for (k = 0; k < n; k++) {
        scanf("%d",A+k);
    }
    int i;

    int A_pos = 0;
    for (i = 1; A_pos < n;)
    {
        if (i < A[A_pos])
        {
            if (m < S.StackLen()+1)break;
            S.push(i);

            i++;
        }
        else if (i>A[A_pos]) {
             temp_pop = S.pop();
            while (temp_pop==A[A_pos]&&S.StackLen())
            {
                A_pos++;
                if (temp_pop > A[A_pos])temp_pop = S.pop();
            }
            if (A[A_pos] < temp_pop)break;
            if (i > n || !S.StackLen())A_pos++;
        }
        else {
            if (m < S.StackLen()+1)break;
            S.push(i);
            S.pop();
            A_pos++; i++;
        }
    }
    if (A_pos!=n)
    {
        cout << "No" << endl;
    }
    else {
        for (int i = 0; i < S.count; i++)
        {
            if (S.table[i]==1)
            {
                cout << "push" << endl;
            }
            else
            {
                cout << "pop" << endl;
            }
        }
    }
    delete A;
    return 0;
}