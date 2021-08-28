#include <cmath>
#include <fstream>


using namespace std;





// types
typedef unsigned long long ullong;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	ullong i;

	ifstream(INPUT_FILE_NAME) >> i;

	ullong const root = (ullong)sqrt(i);
	ullong result = 2 * root * (root+1);
	i -= root*root;
	if(i)
	{
		result += 2*i + ( i > root ? 2 : 1 );
	}

	ofstream(OUTPUT_FILE_NAME) << result;
	

	return 0;
}





// end
