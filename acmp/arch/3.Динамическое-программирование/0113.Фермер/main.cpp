#include <algorithm>
#include <cstdio>
#include <cctype>


using namespace std;





// structs
struct Field
{
	int n;
	int *d;

	void init()
	{
		d = new int[n*n];
		return;
	}
	void free()
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
int result;





// functions
void input()
{
	auto file = fopen(INPUT_FILE_NAME, "r");
	fscanf(file, "%i", &f.n);
	f.init();
	char ch;
	for(auto *b = f.d, *e = f.d+f.n*f.n; b != e;)
	{
		ch = getc(file);
		if(isspace(ch))
			continue;
		*b = ch == '1';
		++b;
	}
	fclose(file);
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

bool check_horizontal(int x, int y, int len)
{
	while(len)
	{
		if(!f[y][x])
			return false;
		++x;
		--len;
	}
	return !len;
}

bool check_vertical(int x, int y, int len)
{
	while(len)
	{
		if(!f[y][x])
			return false;
		++y;
		--len;
	}
	return !len;
}

int calcmaxfrom(int x, int y)
{
	int res = 0;
	while(
		x+res < f.n && y+res < f.n &&
		check_vertical(x+res, y, res+1) &&
		check_horizontal(x, y+res, res)
	)
	{
		++res;
	}
	return res;
}

void calculate()
{
	result = 0;
	for(int y = 0; y < f.n-result; ++y)
	{
		for(int x = 0; x < f.n-result; ++x)
		{
			result = max( result, calcmaxfrom(x, y) );
		}
	}
	result *= result;
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
