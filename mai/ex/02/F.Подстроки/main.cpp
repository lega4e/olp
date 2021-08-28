#include <iostream>
#include <string>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	{
		int null;
		cin >> null >> null;
	}

	string str, sub;
	cin >> str >> sub;

	int c = 0;
	for(int i = 0; i < (int)(str.size()-sub.size()+1); ++i)
		if(str.substr(i, sub.size()) == sub)
			++c;

	cout << c << endl;


	return 0;
}





// end
