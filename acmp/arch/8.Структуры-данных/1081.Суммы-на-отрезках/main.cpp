#include <cstdio>
#include <cstring>


using namespace std;





// types
typedef unsigned long long int ullong;
struct Field
{
	int n;
	ullong *d;

	inline void init()
	{
		d = new ullong[n*n];
		return;
	}
	inline void zero()
	{
		memset(d, 0, sizeof *d * n * n);
		return;
	}
	inline void dree()
	{
		delete[] d;
		return;
	}

	ullong const *operator[](int y) const
	{
		return d + y*n;
	}
	ullong *operator[](int y)
	{
		return d + y*n;
	}
};





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

int n;
ullong *arr;
Field f;





// functions
ullong summ(int first, int last)
{
	if(f[first][last])
		return f[first][last];
	f[first][last] = first ?
		summ(first-1, last) - arr[first-1] :
		summ(first, last-1) + arr[last];
	return f[first][last];
}





// main
int main( int argc, char *argv[] )
{
	int count;
	auto infile = fopen(INPUT_FILE_NAME, "r");
	auto outfile = fopen(OUTPUT_FILE_NAME, "w");



	// read array
	fscanf(infile, "%i", &n);
	arr = new ullong[n];
	for(auto *b = arr, *e = arr+n; b != e; ++b)
	{
		fscanf(infile, "%llu", b);
	}



	// execute
	f.n = n;
	f.init();
	f.zero();
	f[0][0] = arr[0];
	fscanf(infile, "%i", &count);
	int b, e;
	for(int i = 0; i < count; ++i)
	{
		fscanf(infile, "%i%i", &b, &e);
		fprintf(outfile, "%llu ", summ(b-1, e-1));
	}



	// end
	fclose(infile);
	fflush(outfile);
	fclose(outfile);

	

	return 0;
}





// end
