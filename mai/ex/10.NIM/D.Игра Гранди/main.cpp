#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;





// types
typedef long long llong;





// functions
int mex(vector<int> &vec)
{
	sort( vec.begin(), vec.end() );
	if( vec.empty() || vec[0] )
		return 0;
	for(int i = 0; i < (int)vec.size(); ++i)
	{
		if(vec[i] != i)
			return i;
	}
	return vec.size();
}





// main
int main( int argc, char *argv[] )
{
	int n;
	
	
	
	// input
	scanf("%i", &n);
	
	
	
	// solve
	vector<int> stages(n+1, 0);
	vector<int> steps;
	steps.reserve(n/2);
	
	for(int i = 0; i < n+1; ++i)
	{
		steps.clear();
		for(int j = 1; j < i - i/2; ++j)
			steps.push_back( stages[j] ^ stages[i-j] );
		stages[i] = mex(steps);
	}
	
	
	
	// output
	printf("%i\n", stages[n] ? 1 : 2);
	



	return 0;
}





// end
