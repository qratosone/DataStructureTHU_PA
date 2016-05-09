#include<iostream>
#include<cstdio>
#include<cstdlib>
#include "MyVector.h"
using namespace std;
const size_t max_size = 400000;
int preOrder[max_size]={0};
int postOrder[max_size]={0};
int inOrder[max_size]={0};

void rebuild(int pre_left, int pre_right, int post_left, int post_right) {
    if (pre_right == pre_left)return;

    int i, j;
    for (i = post_left, j = 0; postOrder[i] != preOrder[pre_left + 1]; ++i, j++);
    inOrder[i + 1] = preOrder[pre_left];
    int k;
    for(k = post_right; k> i + 1; --k)
        postOrder[k] = postOrder[k-1];
    if(k!= post_right)
        postOrder[k] = 0;

    rebuild(pre_left + 1, pre_left + 1 + j, post_left, i);
    rebuild(pre_left + 1 + j + 1, pre_right, i + 2, post_right);
}
int main(int argc, char *argv[])
{
    int size;
    scanf("%d", &size);
    for (int i = 0; i < size; ++i){
        scanf("%d", &preOrder[i]);
    }

    for (int i = 0; i < size; ++i){
        scanf("%d", &postOrder[i]);
    }
    rebuild(0, size - 1, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        if (inOrder[i] == 0)inOrder[i] = postOrder[i];
    }
    for(int i=0;i<size;i++){
        cout<<inOrder[i]<<" ";
    }
    cout<<endl;
    return 0;
}