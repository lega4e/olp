#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	int l = -1, r = 1000000001;
	int m;

	char answer = 0;
	while(answer != '=')
	{
		m = (l+r)/2;
		cout << m << flush;
		cin >> answer;

		if(answer == '>')
			r = m;
		else if(answer == '<')
			l = m;
	}



	return 0;
}





// end
