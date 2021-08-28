#include <cstdio>


using namespace std;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





int main( int argc, char *argv[] )
{
	int n;
	unsigned long long int *arr;

	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i", &n);
		arr = new unsigned long long int[n+1];
		fclose(file);
	}
	

	// calculate
	arr[0] = 1;
	for(int i = 1; i < n+1; ++i)
	{
		arr[i] = 0;
		for(int j = 1; j < 4 && j <= i; ++j)
		{
			arr[i] += arr[i-j];
		}
	}


	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		fprintf(file, "%llu", arr[n]);
		fflush(file);
		fclose(file);
	}


	return 0;
}





// end
