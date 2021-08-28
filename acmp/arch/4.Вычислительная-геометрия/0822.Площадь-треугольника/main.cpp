#include <cmath>
#include <iomanip>
#include <iostream>
#include <fstream>


using namespace std;





char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





int main( int argc, char *argv[] )
{
	double x1, y1, x2, y2, x3, y3;
	ifstream(INPUT_FILE_NAME) >> 
		x1 >> y1 >>
		x2 >> y2 >>
		x3 >> y3;

	double
		len1 = hypot( x2-x1, y2-y1 ),
		len2 = hypot( x3-x2, y3-y2 ),
		len3 = hypot( x1-x3, y1-y3 );

	// heron
	double p = ( len1 + len2 + len3 ) / 2.0f;
	double s = sqrt( p * ( p-len1 ) * ( p-len2 ) * ( p-len3 ) );

	

	ofstream( OUTPUT_FILE_NAME ) <<
		fixed << setprecision(1) << s;

	return 0;
}





// end
