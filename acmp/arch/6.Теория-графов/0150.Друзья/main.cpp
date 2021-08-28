#include <cstdio>
#include <set>

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
	void read_data(FILE *file)
	{
		for(auto *b = d, *e = d+n*n; b != e; ++b)
		{
			fscanf(file, "%i", b);
		}
		return;
	}
};


using namespace std;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

AdjacTable adjt;
int human;
set<int> friends;
int result;





// functions
void input()
{
	auto file = fopen(INPUT_FILE_NAME, "r");
	fscanf(file, "%i%i", &adjt.n, &human);
	--human;
	adjt.init();
	adjt.read_data(file);
	return;
}

void output()
{
	auto file = fopen(OUTPUT_FILE_NAME, "w");
	fprintf(file, "%i", result);
	fflush(file);
	fclose(file);
	return;
}

void add_friend(int fr)
{
	auto it = friends.find(fr);
	if(it != friends.end())
		return;
	friends.insert(fr);
	for(int x = 0; x < adjt.n; ++x)
	{
		if(adjt[fr][x])
		{
			add_friend(x);
		}
	}
	return;
}

void calculate()
{
	add_friend(human);
	result = friends.size()-1;
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
