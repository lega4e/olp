#include <algorithm>
#include <cstdio>


using namespace std;





// types
typedef long long llong;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

int monheight, curheight, scroll, tabheight;
int linec;
llong *lines;

int result;




// functions
void input()
{
	auto file = fopen(INPUT_FILE_NAME, "r");
	fscanf(
		file, "%i%i%i%i%i",
		&monheight, &curheight,
		&scroll, &tabheight,
		&linec
	);
	lines = new llong[linec];
	for(auto *b = lines, *e = lines+linec; b != e; ++b)
	{
		fscanf(file, "%lli", b);
	}
	fclose(file);
	return;
}

void output()
{
	auto file = fopen(OUTPUT_FILE_NAME, "w");
	fprintf(file, "%i", result);
	fflush(file);
	fclose(file);
	return;
}

int intersects(int y, llong *&b, llong *e)
{
	int count = 0;
	while(b != e && *b < y)
		++b;
	if(b != e)
	{
		auto *bb = b;
		while( *bb < y+curheight )
		{
			++count;
			++bb;
		}
	}
	return count;
}

int calculate_for(int y)
{
	// vars
		// intersects
	auto *b = lines, *e = lines+linec;
		// other
	int count = 0;
	int monpos = 0;
loop:
	count += intersects(y, b, e);
	if(monpos+monheight < tabheight)
	{
		y += scroll;
		monpos += scroll;
		goto loop;
	}

	// printf("count: %i\n", count);
	// fflush(stdout);
	return count;
}

void calculate()
{
	result = calculate_for(monheight-curheight);
	// int resy = 0;
	// int temp;

	for(
		int y = monheight-curheight-1;
		y >= monheight-curheight-scroll && y >= 0;
		--y
	)
	{
		result = min(result, calculate_for(y));
	}

	// for(int y = 1; y <= monheight-curheight; ++y)
	// {
		// temp = calculate_for(y);
		// if(temp < result)
		// {
			// result = temp;
			// // resy = y;
		// }
	// }
	// printf("resulting y: %i\n", resy);
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
