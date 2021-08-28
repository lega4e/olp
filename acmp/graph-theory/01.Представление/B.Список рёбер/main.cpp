#include <iostream>

#include "../AdjacList.cpp"


using namespace std;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	AdjacList adjl;
	FILE *file;

	file = fopen(INPUT_FILE_NAME, "r");
	adjl.scan_riblist1(file, true);
	fclose(file);
	adjl.sort();

	file = fopen(OUTPUT_FILE_NAME, "w");
	adjl.print1(file);
	fclose(file);



	return 0;
}





// end
