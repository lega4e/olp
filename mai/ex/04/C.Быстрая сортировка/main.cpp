#include <cstring>
#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	typedef long long ll;

	constexpr ll const COUNTS_SPACE = 100400;
	constexpr ll const MOD = 1000000007;

	ll csize = 0;
	ll *counts;
	
	
	
	// input
	{
		ll n;
		ll a, m, k, mod;
		scanf("%lli%lli%lli%lli%lli", &n, &a, &m, &k, &mod);
		counts = new ll[COUNTS_SPACE];
		memset( counts, 0, sizeof(*counts)*COUNTS_SPACE );
		for(ll i = 0; i < n; ++i)
		{
			++counts[a];
			if(a >= csize)
				csize = a+1;
			a = (a*m + k) % mod;
		}
	}
	
	

	// solve
	ll sum = 0;
	for(ll i = 0, ptr = 1; i < csize; ++i)
	{
		sum += i*(
			ptr*counts[i] + 
			counts[i] * (counts[i]-1) / 2
		);
		sum %= MOD;
		ptr += counts[i];
	}
	
	
	
	// output
	printf("%lli\n", sum);
	



	return 0;
}





// end
