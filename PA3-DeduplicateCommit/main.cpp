#include <iostream>
#include <string>
#include "Hash.h"
using namespace std;

int main()
{
    string input;
	int n;
	cin >> n;
	string *repeat = new string[n];
	int hashCode[500000] = { 0 };
	int count = 0;
	HashTable hash(500000);
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (hash.insert(input)==2) {
			int code = hash.hash(input);
			if (hashCode[code]==0)
			{
				repeat[count].assign(input.begin(), input.end());
				count++;
				hashCode[code] = 1;
			}
		}
	}
	for (int i = 0; i < count; i++)
	{
		cout << repeat[i] << endl;
	}
    return 0;
}
