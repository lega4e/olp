#include <cstdio>


using namespace std;





// types
typedef unsigned long long ullong;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// functions
inline ullong calculate(int n, int m, int l)
{
	return n - m - l*m + l + 1;
}





// main
int main( int argc, char *argv[] )
{
	int n, m;
	ullong result;
	
	
	
	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i%i", &n, &m);
		fclose(file);
	}
	
	
	
	// calculate
	if(m == 0)
	{
		result = 1;
	}
	else if(m == 1)
	{
		result = n;
	}
	else
	{
		result = 0;
		for(int l = 0; m+l*(m-1) <= n; ++l)
		{
			result += calculate(n, m, l);
		}
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
