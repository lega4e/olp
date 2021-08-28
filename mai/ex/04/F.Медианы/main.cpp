#include <iostream>
#include <set>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	typedef long long llong;

	llong n;
	multiset<llong> lset, rset;



	// solve
	llong input;
	scanf("%lli%lli", &n, &input);
	lset.insert(input);
	printf("%lli\n", input);
	for(llong i = 1; i < n; ++i)
	{
		scanf("%lli", &input);
		if(*--lset.end() < input)
		{
			rset.insert(input);
			if(rset.size() == lset.size()+1)
			{
				lset.insert(*rset.begin());
				rset.erase(rset.begin());
			}
		}
		else
		{
			lset.insert(input);
			if(lset.size() == rset.size()+2)
			{
				rset.insert(*--lset.end());
				lset.erase(--lset.end());
			}
		}

		printf("%lli\n", *--lset.end());
	}



	return 0;
}





// end
