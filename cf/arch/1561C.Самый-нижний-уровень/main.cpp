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



int calculate_minpower(veci_t const &a)
{
	int power = 0;
	for (auto b = a.rbegin(), e = a.rend(); b != e; ++b)
		power = max(*b + 1, power - 1);
	return power;
}

struct elem_t
{
	int p, c;

	bool operator<(elem_t const &rhs) const
	{
		return p < rhs.p;
	}
};

void solve()
{
	int n = nxti();
	vector<elem_t> p(n, elem_t{});

	for (int i = 0; i < n; ++i)
	{
		veci_t a(nxti(), 0);
		for (int j = 0; j < (int)a.size(); ++j)
			a[j] = nxti();
		p[i] = { calculate_minpower(a), (int)a.size() };
	}

	sort(p.begin(), p.end());
	int power = 0;
	for (auto b = p.rbegin(), e = p.rend(); b != e; ++b)
		power = max(b->p, power - b->c);

	cout << power << endl;
}





// main
int main()
{
	ios::sync_with_stdio(false);

	for (int test = 0, testc = nxti(); test < testc; ++test)
		solve();

	return 0;
}





// end
