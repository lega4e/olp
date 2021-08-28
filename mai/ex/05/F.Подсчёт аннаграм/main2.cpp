#include <iostream>
#include <map>

constexpr long long const MOD = 1000000007;
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
		res = mod(res * n, MOD),
		--n;
	return res;
}





// main
int main( int argc, char *argv[] )
{
	map<char, int> counts;
	
	
	
	// input
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	for(char ch = cin.get(); cin && islower(ch); ch = cin.get());


}





// end
