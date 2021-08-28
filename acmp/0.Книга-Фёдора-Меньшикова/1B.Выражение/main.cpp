#include <cmath>
#include <iostream>
#include <iterator>
#include <fstream>
#include <utility>


using namespace std;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

unsigned int n;
int s;

typedef std::pair<char, int> term_type;
term_type *x;





// funcitons
bool find_sign_solution(
	term_type *beg, term_type *end, int summ
)
{
	// if size of seq == 1
	if( next(beg) == end )
	{
		if(beg->second == summ)
		{
			beg->first = '+';
			return true;
		}
		else if(-beg->second == summ)
		{
			beg->first = '-';
			return true;
		}
		return false;
	}


	// assert for optimization
	int realsumm = 0;
	for(auto *b = beg; b != end; ++b)
	{
		realsumm += b->second;
	}

	if(realsumm < abs(summ))
		return false;

	
	// try + and -
	if( find_sign_solution(
		next(beg), end, summ- beg->second
	) )
	{
		beg->first = '+';
		return true;
	}
	else if( find_sign_solution(
		next(beg), end, summ + beg->second
	) )
	{
		beg->first = '-';
		return true;
	}

	return false;
}





int main( int argc, char *argv[] )
{
	{
		ifstream fin(INPUT_FILE_NAME);
		fin >> n >> s;
		x = new term_type[n];

		for(auto *b = x, *e = x+n; b != e; ++b)
		{
			b->first = '+';
			fin >> b->second;
		}
	}

	{
		if(!find_sign_solution( x+1, x+n, s-x->second ))
		{
			ofstream(OUTPUT_FILE_NAME) << "No solution" << flush;
		}
		else
		{
			ofstream fout(OUTPUT_FILE_NAME);
			fout << x->second;
			for(auto *b = next(x), *e = x+n; b != e; ++b)
			{
				fout << b->first << b->second;
			}
			fout << '=' << s << flush;
		}


	}
	delete[] x;

	return 0;
}





// end
