#include <iostream>

#include "../AdjacList.cpp"
#include "../AdjacMatrix.cpp"
#include "../functions.cpp"


using namespace std;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	AdjacList adjl;
	AdjacMatrix adjm;
	FILE *file;

	file = fopen(INPUT_FILE_NAME, "r");
	adjl.scan1(file);
	fclose(file);

	conv(adjl, adjm);

	file = fopen(OUTPUT_FILE_NAME, "w");
	adjm.print(file);
	fclose(file);



	return 0;
}





// end
