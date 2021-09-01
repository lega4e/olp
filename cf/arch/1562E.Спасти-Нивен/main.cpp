#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;





// types
typedef long long llong;
typedef vector<int>           veci_t;
typedef vector<vector<int>>   vveci_t;
typedef vector<llong>         vecll_t;
typedef vector<vector<llong>> vvecll_t;





// functions
template<typename T>
T next()
{
	T t;
	cin >> t;
	return t;
}

auto nxti  = next<int>;
auto nxtll = next<llong>;
auto nxts  = next<string>;



void solve()
{
	int    const n = nxti();
	string const s = nxts();
	veci_t       a(n, 0);
	vveci_t      t(n+1, veci_t(n+1, 0));

	for (int i = n-1; i > -1; --i)
	for (int j = n-1; j > -1; --j)
		t[i][j] = s[i] != s[j] ? 0 : 1 + t[i+1][j+1];

	a[0] = n;
	int res = a[0];
	for (int i = 1; i < n; ++i)
	{
		a[i] = n-i;
		for (int j = 0; j < i; ++j)
			a[i] = max(a[i],
				t[i][j] < n-i && s[i+t[i][j]] > s[j+t[i][j]] ?
				a[j] + n-i-t[i][j] : n-i);
		res = max(res, a[i]);
	}

	cout << res << endl;
}





// main
int main()
{
	ios::sync_with_stdio(false);
	int const testc = nxti();

	for (int test = 0; test < testc; ++test)
		solve();

	return 0;
}





// end
