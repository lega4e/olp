#include <iostream>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	string s;
	cin >> s;


	int res = 0;
	for(char ch : s) switch(ch)
	{
	case '0': case '4':
	case '6': case '9':
		++res;
		break;
	case '8':
		res += 2;
		break;
	default:
		break;
	}



	cout << res << endl;



	return 0;
}





// end
