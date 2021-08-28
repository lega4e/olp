#include <cstdio>
#include <cstring>


using namespace std;





// structs
struct Field
{
	int n;
	int *d;

	int const *operator[](int y) const
	{
		return d + y*n;
	}
	int *operator[](int y)
	{
		return d + y*n;
	}
};





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

Field field;





// functions
void input()
{
	auto file = fopen(INPUT_FILE_NAME, "r");
	fscanf(file, "%i", &field.n);
	field.d = new int[field.n*field.n];
	memset( field.d, 0, sizeof *field.d * field.n * field.n );

	int edgec;
	int ver;
	for(int i = 0; i < field.n; ++i)
	{
		fscanf(file, "%i", &edgec);
		for(int j = 0; j < edgec; ++j)
		{
			fscanf(file, "%i", &ver);
			--ver;
			field[i][ver] = 1;
		}
	}
	fclose(file);

	return;
}

void output()
{
	auto file = fopen(OUTPUT_FILE_NAME, "w");
	fprintf(file, "%i\n", field.n);
	for(int y = 0; y < field.n; ++y)
	{
		for(int x = 0; x < field.n; ++x)
		{
			fprintf(file, "%i ", field[y][x]);
		}
		fprintf(file, "\n");
	}
	fflush(file);
	fclose(file);
	return;
}





// main
int main( int argc, char *argv[] )
{
	input();
	output();

	return 0;
}





// end
