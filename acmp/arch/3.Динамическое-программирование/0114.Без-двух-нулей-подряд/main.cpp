#include <cstdio>


using namespace std;





// types
typedef long long int llong;
struct Pair
{
	llong f, zero;
};





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

int k;




// functions
Pair calculate(int n)
{
	if(n == 1)
		return Pair{ k-1, 0 };
	auto prev = calculate(n-1);
	return Pair{
		(prev.f - prev.zero) +
		prev.f * ( k - 1 ),
		prev.f - prev.zero
	};
}





int main( int argc, char *argv[] )
{
	int n;
	Pair res;


	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i%i", &n, &k);
		fclose(file);
	}

	// calculate
	res = calculate(n);

	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		fprintf(file, "%lli", res.f);
		fflush(file);
		fclose(file);
	}

	return 0;
}





// end
