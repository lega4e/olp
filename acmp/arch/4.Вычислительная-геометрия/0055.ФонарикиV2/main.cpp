#include <algorithm>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>

#include <clever/geometry.cpp>

using namespace std;






/*
 * // structs
 * struct Point
 * {
 *         double x, y;
 * };
 * 
 * 
 * struct Circle
 * {
 *         Point c;
 *         double r;
 * };
 */





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// functions
/*
 * inline double distance(Point const &lhs, Point const &rhs)
 * {
 *         return hypot( rhs.x - lhs.x, rhs.y - lhs.y );
 * }
 */
/*
 * double define_intersects_area(Circle const &f, Circle const &s)
 * {
 *         double const a = distance(f.c, s.c);
 *         if( a >= f.r+s.r )
 *                 return 0.0f;
 *         if(
 *                 f.r+a <= s.r ||
 *                 s.r+a <= f.r
 *         )
 *                 return M_PI * pow( min(f.r, s.r), 2 );
 * 
 *         double const alpha = 
 *                 2 * acos(
 *                         ( pow(f.r, 2) + pow(a, 2) - pow(s.r, 2) ) /
 *                         ( 2 * f.r * a )
 *                 );
 *         double const beta =
 *                 2 * acos(
 *                         ( pow(s.r, 2) + pow(a, 2) - pow(f.r, 2) ) /
 *                         ( 2 * s.r * a )
 *                 );
 *         return 
 *                 pow(f.r, 2)/2*(alpha - sin(alpha)) +
 *                 pow(s.r, 2)/2*(beta - sin(beta));
 * }
 */





int main( int argc, char *argv[] )
{
	Circle f, s;
	double far;

	// read input
	{
		auto infile = fopen(INPUT_FILE_NAME, "r");
		fscanf(
			infile, "%lf%lf%lf%lf%lf%lf",
			&f.c.x, &f.c.y,
			&s.c.x, &s.c.y, &f.r,
			&far
		);
		s.r = f.r;
		fclose(infile);
	}

	// calculate area
	double const area = 
		M_PI*( pow(f.r, 2) + pow(s.r, 2) ) -
		define_intersects_area(f, s);

	// output
	{
		auto outfile = fopen(OUTPUT_FILE_NAME, "w");
		if(area > far)
			fprintf(outfile, "YES");
		else
			fprintf(outfile, "NO");
		fflush(outfile);
		fclose(outfile);
	}

	return 0;
}





// end
