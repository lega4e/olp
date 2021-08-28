#include <iostream>
#include <stack>

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
		adjl.scan_riblist1(file, true);
		fclose(file);
	}
	
	
	
	// solve
	bool res = true;

	vector<int> marks(adjl.n(), 0);
	stack<int> vers;
	marks[0] = 1;
	vers.push(0);
	int it = 1;

	int v;
	vector<int> way;
	bool was;
again:
	way.clear();
	while(!vers.empty())
	{
		v = vers.top();
		vers.pop();
		way.push_back(v);

		was = false;
		for(auto b = adjl[v].begin(), e = adjl[v].end(); b != e; ++b)
		{
			if(marks[*b])
			{
				if( find( way.begin(), way.end(), *b ) != way.end() )
				{
					res = false;
					goto output_label;
				}
				continue;
			}

			was = true;
			marks[*b] = true;
			vers.push(*b);
		}

		if(!was)
			way.pop_back();
	}
	
	for(; it < (int)marks.size(); ++it)
	{
		if(!marks[it])
		{
			marks[it] = true;
			vers.push(it);
			goto again;
		}
	}
	
	
	
output_label:
	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		res ? fprintf(file, "Yes\n") : fprintf(file, "No\n");
		fclose(file);
	}



	return 0;
}





// end
