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
		if(scanf("%lli %lli", &seg.l, &seg.r) <= 0)
			return 0;
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
	llong cur = 0;
	llong point;
	llong amax = 0;
	for(auto ev : evs)
	{
		if(ev.type == 'b')
			++cur;
		else
			--cur;

		if(cur > amax)
		{
			amax = cur;
			point = ev.p;
		}
	}
	
	
	
	// output
	printf("%lli %lli\n", amax, point);
	



	return 0;
}





// end
