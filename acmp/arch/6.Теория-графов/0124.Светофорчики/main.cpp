#include <cstdio>
#include <cstring>


using namespace std;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	int n, m;
	int *count;
	
	
	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i%i", &n, &m);

		count = new int[n];
		memset( count, 0, sizeof *count * n );
		int buf;
		for(int i = 0; i < m*2; ++i)
		{
			fscanf(file, "%i", &buf);
			++count[buf-1];
		}
		fclose(file);
	}
	
	
	
	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		for(auto *b = count, *e = count+n; b != e; ++b)
		{
			fprintf(file, "%i ", *b);
		}
	}

	

	return 0;
}





// end
