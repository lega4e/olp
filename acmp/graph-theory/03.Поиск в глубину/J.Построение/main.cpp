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
again:
	while(!vers.empty())
	{
		v = vers.top();
		if(v < 0)
		{
			v = -(v+1);
			marks[v] = 1;
			vers.pop();
			continue;
		}
		vers.top() = -(v+1);
		marks[v] = 2;

		for(auto b = adjl[v].begin(), e = adjl[v].end(); b != e; ++b)
		{
			if(marks[*b] == 1)
				continue;

			if(marks[*b] == 2)
			{
				res = false;
				goto output_label;
			}

			marks[*b] = 1;
			vers.push(*b);
		}
	}
	
	for(; it < (int)marks.size(); ++it)
	{
		if(marks[it] == 2)
			throw 1;
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
