#include <iostream>
#include <map>

#define MOD 1000000007


using namespace std;





// types
typedef long long llong;





// functions
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

llong mod(llong a, llong b)
{
	return (b + a%b) % b;
}






// main
int main( int argc, char *argv[] )
{
	int n;
	map<llong, llong> evs;
	llong res;
	
	
	// input
	scanf("%i", &n);

	{
		llong l, r, v;
		for(int i = 0; i < n; ++i)
		{
			scanf("%lli%lli%lli", &l, &r, &v);

			evs[l] += v;
			evs[r+1] -= v;
		}
	}
	
	
	// solve
	{
		llong inv, nul;
		exgcd(2, MOD, inv, nul);

		auto it = evs.begin();
		llong cur = 0;
		llong l, r;
		llong toadd;
		res = 0;
		while(next(it) != evs.end())
		{
			cur = (cur + it->second) % MOD;
			l = it->first % MOD;
			r = (next(it)->first-1) % MOD;

			toadd = mod((l + r) % MOD * (r - l + 1) % MOD * inv, MOD) *
				abs(cur) % MOD * abs(cur) % MOD; 
			res = (res + toadd) % MOD;

			++it;
		}
	}
	
	
	// output
	printf("%lli\n", res);


	return 0;
}





// end
