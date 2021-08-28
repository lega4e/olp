#include <iostream>


using namespace std;





// types
typedef long long llong;





// main
int main( int argc, char *argv[] )
{
	int n;
	llong a, k;
	llong res;
	
	
	
	// solve
	scanf("%i", &n);

	res = 0;
	for(int i = 0; i < n; ++i)
	{
		scanf("%lli%lli", &a, &k);
		res ^= a % (k+1);
	}
	
	
	
	// output
	printf("%i\n", res ? 1 : 2);



	return 0;
}





// end
