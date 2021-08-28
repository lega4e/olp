#include <algorithm>
#include <iostream>

#define MOD 1000000007
#define MOD(x) mod(x, MOD)


using namespace std;





// types
typedef long long llong;





// functions
inline llong mod(llong a, llong b)
{
	return (b + a%b) % b;
}

llong exgcd(llong a, llong b, llong &x, llong &y)
{
	if(a == 0)
	{
		x = 0, y = 1;
		return b;
	}
	llong xx, yy, g;
	g = exgcd(b%a, a, xx, yy);
	x = yy - xx*(b/a);
	y = xx;
	return g;
}

llong factorial(llong n)
{
	llong res = 1;
	while(n > 1)
	{
		res = res * n % MOD;
		--n;
	}
	return res;
}





// main
int main( int argc, char *argv[] )
{
	llong chs[26] = { 0 };
	llong total = 0;
	
	
	
	// input
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	for(char ch = cin.get(); cin && islower(ch); ch = cin.get())
		++chs[ch-'a'], ++total;
	
	
	
	// solve
	llong result;
	{
		result = factorial(total);

		llong den = 1;
		for(int i = 0; i < 26; ++i)
			den = den * factorial(chs[i]) % MOD;

		llong invel, null;
		exgcd(den, MOD, invel, null);
		result = MOD(result * invel);
	}
	
	
	
	// output
	printf("%lli\n", result);



	return 0;
}





// end
