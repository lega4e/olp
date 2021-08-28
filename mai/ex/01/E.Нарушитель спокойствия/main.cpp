#include <cmath>
#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	int d, x, y;
	cin >> d >> x >> y;
	if( d >= hypot( (double)x, (double)y ) )
		cout << "YES" << endl;
	else
		cout << "NO" << endl;



	return 0;
}





// end
