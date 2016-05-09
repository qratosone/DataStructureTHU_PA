typedef int Rank;
#define DEFAULT_CAPACITY 3

#include <iostream>
template <typename T>class MyVector{
public:
	MyVector(int c = DEFAULT_CAPACITY) {
		_size = 0;
		_capacity = c;
		_elem = new T[_capacity];
	}
	Rank search(T const& e)  
	{
		return (0 >= _size) ? -1 : search(e, 0, _size);
	}
	Rank search(T const & e, Rank lo, Rank hi) {
		return binSearch(_elem, e, lo, hi);
	}

	static Rank binSearch(T* A, T const&e, Rank lo, Rank hi) {
		while (lo < hi)
		{
			Rank mi = lo + ((hi - lo) >> 1);
			if (e < A[mi]) {
				hi = mi;
			}
			else
			{
				lo = mi + 1;
			}
			
		}
		return --lo;
	}
	
	void show() {
		for (int i = 0; i < _size; i++)
		{
			std::cout << _elem[i] << " ";
		}
	}
	Rank getSize() {
		return _size;
	}
	T* getElem(){
		return _elem;
	}
	T lastvalue() {
		return _elem[_size-1];
	}
	T & operator[](Rank r) const { return _elem[r]; };
	void swap(T &a, T &b) {
		T temp = 0;
		if (a > b)
		{
			temp = b;
			b = a;
			a = temp;
		}
	}
	
private:
	Rank _size;
	int _capacity;
	T* _elem;
};