#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	int n;
	int *vals;
	
	
	
	// input
	scanf("%i", &n);
	vals = new int[n];
	for(auto b = vals, e = vals+n; b != e; ++b)
		scanf("%i", b);
	
	
	
	// solve
	long long sum = 0;
	int amax;
	for(int i = 0; i < n; ++i)
	{
		amax = vals[i];
		for(int j = i; j < n; ++j)
		{
			if(vals[j] > amax)
				amax = vals[j];
			sum += amax;
		}
	}
	
	
	
	// output
	printf("%lli\n", sum);



	return 0;
}





// end
