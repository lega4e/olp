#include <algorithm>
#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	int n, k;
	int *arr;
	
	
	
	// input
	cin >> n >> k;
	arr = new int[n];
	for(auto *b = arr, *e = arr+n; b != e; ++b)
		cin >> *b;
	
	
	
	// solve
	sort(arr, arr+n, greater<int>());

	int sum = 0;
	for(int i = 0; i < n; ++i)
	{
		if((i+1)%k)
			sum += arr[i];
	}
	
	
	
	// output
	cout << sum << endl;



	return 0;
}





// end
