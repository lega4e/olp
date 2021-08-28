#include <cstdio>
#include <utility>


using namespace std;





// structs
struct Part
{
	int prev, level;
};





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

int n;
Part *parts;
int fbad, sbad;
int result;





// functions
void input()
{
	auto file = fopen(INPUT_FILE_NAME, "r");
	fscanf(file, "%i%i%i", &n, &fbad, &sbad);
	--fbad;
	--sbad;
	parts = new Part[n];
	parts[0] = { -1, 0 };
	for(auto *b = parts+1, *e = parts+n; b != e; ++b)
	{
		fscanf(file, "%i", &b->prev);
		--b->prev;
		b->level = parts[b->prev].level+1;
	}
	return;
}

void output()
{
	auto file = fopen(OUTPUT_FILE_NAME, "w");
	fprintf(file, "%i", result+1);
	fflush(file);
	fclose(file);
	return;
}

void calculate()
{
	if(parts[fbad].level > parts[sbad].level)
		swap(fbad, sbad);

	while( parts[sbad].level != parts[fbad].level )
	{
		sbad = parts[sbad].prev;
	}

	while(fbad != sbad)
	{
		fbad = parts[fbad].prev;
		sbad = parts[sbad].prev;
	}
	result = fbad;
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
