#include <iostream>
#include <vector>

#ifndef LIS_TYPE_HPP
#define LIS_TYPE_HPP

#include <limits>



typedef int8_t byte;
typedef uint8_t ubyte;
typedef int64_t llong;
typedef uint64_t ullong;
typedef long double ldouble;


constexpr int  const int_inf  = std::numeric_limits<int>::max() / 2;
constexpr int  const int_max  = std::numeric_limits<int>::max();
constexpr int  const int_min  = std::numeric_limits<int>::min();
constexpr long const long_inf = std::numeric_limits<long>::max() / 2;
constexpr long const long_max = std::numeric_limits<long>::max();
constexpr long const long_min = std::numeric_limits<long>::min();

constexpr llong  const llong_inf  = std::numeric_limits<llong>::max() / 2;
constexpr llong  const llong_max  = std::numeric_limits<llong>::max();
constexpr llong  const llong_min  = std::numeric_limits<llong>::min();
constexpr ullong const ullong_inf = std::numeric_limits<ullong>::max() / 2;
constexpr ullong const ullong_max = std::numeric_limits<ullong>::max();
constexpr ullong const ullong_min = std::numeric_limits<ullong>::min();

constexpr float   const float_inf    = std::numeric_limits<float>::infinity();
constexpr float   const float_nan    = std::numeric_limits<float>::quiet_NaN();
constexpr float   const float_snan   = std::numeric_limits<float>::signaling_NaN();

constexpr double  const double_inf   = std::numeric_limits<double>::infinity();
constexpr double  const double_nan   = std::numeric_limits<double>::quiet_NaN();
constexpr double  const double_snan  = std::numeric_limits<double>::signaling_NaN();

constexpr ldouble const ldouble_inf  = std::numeric_limits<ldouble>::infinity();
constexpr ldouble const ldouble_nan  = std::numeric_limits<ldouble>::quiet_NaN();
constexpr ldouble const ldouble_snan = std::numeric_limits<ldouble>::signaling_NaN();





#endif




using namespace std;





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
	int testc;
	int n;
	vector<int> a;
	vector<int> f, g;

	auto calc_f = [&](int n)->int {
		return min(g[n-1], g[n-2]);
	};

	auto calc_g = [&](int n)->int {
		return min( f[n-1], f[n-2] + a[n-1] ) + a[n];
	};

	testc = nxti();
	for(int test = 0; test < testc; ++test)
	{
		n = nxti();
		a.resize(n);
		f.assign(n, int_max/3);
		g.assign(n, int_max/3);

		for(int i = 0; i < n; ++i)
			a[i] = nxti();

		f[1] = g[0] = a[0];
		g[1] = a[0] + a[1];
		for(int i = 2; i < n; ++i)
		{
			g[i] = calc_g(i);
			f[i] = calc_f(i);
		}

		printf("%i\n", min(g.back(), f.back()));
	}



	return 0;
}





// end
