#include <iostream>


using namespace std;





// functions
int price(char ch)
{
	return ch == '_' ? 0 : ch-'a'+1;
}





// main
int main( int argc, char *argv[] )
{
	int n;
	string from, to, null;
	
	
	
	// input
	cin >> n;
	while(n)
	{
		cin >> null >> null;
		--n;
	}
	cin >> from >> to;
	
	
	
	// solve
	if(from.size() < to.size())
	{
		from.reserve(to.size());
		while(from.size() != to.size())
			from.push_back('_');
	}
	else if(to.size() < from.size())
	{
		to.reserve(from.size());
		while(to.size() < from.size())
			to.push_back('_');
	}

	int sum = 0;
	for(int i = 0; i < (int)from.size(); ++i)
		sum += price(to[i]) - price(from[i]);
	
	
	
	// output
	cout << sum << endl;



	return 0;
}





// end
