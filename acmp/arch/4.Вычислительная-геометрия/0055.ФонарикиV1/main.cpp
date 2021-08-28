#include <algorithm>
#include <cmath>
#include <cstdio>


using namespace std;






// structs
typedef long long int llong;
constexpr double const ALPHA = 0.000000001;
struct Point
{
	double x, y;

	inline double distance(Point const &p) const
	{
		return hypot(p.x-x, p.y-y);
	}
	inline double distance(double xx, double yy) const
	{
		return hypot(xx-x, yy-y);
	}
};

struct Circle
{
	double x, y, r;

	inline bool in(Point const &p) const
	{
		return r - p.distance(x, y) > -ALPHA;
	}
};

struct Rectangle
{
	double x, y, w, h;
};




// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





int main( int argc, char *argv[] )
{
	Circle first, second;
	Rectangle rect;
	double s;
	double res;


	// read input
	{
		auto infile = fopen(INPUT_FILE_NAME, "r");
		fscanf(
			infile, "%lf%lf%lf%lf%lf%lf",
			&first.x, &first.y,
			&second.x, &second.y,
			&first.r,
			&s
		);
		fclose(infile);
		second.r = first.r;
	}


	// calcaulte rectangle
	{
		double
			minx = min( first.x-first.r, second.x-second.r ),
			maxx = max( first.x+first.r, second.x+second.r ),
			miny = min( first.y-first.r, second.y-second.r ),
			maxy = max( first.y+first.r, second.y+second.r );

		rect.x = minx;
		rect.y = miny;
		rect.w = maxx-minx;
		rect.h = maxy-miny;
	}

	
	// calculate area
	{
		constexpr double const STEP = 0.09;
		Point p{ rect.x, rect.y };
		llong count = 0;
		for(; p.y < rect.y+rect.h; p.y += STEP)
		{
			for(; p.x < rect.x+rect.w; p.x += STEP)
			{
				if(
					p.distance(first.x, first.y) <= first.r ||
					p.distance(second.x, second.y) <= second.r
				)
					++count;
			}
			p.x = rect.x;
		}
		res = count*STEP*STEP;
	}


	// output
	{
		auto outfile = fopen(OUTPUT_FILE_NAME, "w");
		if(res > s)
		{
			fprintf(outfile, "YES");
		}
		else
		{
			fprintf(outfile, "NO");
		}
		fflush(outfile);
		fclose(outfile);
	}




	return 0;
}





// end
