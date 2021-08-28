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
		return;
	}
	inline void free()
	{
		delete[] d;
		return;
	}

	inline int const *operator[](int y) const
	{
		return d + y*n;
	}
	inline int *operator[](int y)
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
	int edgec;

	auto file = fopen(INPUT_FILE_NAME, "r");
	fscanf(file, "%i%i", &f.n, &edgec);
	f.init();
	memset(f.d, 0, sizeof *f.d * f.n * f.n);

	int first, second;
	for(int i = 0; i < edgec; ++i)
	{
		fscanf(file, "%i%i", &first, &second);
		--first;
		--second;
		f[first][second] = 1;
		f[second][first] = 1;
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
			if(!f[y][x])
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
