#include <algorithm>
#include <cstring>
#include <iostream>
#include <iterator>
#include <fstream>
#include <list>


using namespace std;





char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";


int n;
char *str;
ofstream fout;

void write_permutation()
{
	for(auto *b = str, *e = str+n; b != e; ++b)
	{
		fout << *b;
	}
	fout << '\n';
	return;
}

void enumeration_permutation(
	char *seqbeg,
	char *seqend
)
{
	// end recurse
	if(seqend-seqbeg == 1)
	{
		write_permutation();
		return;
	}

	// create buffer
	char *buf = new char[ seqend-seqbeg ];
	char *bufend = buf;
	for(auto *b = seqbeg; b != seqend; ++b)
	{
		if(
			find(buf, bufend, *b) == bufend
		)
		{
			*bufend = *b;
			++bufend;
		}
	}

	// recurse
	char *it;
	enumeration_permutation(seqbeg+1, seqend);
	for(auto *b = buf+1; b != bufend; ++b)
	{
		it = find(
			seqbeg+1, seqend, *b
		);
		if(it == seqend)
			throw "skldj";

		swap(*seqbeg, *it);
		enumeration_permutation(seqbeg+1, seqend);
	}

	return;
}




int main( int argc, char *argv[] )
{
	{
		string bufstr;
		ifstream fin(INPUT_FILE_NAME);
		fin >> bufstr;
		n = bufstr.size();
		str = new char[n];
		memcpy(str, bufstr.data(), sizeof(*str)*n);
	}

	fout.open(OUTPUT_FILE_NAME);
	enumeration_permutation(str, str+n);

	return 0;
}





// end
