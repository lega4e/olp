#include <algorithm>
#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	int n;
	int *sides;
	
	
	
	// input, sort
	scanf("%i", &n);
	sides = new int[n];
	for(auto *b = sides, *e = sides+n; b != e; ++b)
		scanf("%i", b);
	sort(sides, sides+n);
	
	
	
	// solve
	long long count = 0;
	int *ptr;
	for(int i = 0; i < n; ++i)
	{
		for(int j = i+1; j < n-1; ++j)
		{
			ptr = lower_bound(sides+j+1, sides+n, sides[i]+sides[j]);
			count += ptr - (sides+j+1);
		}
	}
	
	
	
	// output
	printf("%lli\n", count);



	return 0;
}





// end
