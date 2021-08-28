#include <cmath>
#include <fstream>


using namespace std;





// structs
struct Point
{
	int x, y;
};





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

Point f, s;





// functions
int test()
{
	if( ( (s.x-f.x) + (s.y-f.y) ) % 2 )
		return 0;
	return abs(s.x-f.x) == abs(s.y-f.y) ? 1 : 2;
}





// main
int main( int argc, char *argv[] )
{
	ifstream(INPUT_FILE_NAME) >>
		f.x >> f.y >> s.x >> s.y;
	ofstream(OUTPUT_FILE_NAME) << test();

	return 0;
}





// end
