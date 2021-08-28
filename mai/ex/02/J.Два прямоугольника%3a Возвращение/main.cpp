#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	typedef struct { int x, y; } Point;

	Point a, b, m, n;


	// input
	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	cin >> m.x >> m.y;
	cin >> n.x >> n.y;


	// normalize
	if(a.x > b.x)
		swap(a.x, b.x);
	if(a.y > b.y)
		swap(a.y, b.y);
	if(m.x > n.x)
		swap(m.x, n.x);
	if(m.y > n.y)
		swap(m.y, n.y);


	// solve
	int const xinter =
		min(b.x, n.x) - max(a.x, m.x);
	int const yinter =
		min(b.y, n.y) - max(a.y, m.y);
	int const inter = 
		xinter < 0 || yinter < 0 ? 0 : xinter*yinter;
	int const un =
		(b.x - a.x)*(b.y - a.y) + 
		(n.x - m.x)*(n.y - m.y) -
		inter;


	// output
	cout << un << endl;


	return 0;
}





// end
