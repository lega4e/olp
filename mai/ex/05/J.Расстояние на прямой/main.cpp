#include <algorithm>
#include <iostream>


using namespace std;





// types
typedef long long llong;





// main
int main( int argc, char *argv[] )
{
	int n;
	int *points;
	
	
	
	// input
	scanf("%i", &n);
	points = new int[n];
	for(auto *b = points, *e = points+n; b != e; ++b)
		scanf("%i", b);
	
	
	
	// solve
	sort(points, points+n);
	llong sum = 0;
	llong jsum = 0;
	for(int i = 0; i < n; ++i)
	{
		jsum += points[i];
		sum += (llong)points[i]*(i+1) - jsum;
	}
	
	
	
	// output
	printf("%lli\n", sum);



	return 0;
}





// end
