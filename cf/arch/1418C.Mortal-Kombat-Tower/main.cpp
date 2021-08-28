#include <iostream>
#include <vector>

#include <lis/type.hpp>


using namespace std;





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
	int testc;
	int n;
	vector<int> a;
	vector<int> f, g;

	auto calc_f = [&](int n)->int {
		return min(g[n-1], g[n-2]);
	};

	auto calc_g = [&](int n)->int {
		return min( f[n-1], f[n-2] + a[n-1] ) + a[n];
	};

	testc = nxti();
	for(int test = 0; test < testc; ++test)
	{
		n = nxti();
		a.resize(n);
		f.assign(n, int_max/3);
		g.assign(n, int_max/3);

		for(int i = 0; i < n; ++i)
			a[i] = nxti();

		f[1] = g[0] = a[0];
		g[1] = a[0] + a[1];
		for(int i = 2; i < n; ++i)
		{
			g[i] = calc_g(i);
			f[i] = calc_f(i);
		}

		printf("%i\n", min(g.back(), f.back()));
	}



	return 0;
}





// end
