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
	int s, t;
	
	
	
	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i%i%i", &adjm.n, &s, &t);
		--s, --t;
		adjm.init().scannon(file);
		fclose(file);
	}
	
	
	
	// calculate
	for(int k = 0; k < adjm.n; ++k)
	for(int i = 0; i < adjm.n; ++i)
	for(int j = 0; j < adjm.n; ++j)
	{
		if(adjm[i][k] < 0 || adjm[k][j] < 0)
			continue;
		if(adjm[i][j] < 0 || adjm[i][k] + adjm[k][j] < adjm[i][j])
			adjm[i][j] = adjm[i][k] + adjm[k][j];
	}
	
	
	
	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		fprintf(file, "%i\n", adjm[s][t]);
		fclose(file);
	}



	return 0;
}





// end
