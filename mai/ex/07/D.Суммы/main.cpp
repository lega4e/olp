#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	int n;

	
	
	// solve
	scanf("%i", &n);
	long long sum = 0;
	int inp;
	for(int i = 0; i < n; ++i)
	{
		scanf("%i", &inp);
		sum += inp * ( (long long)(i+1) * (n-i) );
	}
	
	
	
	// output
	printf("%lli\n", sum);



	return 0;
}





// end
