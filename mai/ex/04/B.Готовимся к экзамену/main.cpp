#include <cmath>
#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	typedef long long ll;
	constexpr ll const MOD = 1000000007;

	int n;
	ll val;
	
	
	
	// solve
	scanf("%i %lli", &n, &val);
	ll fmax = -1, smax = -1;
	for(int i = 0; i < n; ++i)
	{
		val = (val*5l)%MOD;
		if(val > fmax)
			smax = fmax,
			fmax = val;
		else if(val > smax)
			smax = val;
	}
	
	
	
	// output
	printf("%lli %lli\n", smax, fmax);



	return 0;
}





// end
