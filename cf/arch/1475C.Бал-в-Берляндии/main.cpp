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





// main
int main( int argc, char *argv[] )
{
	struct pair { int boy, girl; };

	int testc = nxti();
	int a, b, k;
	vector<pair> pairs;
	vector<int> boys, girls;
	llong res;

	for(int test = 0; test < testc; ++test)
	{
		a = nxti();
		b = nxti();
		k = nxti();

		boys.assign(a, 0);
		girls.assign(b, 0);
		pairs.resize(k);

		for(int i = 0; i < k; ++i)
		{
			pairs[i].boy = nxti()-1;
			++boys[pairs[i].boy];
		}

		for(int i = 0; i < k; ++i)
		{
			pairs[i].girl = nxti()-1;
			++girls[pairs[i].girl];
		}

		res = 0;
		for(pair p : pairs)
			res += k-1 - (boys[p.boy] - 1) - (girls[p.girl] - 1);
		res /= 2;

		printf("%lli\n", res);
	}



	return 0;
}





// end
