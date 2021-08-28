#include <cstring>
#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	typedef long long llong;
	typedef struct
	{
		llong rent;
		int prev;
		int next;
	} Bubble;

	int n, k;
	Bubble *vals;
	
	
	
	// input
	scanf("%i%i", &n, &k);
	vals = new Bubble[n+1];
	vals[0] = { 0, -1 };
	vals[n] = { 0, -1 }; 

	for(int i = 1; i < n; ++i)
		scanf("%lli", &vals[i].rent);
	
	
	
	// solve
	{
		// find rent
		int amin;
		for(int i = 1; i < n+1; ++i)
		{
			amin = i-1;
			for(int j = max(0, i-k); j < i-1; ++j)
			{
				if(vals[j].rent <= vals[amin].rent)
					amin = j;
			}
			vals[i].rent += vals[amin].rent;
			vals[i].prev = amin;
		}
	}

	int waylength = 0;
	{
		// find way
		int cur = n;
		++waylength;
		vals[cur].next = -1;
		while( !(vals[cur].prev < 0) )
		{
			vals[ vals[cur].prev ].next = cur;
			++waylength;
			cur = vals[cur].prev;
		}
	}
	
	
	
	// output
	printf("%lli\n%i\n", vals[n].rent, waylength);
	for(int cur = 0; !(cur < 0); cur = vals[cur].next)
		printf("%i ", cur);



	return 0;
}





// end
