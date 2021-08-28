#include <iostream>
#include <fstream>


using namespace std;





// structs
struct Point
{
	int x, y;
};





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	constexpr static int const N = 8;

	Point first, second;
	
	
	
	// input
	{
		ifstream fin(INPUT_FILE_NAME);
		char ch;

		// first
		if(!(fin >> ch))
			goto fail_input_label;
		first.x = ch-'A';


		if(!(fin >> ch))
			goto fail_input_label;
		first.y = ch-'1';


		if(!(fin >> ch) || ch != '-') // term
			goto fail_input_label;


		// second
		if(!(fin >> ch))
			goto fail_input_label;
		second.x = ch-'A';


		if(!(fin >> ch))
			goto fail_input_label;
		second.y = ch-'1';

	}

	

	// calculate
	if(
		first.x < 0 || first.x >= N || 
		first.y < 0 || first.y >= N ||
		second.x < 0 || second.x >= N ||
		second.y < 0 || second.y >= N
	)
	{
fail_input_label:
		ofstream(OUTPUT_FILE_NAME) << "ERROR" << flush;
		return 0;
	}

	int dx = abs(first.x - second.x);
	int dy = abs(first.y - second.y);
	if(
		(dx == 1 && dy == 2) ||
		(dx == 2 && dy == 1)
	)
		ofstream(OUTPUT_FILE_NAME) << "YES";
	else
		ofstream(OUTPUT_FILE_NAME) << "NO";




	return 0;
}





// end
