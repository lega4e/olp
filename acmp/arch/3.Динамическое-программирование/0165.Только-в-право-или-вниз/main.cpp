#include <cstdio>
#include <map>


using namespace std;





// struct
struct Field
{
	int w, h; // sizes
	int *d; // values


	inline int trs(int x, int y) const
	{
		return y*w+x;
	}

	inline int const &at(int x, int y) const
	{
		return d[y*w + x];
	}
	
	inline int &at(int x, int y)
	{
		return d[y*w + x];
	}
};





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

map<int, int> ex;





// functions
int calculate(Field const &f, int x, int y)
{
	if(x == 0 && y == 0)
		return 1;

	int const key = f.trs(x, y);
	auto const it = ex.find(key);
	if(it != ex.end())
	{
		return it->second;
	}

	// look up
	int res = 0;
	for(int i = y-1; i >= 0; --i)
	{
		if(f.at(x, i) == y-i)
			res += calculate(f, x, i);
	}
	for(int i = x-1; i >= 0; --i)
	{
		if(f.at(i, y) == x-i)
			res += calculate(f, i, y);
	}

	ex[key] = res;
	return res;
}





int main( int argc, char *argv[] )
{
	Field f;


	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i%i", &f.h, &f.w);
		f.d = new int[ f.w*f.h ];
		for(int i = 0; i < f.w*f.h; ++i)
		{
			fscanf(file, "%i", f.d+i);
		}
		fclose(file);
	}


	// calculate
	int const res = calculate(f, f.w-1, f.h-1);


	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		fprintf(file, "%i", res);
		fflush(file);
		fclose(file);
	}
	

	return 0;
}





// end
