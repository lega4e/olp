#include <iostream>

#include <quix/Number.hpp>

#include "../AdjacMatrix.cpp"


using namespace std;
using namespace quix;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	AdjacMatrix adjm;

	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		adjm.scann(file);
		fclose(file);
	}

	int val;
	auto file = fopen(OUTPUT_FILE_NAME, "w");
	for(int i = 0; i < adjm.n; ++i)
	{
		val = 0;
		summation(adjm[i], adjm[i+1], val);
		fprintf(file, "%i ", val);
	}
	fclose(file);



	return 0;
}





// end
