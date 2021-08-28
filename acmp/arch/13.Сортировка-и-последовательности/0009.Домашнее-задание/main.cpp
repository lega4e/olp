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
	short *arr;
	
	
	
	// input
	{
		ifstream fin(INPUT_FILE_NAME);
		fin >> n;
		arr = new short[n];
		for(auto *b = arr, *e = arr+n; b != e; ++b)
		{
			fin >> *b;
		}
	}
	
	
	
	// calculate
	short *minptr = arr, *maxptr = arr;
	int positive = 0;
	int between = 1;
	for(auto *b = arr, *e = arr+n; b != e; ++b)
	{
		if( *b > 0 )
			positive += *b;
		if( *b < *minptr )
			minptr = b;
		else if( *b > *maxptr )
			maxptr = b;
	}

	if(minptr > maxptr)
		swap(minptr, maxptr);
	while(++minptr != maxptr)
	{
		between *= *minptr;
	}
	
	
	
	// output
	ofstream(OUTPUT_FILE_NAME) << positive << " " << between << flush;
	

	return 0;
}





// end
