#include <cmath>
#include <iostream>


using namespace std;





// types
typedef struct
{
	int x, y;
} Point;

typedef struct
{
	double dis;
	Point p;
} Stage;





// function
double distance(Point b, Point e)
{
	return sqrt( 
		(e.x-b.x)*(e.x-b.x) +
		(e.y-b.y)*(e.y-b.y)
	);
}





// main
int main( int argc, char *argv[] )
{
	int n;
	Stage fst, sst, tempst;
	Point b, e;
	
	
	// input
	scanf("%i", &n);

		// first case
	scanf(
		"%i%i%i%i",
		&b.x, &b.y, &e.x, &e.y
	);
	fst.dis = sst.dis = distance(b, e);
	fst.p = e;
	sst.p = b;

		// other cases
	for(int i = 1; i < n; ++i)
	{
		scanf(
			"%i%i%i%i",
			&b.x, &b.y, &e.x, &e.y
		);

		// first stage (end is e)
		if(
			sst.dis + distance(sst.p, b) <
			fst.dis + distance(fst.p, b)
		)
			tempst = { sst.dis + distance(sst.p, b) + distance(b, e), e };
		else
			tempst = { fst.dis + distance(fst.p, b) + distance(b, e), e };

		// second stage (end is b)
		if(
			sst.dis + distance(sst.p, e) <
			fst.dis + distance(fst.p, e)
		)
			sst = { sst.dis + distance(sst.p, e) + distance(e, b), b };
		else
			sst = { fst.dis + distance(fst.p, e) + distance(e, b), b };

		fst = tempst;
	}
	
	
	
	// output
	printf("%.7f\n", min(fst.dis, sst.dis));



	return 0;
}





// end
