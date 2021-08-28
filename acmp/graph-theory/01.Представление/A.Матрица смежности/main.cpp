#include <iostream>

#include "AdjacMatrix.cpp"
#include "AdjacList.cpp"
#include "functions.cpp"


using namespace std;





// objects
char const *INPUT_FILE_NAME = "input.txt";
char const *OUTPUT_FILE_NAME = "output.txt";





// main
int main( int argc, char *argv[] )
{
	AdjacMatrix adjm;
	AdjacList adjl;
	FILE *file;

	file = fopen(INPUT_FILE_NAME, "r");
	adjm.scann(file);
	fclose(file);

	conv(adjm, adjl);
	file = fopen(OUTPUT_FILE_NAME, "w");
	adjl.print1(file);
	fclose(file);



	return 0;
}





// end
