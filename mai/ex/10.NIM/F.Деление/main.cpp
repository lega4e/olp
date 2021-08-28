#include <iostream>
#include <vector>


using namespace std;





// types
typedef long long llong;





// main
int main( int argc, char *argv[] )
{
	llong n;

	
	
	// input
	scanf("%lli", &n);
	
	
	
	// solve
	int res = 0;
	int count;

	for(llong i = 2; i*i <= n; ++i)
	{
		count = 0;
		while(n != 1 && n % i == 0)
			n /= i,
			++count;

		res ^= count;
	}
	if(n != 1)
		res ^= 1;
	
	
	
	// output
	printf("%i\n", res ? 1 : 2);



	return 0;
}





// end
