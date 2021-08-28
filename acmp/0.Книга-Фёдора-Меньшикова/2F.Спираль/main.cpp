#include <cstring>
#include <iostream>
#include <fstream>


using namespace std;





// structures
struct Field
{
	int n;
	int *d;

	inline int &at(int x, int y)
	{
		return d[ y*n+x ];
	}
};

struct Interval
{
	int b, e;
};





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// functions
void fill_field(
	Field &f,
	Interval const &x,
	Interval const &y,
	int val = 1
)
{
	if(x.e - x.b <= 0 || y.e - y.b <= 0)
		return;
	if(x.e - x.b == 1)
	{
		for(int i = y.b; i < y.e; ++i, ++val)
		{
			f.at(x.b, i) = val;
		}
		return;
	}
	else if(y.e - y.b == 1)
	{
		for(int i = x.b; i < x.e; ++i, ++val)
		{
			f.at(i, y.b) = val;
		}
		return;
	}


	// left to right
	for(int i = x.b; i < x.e; ++i, ++val)
	{
		f.at(i, y.b) = val;
	}

	// up to down
	for(int i = y.b+1; i < y.e-1; ++i, ++val)
	{
		f.at(x.e-1, i) = val;
	}

	// right to left
	for(int i = x.e-1; i >= x.b; --i, ++val)
	{
		f.at(i, y.e-1) = val;
	}

	// down to up
	for(int i = y.e-2; i > y.b; --i, ++val)
	{
		f.at(x.b, i) = val;
	}

	fill_field(f, {x.b+1, x.e-1}, {y.b+1, y.e-1}, val);

	return;

}





int main( int argc, char *argv[] )
{
	// read input
	Field f;
	{
		int n;
		ifstream(INPUT_FILE_NAME) >> n;
		f.n = n;
		f.d = new int[n*n];
	}
	memset(f.d, 0, sizeof(*f.d)*f.n*f.n);

	fill_field(f, {0, f.n}, {0, f.n});

	// output
	{
		ofstream fout(OUTPUT_FILE_NAME);
		for(int y = 0; y < f.n; ++y)
		{
			for(int x = 0; x < f.n; ++x)
			{
				fout << f.at(x, y) << ' ';
			}
			fout << '\n';
		}
		fout << flush;
	}

	return 0;
}





// end
