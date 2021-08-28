#include <cstring>
#include <iostream>
#include <vector>


using namespace std;





// types
typedef long long llong;





// main
int main( int argc, char *argv[] )
{
	int k;
	string dig;
	
	
	
	// input, prepare
	cin >> k >> dig;
	
	vector< vector< vector<llong> > > dp(
		10, vector< vector<llong> >(10, vector<llong>(k+1, 0) )
	);
	for(int y = 0; y < 10; ++y)
	for(int x = 0; x < 10; ++x)
	{
		dp[y][x][0] = y+x;
	}


	char s[5];
	for(int i = 1; i < k+1; ++i)
	{
		for(int y = 0; y < 10; ++y)
		for(int x = 0; x < 10; ++x)
		{
			sprintf(s, "%i%i%i", y, y+x, x);

			if(strlen(s) == 3)
			{
				dp[y][x][i] = 
					dp[s[0]-'0'][s[1]-'0'][i-1] +
					dp[s[1]-'0'][s[2]-'0'][i-1] -
					( s[1]-'0' );
			}
			else if(strlen(s) == 4)
			{
				dp[y][x][i] = 
					dp[s[0]-'0'][s[1]-'0'][i-1] +
					dp[s[1]-'0'][s[2]-'0'][i-1] +
					dp[s[2]-'0'][s[3]-'0'][i-1] -
					( (s[1] - '0') + (s[2] - '0') );
			}
		}
	}
	
	
	
	// solve
	llong res = 0;
	for(int i = 0; i < (int)dig.size()-1; ++i)
	{
		res += dp[ dig[i]-'0' ][ dig[i+1]-'0' ][k] - (dig[i+1] - '0');
	}
	res += dig[dig.size()-1] - '0';
	
	
	
	// output
	printf("%lli\n", res);



	return 0;
}





// end
