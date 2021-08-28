#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	typedef long long llong;



	int n;
	
	
	
	// input
	scanf("%i", &n);
	vector<vector<llong>> vals(
		n+1, vector<llong>(n+1, 0)
	);
	for(int y = 1; y < n+1; ++y)
	{
		for(int x = 1; x <= y; ++x)
			scanf("%lli", &vals[y][x]);
	}
	
	
	
	// solve
	for(int y = 1; y < n+1; ++y)
	{
		for(int x = 1; x <= y; ++x)
		{
			vals[y][x] += max(
				vals[y-1][x],
				vals[y-1][x-1]
			);
		}
	}

	llong res = *max_element( vals[n].begin(), vals[n].end() );
	
	
	
	// output
	printf("%lli\n", res);
	


	return 0;
}





// end
