#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>


using namespace std;





// structs
struct Point
{
	int x, y;
};





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// functions
inline int distance(Point const &f, Point const &s)
{
	return abs(s.x-f.x) + abs(s.y-f.y);
}





// main
int main( int argc, char *argv[] )
{
	int w, h;
	vector<Point> virals;
	
	
	
	// input
	{
		int viralslen;
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i%i%i", &h, &w, &viralslen);
		virals.resize(viralslen);
		for(auto b = virals.begin(), e = virals.end(); b != e; ++b)
		{
			fscanf(file, "%i%i", &b->y, &b->x);
			--b->y;
			--b->x;
		}
	}
	
	
	
	// calculate
	int result = -1;
	int buf;
	for(int y = 0; y < h; ++y)
	{
		for(int x = 0; x < w; ++x)
		{
			buf = distance(virals.front(), {x, y});
			for(auto b = virals.begin()+1, e = virals.end(); b != e; ++b)
			{
				buf = min( buf, distance(*b, {x, y}) );
			}
			// printf("<%i, %i>: %i\n", x, y, buf);
			result = max(result, buf);
		}
	}
	
	
	
	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		fprintf(file, "%i", result);
		fflush(file);
		fclose(file);
	}

	

	return 0;
}





// end
