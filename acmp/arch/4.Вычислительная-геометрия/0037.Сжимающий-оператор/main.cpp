#include <cmath>
#include <cstdio>


using namespace std;





// structs
struct Point
{
	double x, y;


	inline double distance(Point const &to)
	{
		return hypot(to.x-x, to.y-y);
	}
	inline double distance()
	{
		return hypot(x, y);
	}
};





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";
constexpr double const ALPHA = 0.00000000001;





int main( int argc, char *argv[] )
{
	int n;
	double q;
	Point first, second;

	// read preparation inform
	FILE *infile = fopen(INPUT_FILE_NAME, "r");
	fscanf(infile, "%i%lf", &n, &q);

	// calculate
	bool success = true;
	for(int i = 0; i < n; ++i)
	{
		fscanf(
			infile, "%lf%lf%lf%lf",
			&first.x, &first.y, &second.x, &second.y
		);

		if( !( second.distance() - first.distance() * q < ALPHA ) )
		{
			success = false;
			break;
		}
	}
	fclose(infile);

	// output
	FILE *outfile = fopen(OUTPUT_FILE_NAME, "w");
	if(success)
		fprintf(outfile, "Yes");
	else
		fprintf(outfile, "No");
	fflush(outfile);
	fclose(outfile);


	return 0;
}





// end
