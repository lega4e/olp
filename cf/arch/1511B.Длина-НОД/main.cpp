#include <cmath>
#include <iostream>
#include <random>


using namespace std;





// types
typedef long long llong;
typedef uniform_int_distribution<llong> disLL;





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





// objects
default_random_engine dre(337);





// main
int main( int argc, char *argv[] )
{
	int testc = nxti();
	llong rx, ry, g;
	
	for (int test = 0; test < testc; ++test)
	{
		llong const a = nxtll();
		llong const b = nxtll();
		llong const c = nxtll();
		// printf("a: %lli, b: %lli, c: %lli\n", a, b, c);

		disLL gdis((int)pow(10, c-1), (int)pow(10, c) - 1);
		while (true)
		{
			g = gdis(dre);

			llong const xb = ceil(pow(10, a-1) / g);
			llong const xe = (llong)((pow(10, a) - 1) / g);

			llong const yb = ceil(pow(10, b-1) / g);
			llong const ye = (llong)((pow(10, b) - 1) / g);

			// printf("g: %lli, xb: %lli, xe: %lli, yb: %lli, ye: %lli, \n", g, xb, xe, yb, ye);

			disLL xdis(xb, xe);
			disLL ydis(yb, ye);

			for (int i = 0; i < 1024; ++i)
			{
				rx = xdis(dre), ry = ydis(dre);
				if (gcd(rx, ry) == 1)
					goto success_label;
			}

			// printf("\n");
		}

	success_label:
		printf("%lli %lli\n", g*rx, g*ry);
	}



	return 0;
}





// end
