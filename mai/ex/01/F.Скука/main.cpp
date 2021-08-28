#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	int start, lenth, tlenth, n;
	int h, m;



	// start
	cin >> h >> m;
	start = h*60 + m;

	// lenth
	cin >> h >> m;
	lenth = h*60 + m;

	// tlenth
	cin >> h >> m;
	tlenth = h*60 + m;

	// n
	cin >> n;
	
	
	
	// calc
	m = start + lenth*n + tlenth*(n-1);
	h = m/60;
	h %= 24;
	m %= 60;
	
	
	
	// output
	cout << h << ' ' << m << endl;




	return 0;
}





// end
