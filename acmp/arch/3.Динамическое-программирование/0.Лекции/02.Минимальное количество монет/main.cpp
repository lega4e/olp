#include <iostream>
#include <fstream>


using namespace std;





char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";


int n;

int reslen;
int *result;

int toklen;
int *tokens;





void calculate()
{
	result[0] = 0;
	for(int i = 1; i < reslen; ++i)
	{
		result[i] = -1;
		for(auto *b = tokens, *e = tokens+toklen; b != e; ++b)
		{
			if( i-*b >= 0 )
			{
				if( result[i] == -1 || (result[i-*b] != -1 && result[i-*b] < result[i]) )
				{
					result[i] = result[i-*b];
				}
			}
		}

		if(result[i] != -1)
			++result[i];
	}

	return;

}





int main( int argc, char *argv[] )
{
	// read input
	{
		ifstream fin(INPUT_FILE_NAME);
		fin >> toklen;
		tokens = new int[toklen];
		for(auto *b = tokens, *e = tokens+toklen; b != e; ++b)
		{
			fin >> *b;
		}
		fin >> n;
		reslen = n+1;
		result = new int[reslen];
	}


	// calculate
	calculate();


	// output
	cout << result[n] << endl;

	return 0;
}





// end
