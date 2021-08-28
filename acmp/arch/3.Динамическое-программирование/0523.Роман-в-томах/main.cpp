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
	vector<int> a(N);
	for (int i = 0; i < N; ++i)
		a[i] = nxti() + (i > 0 ? a[i-1] : 0);
	int const K = nxti();

	vector<int> prv = a;
	vector<int> nxt(N, 0);

	int minval;
	for (int k = 1; k < K; ++k)
	{
		for (int n = k; n < N; ++n)
		{
			minval = INT_MAX;
			for (int m = k; m < n+1; ++m)
				minval = min(minval, max(prv[m-1], a[n] - a[m-1]));
			nxt[n] = minval;
		}
		swap(prv, nxt);
	}

	cout << prv.back() << endl;

	return 0;
}





// end
