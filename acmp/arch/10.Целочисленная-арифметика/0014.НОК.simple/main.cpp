#include <cstdio>


using namespace std;





// types
typedef unsigned long long ullong;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// functions
ullong calculate_gcd(ullong a, ullong b)
{
	while(a != b)
	{
		if(a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}

inline ullong calculate_lcm(ullong a, ullong b)
{
	return a*b/calculate_gcd(a, b);
}





// main
int main( int argc, char *argv[] )
{
	ullong a, b, result;
	
	
	
	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%llu%llu", &a, &b);
		fclose(file);
	}
	
	
	
	// calculate
	result = calculate_lcm(a, b);
	
	
	
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
