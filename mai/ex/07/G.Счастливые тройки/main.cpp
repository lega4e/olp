#include <algorithm>
#include <iostream>


using namespace std;





// types
typedef long long llong;





// functions
llong cmn(llong m, llong n)
{
	m = max(m, n-m);

	llong res = 1;
	llong kk = 2;
	for(llong k = m+1; k < n+1; ++k)
	{
		res *= k;
		while( kk < n-m+1 && res % kk == 0 )
			res /= kk,
			++kk;
	}
	return res;
}





// main
int main( int argc, char *argv[] )
{
	int n;
	int k;
	int *a;
	
	
	
	// input
	scanf("%i%i", &n, &k);
	a = new int[n];
	for(auto b = a, e = a+n; b != e; ++b)
		scanf("%i", b);
	sort(a, a+n);
	
	
	
	// solve
	long long res = 0;
	int *l = a, *r = a+2;
	int *oldr = a;

	while(r < a+n)
	{
		while(r < a+n && *r - *l > k)
		{
			if(r - l == 2)
				++r;
			else
				++l;
		}

		if(r == a+n)
			break;

		while(r+1 < a+n && r[1] - *l <= k)
			++r;


		res += cmn(3, r-l+1);
		if(oldr - l >= 2)
			res -= cmn(3, oldr-l+1);

		oldr = r;
		++r;
	}
	
	
	
	// output
	printf("%lli\n", res);



	return 0;
}





// end
