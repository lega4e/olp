#include <iostream>
#include <set>


using namespace std;





// types
typedef long long llong;

struct Point
{
	llong x, y;

	inline llong operator*(Point lhs) const
	{
		return x*lhs.x + y*lhs.y;
	}

	inline Point normal() const
	{
		return Point{-y, x};
	}

	inline Point operator+(Point lhs) const
	{
		return {x+lhs.x, y+lhs.y};
	}

	inline Point operator-(Point lhs) const
	{
		return { x-lhs.x, y-lhs.y };
	}

	inline Point &operator+=(Point lhs)
	{
		x += lhs.x;
		y += lhs.y;
		return *this;
	}

	inline bool operator<(Point lhs) const
	{
		return x != lhs.x ? x < lhs.x : y < lhs.y;
	}
};





// main
int main( int argc, char *argv[] )
{
	set<Point> points;
	int n;
	Point p, q, norm;
	
	
	
	// input
	scanf("%i", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%lli%lli", &p.x, &p.y);
		points.insert(p);
	}
	
	
	
	// solve
	llong result = 0;
	for(auto b = points.begin(), e = points.end(); b != e; ++b)
	{
		p = *b;
		for(auto bb = next(b); bb != e; ++bb)
		{
			q = *bb;
			norm = (q-p).normal();
			if(
				( points.count( p + norm ) &&
				points.count( q + norm ) ) ||
				( points.count( p - norm ) &&
				points.count( q - norm ) )
			)
			{
				result = max(result, norm.x*norm.x + norm.y*norm.y);
			}
		}
	}
	
	
	
	// output
	printf("%lli\n", result);
	



	return 0;
}





// end
