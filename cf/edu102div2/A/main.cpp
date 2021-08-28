#include <iostream>

#include <lis/type.hpp>

#pragma GCC optimize 5


using namespace std;





// main
int main( int argc, char *argv[] )
{
	int testc;
	int n, d;
	int min[2];
	int max;
	int a;

	scanf("%i", &testc);
	for(int test = 0; test < testc; ++test)
	{
		scanf("%i %i", &n, &d);

		min[0] = int_max/3;
		min[1] = int_max/3;
		max = -int_max;
		for(int i = 0; i < n; ++i)
		{
			scanf("%i", &a);

			if(a > max)
				max = a;
			if(a < min[0])
				swap(a, min[0]);
			if(a < min[1])
				min[1] = a;
		}

		if(max <= d || min[0] + min[1] <= d)
			printf("yes\n");
		else
			printf("no\n");
	}



	return 0;
}





// end
