#include <cstdio>


using namespace std;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	int n, m;
	

	
	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i%i", &n, &m);
		fclose(file);
	}
	
	
	
	// calculate & output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		while(m)
		{
			fprintf(file, "%i ", n/m);
			n -= n/m;
			--m;
		}
		fflush(file);
		fclose(file);
	}
	
	
	
	// end
	return 0;
}





// end
