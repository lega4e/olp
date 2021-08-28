#include <cmath>
#include <iostream>


using namespace std;





// types
typedef long long llong;





// main
int main( int argc, char *argv[] )
{
	int n;
	
	
	
	// solve
	scanf("%i", &n);
	llong inp;
	llong val;
	for(int i = 0; i < n; ++i)
	{
		scanf("%lli", &inp);
		val = round( pow(abs(inp), 1.0L/3.0L) );
		if(val*val*val == abs(inp))
			printf("%lli\n", inp < 0 ? -val : val);
		else
			printf("NO\n");
	}




	return 0;
}





// end
