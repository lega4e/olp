#include <cmath>
#include <iostream>
#include <fstream>


using namespace std;





// structs
constexpr double const ALPHA = 0.0000000001f;
typedef struct Point
{
	double x, y;

	Point operator-(Point const &p) const
	{
		return Point{ x-p.x, y-p.y };
	}

	double operator*(Point const &p) const
	{
		return x*p.x + y*p.y;
	}


	inline double length() const
	{
		return hypot(x, y);
	}

	double distance(Point const &p) const
	{
		return hypot( p.x-x, p.y-y );
	}

	double angle(Point const &p) const
	{
		double const len1 = length(), len2 = p.length();
		if( fabs(len1) < ALPHA || fabs(len2) < ALPHA )
			return 0.0f;
		return asin(
			(x*p.y - p.x*y) /
			( length() * p.length() )
		);
	}


} Vector;

struct Rectangle
{
	Point a, b, c, d;
};




// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";






// functions
int define_position( 
	Point const &beg, 
	Point const &end,
	Point const &p
)
{
	double const angle = 
		(end - beg).angle(p - beg);

	return fabs(angle) < ALPHA ?
		0 :
		( angle < ALPHA ? 1 : -1 );
}



bool in( Rectangle const &rect, Point const &p )
{
	int
		first = define_position(rect.a, rect.b, p),
		second = define_position(rect.d, rect.c, p),
		third = define_position(rect.d, rect.a, p),
		fourth = define_position(rect.c, rect.b, p);
	return ( first != second || first == 0 ) &&
		( third != fourth || third == 0 );
}




int main( int argc, char *argv[] )
{
	Rectangle *rects;
	Point *points;
	int n = 0;
	{
		ifstream fin(INPUT_FILE_NAME);
		fin >> n;
		rects = new Rectangle[n];
		points = new Point[n];
		for(int i = 0; i < n; ++i)
		{
			fin >>
				points[i].x >> points[i].y >>
				rects[i].a.x >> rects[i].a.y >>
				rects[i].b.x >> rects[i].b.y >>
				rects[i].c.x >> rects[i].c.y >>
				rects[i].d.x >> rects[i].d.y;
		}
	}

	int counter = 0;
	for(int i = 0; i < n; ++i)
	{
		if( in( rects[i], points[i] ) )
			++counter;
	}

	ofstream(OUTPUT_FILE_NAME) << counter;

	delete[] rects;
	delete[] points;

	return 0;
}





// end
