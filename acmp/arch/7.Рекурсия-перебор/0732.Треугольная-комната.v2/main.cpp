#include <cstdio>


using namespace std;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

int n, x, y, z;

bool success;
int result[6];





// functions
void input()
{
	auto file = fopen(INPUT_FILE_NAME, "r");
	fscanf(file, "%i%i%i%i", &n, &x, &y, &z);
	fclose(file);
}

void output()
{
	auto file = fopen(OUTPUT_FILE_NAME, "w");
	if(success)
	{
		fprintf(file, "YES\n");
		for(auto *b = result, *e = result+6; b != e; ++b)
		{
			fprintf(file, "%i ", *b);
		}
	}
	else
	{
		fprintf(file, "NO");
	}
	fflush(file);
	fclose(file);
	return;
}

void calculate()
{
	int const s = x + y + z;
	if(s < n || s > 2*n)
	{
		success = false;
		return;
	}
	int const a = s-n;

	int toa, tob, toc;
	for(toa = 0; toa <= a && toa <= x && toa <= z; ++toa)
	{
		for(
			tob = 0;
			tob <= a-toa && tob <= x-toa && tob <= y;
			++tob
		)
		{
			toc = a-(toa+tob);
			if(
				toa+tob <= x &&
				tob+toc <= y &&
				toc+toa <= z
			)
				goto success_label;
		}
	}
	success = false;
	return;

success_label:
	success = true;

	result[0] = toa;
	result[2] = tob;
	result[4] = toc;

	result[1] = x - (toa+tob);
	result[3] = y - (tob+toc);
	result[5] = z - (toa+toc);

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
