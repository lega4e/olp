#include <iostream>
#include <map>
#include <stack>

#define MOD 1000000007


using namespace std;





// types
typedef long long llong;





// functions
llong get(map<llong, llong> &mp, llong val)
{
	auto it = mp.find(val);
	if(it != mp.end())
		return it->second;

	llong res = 1;
	for(llong i = 2; i*i <= val; ++i)
	{
		if(i*i == val)
			res += get(mp, i);
		else if(val % i == 0)
			res += get(mp, i) + get(mp, val/i);
	}
	res %= MOD;
	
	mp[val] = res;
	return res;
}





// main
int main( int argc, char *argv[] )
{
	llong n;
	map<llong, llong> mp;

	
	
	// input
	scanf("%lli", &n);
	
	
	
	// solve
	llong res = get(mp, n);
	
	
	
	// output
	printf("%lli\n\n", res);



	return 0;
}





// end
