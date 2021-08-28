#include <cmath>
#include <cstdio>


using namespace std;





// structs
typedef struct Point
{
	double x;
	double y;
} Vector;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	double result = 0.0f;
	int n;
	Point begin, first, second;

	FILE *infile = fopen(INPUT_FILE_NAME, "r");
	fscanf(infile, "%d", &n);
	

	// read first
	float fbuf, sbuf;
	fscanf(infile, "%g%g", &fbuf, &sbuf);
	begin.x = fbuf;
	begin.y = sbuf;
	second = begin;


	// other
	for(int i = 1; i < n; ++i)
	{
		first = second;
		fscanf(infile, "%f%f", &fbuf, &sbuf);
		second.x = fbuf; second.y = sbuf;
		result += ( first.y + second.y ) *
			( second.x - first.x );
	}
	fclose(infile);

	// last
	result += ( second.y + begin.y ) *
		( begin.x - second.x );


	// end
	result /= 2;
	result = fabs(result);


	// output
	FILE *outfile = fopen(OUTPUT_FILE_NAME, "w");
	fprintf(outfile, "%.1f", result);
	fclose(outfile);

	return 0;
}





// end
