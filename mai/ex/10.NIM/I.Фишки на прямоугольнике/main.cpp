#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	int k;
	
	
	
	// input, solve
	scanf("%i", &k);

	int x, y;
	int res = 0, cur;
	for(int i = 0; i < k; ++i)
	{
		scanf("%i%i", &x, &y);
		if(y < x)
			swap(x, y);

		cur = x%2 ? 
			(y%2 ? 0 : 1) :
			(y%2 ? 3 : 2);

		res ^= cur;
	}
	
	
	
	// output
	printf("%i\n", res ? 1 : 2);



	return 0;
}





// end
