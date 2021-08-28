#include <algorithm>
#include <cstdio>
#include <cstring>
#include <list>
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
	void read_edge_list(FILE *file)
	{
		int edgec;
		fscanf(file, "%i%i", &n, &edgec);
		init();

		int first, second;
		for(int i = 0; i < edgec; ++i)
		{
			fscanf(file, "%i%i", &first, &second);
			--first;
			--second;
			l[first].push_back(second);
			l[second].push_back(first);
		}
		return;
	}
};





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

AdjacList adjl;
int *components;





// functions
void input()
{
	return;
}

void output()
{
	int comc = *max_element( components, components+adjl.n );
	int *counts = new int[comc];
	memset(counts, 0, sizeof *counts * comc);

	for(auto *b = components, *e = components+adjl.n; b != e; ++b)
	{
		++counts[*b-1];
	}

	auto file = fopen(OUTPUT_FILE_NAME, "w");
	fprintf(file, "%i\n", comc);
	for(int i = 0; i < comc; ++i)
	{
		fprintf(file, "%i\n", counts[i]);
		for(auto *b = components, *e = components+adjl.n; b != e; ++b)
		{
			if(*b == i+1)
				fprintf(file, "%li ", b-components+1);
		}
		fprintf(file, "\n");
	}

	fflush(file);
	fclose(file);
	return;
}

void calculate()
{
	components = new int[adjl.n];
	memset(components, 0, sizeof *components * adjl.n);

	int *it = components;
	int current;
	int where = 1;
	list<int> ways;
	while(
		(it = find(it, components+adjl.n, 0)) !=
		components+adjl.n
	)
	{
		ways.push_back(it-components);
		components[it-components] = where;
		while(!ways.empty())
			for(auto b = ways.begin(), e = ways.end(); b != e;)
			{
				for(auto i : adjl[*b])
				{
					if( !components[i] )
					{
						components[i] = where;
						ways.push_front(i);
					}
				}
				ways.erase(b++);
			}
		++where;
	}
	return;
}





// main
int main( int argc, char *argv[] )
{
	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		adjl.read_edge_list(file);
		fclose(file);
	}

	// calculate
	components = new int[adjl.n];
	memset(components, 0, sizeof *components * adjl.n);

	int *it = components;
	int current;
	int where = 1;
	list<int> ways;
	while(
		(it = find(it, components+adjl.n, 0)) !=
		components+adjl.n
	)
	{
		ways.push_back(it-components);
		components[it-components] = where;
		current = 1;
		while(!ways.empty())
			for(auto b = ways.begin(), e = ways.end(); b != e;)
			{
				for(auto i : adjl[*b])
				{
					if( !components[i] )
					{
						components[i] = where;
						++current;
						ways.push_front(i);
					}
				}
				ways.erase(b++);
			}
		++where;
	}


	output();

	adjl.free();
	delete[] components;
	return 0;
}





// end
