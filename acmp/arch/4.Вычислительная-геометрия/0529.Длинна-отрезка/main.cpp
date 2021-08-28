#include <cmath>
#include <iomanip>
#include <iostream>
#include <fstream>


using namespace std;





char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";







int main( int argc, char *argv[] )
{
	int x1, y1, x2, y2;
	// input
	ifstream(INPUT_FILE_NAME) >> x1 >> y1 >> x2 >> y2;

	// output
	ofstream(OUTPUT_FILE_NAME) << 
		fixed << setprecision(6) <<
		hypot(x2-x1, y2-y1) << flush;

	return 0;
}





// end
