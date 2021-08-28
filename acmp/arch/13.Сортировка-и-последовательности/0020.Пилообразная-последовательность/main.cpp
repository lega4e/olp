#include <iostream>
#include <fstream>


using namespace std;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	int n;
	int *arr;
	int result;
	
	
	
	// input
	{
		ifstream fin(INPUT_FILE_NAME);
		fin >> n;
		arr = new int[n];
		for(auto *b = arr, *e = arr+n; b != e; ++b)
		{
			fin >> *b;
		}
	}
	
	
	
	// calculate
	result = 1;
	int ftemp = 1, stemp = 1;
	bool fless = true, sless = false;

	for(auto *b = arr+1, *e = arr+n; b != e; ++b)
	{
		if(
			( fless && *(b-1) < *b ) ||
			( !fless && *(b-1) > *b )
		)
		{
			++ftemp;
			if(ftemp > result)
				result = ftemp;
			fless = !fless;
		}
		else
		{
			if(*(b-1) < *b)
			{
				ftemp = 2;
				fless = false;
			}
			else
			{
				ftemp = 1;
				fless = true;
			}
		}


		if(
			( sless && *(b-1) < *b ) ||
			( !sless && *(b-1) > *b )
		)
		{
			++stemp;
			if(stemp > result)
				result = stemp;
			sless = !sless;
		}
		else
		{
			if(*(b-1) > *b)
			{
				stemp = 2;
				sless = true;
			}
			else
			{
				stemp = 1;
				sless = false;
			}
		}
	}
		
	
	

	// output
	ofstream(OUTPUT_FILE_NAME) << result << flush;


	return 0;
}





// end
