#include <iostream>
#include <vector>


using namespace std;





// types
typedef long long llong;





// objects
int n, m;
vector<vector<llong>> f;
vector<vector<llong>> vals;





// functions
llong dp(int y, int x)
{
	if(
		x < 0 || x >= m ||
		y < 0 || y >= n
	)
		return -2;

	if(vals[y][x] != -1)
		return vals[y][x];



	if(x == 0 && y == 0)
	{
		vals[y][x] = f[y][x];
		return vals[y][x];
	}

	llong res;
	res = max(
		dp(y+1, x-2),
		max(
			dp(y-1, x-2),
			max(
				dp(y-2, x-1),
				dp(y-2, x+1)
			)
		)
	);

	if(res == -2)
		vals[y][x] = -2;
	else
		vals[y][x] = res + f[y][x];



	return vals[y][x];
}





// main
int main( int argc, char *argv[] )
{
	// input
	scanf("%i%i", &n, &m);
	f = vector<vector<llong>>(
		n, vector<llong>(m, 0)
	);
	vals = vector<vector<llong>>(
		n, vector<llong>(m, -1)
	);

	for(int y = 0; y < n; ++y)
	for(int x = 0; x < m; ++x)
		scanf("%lli", &f[y][x]);
	
	
	
	// solve
	llong res = 0, cur;
	for(int y = 0; y < n; ++y)
	for(int x = 0; x < m; ++x)
	{
		cur = dp(y, x);
		if(cur > res)
			res = cur;
	}
	
	
	
	// output
	printf("%lli\n", res);



	return 0;
}





// end
