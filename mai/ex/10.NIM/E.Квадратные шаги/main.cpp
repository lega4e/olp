#include <iostream>
#include <vector>


using namespace std;





// types
typedef long long llong;





// main
int main( int argc, char *argv[] )
{
	int n;
	
	
	
	// input
	scanf("%i", &n);
	
	
	
	// solve
	vector<int> stages(n+1, 0);
	for(int i = 1; i < n+1; ++i)
	{
		for(int j = 1; i - j*j >= 0; ++j)
		{
			if(!stages[i - j*j])
			{
				stages[i] = 1;
				break;
			}
		}
	}
	
	
	
	// output
	printf("%i\n", stages[n] ? 1 : 2);



	return 0;
}





// end
