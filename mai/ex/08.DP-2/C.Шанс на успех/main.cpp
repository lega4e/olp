#include <iostream>
#include <vector>


using namespace std;





// types
typedef long long llong;





// objects
int n;
int *rows, *cols;
vector<vector<llong>> memo;





// function
llong dp(int l, int r)
{
	if(l == r)
		return 0;

	if(memo[l][r] >= 0)
		return memo[l][r];

	llong res = dp(l+1, r) + rows[l]*cols[r]*cols[l];
	for(int k = l+1; k < r; ++k)
	{
		res = min(
			res,
			dp(l, k) + dp(k+1, r) +
			rows[l]*cols[r]*cols[k]
		);
	}

	memo[l][r] = res;
	return res;
}





// main
int main( int argc, char *argv[] )
{
	// input
	scanf("%i", &n);
	rows = new int[n];
	cols = new int[n];

	for(int i = 0; i < n; ++i)
		scanf("%i%i", rows+i, cols+i);
	
	
	
	// init memo	
	memo = vector<vector<llong>>( n, vector<llong>(n, -1) );
	
	
	
	// solve
	llong res = dp(0, n-1);
	
	
	
	// output
	printf("%lli\n", res);



	return 0;
}





// end
