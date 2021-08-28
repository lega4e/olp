#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;





// types
typedef long long llong;

struct Segment
{
	llong l, r;
};

struct Event
{
	llong p;
	char type;
};






// main
int main( int argc, char *argv[] )
{
	int n;
	vector<Segment> segs;
	vector<Event> evs;
	
	
	
	// input
	scanf("%i", &n);
	segs.reserve(n);
	evs.reserve(2*n);

	Segment seg;
	for(int i = 0; i < n; ++i)
	{
		scanf("%lli %lli", &seg.l, &seg.r);
		segs.push_back(seg);
	}
	

	for(int i = 0; i < n; ++i)
	{
		evs.push_back( Event{ segs[i].l, 'b' } );
		evs.push_back( Event{ segs[i].r, 'e' } );
	}

	sort( evs.begin(), evs.end(), [](Event lhs, Event rhs)->bool {
		if(lhs.p != rhs.p)
			return lhs.p < rhs.p;
		if(lhs.type == rhs.type)
			return &lhs < &rhs;
		return lhs.type == 'b';
	} );
	
	
	
	// solve
	llong sum = 1;
	llong cur = 1;
	llong prevp = evs[0].p;

	for(int i = 1; i < (int)evs.size(); ++i)
	{
		if(cur)
		{
			sum += evs[i].p - prevp;
			prevp = evs[i].p;
		}

		if(evs[i].type == 'b')
		{
			++cur;
			if(cur == 1)
			{
				++sum;
				prevp = evs[i].p;
			}
		}
		else
			--cur;
	}
	
	
	
	// output
	printf("%lli\n", sum);
	



	return 0;
}





// end
