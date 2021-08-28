#include <cmath>
#include <cstdio>


using namespace std;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	typedef struct { double x, y; } Point;
	int count;
	Point p;
	int dir, step;
	double buf;

	auto infile = fopen(INPUT_FILE_NAME, "r");
	fscanf(infile, "%i", &count);
	for(int i = 0; i < count; ++i)
	{
		fscanf(infile, "%i%i", &dir, &step);
		switch(dir)
		{
		case 1:
			p.y += step;
			break;
		case 2:
			buf = step * sqrt(0.5);
			p.x += buf;
			p.y += buf;
			break;
		case 3:
			p.x += step;
			break;
		case 4:
			buf = step * sqrt(0.5);
			p.x += buf;
			p.y -= buf;
			break;
		case 5:
			p.y -= step;
			break;
		case 6:
			buf = step * sqrt(0.5);
			p.x -= buf;
			p.y -= buf;
			break;
		case 7:
			p.x -= step;
			break;
		case 8:
			buf = step * sqrt(0.5);
			p.x -= buf;
			p.y += buf;
			break;
		}
	}


	auto outfile = fopen(OUTPUT_FILE_NAME, "w");
	fprintf(outfile, "%.3f %.3f", p.x, p.y);
	fflush(outfile);
	fclose(outfile);

	return 0;
}





// end
