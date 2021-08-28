#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;





// types
typedef long long llong;

struct Cut
{
	llong l, r;
};

bool operator<(Cut lhs, Cut rhs)
{
	return
		lhs.l != rhs.l ?
			lhs.l < rhs.l :
			lhs.r > rhs.r;
}





// main
int main( int argc, char *argv[] )
{
	int n;
	
	
	
	// input
	scanf("%i", &n);

	vector<Cut> cuts(n);
	vector<char> exclude(n, 0);
	for(int i = 0; i < n; ++i)
		scanf("%lli%lli", &cuts[i].l, &cuts[i].r);
	
	
	
	// solve
	sort( cuts.begin(), cuts.end() );

	for(int a = 0; a < n; ++a)
	{
		for(int b = a+1; b < n; ++b)
		{
			if(cuts[b].l >= cuts[a].r)
				break;

			if(cuts[b].r <= cuts[a].r)
			{
				exclude[a] = 1;
				break;
			}
		}
	}

	int count;
	{
		int r;
		int p;

		for(p = 0; p < n; ++p)
		{
			if(!exclude[p])
			{
				r = cuts[p].r;
				break;
			}
		}

		count = 1;
		while(++p < n)
		{
			if(exclude[p] || cuts[p].l < r)
				continue;
			r = cuts[p].r;
			++count;
		}
	}
	
	
	
	// output
	printf("%i\n", count);



	return 0;
}





// end
