#include <iostream>


using namespace std;





// types
typedef long long llong;





// main
int main( int argc, char *argv[] )
{
	int tests;
	
	
	
	// solve
	scanf("%i", &tests);

	int n, k;
	for(int test = 0; test < tests; ++test)
	{
		scanf("%i%i", &n, &k);
		if( (k-1) % 2 || (n-k) % 2 )
			printf("Alice\n");
		else
			printf("Bob\n");
	}
	



	return 0;
}





// end
