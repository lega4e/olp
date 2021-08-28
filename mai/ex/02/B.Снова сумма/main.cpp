#include <cmath>
#include <iostream>
#include <string>


using namespace std;





// types
typedef long long llong;






// main
int main( int argc, char *argv[] )
{
	llong a, b;
	llong asum = 0, bsum = 0;

	while( cin >> a && cin.get() == '.' && cin >> b )
	{
		asum += a;
		bsum += b;
	}

	asum += bsum / 1000000000000000ll;
	bsum %= 1000000000000000ll;

	string fill;
	fill.resize(
		15 - ( bsum == 0 ? 1 : (int)log10(abs(bsum)) + 1),
		'0'
	);

	cout << asum << '.' << fill << bsum << endl;



	return 0;
}





// end
