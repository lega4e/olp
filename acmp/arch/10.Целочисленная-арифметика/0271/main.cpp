#include <iostream>
#include <fstream>
#include <tuple>


using namespace std;





// types
typedef unsigned long long ullong;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// functions
int calculate(ullong fib)
{
	ullong first = 1, second = 1;
	int counter = 1;

loop:
	if(fib == first)
		return counter;
	if(fib > first)
	{
		++counter;
		tie(first, second) = make_tuple(second, first+second);
		goto loop;
	}
	return -1;
}





// main
int main( int argc, char *argv[] )
{
	ullong fib;
	ifstream(INPUT_FILE_NAME) >> fib;

	int answer = calculate(fib);

	if(answer < 0)
		ofstream(OUTPUT_FILE_NAME) << 0 << flush;
	else
		ofstream(OUTPUT_FILE_NAME) << 1 << '\n' << answer << flush;

	return 0;
}





// end
