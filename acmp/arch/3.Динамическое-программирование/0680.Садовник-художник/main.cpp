#include <cmath>
#include <cstdio>


using namespace std;





// types
typedef unsigned long long ullong;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	ullong n;
	


	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%llu", &n);
		fclose(file);
	}
	
	
	
	// calculate
	ullong result = 3*pow(2, n-1);
	
	
	
	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		fprintf(file, "%llu", result);
		fflush(file);
		fclose(file);
	}
	

	return 0;
}





// end
