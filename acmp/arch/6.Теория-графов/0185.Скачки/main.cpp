#include <cstdio>
#include <set>
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
};





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

int horse;
AdjacList adjl;
set<int> reachable;
bool result;





// functions
void input()
{
	auto file = fopen(INPUT_FILE_NAME, "r");
	fscanf(file, "%i%i", &adjl.n, &horse);
	--horse;
	adjl.init();


	int first, second;
loop:
	fscanf(file, "%i", &first);
	if(first)
	{
		fscanf(file, "%i", &second);
		--first;
		--second;

		adjl[ first ].push_back(second);
		goto loop;
	}

	fclose(file);
	return;
}

void output()
{
	auto file = fopen(OUTPUT_FILE_NAME, "w");
	if(result)
		fprintf(file, "Yes");
	else
		fprintf(file, "No");
	fflush(file);
	fclose(file);
	return;
}

void add_in_reachable(int vertex)
{
	set<int>::const_iterator it;
	for(
		auto
			b = adjl[ vertex ].begin(),
			e = adjl[ vertex ].end();
		b != e; ++b
	)
	{
		it = reachable.find(*b);
		if(it == reachable.end())
		{
			reachable.insert(*b);
			add_in_reachable(*b);
		}
	}

	return;
}

void calculate()
{
	add_in_reachable(horse);
	result = ( (int)reachable.size() == adjl.n-1 );
	return;
}





// main
int main( int argc, char *argv[] )
{
	input();
	calculate();
	output();

	adjl.free();
	return 0;
}





// end
