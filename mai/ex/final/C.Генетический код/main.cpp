#include <algorithm>
#include <iostream>
#include <vector>
#include <map>


using namespace std;





// main
int main( int argc, char *argv[] )
{
	map<string, char> map = {
		{ "UUU", 'F' }, { "CUU", 'L' }, { "AUU", 'I' }, { "GUU", 'V' },
		{ "UUC", 'F' }, { "CUC", 'L' }, { "AUC", 'I' }, { "GUC", 'V' },
		{ "UUA", 'L' }, { "CUA", 'L' }, { "AUA", 'I' }, { "GUA", 'V' },
		{ "UUG", 'L' }, { "CUG", 'L' }, { "AUG", 'M' }, { "GUG", 'V' },
		{ "UCU", 'S' }, { "CCU", 'P' }, { "ACU", 'T' }, { "GCU", 'A' },
		{ "UCC", 'S' }, { "CCC", 'P' }, { "ACC", 'T' }, { "GCC", 'A' },
		{ "UCA", 'S' }, { "CCA", 'P' }, { "ACA", 'T' }, { "GCA", 'A' },
		{ "UCG", 'S' }, { "CCG", 'P' }, { "ACG", 'T' }, { "GCG", 'A' },
		{ "UAU", 'Y' }, { "CAU", 'H' }, { "AAU", 'N' }, { "GAU", 'D' },
		{ "UAC", 'Y' }, { "CAC", 'H' }, { "AAC", 'N' }, { "GAC", 'D' },
		{ "UAA",  0  }, { "CAA", 'Q' }, { "AAA", 'K' }, { "GAA", 'E' },
		{ "UAG",  0  }, { "CAG", 'Q' }, { "AAG", 'K' }, { "GAG", 'E' },
		{ "UGU", 'C' }, { "CGU", 'R' }, { "AGU", 'S' }, { "GGU", 'G' },
		{ "UGC", 'C' }, { "CGC", 'R' }, { "AGC", 'S' }, { "GGC", 'G' },
		{ "UGA",  0  }, { "CGA", 'R' }, { "AGA", 'R' }, { "GGA", 'G' },
		{ "UGG", 'W' }, { "CGG", 'R' }, { "AGG", 'R' }, { "GGG", 'G' }
	};



	// solve
	char ch;
	int c;
	string input;
	char val;

	while(true)
	{
		// input
		c = 0;
		input.clear();
		while( c < 3 && isupper((ch = getchar())) )
			input.push_back(ch),
			++c;
		if(!isupper(ch))
			break;


		// output
		val = map[input];
		if(val)
			putchar(val);
		else
			break;
	}
	printf("\n");



	return 0;
}





// end
