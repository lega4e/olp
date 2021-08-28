#include <cstdio>
#include <set>
#include <utility>


using namespace std;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	int n;
	set<pair<int, int>> links;
	int *colors;
	int result;
	
	
	
	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i", &n);

		int buf;
		for(int y = 0; y < n; ++y)
		{
			for(int x = 0; x < n; ++x)
			{
				fscanf(file, "%i", &buf);
				if(buf)
				{
					if(x < y)
						links.insert(make_pair(x, y));
					else
						links.insert(make_pair(y, x));
				}
			}
		}

		colors = new int[n];
		for(auto *b = colors, *e = colors+n; b != e; ++b)
		{
			fscanf(file, "%i", b);
		}
	}
	
	
	
	// calculate
	result = 0;
	for(auto b = links.begin(), e = links.end(); b != e; ++b)
	{
		if(colors[b->first] != colors[b->second])
			++result;
	}
	
	
	
	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		fprintf(file, "%i", result);
		fflush(file);
		fclose(file);
	}



	return 0;
}





// end
