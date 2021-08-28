#include <iostream>
#include <vector>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	typedef long long llong;

	int n;
	llong wmax, cmax;
	llong *weights;
	int *coins;
	
	
	
	// input
	scanf("%i%lli", &n, &wmax);
	weights = new llong[n+1];
	coins = new int[n+1];

	cmax = 0;
	for(int i = 1; i < n+1; ++i)
		scanf("%lli%i", weights+i, coins+i),
		cmax += coins[i];
	
	
	
	// prepare
	vector<llong> prev(cmax+1, wmax+1);
	prev[0] = 0;
	vector<llong> cur(cmax+1);
	
	
	
	// solve
	for(int i = 1; i < n+1; ++i)
	{
		cur[0] = 0;
		for(int c = 1; c < (int)cur.size(); ++c)
		{
			cur[c] = prev[c];

			if( c - coins[i] >= 0 && prev[c-coins[i]] + weights[i] < cur[c] )
				cur[c] = prev[c-coins[i]] + weights[i];
		}

		swap(prev, cur);
	}

	int coin;
	for(int c = prev.size()-1; c >= 0; --c)
		if(prev[c] <= wmax)
		{
			coin = c;
			break;
		}
	
	
	
	// output
	printf("%i\n", coin);



	return 0;
}





// end
