#include <iostream>
#include <string>
using namespace std;
class HashTable {
private:
	string *elem;
	int size;
public:
	HashTable(int num) {
		size = num;
		elem = new string[size];
		for (int i = 0; i < size; i++)
		{
			elem[i] = "#";
		}
	}
	~HashTable() {
		delete[] elem;
	}
	int hash(string &index) {
		int code = 0;
		for (size_t i = 0; i < index.length(); i++)
		{
			code = (code * 26 + index[i] + 13) % size;
		}
		return code;
	}
	
	bool searchFor(string &index) {
		int posi = 0;
		int count = 0;
		return search(index, posi, count);
	}
	bool search(string &index, int &pos, int &times) {
		pos = hash(index);
		times = 0;
		while (elem[pos]!="#"&&elem[pos]!=index)
		{
			times++;
			if (times<size)
			{
				pos = (pos + 1) % size;
			}
			else {
				return false;
			}
		}
		if (elem[pos] == index) {
			return true;
		}
		else
		{
			return false;
		}
	}
	int insert(string &index) {
		int pos, times;
		if (search(index,pos,times)) //已有元素
		{
			return 2;
		}
		else if(times<size/2) //插入成功
		{
			elem[pos] = index;
			return 1;
		}
		else {  //空间不足，插入失败
			recreate();
			return 0;
		}
	}
	void recreate() {
		string *temp_elem;
		temp_elem = new string[size];
		for (size_t i = 0;  i < size;  i++)
		{
			temp_elem[i] = elem[i];
		}
		int copy_size =  size;
		size = size * 2;
		delete[] elem;
		elem = new string[size];
		for (size_t i = 0; i < size; i++)
		{
			elem[i] = "#";
		}
		for (size_t i = 0; i < copy_size; i++)
		{
			if (temp_elem[i]!="#")
			{
				insert(temp_elem[i]);
			}
		}
		delete[] temp_elem;
	}

};