#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>


using namespace std;





// types
typedef long long llong;





// functions
int decode(char ch)
{
	if(isdigit(ch))
		return ch - '0';
	else if(islower(ch))
		return ch + 10 - 'a';
	else if(isupper(ch))
		return ch + 10 - 'A';
	throw 1;
}

char encode(int val)
{
	if(val < 10)
		return '0' + val;
	else if(val < 36)
		return 'a' + (val-10);
	throw 2;
}

llong parse(int a, string s)
{
	llong res = 0;
	for(char ch : s)
	{
		res *= a;
		res += decode(ch);
	}
	return res;
}

string format(int a, llong val)
{
	string res;
	while(val)
	{
		res.push_back( encode(val%(llong)a) );
		val /= (llong)a;
	}
	if(res.empty())
		res = "0";
	else
		reverse( res.begin(), res.end() );
	return res;
}






// main
int main( int argc, char *argv[] )
{
	int froma, toa;
	string val;

	cin >> froma >> toa >> val;
	llong num = parse(froma, val);
	string const res = format(toa, num);
	cout << res << endl;


	return 0;
}





// end
