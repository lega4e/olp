#include <iostream>
#include <vector>
#include <string>


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

int print_string(string const &s, int k)
{
	int symbols = 0;
	for (int i = 0; i < k && symbols < 1023; ++i)
	{
		cout << s.substr(0, 1023 - symbols);
		symbols += min((int)s.size(), 1023 - symbols);
	}
	cout << endl;
	return 0;
}

string find_root(string const &s, int pow)
{
	if (s.size() % pow != 0)
		return "";

	string const root = s.substr(0, s.size() / pow);
	for (int i = 0; i < (int)s.size(); ++i)
		if (s[i] != root[i % root.size()])
			return "";

	return root;
}

int print_root(string const &s, int pow)
{
	string const root = find_root(s, pow);
	if (root.empty())
		cout << "NO SOLUTION" << endl;
	else
		cout << root << endl;
	return 0;
}





// main
int main( int argc, char *argv[] )
{
	string s    = next<string>();
	int const k = nxti();

	return k > 0 ? print_string(s, k) : print_root(s, -k);
}





// end
