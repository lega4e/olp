#include <cstring>
#include <iostream>

#define MOD(x) ( (x) % 1000000007 )


using namespace std;





// main
int main( int argc, char *argv[] )
{
	typedef long long llong;

	int l, r;
	llong *vals;
	
	
	
	// input, prepare
	cin >> l >> r;
	vals = new llong[r+1];
	memset(vals, 0, sizeof(llong)*(r+1));
	vals[1] = 1;
	
	
	
	// solve
	for(int i = 1; i <= r - r/2; ++i)
	{
		vals[i] = MOD(vals[i]);
		for(int j = 2*i; j <= r; j += i)
		{
			vals[j] += vals[i];
		}
	}

	llong sum = 0;
	for(int i = l; i < r+1; ++i)
		sum += vals[i];
	sum = MOD(sum);
	
	
	
	// output
	cout << sum << endl;



	return 0;
}





// end
