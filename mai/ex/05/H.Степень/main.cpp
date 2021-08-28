#include <iostream>


using namespace std;





// types
typedef long long llong;





// objects
constexpr llong const MOD = 1000000007;





// functions
llong bin_pow(llong a, llong n)
{
	llong res = 1;
	while(n)
	{
		if(n % 2)
			res = res*a % MOD;
		a = a*a % MOD;
		n /= 2;
	}
	return res;
}





// main
int main( int argc, char *argv[] )
{
	int t;
	scanf("%i", &t);
	
	
	// solve
	{
		llong a, n;
		for(int i = 0; i < t; ++i)
		{
			scanf("%lli%lli", &a, &n);
			printf("%lli\n", bin_pow(a, n));
		}
	}



	return 0;
}





// end
