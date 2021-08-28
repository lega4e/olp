#include <iostream>
#include <fstream>
#include <vector>


using namespace std;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

vector< int > seq;

ofstream fout;




// procedures
void write()
{
	if(seq.empty())
		return;

	fout << seq.front();
	for(auto b = seq.begin()+1, e = seq.end(); b != e; ++b)
	{
		fout << '+' << *b;
	}
	fout << '\n';

	return;
}


void process(int n, int eqless)
{
	if(n == 0)
	{
		write();
		return;
	}

	seq.push_back(0);
	for( int i = min(eqless, n); i > 0; --i )
	{
		seq.back() = i;
		process(n-i, i);
	}
	seq.pop_back();

	return;
}





// main
int main( int argc, char *argv[] )
{
	int n;
	ifstream(INPUT_FILE_NAME) >> n;
	fout.open(OUTPUT_FILE_NAME);

	process(n, n-1);

	return 0;
}





// end
