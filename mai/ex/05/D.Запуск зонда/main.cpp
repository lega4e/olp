#include <iostream>


using namespace std;





// types
typedef unsigned long long llong;





// functions
llong gcd(llong a, llong b)
{
	while(a)
	{
		b %= a;
		swap(a, b);
	}
	return b;
}

llong lcm(llong a, llong b)
{
	return a/gcd(a, b)*b;
}





// main
int main( int argc, char *argv[] )
{
	llong n;
	llong *arr;
	
	
	
	// input
	cin >> n;
	arr = new llong[n];
	for(auto *b = arr, *e = arr+n; b != e; ++b)
		cin >> *b;
	
	
	
	// solve
	llong res = 1;
	for(auto *b = arr, *e = arr+n; b != e; ++b)
		res = lcm(res, *b);
	
	
	
	// output
	cout << res << endl;




	return 0;
}





// end
