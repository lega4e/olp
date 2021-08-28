#include <cstdio>
#include <map>


using namespace std;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

map< pair<int, int>, int > ex;





// functions
int calculate(int n, int k)
{
	printf("n: %i, k: %i\n", n, k);
	if(n == k)
		return 1;
	if(n > k)
		return 0;

	auto const key = make_pair(n, k);
	auto const it = ex.find(key);
	if(it != ex.end())
		return it->second;

	int const result =
		calculate(n+1, k-1) +
		( n > 1 ? calculate(n-1, k-1) : 0 );
	ex[key] = result;
	return result;
}




int main( int argc, char *argv[] )
{
	int n, k;

	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i%i", &n, &k);
		fclose(file);
	}

	// calculate
	int const result =
		(n-k) % 2 == 1 ? 0 : calculate(n, k);

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
