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





// main
int main()
{
	vector<string> s;

	string inp;
	while ( (inp = next<string>()) != "ENDOFINPUT" )
		s.push_back(inp);
	sort(s.begin(), s.end());

	int c = 0;
	for (int i = 0; i < (int)s.size(); ++i)
	{
		string estr = "1";
		estr[0] = s[i][0] + 1;
		for (
			auto b = lower_bound(s.begin(), s.end(), s[i].substr(0, 1)),
				 e = lower_bound(s.begin(), s.end(), estr);
			b != e; ++b
		)
		{
			if (s[i].size() > b->size() &&
				s[i].substr(0, b->size()) == *b &&
				binary_search(s.begin(), s.end(), s[i].substr(b->size())))
			{
				++c;
				break;
			}
		}
	}

	cout << c << endl;


	return 0;
}





// end
