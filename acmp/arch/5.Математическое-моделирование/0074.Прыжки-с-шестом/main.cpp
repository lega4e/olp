#include <cmath>
#include <iostream>
#include <fstream>


using namespace std;





char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// function
int calculate_number(int n, int m)
{
	if(m % 2 == 0)
	{
		return m/2;
	}

	if(n == 1)
	{
		return 1;
	}

	return n/2 + calculate_number(
		n % 2 == 0 ? n/2 : n/2+1,
		m - m/2
	);
}





// main
int main( int argc, char *argv[] )
{
	// read input
	int n, m;
	ifstream(INPUT_FILE_NAME) >> n >> m;

	// calculate
	int const result = calculate_number(n, m);
	
	// output
	ofstream(OUTPUT_FILE_NAME) << result << flush;


	return 0;
}





// end
