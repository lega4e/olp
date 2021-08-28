#include <cmath>
#include <iostream>

#define PI 3.1415926535897932


using namespace std;





// main
int main( int argc, char *argv[] )
{
	int tests;
	
	
	
	// solve
	scanf("%i", &tests);

	int x, y;
	double res;
	cout.precision(10);
	for(int i = 0; i < tests; ++i)
	{
		cin >> x >> y;
		res = atan2((double)y, (double)x);
		if(res < 0)
			res = 2*PI + res;

		cout << res << '\n';
	}



	return 0;
}





// end
