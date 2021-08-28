#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>


using namespace std;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





int main( int argc, char *argv[] )
{
	int n;
	double a;
	
	// read input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%d%lf", &n, &a);
		fclose(file);
	}

	// calculate
	double const beta = M_PI/(double)n;
	double const b = a / (2.0f * sin(beta));
	double const h = b * cos(beta);

	// output
	{
		printf("b: %g, h: %g\n", b, h);

		auto file = fopen(OUTPUT_FILE_NAME, "w");
		if(b-h < 1.0f)
			fprintf(file, "YES");
		else
			fprintf(file, "NO");
		fflush(file);
		fclose(file);
	}

	return 0;
}





// end
