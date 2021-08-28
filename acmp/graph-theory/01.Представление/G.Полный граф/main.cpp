#include <iostream>
#include <fstream>

#include <quix/Number.hpp>

#include "../AdjacMatrix.cpp"


using namespace std;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	AdjacMatrix adjm;

	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		adjm.scan_riblist1(file);
		fclose(file);
	}

	bool res = true;
	int val;
	for(int i = 0; i < adjm.n; ++i)
	{
		val = quix::summation(adjm[i], adjm[i+1]);
		if(val != adjm.n-1)
		{
			res = false;
			break;
		}
	}

	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		if(res)
			fprintf(file, "YES\n");
		else
			fprintf(file, "NO\n");
	}


	return 0;
}





// end
