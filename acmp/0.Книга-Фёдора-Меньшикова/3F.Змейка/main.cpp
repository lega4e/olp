#include <cstring>
#include <iostream>
#include <fstream>


using namespace std;





// structs
struct Point
{
	int x, y;
};

struct Field
{
	int *d;
	int n;

	int &at(int x, int y)
	{
		return d[ y*n + x ];
	}
};





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

Field field;
int cur;





// functions
Point write_diagonale(int x, int y, int dir)
{
	if(dir > 0)
	{
		while( x < field.n && y >= 0 )
		{
			field.at(x, y) = cur;
			++cur;
			++x;
			--y;
		}
	}
	else
	{
		while( x >= 0 && y < field.n )
		{
			field.at(x, y) = cur;
			++cur;
			--x;
			++y;
		}
	}

	return { x, y };
	
}





// main
int main( int argc, char *argv[] )
{
	// init
	ifstream(INPUT_FILE_NAME) >> field.n;
	field.d = new int[ field.n * field.n ];
	memset(field.d, 0, sizeof *field.d * field.n * field.n );
	cur = 1;

	// calculate
	Point p{ 0, 0 };
	int dir = 1;

	while( p.x < field.n && p.y < field.n )
	{
		p = write_diagonale(p.x, p.y, dir);

		// next
		if(dir > 0)
		{
			if( p.x == field.n )
			{
				--p.x;
				p.y += 2;
			}
			else
			{
				++p.y;
			}
			dir = -1;
		}
		else
		{
			if( p.y == field.n )
			{
				p.x += 2;
				--p.y;
			}
			else
				++p.x;
			dir = 1;
		}
	}


	// print
	ofstream fout(OUTPUT_FILE_NAME);
	for(int y = 0; y < field.n; ++y)
	{
		for(int x = 0; x < field.n; ++x)
		{
			fout << field.at(x, y) << ' ';
		}
		fout << '\n';
	}
	fout.flush();

	return 0;
}





// end
