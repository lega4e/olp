#include <iostream>

#define MOD 1000000007


using namespace std;





// types
typedef long long llong;





// functions
inline llong mod(llong a, llong b)
{
	return (b + a%b) % b;
}





// main
int main( int argc, char *argv[] )
{
	int n, k;
	llong *vals;
	llong *sums;
	
	
	// input
	cin >> n >> k;
	vals = new llong[n+1];
	sums = new llong[n+1];

	vals[0] = 1;
	sums[0] = 1;
	
	
	
	// solve
	for(int i = 1; i < n+1; ++i)
	{
		vals[i] = sums[i-1];
		if(i-k-1 >= 0)
			vals[i] -= sums[i-k-1];
		vals[i] = mod(vals[i], MOD);
		sums[i] = mod(sums[i-1] + vals[i], MOD);
	}
	
	
	
	// output
	printf("%lli\n", vals[n]);



	return 0;
}





// end
