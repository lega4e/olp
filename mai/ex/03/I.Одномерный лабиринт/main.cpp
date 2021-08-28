#include <algorithm>
#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	int n, q;
	int *darr;

	scanf("%i", &n);
	darr = new int[n];
	for(auto *b = darr, *e = darr+n; b != e; ++b)
		scanf("%i", b);

	sort(darr, darr+n);

	scanf("%i", &q);
	int a, b;
	for(int i = 0; i < q; ++i)
	{
		scanf("%i%i", &a, &b);
		if(b < a)
			swap(a, b);
		printf(
			"%li\n",
			lower_bound(darr, darr+n, b) -
			lower_bound(darr, darr+n, a)
		);
	}




	return 0;
}





// end
