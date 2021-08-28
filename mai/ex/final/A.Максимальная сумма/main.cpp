#include <algorithm>
#include <cmath>
#include <iostream>


using namespace std;





// types
typedef long long llong;





// objects
constexpr llong const MOD = pow(2, 32);





// functions
inline llong mod(llong x)
{
	return x % MOD;
}





// main
int main( int argc, char *argv[] )
{
	int n;
	llong *a;
	
	
	
	// input
	scanf("%i", &n);
	a = new llong[n];
	for(auto *b = a, *e = a+n; b != e; ++b)
		scanf("%lli", b);
	
	
	
	// solve
	sort(a, a+n);

	llong themax = 0;
	llong mm;
	llong *p;
	for(int r = n-1; r > 0 && a[r]*2 > themax; --r)
	{
		mm = mod(a[r] + a[r-1]);
		p = lower_bound(a, a+r, MOD-a[r]);
		if(p != a)
			mm = max(mm, p[-1] + a[r]);
		themax = max(themax, mm);
	}
	
	
	
	// output
	printf("%lli\n", themax);



	return 0;
}





// end
