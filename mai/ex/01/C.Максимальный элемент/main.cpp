#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	long long a, b, c;
	cin >> a >> b >> c;
	cout <<
		(a > b ? 
			(a > c ? a : c) :
			b > c ? b : c
	) << endl;



	return 0;
}





// end
