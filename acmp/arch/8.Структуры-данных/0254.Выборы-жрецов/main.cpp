#include <iostream>
#include <fstream>


using namespace std;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	struct Pair{ int cur; bool change; };

	int n;
	Pair *graphs;
	
	
	
	// input&calc
	{
		ifstream fin(INPUT_FILE_NAME);
		fin >> n;
		graphs = new Pair[n];
		for(auto *b = graphs, *e = graphs+n; b != e; ++b)
		{
			fin >> b->cur;
			b->change = false;
		}

		int requestc;
		fin >> requestc;
		int from, where;
		for(int i = 0; i < requestc; ++i)
		{
			fin >> from >> where;
			for(auto *b = graphs, *e = graphs+n; b != e; ++b)
			{
				if(b->cur == from && !b->change)
					*b = { where, true };
			}
		}
	}
	
	
	
	// output
	{
		ofstream fout(OUTPUT_FILE_NAME);
		for(auto *b = graphs, *e = graphs+n; b != e; ++b)
		{
			fout << b->cur << ' ';
		}
	}
	

	return 0;
}





// end
