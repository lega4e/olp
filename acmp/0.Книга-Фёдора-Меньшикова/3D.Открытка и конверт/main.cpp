#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <fstream>


using namespace std;





char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

constexpr double const ALPHA = 0.000001;





// main
int main( int argc, char *argv[] )
{
	// read input
	double w1, h1, w2, h2;
	ifstream(INPUT_FILE_NAME) >>
		w2 >> h2 >> w1 >> h1;

	// correct
	if(w1 < h1)
		swap(w1, h1);
	if(w2 < h2)
		swap(w2, h2);


	// pre test
	if(w2 <= w1 && h2 <= h1)
	{
		ofstream(OUTPUT_FILE_NAME) << "Possible" << flush;
		return 0;
	}
	if(h2 > h1)
	{
		ofstream(OUTPUT_FILE_NAME) << "Impossible" << flush;
		return 0;
	}


	// calculate
	double const alpha =
		M_PI/2.0f - 
		acos( h1 / hypot(h2, w2) ) -
		atan( h2 / w2 );

	double const a = cos(alpha) * w2;
	double const b = sin(alpha) * h2;
	if( a + b - w1 < ALPHA )
		ofstream(OUTPUT_FILE_NAME) << "Possible" << flush;
	else
		ofstream(OUTPUT_FILE_NAME) << "Impossible" << flush;


	return 0;
}





// end
