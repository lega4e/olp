#include <cmath>
#include <iostream>


using namespace std;





// functions
inline ldouble distance(Point a, Point b)
{
	return hypot( b.x - a.x, b.y - a.y );
}

inline ldouble scalar(Vector a, Vector b)
{
	return a.x*b.x + a.y*b.y;
}

inline ldouble skew(Vector a, Vector b)
{
	return a.x*b.y - a.y*b.x;
}

inline ldouble distance_to_straight(Point p, Point a, Point b)
{
	return fabs(skew(b-a, p-a)) / distance(a, b);
}

ldouble distance_to_segment(Point p, Point a, Point b)
{
	return
		scalar(b-a, p-a) < -ALPHA ? distance(a, p) :
		scalar(a-b, p-b) < -ALPHA ? distance(b, p) :
		distance_to_straight(p, a, b);
}





// main
int main( int argc, char *argv[] )
{
	int tests;



	// solve
	scanf("%i", &tests);
	Point a, p, q;
	double res;
	for(int test = 0; test < tests; ++test)
	{
		scanf(
			"%lf%lf%lf%lf%lf%lf",
			&a.x, &a.y,
			&p.x, &p.y,
			&q.x, &q.y
		);

		res = distance_to_segment(p, q, a);

		printf("%.9lg\n", res);
	}



	return 0;
}





// end
