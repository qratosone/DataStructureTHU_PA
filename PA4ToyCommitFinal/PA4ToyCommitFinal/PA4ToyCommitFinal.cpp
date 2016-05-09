// PA4ToyCommitFinal.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"

#include <iostream>
using namespace std;
void copyInt(int *a, int *b) {
	for (int i = 0; i < 8; i++)
	{
		a[i] = b[i];
	}
}
#define MAX 40321
int Map[MAX];
int fac[8] = { 1,1,2,6,24,120,720,5040 };
class Board {
public:
	int back;
	int hash;
	int num[10];
	void Contor() {
		int num = 0;
		for (int i = 0; i < 8; i++)
		{
			int tmp = 0;
			for (int j = i + 1; j < 8; j++)
			{
				if (this->num[j] < this->num[i]) tmp++;
			}
			num += tmp*fac[7 - i];
		}
		this->hash = num;
	}
};
void output(int *a) {
	for (int i = 0; i < 8; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void exchange(int *a) {
	for (int i = 0; i <4; i++)
	{
		swap(a[i], a[i + 4]);
	}
	//count++;
}
void shift(int *a) {
	int temp = a[0];
	for (int i = 0; i < 3; i++)
		a[i] = a[i + 1];
	a[3] = temp;
	temp = a[4];
	for (int i = 4; i < 7; i++)
		a[i] = a[i+1];
	a[7] = temp;
	//output(a);
	//count++;
}
void turn(int *a) {
	int temp[4];
	temp[0] = a[1];
	temp[1] = a[2];
	temp[2] = a[6];
	temp[3] = a[5];
	a[5] = temp[0];
	a[1] = temp[1];
	a[2] = temp[2];
	a[6] = temp[3];
	//count++;
}
bool check(int *a) {
	int standard[8] = { 1,2,3,4,8,7,6,5 };
	for (int i = 0; i < 8; i++)
	{
		if (a[i] != standard[i])return false;
	}
	return true;
}
Board m[2 * MAX], ts;
int cnt = 0;
void Init(int *a) {
	int rear = 0;
	int tail = 1;
	copyInt(m[rear].num, a);
	m[rear].Contor();
	Map[m[rear].hash] = 1;
	//cout << m[rear].hash << endl;
	while (rear<tail)
	{
		//Map[m[rear].hash] = Map[m[m[rear].back].hash] + 1;//把rear的哈希Map值更新为rear.back的哈希Map加1,即从上一步再走一步到rear

		/*if (cnt <= 100)
		{
		output(m[rear].num);
		cout << "step =  " << Map[m[rear].hash] << " " << endl;
		cnt++;
		}*/
		copyInt(m[tail].num, m[rear].num);//交换
		exchange(m[tail].num);
		m[tail].Contor();
		if (!Map[m[tail].hash]) {
			Map[m[tail].hash] = Map[m[rear].hash] + 1;
			tail++;
		}
		copyInt(m[tail].num, m[rear].num);
		shift(m[tail].num);
		m[tail].Contor();
		if (!Map[m[tail].hash]) {
			Map[m[tail].hash] = Map[m[rear].hash] + 1;
			tail++;
		}
		copyInt(m[tail].num, m[rear].num);//交换
		turn(m[tail].num);
		m[tail].Contor();
		if (!Map[m[tail].hash]) {
			Map[m[tail].hash] = Map[m[rear].hash] + 1;
			tail++;
		}
		rear++;
	}
}
int main()
{
	//Board test;
	//for (int i = 0; i < 4; i++)
	//{
	//	cin >> test.num[i];
	//}
	//for (int i = 7; i > 3; i--)
	//{
	//	cin >> test.num[i];
	//}

	//turn(test.num);

	//	output(test.num);
	int model[8] = { 1,2,3,4,8,7,6,5 };
	Init(model);
	int T;
	cin >> T;
	while (T--)
	{
		//int input;
		for (int i = 0; i < 4; i++)
		{
			cin >> ts.num[i];
		}
		for (int i = 7; i > 3; i--)
		{
			cin >> ts.num[i];
		}
		//output(ts.num);
		ts.Contor();
		int result = Map[ts.hash] - 1;
		cout << result << endl;
	}
	return 0;
}
