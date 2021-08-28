#include <cmath>
#include <cstdio>
#include <utility>


using namespace std;





// types
typedef unsigned long long ullong;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

ullong stage, first, second;
ullong result;





// functioins
void input()
{
	auto file = fopen(INPUT_FILE_NAME, "r");
	fscanf(file, "%llu%llu%llu", &stage, &first, &second);
	--stage;
	--first;
	--second;
	fclose(file);
	return;
}

void output()
{
	auto file = fopen(OUTPUT_FILE_NAME, "w");
	fprintf(file, "%llu", result+1);
	fflush(file);
	fclose(file);
	fclose(file);
	return;
}

inline ullong parent(ullong child, ullong stage)
{
	return child == 0 ? 0 :
		(child - pow(2, stage) + 1) / 2 +
		pow(2, stage-1) - 1;
}

inline ullong number(ullong element)
{
	return ullong(log2(element+1));
}

ullong calculate_comparent(ullong first, ullong second, ullong stage)
{
	ullong const fpar = parent(first, stage);
	ullong const spar = parent(second, stage);

	if(fpar == spar)
		return fpar;

	return calculate_comparent(fpar, spar, stage-1);
}

void calculate()
{

	ullong fnum = number(first);
	ullong snum = number(second);

	if(fnum != snum)
	{
		if(first > second)
		{
			swap(first, second);
			swap(fnum, snum);
		}

		do
		{
			second = parent(second, snum);
			--snum;
		}
		while(snum != fnum);
		stage = fnum;
	}

	result = calculate_comparent(first, second, stage);
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
