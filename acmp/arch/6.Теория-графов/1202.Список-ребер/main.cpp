#include <algorithm>
#include <cstdio>
#include <vector>


using namespace std;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

int n;
vector<int> *adjaclist;





// functions
void inputcalc()
{
	int edgec;

	auto file = fopen(INPUT_FILE_NAME, "r");
	fscanf(file, "%i%i", &n, &edgec);
	adjaclist = n ? new vector<int>[n] : nullptr;

	int fbuf, sbuf;
	for(int i = 0; i < edgec; ++i)
	{
		fscanf(file, "%i%i", &fbuf, &sbuf);
		--fbuf;
		--sbuf;
		adjaclist[fbuf].push_back(sbuf);
	}
	fclose(file);
	
	for(auto *b = adjaclist, *e = adjaclist+n; b != e; ++b)
	{
		sort(b->begin(), b->end());
	}
	return;
}

void output()
{
	auto file = fopen(OUTPUT_FILE_NAME, "w");
	fprintf(file, "%i", n);
	for(auto *b = adjaclist, *e = adjaclist+n; b != e; ++b)
	{
		fprintf(file, "\n%lu", b->size());
		for(auto ab = b->begin(), ae = b->end(); ab != ae; ++ab)
		{
			fprintf(file, " %i", *ab+1);
		}
	}
	fflush(file);
	fclose(file);
	return;
}





// main
int main( int argc, char *argv[] )
{
	inputcalc();
	output();
	

	return 0;
}





// end
