#include <cmath>
#include <iostream>
#include <fstream>


using namespace std;





struct Cyrcle
{
	double x, y, r;
};





char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





int main( int argc, char *argv[] )
{
	Cyrcle first, second;
	ifstream(INPUT_FILE_NAME) >>
		first.x >> first.y >> first.r >>
		second.x >> second.y >> second.r;

	double const d = hypot( second.x-first.x, second.y-first.y );

	if( d <= first.r + second.r && d >= fabs(second.r-first.r) )
	{
		ofstream(OUTPUT_FILE_NAME) << "YES" << flush;
	}
	else
	{
		ofstream(OUTPUT_FILE_NAME) << "NO" << flush;
	}

	return 0;
}





// end
