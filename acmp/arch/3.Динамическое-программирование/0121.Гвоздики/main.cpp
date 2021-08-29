#include <algorithm>
#include <climits>
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
int main()
{
	int const N = nxti();
	vector<int> a(N), f(N), g(N);

	for (int i = 0; i < N; ++i)
		a[i] = nxti();
	sort(a.begin(), a.end());

	f[0] = 0;
	g[0] = INT_MAX;

	for (int i = 1; i < N; ++i)
	{
		f[i] = g[i-1];
		g[i] = min(f[i-1], g[i-1]) + a[i] - a[i-1];
	}

	cout << g[N-1] << endl;


	return 0;
}





// end
