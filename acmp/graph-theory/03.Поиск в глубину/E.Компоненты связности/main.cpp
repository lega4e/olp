#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

#include "../AdjacList.cpp"


using namespace std;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	AdjacList adjl;
	
	
	
	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		adjl.scan_riblist1(file);
		fclose(file);
	}
	
	
	
	// solve
		// objects
	stack<int> vers;
	vector<bool> marks(adjl.n(), 0);
	vector< vector<int> > comps;

		// dfs
	int v;
	for(int i = 0; i < adjl.n(); ++i)
	{
		if(marks[i])
			continue;

		marks[i] = true;
		comps.push_back( { i } );

		vers.push(i);
		while(!vers.empty())
		{
			v = vers.top();
			vers.pop();

			for(auto b = adjl[v].begin(), e = adjl[v].end(); b != e; ++b)
			{
				vers.push(*b);
				comps.back().push_back(*b);
				marks[*b] = true;
			}
		}
	}

		// sort
	sort(
		comps.begin(), comps.end(),
		[](vector<int> const &lhs, vector<int> const &rhs)->bool {
			return lhs.size() < rhs.size();	
		}
	);
	for(auto b = comps.begin(), e = comps.end(); b != e; ++b)
		sort( b->begin(), b->end() );
	
	
	
	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		fprintf(file, "%i\n", (int)comps.size());
		for(auto b = comps.begin(), e = comps.end(); b != e; ++b)
		{
			fprintf(file, "%i\n", (int)b->size());
			for(auto bb = b->begin(), ee = b->end(); bb != ee; ++bb)
				fprintf(file, "%i ", *bb);
			fprintf(file, "\n");
		}
		fclose(file);
	}
	



	return 0;
}





// end
