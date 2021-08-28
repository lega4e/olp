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

void exgcd(llong a, llong b, llong &x, llong &y)
{
	if(a == 0)
	{
		x = 0;
		y = 1;
		return;
	}
	llong xx, yy;
	exgcd(b%a, a, xx, yy);
	x = yy - xx*(b/a);
	y = xx;
	return;
}





// main
int main( int argc, char *argv[] )
{
	llong m, n, res;
	
	
	
	// input
	scanf("%lli%lli", &m, &n);
	
	
	
	// solve
	{
		llong up = 1;
		for(llong i = 2; i < m+n+1; ++i)
			up = up * i % MOD;

		llong down = 1;
		for(llong i = 2; i < m+1; ++i)
			down = down * i % MOD;
		for(llong i = 2; i < n+1; ++i)
			down = down * i % MOD;

		llong null;
		exgcd(down, MOD, down, null);
		res = mod(up*down, MOD);
	}
	
	
	
	// output
	printf("%lli\n", res);



	return 0;
}





// end
