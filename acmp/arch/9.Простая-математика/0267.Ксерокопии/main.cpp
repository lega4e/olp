#include <algorithm>
#include <cstdio>


using namespace std;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

int n, x, y;
int mintime;





// functions
void input()
{
	auto file = fopen(INPUT_FILE_NAME, "r");
	fscanf(file, "%i%i%i", &n, &x, &y);
	if(x > y)
		swap(x, y);
	fclose(file);
	return;
}

void output()
{
	auto file = fopen(OUTPUT_FILE_NAME, "w");
	fprintf(file, "%i", mintime);
	fflush(file);
	fclose(file);
	return;
}

void calculate()
{
	mintime = x;
	--n;
	int down = (n*y) / (x+y);
	int up = down+1;
	mintime += min(
		max( down * x, (n-down) * y ),
		max( up * x, (n-up) * y )
	);
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
