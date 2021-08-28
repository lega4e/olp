#include <algorithm>
#include <cstring>
#include <iostream>
#include <fstream>


using namespace std;





// struct
struct Field
{
	int w, h;
	char *d;

	void init() 
	{
		d = new char[w*h];
		return;
	}
	void free()
	{
		delete[] d;
		return;
	}

	char const &at(int x, int y) const
	{
		return d[ y*w + x ];
	}
	char &at(int x, int y)
	{
		return d[ y*w + x ];
	}
};





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	Field f;
	int result;
	
	
	
	// input & calculate
	{
		ifstream fin(INPUT_FILE_NAME);
		fin >> f.w >> f.h;
		f.init();
		memset( f.d, 0, sizeof *f.d * f.w * f.h );
		int rectc;
		fin >> rectc;
		int fx, fy, sx, sy;
		for(int i = 0; i < rectc; ++i)
		{
			fin >> fx >> fy >> sx >> sy;
			for(int y = fy; y < sy; ++y)
			{
				memset( f.d + y*f.w + fx, 1, sizeof *f.d * (sx-fx) );
			}
		}

		result = count( f.d, f.d+f.w*f.h, 0 );
	}
	
	
	
	// output
	{
		ofstream(OUTPUT_FILE_NAME) << result << flush;
	}
	
	

	return 0;
}





// end
