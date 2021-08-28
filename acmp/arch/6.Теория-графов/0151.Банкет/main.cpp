#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>


using namespace std;





// structs
struct AdjacList
{
	int n;
	std::vector<int> *l;


	// creation, destroy
	inline void init()
	{
		l = new std::vector<int>[n];
		return;
	}
	inline void free()
	{
		delete[] l;
		return;
	}


	// access
	inline std::vector<int> const &operator[](int i) const
	{
		return l[i];
	}
	inline std::vector<int> &operator[](int i)
	{
		return l[i];
	}


	// input, output streams
	void read_adjac_table(FILE *file)
	{
		fscanf(file, "%i", &n);
		init();
		read_data_adjac_table(file);
		return;
	}
	void read_data_adjac_table(FILE *file)
	{
		int buf;
		for(int y = 0; y < n; ++y)
		{
			for(int x = 0; x < n; ++x)
			{
				fscanf(file, "%i", &buf);
				if(buf)
					l[y].push_back(x);
			}
		}
		return;
	}
	void print(FILE *file) const
	{
		fprintf(file, "%i", n);
		for(auto *b = l, *e = l+n; b != e; ++b)
		{
			fprintf(file, "\n%lu", b->size());
			for(auto lb = b->begin(), le = b->end(); lb != le; ++lb)
			{
				fprintf(file, " %i", *lb);
			}
		}
		return;
	}
};





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

AdjacList adjl;
bool result;





// functions
void input()
{
	auto file = fopen(INPUT_FILE_NAME, "r");
	int pairc;
	fscanf(file, "%i%i", &adjl.n, &pairc);
	adjl.init();

	int first, second;
	for(int i = 0; i < pairc; ++i)
	{
		fscanf(file, "%i%i", &first, &second);
		--first;
		--second;
		adjl[first].push_back(second);
		adjl[second].push_back(first);
	}
	fclose(file);

	return;
}

void output()
{
	auto file = fopen(OUTPUT_FILE_NAME, "w");
	if(result)
		fprintf(file, "YES");
	else
		fprintf(file, "NO"); 
	fflush(file);
	fclose(file);
	return;
}

bool check_is_bipartite(
	AdjacList const &adjl, int what, int *groups
)
{
	for(auto i : adjl[what])
	{
		if( !groups[i] )
		{
			groups[i] = 3 - groups[what];
			if(!check_is_bipartite(adjl, i, groups))
				return false;
		}
		else if(groups[i] == groups[what])
			return false;
	}
	return true;
}

int *split_to_bipartite(AdjacList const &adjl)
{
	int *groups = new int[adjl.n];
	memset(groups, 0, sizeof *groups * adjl.n);

	int *checkwhat = groups;
	do
	{
		*checkwhat = 1;
		if( !check_is_bipartite( adjl, checkwhat-groups, groups ) )
		{
			delete[] groups;
			return nullptr;
		}
		checkwhat = find( groups, groups+adjl.n, 0 ); 
	}
	while( checkwhat != groups+adjl.n );

	return groups;
}

void calculate()
{
	int *groups = split_to_bipartite(adjl);
	if(groups)
	{
		result = true;
		delete[] groups;
	}
	else
		result = false;
	return;
}



// main
int main( int argc, char *argv[] )
{
	input();
	calculate();
	output();

	return 0;
}





// end
