#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	struct Note
	{
		int t;
		long long v;
	};

	int n;
	
	
	
	// solve
	int time = 1;
	long long val = 0;
	Note bestmin = { -1, 0 }, bestmax = { -1, 0 };
	Note curmin = { 1, 0 }, curmax = { 1, 0 };

	int inp;
	scanf("%i", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%i", &inp);
		val += inp;
		++time;

		if(val < curmin.v)
			curmin = { time, val },
			curmax = { time, val };
		else if(val > curmax.v)
			curmax = { time, val };

		if( curmax.v - curmin.v > bestmax.v - bestmin.v )
			bestmin = curmin,
			bestmax = curmax;
	}
	
	
	
	// output
	printf("%i %i\n", bestmin.t, bestmax.t);



	return 0;
}





// end
