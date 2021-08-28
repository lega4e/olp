#include <algorithm>
#include <iostream>
#include <fstream>


using namespace std;





char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";


int toklen;
int *tokens;
int n;
int *vars;



void calculate_variants()
{
	vars[0] = 1;
	for(int i = 1; i < n+1; ++i)
	{
		vars[i] = 0;
		for(
			auto *b = tokens, *e = tokens+toklen;
			b != e && *b <= i; ++b
		)
		{
			vars[i] += vars[i-*b];
		}
	}
}




int main( int argc, char *argv[] )
{
	{
		ifstream fin(INPUT_FILE_NAME);

		// tokens
		fin >> toklen;
		tokens = new int[toklen];
		for(auto *b = tokens, *e = tokens+toklen; b != e; ++b)
		{
			fin >> *b;
		}
		sort(tokens, tokens+toklen);

		// n, vars
		fin >> n;
		vars = new int[n+1];
	}

	calculate_variants();

	cout << vars[n] << endl;
	

	return 0;
}





// end
