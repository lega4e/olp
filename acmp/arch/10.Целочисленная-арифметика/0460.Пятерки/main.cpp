#include <cmath>
#include <iostream>
#include <fstream>


using namespace std;





// types
typedef unsigned long long int ullong;





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
	result = 0u;
	if(n >= 5)
		result += 1 + (n-5)/10;
	ullong power = 10;
	ullong count;
	ullong residue;
	while( n >= power*5 )
	{
		count = 1 + (n - power*5) / (power*10);
		residue = n % (power*10);
		if( residue >= power*5 && residue < power*6 )
		{
			result += (count-1) * power + ( n % power + 1 );
		}
		else
		{
			result += count * power;
		}
		power *= 10;
	}
	
	
	
	// output
	(ofstream(OUTPUT_FILE_NAME) << result).flush();



	return 0;
}





// end
