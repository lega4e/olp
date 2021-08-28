#include <algorithm>
#include <iostream>
#include <set>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	int n;
	set<string> coll;
	string input;
	
	
	
	// input
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> input;
		sort( input.begin(), input.end() );
		coll.insert(input);
	}
	
	
	
	// output
	cout << coll.size() << endl;



	return 0;
}





// end
