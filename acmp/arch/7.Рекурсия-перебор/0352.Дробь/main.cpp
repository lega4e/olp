#include <cmath>
#include <cstdio>


using namespace std;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

int n;
int a, b;





// functions
void input()
{
	auto file = fopen(INPUT_FILE_NAME, "r");
	fscanf(file, "%i", &n);
	fclose(file);
	return;
}

void output()
{
	auto file = fopen(OUTPUT_FILE_NAME, "w");
	fprintf(file, "%i %i", a, b);
	fflush(file);
	fclose(file);
}

bool is_this()
{
	int root = ceil(sqrt(a));
	for(int i = 2; i <= root; ++i)
		if( a % i == 0 && b % i == 0 )
			return false;
	return true;
}


void calculate()
{
	a = n%2 == 0 ? n/2-1 : n/2;
	b = n-a;
	while(a != 1)
	{
		if(is_this())
			return;
		--a;
		++b;
	}
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
