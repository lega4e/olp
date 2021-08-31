#include <algorithm>
#include <cmath>
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
	ios::sync_with_stdio(false);
	int const n = nxti();
	int const m = nxti();

	vector<llong> a(n+1, 0);
	vector<llong> s(n+1, 0);

	a[n] = 1;
	s[n] = 1;
	for (int i = n-1; i > 0; --i)
	{
		a[i] = s[i+1];
		for (int z = 2; i * z <= n; ++z)
			a[i] = (a[i] + s[i*z] - ((i+1)*z <= n ? s[(i+1)*z] : 0)) % m;
		s[i] = (s[i+1] + a[i]) % m;
	}

	cout << a[1] << endl;

	return 0;
}





// end
