#include <algorithm>
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

auto nxti  = next<int>;
auto nxtll = next<llong>;
auto nxts  = next<string>;



void solve()
{
	string n  = nxts();
	int k     = nxti();
	int d[10] = { 0 };
	int i, u, minnou;

	auto min_nouniqal = [&](int b)->int {
		for (int i = b; i < 10; ++i)
			if (d[i])
				return i;
		return -1;
	};

	auto fill = [&](int b, char c)->void {
		for (int i = b; i < (int)n.size(); ++i)
			n[i] = c;
	};

	for (i = 0; i < (int)n.size() && k > 1; ++i)
	{
		if (!d[n[i] - '0']++)
			--k;
	}

	while (i < (int)n.size() && d[n[i] - '0'])
		++i;

	if (i >= int(n.size())-1)
		goto success_label;

	// оставляем u
	u = i;
	if (!d[n[u] - '0']++)
		--k;
	while (++i < (int)n.size() && d[n[i] - '0']);

	if (i == (int)n.size())
		goto success_label;

	do
	{
		minnou = min_nouniqal(n[i] - '0' + 1);
		if (minnou >= 0)
		{
			n[i] = minnou + '0';
			fill(i+1, min_nouniqal(0) + '0');
			goto success_label;
		}
	}
	while (--i != u);

	--d[n[u] - '0'], ++k;
	++n[u];
	if (!d[n[u] - '0']++)
		--k;
	if (k)
		d[0] = 1;
	fill(u+1, min_nouniqal(0) + '0');

success_label:
	cout << n << endl;
}





// main
int main()
{
	// ios::sync_with_stdio(false);
	int const testc = nxti();

	for (int test = 0; test < testc; ++test)
		solve();

	return 0;
}





// end
