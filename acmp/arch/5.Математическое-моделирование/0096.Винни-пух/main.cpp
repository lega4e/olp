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
	int const m = nxti();
	int const n = nxti();
	int const y = nxti() - 1;
	int const x = nxti() - 1;

	int const c = min(x, min(y, min(n-1-x, m-1-y)));

	int res = n * m - (n - c*2) * (m - c*2);

	if (y == c)
	{
		res += x - c;
		goto end_label;
	}
	res += n - c*2;

	if (n-1-x == c)
	{
		res += y - c - 1;
		goto end_label;
	}
	res += m - c*2 - 1;

	if (m-1-y == c)
	{
		res += n-1-c - x - 1;
		goto end_label;
	}
	res += n - c*2 - 1;

	res += m-2-c - y;

end_label:
	cout << res + 1 << endl;

	return 0;
}





// end
