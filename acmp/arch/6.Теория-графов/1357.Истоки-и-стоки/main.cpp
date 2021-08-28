#include <cstdio>
#include <set>


using namespace std;





// structs
struct AdjacTable
{
	int n;
	int *d;



	// creation, destroy
	inline void init()
	{
		d = new int[n*n];
		return;
	}
	inline void free()
	{
		delete[] d;
		return;
	}



	// acess
	int *operator[](int y)
	{
		return d + y*n;
	}
	int const *operator[](int y) const
	{
		return d + y*n;
	}



	// input, output streams
	void read(FILE *file)
	{
		fscanf(file, "%i", &n);
		init();
		for(auto *b = d, *e = d+n*n; b != e; ++b)
		{
			fscanf(file, "%i", b);
		}
		return;
	}
};





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

AdjacTable adjt;
set<int> source, drain;





// functions
void input()
{
	auto file = fopen(INPUT_FILE_NAME, "r");
	adjt.read(file);
	fclose(file);
	return;
}

void output()
{
	auto file = fopen(OUTPUT_FILE_NAME, "w");

	// source
	fprintf(file, "%lu ", source.size());
	for(auto b = source.begin(), e = source.end(); b != e; ++b)
	{
		fprintf(file, "%i ", *b+1);
	}

	// drain
	fprintf(file, "\n%lu ", drain.size());
	for(auto b = drain.begin(), e = drain.end(); b != e; ++b)
	{
		fprintf(file, "%i ", *b+1);
	}

	fflush(file);
	fclose(file);
	return;
}

void calculate()
{
	// drain
	for(int y = 0; y < adjt.n; ++y)
	{
		for(int x = 0; x < adjt.n; ++x)
		{
			if(adjt[y][x])
				goto is_not_drain_label;
		}
		drain.insert(y);
is_not_drain_label:;
	}

	// source
	for(int x = 0; x < adjt.n; ++x)
	{
		for(int y = 0; y < adjt.n; ++y)
		{
			if(adjt[y][x])
				goto is_not_source_label;
		}
		source.insert(x);
is_not_source_label:;
	}

	return;
}





// main
int main( int argc, char *argv[] )
{
	input();
	calculate();
	output();
	adjt.free();

	return 0;
}





// end
