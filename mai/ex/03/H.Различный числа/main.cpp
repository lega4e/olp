#include <iostream>
#include <set>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	int n, input;
	set<int> sint;

	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		cin >> input;
		sint.insert(input);
	}

	cout << sint.size() << endl;




	return 0;
}





// end
