#include <algorithm>
#include <cmath>
#include <iostream>


using namespace std;





// types
typedef long long llong;

typedef struct
{
	llong x, y;
} Point, Vector;





// functions
inline bool operator<(Vector const &lhs, Vector const &rhs)
{
	double
		l = (double)lhs.y / lhs.x,
		r = (double)rhs.y / rhs.x;

	return l > r;
}





// main
int main( int argc, char *argv[] )
{
	int n;
	Vector *vecs;
	
	
	// input
	scanf("%i", &n);
	vecs = new Vector[n];
	
	for(int i = 0; i < n; ++i)
		scanf("%lli%lli", &vecs[i].x, &vecs[i].y);
	
	
	
	// solve
	sort(vecs, vecs+n);

	llong cury = 0;
	llong sum = 0;
	for(auto *b = vecs, *e = vecs+n; b != e; ++b)
	{
		sum +=
			b->x * b->y +
			2 * b->x * cury;
		cury += b->y;
	}
	
	
	
	// output
	printf("%lli\n", sum);



	return 0;
}





// end
