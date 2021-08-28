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

AdjacList adjt;
unsigned char *was;
bool result;





// functions
void input()
{
	auto file = fopen(INPUT_FILE_NAME, "r");
	adjt.read_adjac_table(file);
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

bool add_in_was(int from, int i)
{
	if( was[i] )
		return false;
	was[i] = 1;
	for(auto v : adjt[i])
	{
		if(
			v != from &&
			!add_in_was(i, v)
		)
			return false;
	}
	return true;
}

void calculate()
{
	was = new unsigned char[adjt.n];
	memset( was, 0, sizeof *was * adjt.n );

	if(!add_in_was(-1, 0))
	{
		result = false;
		return;
	}

	if( (int)count(was, was+adjt.n, 1) != adjt.n )
	{
		result = false;
		return;
	}

	result = true;
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
