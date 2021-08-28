#include <iostream>
#include <regex>


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
	regex const rg(R"((-?\d+)([-+*/])(-?\d+)=(-?\d+))");
	smatch m;

	string expr;
	getline(cin, expr);

	if (!regex_search(expr, m, rg) || (int)m[0].length() != (int)expr.size())
	{
		cout << "ERROR" << endl;
		return 0;
	}

	long const a = stol(m[1].str());
	long const b = stol(m[3].str());
	long const r = stol(m[4].str());

	if (m[2].str() == "/")
	{
		if (b == 0 || a % b || a / b != r)
			goto no_label;
		goto yes_label;
	}

	if (r != (m[2].str() == "+" ? a + b : m[2].str() == "-" ? a - b : a * b))
		goto no_label;

yes_label:
	cout << "YES" << endl;
	return 0;

no_label:
	cout << "NO" << endl;
	return 0;
}





// end
