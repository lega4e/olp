#include <iostream>
#include <vector>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	typedef long long llong;

	string a, b;
	int n, m;
	
	
	
	// input
	cin >> a >> b;
	n = a.size();
	m = b.size();

	

	// solve
	vector<vector<llong>> dp(
		n+1, vector<llong>(m+1, 0)
	);

	for(int i = 1; i < n+1; ++i)
	{
		for(int j = 1; j < m+1; ++j)
		{
			if(a[i-1] == b[j-1])
				dp[i][j] = dp[i-1][j-1]+1;

			dp[i][j] = max(
				max(dp[i][j], dp[i-1][j]),
				dp[i][j-1]
			);
		}
	}
	
	
	
	// output
	printf("%lli\n", dp[n][m]);



	return 0;
}





// end
