#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <fstream>


using namespace std;





char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





void summation(
	char const *lhsbeg, char const *lhsend,
	char const *rhsbeg, char const *rhsend,
	char *desteny
)
{
	int shift = 0;
	int summ;

	while(lhsbeg != lhsend && rhsbeg != rhsend)
	{
		summ = (int)*lhsbeg + (int)*rhsbeg + shift;
		shift = summ/10;
		summ %= 10;
		*desteny = summ;

		++lhsbeg;
		++rhsbeg;
		++desteny;
	}

	if(lhsbeg == lhsend)
	{
		lhsbeg = rhsbeg;
		lhsend = rhsend;
	}

	while(lhsbeg != lhsend)
	{
		summ = (int)*lhsbeg + shift;
		shift = summ/10;
		summ %= 10;
		*desteny = summ;

		++desteny;
		++lhsbeg;
	}

	if(shift != 0)
		*desteny = shift;

	return;
}



int main( int argc, char *argv[] )
{
	int resultn;
	char *result;
	string first, second;

	// read input
	{
		ifstream(INPUT_FILE_NAME) >> first >> second;

		// first
		reverse( first.begin(), first.end() );
		for(auto b = first.begin(), e = first.end(); b != e; ++b)
		{
			*b -= '0';
		}

		// second
		reverse( second.begin(), second.end() );
		for(auto b = second.begin(), e = second.end(); b != e; ++b)
		{
			*b -= '0';
		}

		// result
		resultn = max( first.size(), second.size() ) + 1;
		result = new char[ resultn ];
		memset(result, 0, sizeof(*result)*resultn);
	}

	summation(
		first.data(), first.data() + first.size(),
		second.data(), second.data() + second.size(),
		result
	);

	{
		char const *resrbeg = result+resultn-1;

		// pass zero
		while(*resrbeg == 0 && resrbeg != result)
			--resrbeg;

		// output
		ofstream fout(OUTPUT_FILE_NAME);
		while(resrbeg != result-1)
		{
			fout << (int)*resrbeg;
			--resrbeg;
		}
		fout << flush;
	}



	return 0;
}





// end
