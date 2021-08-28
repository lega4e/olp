#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	int m, n;
	
	
	
	// input, solve
	scanf("%i%i", &m, &n);

	int l, r;
	int res = 0;
	for(int i = 0; i < n; ++i)
	{
		scanf("%i%i", &l, &r);
		res ^= r-l-1;
	}
	
	
	
	// output
	printf("%i\n", res ? 1 : 2);



	return 0;
}





// end
