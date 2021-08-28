#include <cmath>
#include <iostream>


using namespace std;





// types
typedef struct
{
	double x, y;
} Point, Vector;







// funcitons
double square(Point const *vers, int n)
{
	double sum = 0.0;
	for(int i = 0; i < n; ++i)
	{
		sum +=
			( vers[i].y + vers[ (i+1)%n ].y ) / 2.0 *
			( vers[ (i+1)%n ].x - vers[i].x );
	}
	return fabs(sum);
}






// main
int main( int argc, char *argv[] )
{
	int n;
	Point *points;
	
	
	
	// input
	scanf("%i", &n);
	points = new Point[n];
	for(int i = 0; i < n; ++i)
		scanf("%lf%lf", &points[i].x, &points[i].y);
	
	
	
	// output
	double result = square(points, n);
	printf("%.9g\n", result);



	return 0;
}





// end
