#include <iostream>

#include "../AdjacMatrix.cpp"


using namespace std;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	AdjacMatrixI adjm;
	
	
	
	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		adjm.scan(file);
		fclose(file);
	}
	
	
	
	// calculate
	for(int k = 0; k < adjm.n; ++k)
	for(int i = 0; i < adjm.n; ++i)
	for(int j = 0; j < adjm.n; ++j)
		adjm[i][j] = min(adjm[i][j], adjm[i][k] + adjm[k][j]);
	
	
	
	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		for(int y = 0; y < adjm.n; ++y)
		{
			for(int x = 0; x < adjm.n; ++x)
				fprintf(file, "%i ", adjm[y][x]);
			fprintf(file, "\n");
		}
		fclose(file);
	}



	return 0;
}





// end
