#include <algorithm>
#include <cstdio>


using namespace std;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// functions
void calculate(int i, int *seq, int *res)
{
	int buf = 0;
	for(int j = 0; j < i; ++j)
	{
		if(seq[i] > seq[j] && res[j] > buf)
			buf = res[j];
	}
	res[i] = buf+1;
	return;
}





int main( int argc, char *argv[] )
{
	int n;
	int *seq;
	int *res;


	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i", &n);
		seq = new int[n];
		res = new int[n];
		for(auto *b = seq, *e = seq+n; b != e; ++b)
		{
			fscanf(file, "%i", b);
		}
		fclose(file);
	}

	// calculate
	res[0] = 1;
	int maxres = 1;
	for(int i = 1; i < n; ++i)
	{
		calculate(i, seq, res);
		if(res[i] > maxres)
			maxres = res[i];
	}


	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		fprintf(file, "%i", maxres);
		fflush(file);
		fclose(file);
	}



	return 0;
}





// end
