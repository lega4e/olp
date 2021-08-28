#include <iostream>
#include <vector>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	typedef long long llong;

	int n;



	// input
	scanf("%i", &n);

	vector<vector<llong>>
		first(n, vector<llong>(n)),
		second(n, vector<llong>(n)),
		result(n, vector<llong>(n));

	for(int y = 0; y < n; ++y)
	for(int x = 0; x < n; ++x)
		scanf("%lli", &first[y][x]);

	for(int y = 0; y < n; ++y)
	for(int x = 0; x < n; ++x)
		scanf("%lli", &second[y][x]);
	
	
	
	// solve
	llong sum;
	for(int y = 0; y < n; ++y)
	for(int x = 0; x < n; ++x)
	{
		sum = 0;
		for(int i = 0; i < n; ++i)
			sum += first[y][i] * second[i][x];
		result[y][x] = sum;
	}
	
	
	
	// output
	for(int y = 0; y < n; ++y)
	{
		for(int x = 0; x < n; ++x)
			printf("%lli ", result[y][x]);
		printf("\n");
	}





	return 0;
}





// end
