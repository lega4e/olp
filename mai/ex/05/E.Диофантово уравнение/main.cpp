#include <iostream>


using namespace std;





// types
typedef long long llong;





// functions
llong exgcd(llong a, llong b, llong &x, llong &y)
{
	if(a == 0)
	{
		x = 0;
		y = 1;
		return b;
	}
	llong xx, yy;
	llong const g = exgcd(b%a, a, xx, yy);
	x = yy - b/a * xx;
	y = xx;
	return g;
}





// main
int main( int argc, char *argv[] )
{
	int t;
	cin >> t;
	
	
	
	// solve
	llong a, b, c, x, y, g;
	for(int i = 0; i < t; ++i)
	{
		scanf("%lli%lli%lli", &a, &b, &c);
		g = exgcd(a, b, x, y);
		if(c%g == 0)
			printf("%lli %lli %lli\n", g, x*(c/g), y*(c/g));
		else
			printf("-1\n");
	}
	



	return 0;
}





// end
