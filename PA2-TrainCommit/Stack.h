#pragma once
#include "MyVector.h"
template <typename T>
class Stack:public MyVector<T>
{
public:
	
	Stack() {count=0;};
	~Stack() {};
	int table[10000];
	int count ;
	void push(T const & e)
	{
		this->insert(this->getSize(), e);
		table[count] = 1;
		count++;

	}  //ÈëÕ»
	T pop()
	{
		if(this->getSize()==0)return 0;
		table[count] = 0;
		count++;
		return this->remove(this->getSize() - 1);
	}  //³öÕ»
	int StackLen() { return this->getSize(); }
private:
	
};

