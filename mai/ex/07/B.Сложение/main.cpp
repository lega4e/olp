#include <algorithm>
#include <cstring>
#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	typedef long long llong;

	struct Event
	{
		int p;
		llong v;
	};

	int n, q;
	Event *evs;
	
	
	
	// input, prepare
	scanf("%i%i", &n, &q);
	evs = new Event[q*2];
	for(int i = 0; i < q; ++i)
	{
		scanf("%i%i%lli", &evs[2*i].p, &evs[2*i+1].p, &evs[2*i].v);
		--evs[2*i].p;
		evs[2*i+1].v = -evs[2*i].v;
	}
	
	sort(evs, evs+q*2, [](Event lhs, Event rhs)->bool {
		return lhs.p < rhs.p;
	} );

	
	
	// solve, output
	llong value = 0;
	int cur = 0;
	for(auto *b = evs, *e = evs + 2*q; b != e; ++b)
	{
		while(cur < b->p)
			printf("%lli ", value),
			++cur;

		value += b->v;
	}

	while(cur < n)
		printf("%lli ", value),
		++cur;



	return 0;
}





// end
