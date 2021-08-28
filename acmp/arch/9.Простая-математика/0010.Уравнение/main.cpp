#include <cmath>
#include <cstdio>
#include <vector>


using namespace std;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

int a, b, c, d;
vector<int> result;





// functions
void input()
{
	auto file = fopen(INPUT_FILE_NAME, "r");
	fscanf(file, "%i%i%i%i", &a, &b, &c, &d);
	fclose(file);
	return;
}

void output()
{
	auto file = fopen(OUTPUT_FILE_NAME, "w");
	for(auto b = result.begin(), e = result.end(); b != e; ++b)
	{
		fprintf(file, "%i ", *b);
	}
	fflush(file);
	fclose(file);
	return;
}

void calculate()
{
	for(int i = -100; i != 101; ++i)
	{
		if(
			a * pow(i, 3) +
			b * pow(i, 2) +
			c * i + d == 0
		)
			result.push_back(i);
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
