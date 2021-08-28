#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	int a, b, x, y;
	cin >> a >> b >> x >> y;
	// cout << min(
		// (w/wp + (w%wp ? 1 : 0)) * (h/hp + (h%hp ? 1 : 0)),
		// (w/hp + (w%hp ? 1 : 0)) * (h/wp + (h%wp ? 1 : 0))
	// ) << endl;

	cout <<
		( a/x + (a%x ? 1 : 0) )*
		( b/y + (b%y ? 1 : 0) )
	<< endl;



	return 0;
}





// end
