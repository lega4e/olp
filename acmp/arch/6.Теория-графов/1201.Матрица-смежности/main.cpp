#include <cstdio>
#include <utility>
#include <vector>


using namespace std;





// structs
typedef pair<int, int> link_type;




// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

int n;
vector< link_type > links;





// functions
void inputcalc()
{
	links.clear();

	auto file = fopen(INPUT_FILE_NAME, "r");
	fscanf(file, "%i", &n);

	int buf;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			fscanf(file, "%i", &buf);
			if(buf)
			{
				links.push_back({i, j});
			}
		}
	}

	return;
}

void output()
{
	auto file = fopen(OUTPUT_FILE_NAME, "w");
	fprintf(file, "%i %lu\n", n, links.size());
	for(auto b = links.begin(), e = links.end(); b != e; ++b)
	{
		fprintf(file, "%i %i\n", b->first+1, b->second+1);
	}
	return;
}





// main
int main( int argc, char *argv[] )
{
	inputcalc();
	output();

	return 0;
}





// end
