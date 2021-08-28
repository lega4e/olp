#include <iostream>
#include <fstream>


using namespace std;





// types
typedef unsigned long long int ullong;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// functions
ullong calculate_c(ullong m, ullong n)
{
	ullong result = n;
	for(ullong i = n-1; i != n-m; --i)
		result *= i;
	for(ullong i = 2; i <= m; ++i)
		result /= i;
	return result;
}





// main
int main( int argc, char *argv[] )
{
	int n;
	
	
	
	// input
	ifstream(INPUT_FILE_NAME) >> n;
	
	
	
	// calculate
	ullong result;
	if(n == 1)
		result = 0;
	else
	{
		result = 1;
		for(int i = 2; i < n; ++i)
			result += calculate_c(i, n);
	}
	
	
	
	// output
	cout << result << endl;
	ofstream(OUTPUT_FILE_NAME) << result << flush;
	
	

	return 0;
}





// end
