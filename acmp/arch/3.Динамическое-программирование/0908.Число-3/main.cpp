#include <cstdio>


using namespace std;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	int n;
	int reslen;
	int *res;
	
	
	
	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i", &n);
		fclose(file);
		reslen = n+1;
		res = new int[reslen];
	}
	
	
	
	// calculate
		// preparation
	res[0] = res[1] = 0;
	int best;
	for(int i = 2; i < reslen; ++i)
	{
		best = res[i-1];
		if(i % 2 == 0 && res[i/2] < best)
			best = res[i/2];
		if(i % 3 == 0 && res[i/3] < best)
			best = res[i/3];
		res[i] = best+1;
	}
	
	
	
	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		fprintf(file, "%i", res[n]);
		fflush(file);
		fclose(file);
	}

	

	return 0;
}





// end
