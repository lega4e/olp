#include <cmath>
#include <iostream>
#include <fstream>
#include <cstdio>


using namespace std;





char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

typedef struct Point
{
	double x, y;
	Point operator-(Point const &p)
	{
		return { x-p.x, y-p.y };
	}
} Vector;

struct Interval
{
	double b, e;
};

constexpr double const ALPHA = 0.0000000001;


int main( int argc, char *argv[] )
{
	// read input
	Point a, b, c, d;
	ifstream(INPUT_FILE_NAME) >>
		a.x >> a.y >> 
		b.x >> b.y >> 
		c.x >> c.y >> 
		d.x >> d.y;

	// calculate straight
	Vector f = b-a;
	Vector s = d-c;
	double k1, j1, b1, k2, j2, b2;

	if(f.x == 0 && f.y == 0)
	{
		throw "null vector";
	}

	if(f.x == 0)
	{
		k1 = 1;
		j1 = 0;
		b1 = -a.x;
	}
	else
	{
		k1 = f.y/f.x;
		j1 = 1;
		b1 = a.y - k1*a.x;
	}

	if(s.x == 0)
	{
		k2 = 1;
		j2 = 0;
		b2 = -c.x;
	}
	else
	{
		k2 = s.y/s.x;
		j2 = 1;
		b2 = c.y - k2*c.x;
	}

	// assert
	ofstream fout(OUTPUT_FILE_NAME);
	double const div = j1*k2 - j2*k1;
	if(b.x < a.x)
		swap(a, b);
	if(d.x < c.x)
		swap(c, d);

	Interval inter;
	inter.b = max(a.x, c.x);
	inter.e = min(b.x, d.x);

	if(fabs(div) < ALPHA)
	{
		if( fabs(f.x) < ALPHA )
		{
			if(b.y < a.y)
				swap(a, b);
			if(d.y < c.y)
				swap(c, d);

			if( fabs(b1 - b2) < ALPHA && max(a.y, c.y) - min(b.y, d.y) < ALPHA )
				fout << "Yes" << flush;
			else
				fout << "No" << flush;
		}
		else
		{
			if( fabs(b1 - b2) < ALPHA && inter.b - inter.e < ALPHA )
				fout << "Yes" << flush;
			else
				fout << "No" << flush;
		}
	}
	else
	{
		double const x = ( j2*b1 - j1*b2 ) / div;
		if( inter.b - x < ALPHA && x - inter.e < ALPHA )
		{
			fout << "Yes" << flush;
		}
		else
		{
			fout << "No" << flush;
		}

	}





	return 0;
}





// end
