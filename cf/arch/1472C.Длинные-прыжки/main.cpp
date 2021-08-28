#include <iostream>
#include <vector>


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
	int testc = nxti();
	int n;
	vector<llong> a, f;
	llong mx;

	for(int test = 0; test < testc; ++test)
	{
		n = nxti();
		a.resize(n);
		f.resize(n);
		for(int i = 0; i < n; ++i)
			a[i] = nxtll();

		mx = 0;
		for(int i = n-1; i >= 0; --i)
		{
			f[i] = i+1 + a[i] > n ? a[i] : a[i] + f[i+a[i]];
			mx = max(mx, f[i]);
		}

		printf("%lli\n", mx);
	}



	return 0;
}





// end
