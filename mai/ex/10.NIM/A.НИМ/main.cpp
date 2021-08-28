#include <iostream>


using namespace std;





// types
typedef long long llong;





// main
int main( int argc, char *argv[] )
{
	int n;
	llong a, inp;
	
	
	
	// solve
	scanf("%i", &n);

	a = 0;
	for(int i = 0; i < n; ++i)
	{
		scanf("%lli", &inp);
		a ^= inp;
	}
	
	
	
	// output
	printf("%i\n", a ? 1 : 2);



	return 0;
}





// end
