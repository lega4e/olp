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
int main( int argc, char *argv[] )
{
	int const n = nxti();
	vector<int> a(n, 0);
	vector<int> f(n, 0);

	for (int i = 0; i < n; ++i)
		a[i] = nxti();

	f[0] = 0;
	if (n > 1)
		f[1] = f[0] + abs(a[1] - a[0]);
	for (int i = 2; i < n; ++i)
		f[i] = min( f[i-1] + abs(a[i] - a[i-1]),
		            f[i-2] + abs(a[i] - a[i-2]) * 3 );

	cout << f.back() << endl;

	return 0;
}





// end
