#include <cmath>
#include <iostream>


using namespace std;





// types
typedef long double ldouble;

typedef struct
{
	ldouble x, y;
} Point, Vector;





// objects
constexpr ldouble const ALPHA = 0.00001L;





// functions
inline Vector operator-(Point e, Point b)
{
	return { e.x - b.x, e.y - b.y };
}

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
	ldouble res;
	for(int test = 0; test < tests; ++test)
	{
		scanf(
			"%Lf%Lf%Lf%Lf%Lf%Lf",
			&a.x, &a.y,
			&p.x, &p.y,
			&q.x, &q.y
		);

		res = distance_to_segment(a, p, q);

		printf("%.9Lg\n", res);
	}



	return 0;
}





// end
