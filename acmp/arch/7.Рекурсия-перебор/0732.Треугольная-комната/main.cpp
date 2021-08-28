#include <algorithm>
#include <cstdio>


using namespace std;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

int n, x, y, z;

bool success;
struct Result
{
	int r[6] = { 0 };
	int &operator[](int i)
	{
		printf("op[%i]\n", i);
		return r[i];
	}
};
Result result;





// functions
void input()
{
	auto file = fopen(INPUT_FILE_NAME, "r");
	fscanf(file, "%i%i%i%i", &n, &x, &y, &z);
	fclose(file);
	return;
}

int false_from_a = 0;

void output()
{
	printf("false form a: %i\n", false_from_a);

	auto file = fopen(OUTPUT_FILE_NAME, "w");
	if(success)
	{
		fprintf(file, "YES\n");
		for(auto *b = result.r, *e = result.r+6; b != e; ++b)
		{
			fprintf(file, "%i ", *b);
		}
	}
	else
	{
		fprintf(file, "NO");
	}
	fflush(file);
	fclose(file);
	return;
}

bool calculate(int x, int y, int z, int a, int o, int offset = 0)
{
	if(!x && !y && !z)
	{
		return !a && !o;
	}

	int buf;
	if(a)
	{
		buf = min(x, min(z, a));
		if(buf > 1)
			buf /= 2;
		if(x && z && calculate(z-buf, x-buf, y, a-buf, o, (offset+1)%3))
		{
			result[ (0+2*offset) % 6 ] += buf;
			return true;
		}
		buf = min(x, min(y, a));
		if(buf > 1)
			buf /= 2;
		if(x && y && calculate(z, x-buf, y-buf, a-buf, o, (offset+1)%3))
		{
			result[ (2+2*offset) % 6 ] += buf;
			return true;
		}
		buf = min(y, min(z, a));
		if(buf > 1)
			buf /= 2;
		if(y && z && calculate(z-buf, x, y-buf, a-buf, o, (offset+1)%3))
		{
			result[ (4+2*offset) % 6 ] += buf;
			return true;
		}
		++false_from_a;
		return false;
	}

	if(!o)
		return false;
	if(x && calculate(x-1, y, z, 0, o-1, offset))
	{
		++result[ (1+2*offset) % 6 ];
		return true;
	}
	if(y && calculate(x, y-1, z, 0, o-1, offset))
	{
		++result[ (3+2*offset) % 6 ];
		return true;
	}
	if(z && calculate(x, y, z-1, 0, o-1), offset)
	{
		++result[ (5+2*offset) % 6 ];
		return true;
	}
	return false;
}

void calculate()
{
	int const s = x+y+z;
	if(s < n || s > 2*n)
	{
		success = false;
		return;
	}

	int const a = s-n;
	int const o = n-a;
	// for(auto *b = result, *e = result+6; b != e; ++b)
	// {
		// *b = 0;
	// }
	success = calculate(x, y, z, a, o);
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
