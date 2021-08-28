#include <algorithm>
#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	int n;
	int *arr;
	
	
	
	// input
	cin >> n;
	arr = new int[n];
	for(auto *b = arr, *e = arr+n; b != e; ++b)
		cin >> *b;
	
	
	
	// sort
	sort(arr, arr+n);
	
	
	
	// output
	for(auto *b = arr, *e = arr+n; b != e; ++b)
		cout << *b << ' ';
	cout << endl;



	return 0;
}





// end
