#include <algorithm>
#include <iostream>
#include <string>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	typedef long long llong;

	llong n;
	llong const d = 1000000007;

	cin >> n;
	if(n == 0)
	{
		cout << 1 << endl;
		return 0;
	}

	llong res = 1;
	for(llong i = 2; i <= n; ++i)
		res = res * i % d;

	cout << res << endl;


	return 0;
}





// end
