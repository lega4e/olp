#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

int num, den;
string result;





// functions
void input()
{
	ifstream(INPUT_FILE_NAME) >> num >> den;
	return;
}

void output()
{
	ofstream(OUTPUT_FILE_NAME) << result;
	return;
}

void calculate(int num, int den, string &result)
{
	// preparation
	result.clear();
	typedef struct { int d, v; } Unit;

	vector< Unit >units{ {num, num/den} };
	vector< Unit >::const_iterator b;


	// loop
	int nextd = (num % den) * 10;
	if(nextd)
	{
loop:
		units.push_back( { nextd, nextd/den } );
		nextd = (nextd % den) * 10;
		b = find_if(
			units.cbegin(), units.cend(),
			[=](Unit const &u){ return u.d == nextd; }
		);
		if(b == units.cend() && nextd != 0)
			goto loop;
	}


	// output
	result += to_string( units.front().v );
	if(units.size() > 1)
	{
		result.push_back('.');
		for(auto bb = units.begin()+1; bb < b; ++bb)
		{
			result.push_back('0'+bb->v);
		}
		if(b != units.end())
		{
			result.push_back('(');
			do
				result.push_back('0'+b->v);
			while(++b != units.end());
			result.push_back(')');
		}
	}
}





// main
int main( int argc, char *argv[] )
{
	input();
	calculate(num, den, result);
	output();

	return 0;
}





// end
