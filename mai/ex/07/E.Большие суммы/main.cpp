#include <iostream>

#define MOD 1000000007


using namespace std;





// types
typedef long long llong;





// functions
llong bin_pow(llong a, llong n)
{
	llong res = 1;
	for(int i = 0; i < n; ++i)
	{
		res = res * a % MOD;
	}

	return res;
}





// main
int main( int argc, char *argv[] )
{

	int n;



	// input
	scanf("%i", &n);
	llong input;
	llong sum = 0;
	for(int i = 0; i < n; ++i)
	{
		scanf("%lli", &input);
		sum += input;
	}
	sum = sum * bin_pow(2, n-1) % MOD;
	
	
	
	// output
	printf("%lli\n", sum);




	return 0;
}





// end
