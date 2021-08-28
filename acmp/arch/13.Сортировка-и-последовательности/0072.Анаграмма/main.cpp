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
int main( int argc, char *argv[] )
{
	string word = next<string>();

	int sym;
	for (sym = (int)word.size()-1; sym >= 0; --sym)
	{
		if (find_if(word.begin()+sym+1, word.end(), [&](char ch) {
				return word[sym] < ch;
			}) != word.end())
		{
			break;
		}
	}

	if (sym < 0)
		throw "Error";

	int min = -1;
	for (int i = sym+1; i < (int)word.size(); ++i)
	{
		if (word[i] > word[sym] && (min < 0 || word[i] < word[min]))
			min = i;
	}
	swap(word[sym], word[min]);
	sort(word.begin() + sym + 1, word.end());

	cout << word << endl;

	return 0;
}





// end
