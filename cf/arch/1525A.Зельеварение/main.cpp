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


template<typename T>
T gcd(T a, T b)
{
	while(a)
	{
		b %= a;
		std::swap(a, b);
	}
	return b;
}





// main
int main( int argc, char *argv[] )
{
	int testc = nxti();
	int k;

	for (int test = 0; test < testc; ++test)
	{
		k = nxti();
	
		int g = gcd(k, 100);
		printf("%i\n", 100/g);
	}



	return 0;
}





// end
