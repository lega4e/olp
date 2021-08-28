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


int gcd(int a, int b)
{
	while (b)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}





// main
int main( int argc, char *argv[] )
{
	vector<int> a;
	int testc = nxti();
	int n;
	
	for (int test = 0; test < testc; ++test)
	{
		n = nxti();
	
		a.clear();
		a.reserve(n);
		int evenc = 0;

		int val;
		for (int i = 0; i < n; ++i)
		{
			cin >> val;
			if (val % 2 == 0)
				++evenc;
			else
				a.push_back(val);
		}

		int good = 0;
		for (auto b = a.begin(), e = a.end(); b != e; ++b)
		for (auto bb = next(b); bb != e; ++bb)
		{
			if (gcd(*b, *bb * 2) > 1)
				++good;
		}

		cout << (good + (2*n - 1 - evenc)*evenc / 2) << '\n';
	}


	return 0;
}





// end
