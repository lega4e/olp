#include <iostream>
#include <vector>


using namespace std;





// types
typedef long long llong;





// functions
inline llong firstn(llong n)
{
	return n * (n + 1) / 2;
}





// main
int main( int argc, char *argv[] )
{
	int n;
	int *a, *id;
	llong *sums;
	vector<pair<int, int>> result;
	
	
	
	// input
	scanf("%i", &n);
	a = new int[n+1];
	id = new int[n+1];
	sums = new llong[n+1];
	sums[0] = 0;
	result.reserve(n/2);
	for(int i = 1; i < n+1; ++i)
	{
		scanf("%i", a+i);
		id[a[i]] = i;
		sums[i] = sums[i-1] + a[i];
	}
	
	
	
	// solve
	int l, r;
	int cur = 1;
	l = r = id[cur];

	while(true)
	{
		if(
			r-l+1 == cur &&
			sums[r] - sums[l-1] == firstn(cur)
		)
			result.push_back({l, r});


		++cur;
		if(cur > n)
			break;

		l = min(l, id[cur]);
		r = max(r, id[cur]);
	}
	
	
	
	// output
	printf("%i\n", (int)result.size());
	for(auto b = result.begin(), e = result.end(); b != e; ++b)
		printf("%i %i\n", b->first, b->second);



	return 0;
}





// end
