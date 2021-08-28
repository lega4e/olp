#include <cmath>
#include <iostream>
#include <fstream>
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

llong comb(llong m, llong n)
{
	if (m > n)
		return 0;

	llong res = 1;
	llong nn  = n - m + 1; // n - m + 1 -> n
	llong mm  = 1;         // 1 -> m
	while (nn <= n || mm <= m)
	{
		while (mm <= m && res % mm == 0)
			res /= mm, ++mm;
		if (nn <= n)
			res *= nn, ++nn;
	}
	return res;
}

llong calculate(int k, llong val, int lg)
{
	if (k < 0 || k > lg)
		return 0;

	int zeroes = 0;
	int i;
	for(i = lg-1; i >= 0; --i)
	{
		if (val & (1 << i))
		{
			return comb(k-1-zeroes, i) + calculate(k-zeroes, val, i);
			break;
		}
		++zeroes;
	}
	return k == zeroes ? 1 : 0;
}





// main
int main( int argc, char *argv[] )
{
	int const N  = nxti();
	int const K  = nxti();
	int const lg = (int)log2(N);

	llong res = 0;

	for (int b = K; b < lg; ++b)
		res += comb(K, b);

	cout << res + calculate(K, N, lg) << endl;

	return 0;
}





// end
