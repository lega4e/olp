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

	int const *operator[](int y) const
	{
		return d + y*n;
	}
	int *operator[](int y)
	{
		return d + y*n;
	}

};





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

Field f;
bool result;





// functions
void input()
{
	auto file = fopen(INPUT_FILE_NAME, "r");
	fscanf(file, "%i", &f.n);
	f.init();

	for(auto *b = f.d, *e = f.d+f.n*f.n; b != e; ++b)
	{
		fscanf(file, "%i", b);
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
	for(int yy = 1; yy < f.n; ++yy)
	{
		for(int x = 0, y = yy; y < f.n; ++x, ++y)
		{
			if(f[y][x] != f[x][y])
				goto success_label;
		}
	}
	result = false;
	return;


success_label:

	for(int d = 0; d < f.n; ++d)
	{
		if(f[d][d])
		{
			result = false;
			return;
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
