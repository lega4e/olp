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

int calculate_profit(int set, vector<int> const &w)
{
	int first = 0;
	int second = 0;

	for (int i = 0; i < (int)w.size(); ++i)
		(set & (1 << i) ? first : second) += w[i];
	return abs(second - first);
}





// main
int main( int argc, char *argv[] )
{
	int const n = nxti();
	vector<int> w(n);

	for (int i = 0; i < n; ++i)
		w[i] = nxti();

	int res = INT_MAX;
	int const m = 1 << n;
	for (int i = 0; i < m; ++i)
		res = min(res, calculate_profit(i, w));

	cout << res << endl;

	return 0;
}





// end
