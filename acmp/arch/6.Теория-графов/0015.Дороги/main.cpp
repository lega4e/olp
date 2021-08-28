#include <algorithm>
#include <cstdio>


using namespace std;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	int n;
	int result;


	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i", &n);
		result = 0;
		int buf;
		for(int i = 0; i < n*n; ++i)
		{
			fscanf(file, "%i", &buf);
			result += buf;
		}
		fclose(file);
		result /= 2;
	}
	
	
	
	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		fprintf(file, "%i", result);
		fflush(file);
		fclose(file);
	}



	return 0;
}





// end
