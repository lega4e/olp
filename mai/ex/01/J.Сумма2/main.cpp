#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	long long a, b;
	cin >> a >> b;
	if(b < a)
		swap(a, b);
	cout << (a+b)*(b-a+1)/2 << endl;



	return 0;
}





// end
