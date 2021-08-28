#include <iostream>
#include <fstream>


using namespace std;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	int n;
	ifstream(INPUT_FILE_NAME) >> n;
	ofstream(OUTPUT_FILE_NAME) << n*n - 3*n + 2;
	return 0;
}





// end
