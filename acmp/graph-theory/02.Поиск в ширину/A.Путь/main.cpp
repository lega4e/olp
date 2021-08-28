#include <iostream>
#include <queue>
#include <vector>

#include "../AdjacList.cpp"


using namespace std;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// functions
int bfs_length(AdjacList const &adjl, int beg, int end)
{
	if(beg == end)
		return 0;

	queue<int> que;
	que.push(beg);

	vector<char> marks(adjl.n(), 0);
	marks[beg] = 1;

	int cur;
	while(!que.empty())
	{
		cur = que.front();
		for(auto b = adjl[cur].begin(), e = adjl[cur].end(); b != e; ++b)
		{
			if(*b == end)
				return marks[cur];
			if(!marks[*b])
			{
				marks[*b] = marks[cur] + 1;
				que.push(*b);
			}
		}
		que.pop();
	}

	return -1;
}





// main
int main( int argc, char *argv[] )
{
	AdjacList adjl;
	int beg, end;


	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		adjl.scan_matrix(file);
		fscanf(file, "%i%i", &beg, &end);
		--beg, --end;
		fclose(file);
	}


	// calculate
	int const result = bfs_length(adjl, beg, end);
	
	
	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		fprintf(file, "%i\n", result);
		fclose(file);
	}


	return 0;
}





// end
