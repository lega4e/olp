#include <cstdio>


using namespace std;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	int n;
	int counter;
	int buf;
	auto infile = fopen(INPUT_FILE_NAME, "r");
	auto outfile = fopen(OUTPUT_FILE_NAME, "w");

	fscanf(infile, "%i", &n);
	for(int i = 0; i < n; ++i)
	{
		counter = 0;
		for(int j = 0; j < n; ++j)
		{
			fscanf(infile, "%i", &buf);
			if(buf)
				++counter;
		}
		fprintf(outfile, "%i ", counter);
	}

	fclose(infile);
	fclose(outfile);

	

	return 0;
}





// end
