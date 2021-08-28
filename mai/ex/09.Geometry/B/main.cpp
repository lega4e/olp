#include <cmath>
#include <iostream>


using namespace std;





// types
typedef struct
{
	double x, y;
} Point, Vector;





// functions
inline double length(Vector v)
{
	return sqrt( v.x*v.x + v.y*v.y );
}


inline double cos(Vector a, Vector b)
{
	return 
		(double)(a.x*b.x + a.y*b.y) /
		( length(a) * length(b) );
}


inline Vector operator-(Point e, Point b)
{
	return { e.x - b.x, e.y - b.y };
}


inline double anglew(Vector a, Vector b)
{
	return acos(cos(a, b));
}





// main
int main( int argc, char *argv[] )
{
	int tests;
	
	
	
	// solve
	scanf("%i", &tests);

	Point p0, p1, p2;
	Vector a, b;
	double res;
	cout.precision(10);
	for(int test = 0; test < tests; ++test)
	{
		cin >>
			p0.x >> p0.y >>
			p1.x >> p1.y >>
			p2.x >> p2.y;

		a = p1-p0;
		b = p2-p0;
		res = anglew(a, b);

		cout << res << '\n';
	}



	return 0;
}





// end
