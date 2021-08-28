#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

#include <nvx/iostream.hpp>


using namespace std;





// types
typedef long long llong;





// functions
template<typename T>
T next()
{
	T t;
	cin >> t;
	return t;
}

auto nxti = next<int>;
auto nxtll = next<llong>;





// main
int main( int argc, char *argv[] )
{
	// input
	int         n;
	int         k;
	vector<int> a;

	n = nxti();
	a.resize(n+1);
	for (int i = 1; i < n+1; ++i)
		a[i] = nxti();
	k = nxti();



	// calculate
	vector<int> prv(n+1), cur(n+1);
	prv[0] = 0;
	for (int i = 1; i < n+1; ++i)
		prv[i] = prv[i-1] + a[i];
	
	for (int i = 1; i < k+1; ++i)
	{
		cur[0] = 0;
		for (int j = 1; j < n+1; ++j)
		{
			cur[j] = *min_element(prv.begin(), prv.end());
		}
	}


	return 0;
}





// end
