#include <cmath>
#include <iostream>


using namespace std;





// types
typedef long double ldouble;

typedef struct
{
	ldouble x, y;
} Point, Vector;

typedef struct
{
	ldouble a, b, c;
} Straight;





// objects
constexpr ldouble const ALPHA = 0.000001;





// functions
inline ldouble distance(Point a, Point b)
{
	return sqrt(
		(b.x - a.x) * (b.x - a.x) +
		(b.y - a.y) * (b.y - a.y)
	);
}


Straight tostraight(Point p, Point pp)
{
	Straight s;
	if( fabs(p.y - pp.y) < ALPHA )
	{
		s.b = 1.0;
		s.a = 0.0;
	}
	else
	{
		s.a = 1.0;
		s.b = (ldouble)(p.x - pp.x) / (pp.y - p.y);
	}
	s.c = s.a*p.x + s.b*p.y;
	return s;
}


inline Point cross(Straight s, Straight ss)
{
	if( fabs(s.a*ss.b - ss.a*s.b) < ALPHA )
		return { NAN, NAN };
	return {
		-(ldouble)( s.b*ss.c - ss.b*s.c ) /
			(s.a*ss.b - ss.a*s.b),
		(ldouble)( s.a*ss.c - ss.a*s.c ) /
			(s.a*ss.b - ss.a*s.b)
	};
}


inline Straight perpend(Straight s, Point p)
{
	return 
		fabs(s.a) < ALPHA ? Straight{ 1.0, 0.0, p.x } :
		fabs(s.b) < ALPHA ? Straight{ 0.0, 1.0, p.y } :
		Straight{
			1.0, -(ldouble)s.a/s.b, 
			p.x - (ldouble)s.a/s.b*p.y
		};
}

ldouble distance_to_straight(Point p, Straight s)
{
	Straight perp = perpend(s, p);
	Point const crp = cross(s, perp);
	return distance(p, crp);
}





// main
int main( int argc, char *argv[] )
{
	int tests;
	
	
	
	// solve
	scanf("%i", &tests);
	Point p, a, b;
	for(int test = 0; test < tests; ++test)
	{
		scanf(
			"%Lf%Lf%Lf%Lf%Lf%Lf",
			&p.x, &p.y,
			&a.x, &a.y,
			&b.x, &b.y
		);
		printf(
			"%.10Lg\n",
			distance_to_straight(p, tostraight(a, b))
		);
	}



	return 0;
}





// end
