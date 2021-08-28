#include <iostream>
#include <lis/olp/number_theory.cpp>

#include <lis/string.hpp>

// #pragma GCC optimize 5


using namespace std;





// main
int main( int argc, char *argv[] )
{
	int testc;
	string s, t;
	llong szlcm;

	cin >> testc;
	for(int test = 0; test < testc; ++test)
	{
		cin >> s >> t;
		szlcm = lcm(s.size(), t.size());
		if(szlcm / s.size() * s == szlcm / t.size() * t)
			cout << szlcm / s.size() * s << endl;
		else
			cout << -1 << endl;
	}



	return 0;
}





// end
