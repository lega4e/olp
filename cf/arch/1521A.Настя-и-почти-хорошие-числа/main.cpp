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
	int testc = nxti();
	
	for (int test = 0; test < testc; ++test)
	{
		llong a = nxti(), b = nxti();
	
		if (b == 1)
			printf("NO\n");
		else
		{
			llong x = a*b;
			llong y = (b + 1) * a;
			llong z = (2*b + 1) * a;
			printf("YES\n%lli %lli %lli\n", x, y, z);
		}
	}



	return 0;
}





// end
