#include <cstring>
#include <iostream>
 
 
using namespace std;
 
 
 
 
 
// main
int main( int argc, char *argv[] )
{
	int n;
	int *arr;
	bool *table;
 
 
	// input
	cin >> n;
	arr = new int[n];
	table = new bool[n+1];
	memset(table, 0, sizeof(bool)*(n+1));

	for(auto *b = arr, *e = arr+n; b != e; ++b)
	{
		cin >> *b;
		if(!*b)
			continue;
		if(*b > n || table[*b])
			goto fail_label;
		table[*b] = true;
	}
	
	
	
	// solve
	{
		int val = 1;
		for(auto *b = arr, *e = arr+n; b != e; ++b)
		{
			if(*b)
				continue;
			while(table[val])
				++val;
			*b = val;
			++val;
		}
	}
 
 
 
	// output
	cout << n << endl;
	for(auto *b = arr, *e = arr+n; b != e; ++b)
		cout << *b << ' ';
	cout << endl;
	return 0;
 
 
fail_label:
	cout << -1 << endl;
	return 0;
}
 
 
 
 
 
// end
