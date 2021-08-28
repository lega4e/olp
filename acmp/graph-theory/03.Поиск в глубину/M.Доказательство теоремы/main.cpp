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
		
		int inp;
		fscanf(file, "%i", &inp);
		adjl.ribs.resize(inp);

		for(auto b = adjl.ribs.begin(), e = adjl.ribs.end(); b != e; ++b)
		{
			while(true)
			{
				fscanf(file, "%i", &inp);
				if(!inp)
					break;
				b->push_back(inp-1);
			}
		}

		fclose(file);
	}
	
	
	
	// solve
	stack<int> vers;
	vector<int> marks(adjl.n(), 0);

	marks[0] = 1;
	vers.push(0);

	int v;
	while(!vers.empty())
	{
		v = vers.top();
		if(v < 0)
		{
			v = -v-1;
			vers.pop();
			marks[v] = 1;

			sort(
				adjl[v].begin(), adjl[v].end(),
				[&](int lhs, int rhs)->bool {
					return marks[lhs] < marks[rhs];
				}
			);

			for(auto b = adjl[v].begin(), e = adjl[v].end() - adjl[v].size()/2; b != e; ++b)
				marks[v] += marks[*b];
			continue;
		}

		vers.top() = -v-1;
		for(auto b = adjl[v].begin(), e = adjl[v].end(); b != e; ++b)
			vers.push(*b);
	}
	
	
	
	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		fprintf(file, "%i\n", marks[0]);

		vers.push(0);
		while(!vers.empty())
		{
			v = vers.top();
			if(v < 0)
			{
				vers.pop();
				fprintf(file, "%i\n", -v);
				continue;
			}

			vers.top() = -v-1;
			for(auto b = adjl[v].begin(), e = adjl[v].end() - adjl[v].size()/2; b != e; ++b)
				vers.push(*b);
		}

		fclose(file);
	}



	return 0;
}





// end
