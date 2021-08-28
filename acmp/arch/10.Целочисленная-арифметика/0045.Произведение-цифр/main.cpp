#include <cstring>
#include <iostream>
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
	ullong number;
	
	
	
	// input
	ifstream(INPUT_FILE_NAME) >> number;
	
	
	
	// calculate
		// number == zero
	if(number == 0)
	{
		ofstream(OUTPUT_FILE_NAME) << 10 << flush;
		return 0;
	}
	if(number == 1)
	{
		ofstream(OUTPUT_FILE_NAME) << 1 << flush;
		return 0;
	}

		// else
	ullong digits[10];
	for( auto &i : digits )
		i = 0;
	for( ullong i = 9; i >= 2; --i )
	{
	again:
		if(number % i == 0)
		{
			number /= i;
			++digits[i];
			if(number == 1)
				break;
			goto again;
		}
	}

		// impossible
	if(number != 1)
	{
		ofstream(OUTPUT_FILE_NAME) << -1 << flush;
		return 0;
	}



	// output
	ofstream fout(OUTPUT_FILE_NAME);
	for(int i = 2; i < 10; ++i)
	{
		for(ullong j = 0; j < digits[i]; ++j)
		{
			fout << i;
		}
	}
	fout << endl;

	
	

	return 0;
}





// end
