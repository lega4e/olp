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


bool solve(string const &line, string &ans, string &ord)
{
	int count['z'-'a'+1] = { 0 };
	int wrd1len          = 0;

	ord.clear();
	for (auto b = line.rbegin(), e = line.rend(); b != e; ++b)
		if (!count[*b - 'a']++)
			ord.push_back(*b);
	reverse(ord.begin(), ord.end());

	for (int i = 0; i < (int)ord.size(); ++i)
		wrd1len += count[ord[i] - 'a'] / (i + 1);

	string word = line.substr(0, wrd1len);
	ans = word;
	string res = word;
	for (char c : ord)
		word.erase(remove(word.begin(), word.end(), c), word.end()),
		res += word;

	return res == line;
}





// main
int main()
{
	ios::sync_with_stdio(false);

	int const testc = nxti();
	string line;
	string ans, ord;

	for (int test = 0; test < testc; ++test)
	{
		cin >> line;
		if (solve(line, ans, ord))
			cout << ans << " " << ord << '\n';
		else
			cout << -1 << '\n';
	}

	return 0;
}





// end
