#include <cmath>
#include <iostream>
#include <fstream>
#include <set>


using namespace std;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	struct Point{ double x, y; };

	int len;
	Point *points;
	set<double> distance;
	
	
	
	// input
	{
		ifstream fin(INPUT_FILE_NAME);
		fin >> len;
		points = new Point[len];
		for(auto *b = points, *e = points+len; b != e; ++b)
		{
			fin >> b->x >> b->y;
		}
	}
	
	
	
	// calculate
	for(int i = 0; i < len; ++i)
	{
		for(int j = i+1; j < len; ++j)
		{
			distance.insert( hypot(
				points[j].x - points[i].x,
				points[j].y - points[i].y
			) );
		}
	}
	
	
	
	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		fprintf(file, "%lu\n", distance.size());
		for(auto b = distance.begin(), e = distance.end(); b != e; ++b)
		{
			fprintf(file, "%.20g\n", *b);
		}
		fflush(file);
		fclose(file);
	}
	
	

	return 0;
}





// end
