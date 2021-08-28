#include <cmath>
#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	double x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	double const
		a = hypot(x2-x1, y2-y1),
		b = hypot(x3-x2, y3-y2),
		c = hypot(x1-x3, y1-y3);
	double const p = (a+b+c)/2;

	printf(
		"%.9f\n",
		sqrt(p*(p-a)*(p-b)*(p-c))
	);



	return 0;
}





// end
