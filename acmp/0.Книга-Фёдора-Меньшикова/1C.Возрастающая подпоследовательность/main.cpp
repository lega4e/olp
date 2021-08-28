#include <algorithm>
#include <iostream>
#include <fstream>


using namespace std;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

int n;
int *seq;
int *seql;
int *seqprev;





// functions
void calculate_seql()
{
	int max;
	for(int i = 0; i < n; ++i)
	{
		// found max subsequence
		max = -1;
		for(int j = 0; j < i; ++j)
		{
			if(
				seq[j] < seq[i] &&
				( max == -1 || seql[j] > seql[max] )
			)
			{
				max = j;
			}
		}

		// if not found
		if(max == -1)
		{
			seql[i] = 1;
			seqprev[i] = -1;
		}
		// if found
		else
		{
			seql[i] = seql[max] + 1;
			seqprev[i] = max;
		}

	}
}





int main( int argc, char *argv[] )
{
	// read input data
	{
		ifstream fin(INPUT_FILE_NAME);
		fin >> n;
		seq = new int[n];
		seql = new int[n];
		seqprev = new int[n];
		for(auto *b = seq, *e = seq+n; b != e; ++b)
		{
			fin >> *b;
		}
	}


	// calculate
	calculate_seql();

	int next = max_element( seql, seql+n ) - seql;
	int resseqsize = seql[next];
	int *resseq = new int[ resseqsize ];

	for(int i = resseqsize-1; i >= 0; --i)
	{
		resseq[i] = seq[next];
		next = seqprev[next];
	}


	// output
	{
		ofstream fout(OUTPUT_FILE_NAME);
		fout << resseqsize << '\n';
		for(auto *b = resseq, *e = resseq+resseqsize; b != e; ++b)
		{
			fout << *b << ' ';
		}
		fout << flush;
	}



	// free
	delete[] seq;
	delete[] seql;
	delete[] seqprev;

	return 0;
}





// end
