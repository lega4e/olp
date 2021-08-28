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





// main
int main( int argc, char *argv[] )
{
	int tests;
	
	
	
	// solve
	scanf("%i", &tests);
	Point a, b;
	Straight s;
	for(int test = 0; test < tests; ++test)
	{
		scanf(
			"%Lf%Lf%Lf%Lf",
			&a.x, &a.y,
			&b.x, &b.y
		);
		s = tostraight(a, b);
		printf(
			"a = %Lf, b = %Lf, c = %Lf\n",
			s.a, s.b, s.c
		);
	}



	return 0;
}





// end
