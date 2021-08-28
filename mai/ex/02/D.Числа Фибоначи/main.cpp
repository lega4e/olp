#include <iostream>
#include <vector>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	long long n;
	cin >> n;

	if(n == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	if(n == 1)
	{
		cout << 1 << endl;
		return 0;
	}

	vector<long long> fib = { 0, 1 };
	fib.reserve(1024);

	while(true)
	{
		fib.push_back( fib.back() + *(fib.end()-2) );
		if(n == fib.back())
		{
			cout << fib.size()-1 << endl;
			return 0;
		}
		else if(fib.back() > n)
		{
			cout << -1 << endl;
			return 0;
		}
	}

	throw 1;



	return 0;
}





// end
