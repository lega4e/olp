#include <algorithm>
#include <cstdio>


using namespace std;





// structs
struct Field
{
	int n;
	int *d;

	inline void init()
	{
		d = new int[n*n];
	}
	inline void free()
	{
		delete[] d;
	}

	inline int const &at(int x, int y) const
	{
		return d[ y*n + x ];
	}
	inline int &at(int x, int y)
	{
		return d[ y*n + x ];
	}
};





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	Field f;
	
	
	
	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i", &f.n);
		f.init();
		for(auto *b = f.d, *e = f.d+f.n*f.n; b != e; ++b)
		{
			fscanf(file, "%i", b);
		}
		fclose(file);
	}
	
	
	
	// calculate
	int result = f.at(0, 1) + f.at(1, 2) + f.at(2, 0);
	// printf("result: %i\n", result);
	for(int i = 0; i < f.n; ++i)
	{
		for(int j = i+1; j < f.n; ++j)
		{
			for(int k = j+1; k < f.n; ++k)
			{
				result = min(
					result,
					f.at(i, j) + f.at(j, k) + f.at(k, i)
				);
				// printf("result: %i\n", result);
			}
		}
	}
	
	
	
	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		fprintf(file, "%i", result);
		// printf("%i\n", result);
		// for(int y = 0; y < f.n; ++y)
		// {
			// for(int x = 0; x < f.n; ++x)
			// {
				// printf("%i\t", f.at(x, y));
			// }
			// printf("\n");
		// }
	}

	

	return 0;
}





// end
