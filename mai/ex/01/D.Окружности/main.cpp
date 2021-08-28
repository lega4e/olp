#include <cmath>
#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	double x1, y1, r1;
	double x2, y2, r2;

	cin >> x1 >> y1 >> r1;
	cin >> x2 >> y2 >> r2;

	double const dx = x2-x1, dy = y2-y1;


	if(
		dx*dx + dy*dy <= (r1+r2)*(r1+r2) &&
		dx*dx + dy*dy >= (r1-r2)*(r1-r2)
	)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;



	return 0;
}





// end
