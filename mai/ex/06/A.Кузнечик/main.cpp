#include <iostream>

#define MOD(x) ( (x) % 1000000007l )


using namespace std;





// main
int main( int argc, char *argv[] )
{
	typedef long long llong;

	int n, k;
	llong *arr;
	
	
	
	// input, prepare
	cin >> n >> k;
	arr = new llong[n+1];
	arr[0] = 1;
	
	
	
	// solve
	for(int i = 1; i < n+1; ++i)
	{
		arr[i] = 0;
		for(int j = max(i-k, 0); j < i; ++j)
			arr[i] = MOD(arr[i]+arr[j]);
	}
	
	
	
	// output
	cout << arr[n] << endl;



	return 0;
}





// end
