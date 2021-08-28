#include <algorithm>
#include <iostream>
#include <vector>

#include <cmath>

#include "Fraction.hpp"
#include "geometry_straight.hpp"


using namespace std;
using namespace quix;





// types
typedef Fraction<long long> frac_type;
typedef Point<frac_type> point_type;
typedef Straight<frac_type> straight_type;





// main
int main( int argc, char *argv[] )
{
	int n, r;
	int result;
	
	
	
	// input
	scanf("%i%i", &n, &r);

	vector<straight_type> strais;
	strais.reserve(n);
	vector<point_type> points;
	points.reserve(n);

	point_type a, b;
	point_type p;
	straight_type s;
	result = 1;
	int toadd;
	for(int i = 0; i < n; ++i)
	{
		scanf( "%lli%lli%lli%lli", &a.x.a, &a.y.a, &b.x.a, &b.y.a );
		s = tostrai(a, b);
		reduce(&s.a.a, &s.b.a, &s.c.a);
		if(i == 2)
			return 0;


		// пересекает ли окружность
		if(
			s.a*s.a*s.c*s.c - (s.b*s.b + s.a*s.a)*(s.c*s.c - s.b*s.b*r*r) < ALPHA &&
			!( fabs(s.b) < ALPHA && s.c*s.c < r*r )
		)
		{
			cout << a << ", " << b << endl;
			cout << s.a << ", " << s.b << ", " << s.c << endl;
			printf("continue because D < 0\n\n");
			goto next_hit;
		}
		toadd = 1;



		// пересекает ли другую прямую
		points.clear();
		for(auto b = strais.begin(), e = strais.end(); b != e; ++b)
		{
			p = cross(s, *b);
			if(p.x != p.x)
				continue;

			if( scalar(p, p) >= r*r )
				continue;

			if( find(points.begin(), points.end(), p) != points.end() )
				continue;

			points.push_back(p);
			++toadd;
		}

		strais.push_back(s);
		result += toadd;

	next_hit:
		printf("%i\n", result);
		// printf("result: %i\n\n", result);
		;
	}



	return 0;
}





// end
