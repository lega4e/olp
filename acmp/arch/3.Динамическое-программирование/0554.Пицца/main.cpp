#include <cmath>
#include <cstdio>


using namespace std;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";






int main( int argc, char *argv[] )
{
	int n;
	int result;

	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i", &n);
		fclose(file);
	}


	result = 2 + (pow(n-1, 2) + 3*(n-1)) / 2;

	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		fprintf(file, "%i", result);
		fclose(file);
	}



	return 0;
}





// end
