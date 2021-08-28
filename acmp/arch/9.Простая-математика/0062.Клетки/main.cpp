#include <iostream>
#include <fstream>


using namespace std;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	int x, y;
	
	
	
	// input
	{
		ifstream fin(INPUT_FILE_NAME);
		x = fin.get() - 'A';
		y = fin.get() - '1';
	}
	
	
	
	// output
	{
		ofstream(OUTPUT_FILE_NAME) << (
			(x % 2 == 0) == (y % 2 == 0) ?
			"BLACK" : "WHITE"
		) << endl;
	}


	return 0;
}





// end
