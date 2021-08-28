#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;





// functions
int mex(vector<int> &vec)
{
	sort( vec.begin(), vec.end() );
	if( vec.empty() || vec[0] > 0 )
		return 0;
	for(int i = 1; i < (int)vec.size(); ++i)
	{
		if(vec[i-1]+1 < vec[i])
			return vec[i-1]+1;
	}
	return vec.back()+1;
}





// main
int main( int argc, char *argv[] )
{
	int n;
	
	
	
	// input
	scanf("%i", &n);

	
	
	// solve
	vector<int> vec(max(4, n+1), 0);

	vector<int> steps;
	steps.reserve(3 + n/2);

	vec[1] = 1;
	vec[2] = 1;

	for(int i = 3; i < n+1; ++i)
	{
		steps.clear();
		steps.push_back( vec[0] ^ vec[i-2] );
		for(int j = 1; j <= i/2; ++j)
		{
			steps.push_back(
				vec[ j-1 ] ^
				vec[ i-j-2 ]
			);
		}

		vec[i] = mex(steps);
	}
	
	
	
	// output
	printf("%i\n", vec[n] ? 1 : 2);



	return 0;
}





// end
