#include <iostream>


using namespace std;





int main( int argc, char *argv[] )
{
	int a, b, r;
	cin >> a >> b;

	if(!cin)
		return 1;

again:
	r = a % b;
	if(r == 0)
	{
		cout << b << endl;
		return 0;
	}
	a = b;
	b = r;

	goto again;
	

	return 0;
}





// end
