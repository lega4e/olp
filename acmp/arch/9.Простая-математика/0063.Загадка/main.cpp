#include <cmath>
#include <iostream>
#include <fstream>


using namespace std;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	int a, b, x, y;
	
	// input
	ifstream(INPUT_FILE_NAME) >> x >> y;

	// calculate
	a = ( x + sqrt(x*x - 4*y) ) / 2;
	b = x - a;
	if(a > b)
		swap(a, b);

	// output
	ofstream(OUTPUT_FILE_NAME) << a << " " << b;

	return 0;
}





// end
