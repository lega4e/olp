#include <cmath>
#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
#define double long double

	// objects
	double x, y;
	double d;
	double v1, v2;
	
	
	
	// input
	cin >> x >> y >> v1 >> v2 >> d;
	
	
	
	// fun
	auto f = [=](double x0)->double
	{
		return 
			hypot(x0, d) / v1 +
			hypot(x-x0, y-d) / v2;
	};
	
	
	
	// solve
	double l = 0.0, r = x;
	double ll, rr;
	for(int i = 0; i < 10000; ++i)
	{
		ll = l + (r - l)/3.0;
		rr = r - (r - l)/3.0;
		if( f(ll) < f (rr) )
			r = rr;
		else
			l = ll;
	}

	double const res = (l + r) / 2.0;
	
	
	
	// output
	cout.precision(50);
	cout << res << endl;



	return 0;
}





// end
