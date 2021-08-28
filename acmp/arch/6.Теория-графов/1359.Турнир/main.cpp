#include <cstdio>
#include <cstring>
#include <utility>

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
	inline void zero()
	{
		memset( d, 0, sizeof *d * n * n );
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
	void write(FILE *file) const
	{
		fprintf(file, "%i\n", n);
		for(int y = 0; y < n; ++y)
		{
			for(int x = 0; x < n; ++x)
			{
				fprintf(file, "%i ", operator[](y)[x]);
			}
			fprintf(file, "\n");
		}
		return;
	}
};


using namespace std;





// types
typedef pair<int, int> link_type;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

AdjacTable adjt;
bool result;





// functions
void input()
{
	int edgec;

	auto file = fopen(INPUT_FILE_NAME, "r");
	fscanf(file, "%i%i", &adjt.n, &edgec);
	adjt.init();
	adjt.zero();

	int first, second;
	for(int i = 0; i < edgec; ++i)
	{
		fscanf(file, "%i%i", &first, &second);
		--first;
		--second;
		adjt[first][second] = 1;
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

void calculate()
{
	for(int yy = 1; yy < adjt.n; ++yy)
	{
		for(int x = 0, y = yy; y < adjt.n; ++x, ++y)
		{
			if(adjt[y][x] + adjt[x][y] != 1)
			{
				result = false;
				return;
			}
		}
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

	return 0;
}





// end
