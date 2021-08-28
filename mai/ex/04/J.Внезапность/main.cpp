#include <algorithm>
#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	typedef long long llong;
	typedef struct
	{
		int t;
		int remt;
	} Printer;

	llong n;
	int k;
	Printer *prs;
	llong time = 0;
	
	
	
	// input, sort
	scanf("%lli%i", &n, &k);
	++n;
	prs = new Printer[k];
	for(auto *b = prs, *e = prs+k; b != e; ++b)
		scanf("%i", &b->t),
		b->remt = -1;
	sort(
		prs, prs+k,
		[](Printer lhs, Printer rhs) { return lhs.t < rhs.t; }
	);
	
	
	// prepare
	{
		llong hvcp = 1, alcp = 1;
		prs[0].remt = prs[0].t;
		--hvcp;

		while(true)
		{
			if(alcp >= n)
				goto end_label;
			if(alcp >= k)
				break;
			++time;
			for(int i = 0; i < k; ++i)
			{
				if(prs[i].remt < 0)
				{
					if(hvcp)
					{
						prs[i].remt = prs[i].t;
						--hvcp;
					}
					else
						break;
				}
				else if(!--prs[i].remt)
				{
					++hvcp;
					++alcp;
					prs[i].remt = prs[i].t;
				}
			}
		}
		n -= alcp;
	}
	
	
	
	// solve
	{
		llong l = -1, r = prs[0].t*n, m, val;
		while(r-l > 1)
		{
			m = (l+r)/2;
			val = 0;
			for(int i = 0; i < k; ++i)
				if(prs[i].remt <= m)
					val += (m - prs[i].remt)/prs[i].t + 1;
			if(n <= val)
				r = m;
			else
				l = m;
		}
		time += r;
	}
	
	
	
	// output
end_label:
	printf("%lli\n", time);
	return 0;
}





// end
