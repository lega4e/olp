#include <cmath>
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
		return;
	}
	inline void free()
	{
		delete[] d;
		return;
	}

	inline int const &at(int x, int y) const
	{
		static int const gost = 1;
		if(x < 0 || x >= n || y < 0 || y >= n)
			return gost;
		return d[ y*n + x];
	}
	inline int &at(int x, int y)
	{
		static int gost = 1;
		if(x < 0 || x >= n || y < 0 || y >= n)
		{
			gost = 1;
			return gost;
		}
		return d[ y*n + x];
	}
};





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

Field f;

	constexpr int const TRY[][4] = {
		{ 0, -1, -1, 0 },
		{ 0, -1, 1, 0 },
		{ 1, 0, 0, 1 },
		{ 0, 1, -1, 0 }
	};





// functions
void input()
{
	int n, x, y;

	auto file = fopen(INPUT_FILE_NAME, "r");
	fscanf(file, "%i%i%i", &n, &x, &y);
	fclose(file);

	f.n = pow(2, n);
	f.init();
	for(auto *b = f.d, *e = f.d+f.n*f.n; b != e; ++b)
	{
		*b = -1;
	}
	f.at(x-1, y-1) = 0;
	return;
}

void output()
{
	auto file = fopen(OUTPUT_FILE_NAME, "w");
	for(int y = 0; y < f.n; ++y)
	{
		for(int x = 0; x < f.n; ++x)
		{
			fprintf(file, "%i ", f.at(x, y));
		}
		fprintf(file, "\n");
	}

	return;
}

bool cell_is_correct(int x, int y)
{

	for(int i = 0; i < 4; ++i)
	{
		if(
			f.at( x+TRY[i][0], y + TRY[i][1] ) < 0 &&
			f.at( x+TRY[i][2], y + TRY[i][3] ) < 0
		)
			return true;
	}

	return false;
}

bool field_is_correct()
{
	for(int y = 0; y < f.n; ++y)
	{
		for(int x = 0; x < f.n; ++x)
		{
			if(
				f.at(x, y) < 0 &&
				!cell_is_correct(x, y)
			)
				return false;
		}
	}
	return true;
}

bool calculate(int x = 0, int y = 0, int number = 1)
{

	constexpr auto const next = [](int n, int &x, int &y)->bool
	{
		++x;
		if(x == n)
		{
			x = 0;
			++y;
			if(y == n)
				return false;
		}
		return true;
	};
	constexpr auto const prev = [](int n, int &x, int &y)->bool
	{
		--x;
		if(x == -1)
		{
			x = n-1;
			--y;
			if(y == -1)
				return false;
		}
		return true;
	};


	if(f.at(x, y) >= 0)
	{
		return (
				!next(f.n, x, y) ||
				calculate(x, y, number)
			) &&
			field_is_correct();
	}

	// printf("calculate(%i, %i, %i);\n", x, y, number);
	for(int i = 0; i < 4; ++i)
	{
		if(
			f.at( x+TRY[i][0], y + TRY[i][1] ) < 0 &&
			f.at( x+TRY[i][2], y + TRY[i][3] ) < 0
		)
		{
			// printf("set(%i, %i, %i);\n", x, y, i);
			f.at(x, y) = number;
			f.at( x+TRY[i][0], y + TRY[i][1] ) = number;
			f.at( x+TRY[i][2], y + TRY[i][3] ) = number;
			if(
				( !next(f.n, x, y) ||
				calculate(x, y, number+1) ) &&
				field_is_correct())
			{
				return true;
			}
			prev(f.n, x, y);
			f.at(x, y) = -1;
			f.at( x+TRY[i][0], y + TRY[i][1] ) = -1;
			f.at( x+TRY[i][2], y + TRY[i][3] ) = -1;
		}
	}

	return next(f.n, x, y) && calculate(x, y, number) && field_is_correct();
}







// main
int main( int argc, char *argv[] )
{
	input();
	printf("%i\n", calculate());
	output();

	return 0;
}





// end
