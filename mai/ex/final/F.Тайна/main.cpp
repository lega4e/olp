#include <cmath>
#include <iostream>


using namespace std;





// types
typedef long long llong;





// main
int main( int argc, char *argv[] )
{
	double ans;
	int res;



	// solve
	cout << "? -1000000 -1000000" << endl;
	cin >> ans;

	double a = (1000000 - 100000) * sqrt(2);
	double b = (1000000 + 100000) * sqrt(2);
	for(int i = 1; i < 1000+1; ++i)
	{
		if(
			i*a - ans < 100 &&
			ans - i*b < 100
		)
		{
			res = i;
			break;
		}
	}



	// output
	printf("! %i\n", res);



	return 0;
}





// end
