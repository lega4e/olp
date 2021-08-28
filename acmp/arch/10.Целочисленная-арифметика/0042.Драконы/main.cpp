#include <cmath>
#include <fstream>


using namespace std;





// functions
typedef unsigned long long ullong;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	ullong n;
	ullong result;
	
	
	
	// input
	ifstream(INPUT_FILE_NAME) >> n;
	
	
	
	// calculate
	if(n == 0)
		result = 0;
	else if(n == 1)
		result = 1;
	else switch(n % 3)
	{
	case 0:
		result = pow(3, n/3);
		break;
	case 1:
		result = pow(3, n/3-1)*2*2;
		break;
	default:
		result = pow(3, n/3) * 2;
		break;
	}
	
	
	
	// output
	ofstream(OUTPUT_FILE_NAME) << result << endl;
	
	

	return 0;
}





// end
