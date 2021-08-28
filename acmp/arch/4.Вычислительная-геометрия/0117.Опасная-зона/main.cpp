#include <cstdio>

#include <clever/geometry.cpp>


using namespace std;





// structs
struct Polygon
{
	int n;
	Point *v;
};





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	int n;
	Point *points;
	Polygon pol;

	// read input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i", &n);
		points = new Point[n];
		for(int i = 0; i < n; ++i)
		{
			fscanf(
				file, "%lf%lf",
				&points[i].x, &points[i].y
			);
		}
		fclose(file);
	}

	// calculate
	{
		pol.v = new Point[n];
		pol.n = 0;

		pol.v[0] = *min_element(
			points, points+n,
			[](Point const &lhs, Point const &rhs)
				{ return lhs.y < rhs.y; }
		);



		printf("%g, %g\n", pol.v[0].x, pol.v[0].y);
		fflush(stdout);
	}

	return 0;
}





// end
