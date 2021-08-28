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
	int testc;
	int n;
	vector<string> f;
	bool perh;

	testc = nxti();
	for(int test = 0; test < testc; ++test)
	{
		n = nxti();
		f.resize(n, "");

		for(int i = 0; i < n; ++i)
			f[i] = next<string>();

		for(int y = n-1; y >= 0; --y)
		{
			for(int x = n-1; x >= 0; --x)
			{
				if(f[y][x] == '0')
					continue;

				perh = x == n-1 or f[y][x+1] == '1' or
				       y == n-1 or f[y+1][x] == '1';

				if(!perh and f[y][x] == '1')
					goto fail_label;
			}
		}

		printf("YES\n");
		continue;

	fail_label:
		printf("NO\n");
	}


	return 0;
}





// end
