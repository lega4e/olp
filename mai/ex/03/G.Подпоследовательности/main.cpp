#include <iostream>


using namespace std;





// functions
bool is(string const &s, string const &l)
{
	auto lb = l.begin(), le = l.end();
	for(char ch : s)
	{
		if(lb == le)
			return true;
		if(*lb == ch)
			++lb;
	}
	return lb == le;
}





// main
int main( int argc, char *argv[] )
{
	int n, m;
	string s, l;

	cin >> n >> s >> m;

	for(int i = 0; i < m; ++i)
	{
		cin >> n >> l;
		cout << !is(s, l);
	}
	cout << endl;



	return 0;
}





// end
