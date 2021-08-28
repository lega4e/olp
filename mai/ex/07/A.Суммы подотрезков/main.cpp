#include <iostream>


using namespace std;





// types
typedef long long llong;





// main
int main( int argc, char *argv[] )
{
	int n;
	llong *a, *sums;



	// input
	scanf("%i", &n);

	a = new llong[n];
	sums = new llong[n+1];
	sums[0] = 0;

	for(auto b = a, e = a+n; b != e; ++b)
		scanf("%lli", b);

	for(int i = 1; i < n+1; ++i)
		sums[i] = sums[i-1] + a[i-1];



	// solve
	int tests;
	int l, r;
	llong sum;
	scanf("%i", &tests);
	for(int test = 0; test < tests; ++test)
	{
		scanf("%i%i", &l, &r);

		/*
		 * второй метод, используя
		 * вектор сумм
		 */
		sum = sums[r] - sums[l-1];
		printf("%lli\n", sum);
	}


	return 0;
}





// end
