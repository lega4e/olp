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
	int last;
	int *arr;
	
	
	
	// input
	{
		ifstream fin(INPUT_FILE_NAME);
		fin >> n;
		last = n-1;
		arr = new int[n];
		fin >> arr[last];
		fin.close();
		for(auto *b = arr, *e = arr+n-1; b != e; ++b)
		{
			*b = -1;
		}
	}
	
	
	
	// calculate
	if( last == 2 )
	{
		arr[0] = arr[last];
		arr[1] = 0;
	}
	else if( last == 3 )
	{
		if(arr[3] <= 3)
		{
			arr[0] = arr[3];
			arr[1] = 0;
			arr[2] = arr[3];
		}
		else
		{
			arr[1] = arr[3] % 3 == 0 ?
				arr[3]/3 - 1 : arr[3]/3;
			arr[2] = arr[3] - arr[1];
			arr[0] = arr[2] - arr[1];
		}
	}


	return 0;
}





// end
