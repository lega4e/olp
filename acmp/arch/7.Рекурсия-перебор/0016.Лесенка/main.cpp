#include <cstdio>


using namespace std;





// types
typedef unsigned long long int ullong;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// functions
ullong calculate(int min, int n)
{
	if(n == 0)
		return 1;

	ullong result = 0;
	for(int i = min; i <= n; ++i)
	{
		result += calculate(i+1, n-i);
	}
	return result;
}





// main
int main( int argc, char *argv[] )
{
	int n;
	ullong result;
	
	
	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i", &n);
		fclose(file);
	}
	
	
	
	// calculate
	{
		result = calculate(1, n);
	}
	
	
	
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
