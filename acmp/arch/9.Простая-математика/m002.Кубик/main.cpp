#include <cmath>
#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	int n;
	cin >> n;
	if(n > 1)
		cout <<
			"0/" << pow(n-2, 3) << " " <<
			"1/" << pow(n-2, 2)*6 << " " <<
			"2/" << (n-2) * 12 << " " <<
			"3/" << 8 << endl;
	else 
		cout <<
			"0/0" << " " <<
			"1/0" << " " <<
			"2/0" << " " <<
			"3/8" << endl;
	return 0;
}





// end
