#include <algorithm>
#include <cstdio>
#include <cstring>


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
	
	
	
	// init
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i", &f.n);
		f.init();
		memset( f.d, 0, sizeof *f.d * f.n * f.n );
		for(int x = 0, y = 0; x < f.n; ++x, ++y)
		{
			fscanf(file, "%i", f.d + y*f.n + x);
		}
	}
	
	
	
	// calculate
	{
		int player = f.n % 2 == 0 ? 1 : 2;
		for(int yy = 1; yy < f.n; ++yy)
		{
			for(int x = 0, y = yy; y < f.n; ++x, ++y)
			{
				if(player == 1)
				{
					f.at(x, y) = max(
						f.at(x, y-1), f.at(x+1, y)
					);
				}
				else
				{
					f.at(x, y) = min(
						f.at(x, y-1), f.at(x+1, y)
					);
				}
			}
			if(player == 1)
				player = 2;
			else
				player = 1;
		}
		if(player != 2)
			throw "invalid definition of player";
	}
	
	
	
	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		fprintf(file, "%i", f.at(0, f.n-1));
		fflush(file);
		fclose(file);
	}
	
	
	
	// free
	f.free();

	

	return 0;
}





// end
