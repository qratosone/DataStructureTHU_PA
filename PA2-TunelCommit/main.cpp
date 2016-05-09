#include <stdio.h>
#include "ListNode.h"
#include <iostream>
#define Posi(int)  ListNode<int>*
using namespace std;
class Deque {
private:
    List<int> list;
public:
    Posi(int) front() { return list.first(); }
    Posi(int) rear() { return list.last(); }
    void insertFront(int const&e) { list.insertAsFirst(e); }
    void insertLast(int const&e) { list.insertAsLast(e); }
    int removeFront() { return list.remove(list.first()); }
    int removeRear() { return list.remove(list.last()); }
    int showMax() { return this->front()->data; }
    bool empty() {
        if (list.returnSize())
        {
            return false;
        }
        else {
            return true;
        }
    }
    void judgeRemoveFront() {
        if (!(--(this->front()->counter)))
        {
            this->removeFront();
        }
    }
    void judgeInsertRear(int const&e) { //只保存当前的最大值，在最大值之后插入的如实记录，在最大值之前插入的直接覆盖
        int a = 1;                                        //不可能存在一个数在最大值之前插入而比最大值晚出
        while (!this->empty()&&(this->rear()->data<=e))
        {
            a += this->rear()->counter;
            this->removeRear();
        }
        this->insertLast(e);
        this->rear()->counter = a;
    }
};

class Queue {
private:
    List<int> list;
public:
    void enqueue(int const& e) { list.insertAsLast(e); }
    int dequeue() { return list.remove(list.first()); }
    int  front() { return list.firstData(); }
    int returnMax() { return list.selectMaxData(); }

};
int main()
{
    Queue q;
    Deque max;
    int n;
    cin >> n;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        char op='0';

        do
        {
            op = getchar();
        } while ((op!= 'E') && (op!= 'M') && (op!= 'D'));
        switch (op)
        {
            case('E') :
                scanf("%d", &x);
                q.enqueue(x);
                max.judgeInsertRear(x);
                break;
            case('M') :
                printf("%d \n",max.showMax());
                break;
            case('D') :
                printf("%d \n",q.dequeue());
                max.judgeRemoveFront();
                break;
        }
    }

    return 0;
}