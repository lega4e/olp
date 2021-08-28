#include <iostream>

#define MOD(x) ( (x) % 1000000007 )


using namespace std;





// objects
constexpr int const
	S = 1000,
	N = 100;





// main
int main( int argc, char *argv[] )
{
	typedef long long llong;

	llong vals[N+1][S+1] = { { 0 } };



	// fill
	for(int s = 0; s < 10; ++s)
		vals[1][s] = 1;

	for(int n = 2; n < N+1; ++n)
	for(int s = 1; s < S+1; ++s)
	{
		for(int i = s; i > max(0, s-10); --i)
			vals[n][s] += vals[n-1][i];
		vals[n][s] = MOD(vals[n][s]);
	}
	
	
	
	// process
	{
		int tests, n, s;
		llong res;
		scanf("%i", &tests);
		for(int i = 0; i < tests; ++i)
		{
			scanf("%i%i", &n, &s);

			res = 0;
			for(int i = 1; i < n+1; ++i)
				res += vals[i][s];
			res = MOD(res);

			printf("%lli\n", res);
		}
	}



	return 0;
}





// end
