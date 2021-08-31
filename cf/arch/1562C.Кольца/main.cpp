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

auto nxti = next<int>;
auto nxtll = next<llong>;



void solve()
{
	int    const n = nxti();
	string const s = next<string>();

	int    const zero = s.find('0');

	if (zero == string::npos)
		printf("%i %i %i %i\n", 1, n/2, 2, n/2+1);
	else if (n - zero - 1 >= n/2)
		printf("%i %i %i %i\n", zero + 2, n, zero+1, n);
	else
		printf("%i %i %i %i\n", 1, zero+1, 1, zero);
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
