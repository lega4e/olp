#include <cstring>
#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	int n;
	int maxw;

	int *weis;
	
	
	
	// input
	scanf("%i", &n);
	weis = new int[n];

	maxw = 0;
	for(auto *b = weis, *e = weis+n; b != e; ++b)
		scanf("%i", b), maxw += *b;
	
	
	
	// solve
	int res;
	{
		int *pre = new int[maxw+1];
		int *cur = new int[maxw+1];


		// prepare
		for(auto *b = pre, *e = pre+maxw+1; b != e; ++b)
			*b = n+1;
		pre[weis[0]] = 1;
	

		// main
		for(int i = 1; i < n; ++i)
		{
			for(int w = 0; w < maxw+1; ++w)
			{
				if(w == weis[i])
				{
					cur[w] = 1;
					continue;
				}

				cur[w] = pre[w];
				if( w + weis[i] <= maxw )
					cur[w] = min( cur[w], 1 + pre[w + weis[i]] );
				cur[w] = min( cur[w], 1 + pre[abs(w - weis[i])] );
			}
			swap(cur, pre);
		}

		res = pre[0];
	}
	
	
	
	// output
	printf("%i\n", res > n ? -1 : res);
	
	
	
	return 0;
}





// end
