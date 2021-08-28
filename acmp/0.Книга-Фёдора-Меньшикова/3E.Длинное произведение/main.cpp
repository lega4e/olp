#include <algorithm>
#include <cstring>
#include <iostream>
#include <fstream>


using namespace std;





char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";



void multiplication(
	char const *lhsbeg, char const *lhsend,
	char const *rhsbeg, char const *rhsend,
	char *output
)
{
	int shift;
	for(; lhsbeg != lhsend; ++lhsbeg)
	{
		shift = 0;
		for(auto *b = rhsbeg; b != rhsend; ++b)
		{
			*output += *lhsbeg * *b + shift;
			shift = *output / 10;
			*output %= 10;
			++output;
		}
		if(shift)
		{
			*output += shift;
		}
		output -= rhsend - rhsbeg;
		++output;
	}

	return;
}




int main( int argc, char *argv[] )
{
	// objects
	int reslen;
	char *res;
	string lhs, rhs;


	// read
	ifstream(INPUT_FILE_NAME) >> lhs >> rhs;


	// adjust
	reverse( lhs.begin(), lhs.end() );
	for(auto b = lhs.begin(), e = lhs.end(); b != e; ++b)
	{
		*b -= '0';
	}

	reverse( rhs.begin(), rhs.end() );
	for(auto b = rhs.begin(), e = rhs.end(); b != e; ++b)
	{
		*b -= '0';
	}

	// init
	reslen = lhs.size() + rhs.size();
	res = new char[ reslen ];
	memset(res, 0, sizeof *res * reslen);

	multiplication( 
		lhs.data(), lhs.data() + lhs.size(),
		rhs.data(), rhs.data() + rhs.size(),
		res
	);


	// output
	{
		char *resptr = res+reslen-1;
		while(*resptr == 0 && resptr != res)
			--resptr;
		ofstream fout(OUTPUT_FILE_NAME);
		while(resptr != res-1)
		{
			fout << (int)*resptr;
			--resptr;
		}
		fout << flush;
	}


	// free
	delete[] res;

	return 0;
}





// end
