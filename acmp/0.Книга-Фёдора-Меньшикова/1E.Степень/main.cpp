#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;





char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





int multiplication(
	char const *lhsbeg, char const *lhsend, 
	char const *rhsbeg, char const *rhsend,
	char *desteny
)
{
	char buf;
	int pos = 0;
	int lastpos = 0;
	for(; lhsbeg != lhsend; ++lhsbeg)
	{
		for(char const *rhsb = rhsbeg; rhsb != rhsend; ++rhsb)
		{
			buf = *lhsbeg * *rhsb;

			for(int bpos = pos; true; ++bpos)
			{
				desteny[bpos] += buf;
				lastpos = bpos;
				if(desteny[bpos] > 9)
				{
					buf = desteny[bpos]/10;
					desteny[bpos] %= 10;
				}
				else
					break;
			}
			++pos;
		}
		pos -= rhsend-rhsbeg;
		++pos;
	}
	return lastpos;
}





int main( int argc, char *argv[] )
{
	// read
	int a, n;
	char input, *current, *output;

	{
		ifstream(INPUT_FILE_NAME) >> a >> n;
	}
	input = a;
	current = new char[n];
	current[0] = input;
	output = new char[n];

	int len = 1;
	int curpower = 1;
	while(curpower*2 <= n)
	{
		memset(output, 0, sizeof(char)*n);
		len = 1+multiplication(
			current, current+len,
			current, current+len,
			output
		);
		curpower *= 2;
		swap(current, output);
	}
	while(curpower < n)
	{
		memset(output, 0, sizeof(char)*n);
		len = 1+multiplication(
			&input, &input+1,
			current, current+len,
			output
		);
		++curpower;
		swap(current, output);
	}


	// print
	ofstream fout(OUTPUT_FILE_NAME);
	bool isstart = true;
	for(auto *b = current+n-1, *e = current-1; b != e; --b)
	{
		if(*b == 0 && isstart);
		else {
			fout << (int)*b;
			isstart = false;
		}
	}
	fout << flush;

	delete[] current;
	delete[] output;
	return 0;
}





// end
