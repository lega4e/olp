#include <cstdio>
#include <vector>


using namespace std;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

constexpr int const N = 8;

int bx, by, ex, ey;
int result;





// functions
void input()
{
	auto file = fopen(INPUT_FILE_NAME, "r");

	bx = fgetc(file)-'a';
	by = fgetc(file)-'1';

	fgetc(file); // ','
	fgetc(file); // ' '

	ex = fgetc(file)-'a';
	ey = fgetc(file)-'1';

	fclose(file);
	return;
}

void output()
{
	auto file = fopen(OUTPUT_FILE_NAME, "w");
	if(result == 1 || result == 2)
		fprintf(file, "%i", result);
	else
		fprintf(file, "NO");
	fflush(file);
	fclose(file);
	return;
}

void calculate()
{
#define is_valid(x, y) ( \
	(x) >= 0 && \
	(x) < N && \
	(y) >= 0 && \
	(y) < N \
)
	constexpr static int const DIRECTS[8][2] = {
		{ -1, -2 },
		{ 1, -2 },
		{ 2, -1 },
		{ 2, 1 },
		{ 1, 2 },
		{ -1, 2 },
		{ -2, 1 },
		{ -2, -1 }
	};

	vector<pair<int, int>> vec;
	for(int i = 0; i < 8; ++i)
	{
		if( is_valid(
			bx+DIRECTS[i][0],
			by+DIRECTS[i][1]
		) )
		{
			vec.push_back({
				bx+DIRECTS[i][0],
				by+DIRECTS[i][1]
			});

			if(vec.back().first == ex && vec.back().second == ey)
			{
				result = 1;
				return;
			}
		}
	}

	for(auto b = vec.begin(), e = vec.end(); b != e; ++b)
	{
		for(int i = 0; i < 8; ++i)
		{
			if(
				b->first+DIRECTS[i][0] == ex &&
				b->second+DIRECTS[i][1] == ey
			)
			{
				result = 2;
				return;
			}
		}
	}

	result = -1;
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
