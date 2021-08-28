#include <cstring>
#include <iostream>

#define MOD(x) ( (x) % 1000000007 )


using namespace std;





// main
int main( int argc, char *argv[] )
{
	typedef long long llong;

	int n, k, m;
	llong *vals;
	
	
	
	// input, prepare
	scanf("%i%i%i", &n, &k, &m);
	vals = new llong[n+1];
	memset(vals, 0, sizeof(llong)*(n+1));

	for(int i = 0, input; i < m; ++i)
	{
		scanf("%i", &input);
		vals[input] = -1;
	}
	
	
	
	// solve
	vals[0] = 1;
	for(int i = 1; i < n+1; ++i)
	{
		if(vals[i] < 0)
		{
			vals[i] = 0;
			continue;
		}
		for(int j = max(0, i-k); j < i; ++j)
		{
			vals[i] += vals[j];
		}
		vals[i] = MOD(vals[i]);
	}
	
	
	
	// output
	printf("%lli\n", vals[n]);



	return 0;
}





// end
