#include <iostream>
#include <fstream>


using namespace std;





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





char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";






// functions
int were_point(
	Point const &beg,
	Point const &end,
	Point const &p
)
{
	double const dx = (end.x - beg.x);
	if(dx != 0)
	{
		double const k = (end.y - beg.y) / dx;
		double const b = beg.y - k*beg.x;
		double const res = k*p.x + b;

		if(p.y < res)
			return -1;
		if(p.y > res)
			return 1;
		return 0;
	}
	else
	{
		if(p.x < beg.x)
			return -1;
		if(p.x > beg.x)
			return 1;
		return 0;
	}
}





int main( int argc, char *argv[] )
{
	Point a, b, c, d;
	ifstream(INPUT_FILE_NAME) >>
		a.x >> a.y >>
		b.x >> b.y >>
		c.x >> c.y >>
		d.x >> d.y;

	int
		abc = were_point(a, b, c),
		abd = were_point(a, b, d),
		cda = were_point(c, d, a),
		cdb = were_point(c, d, b);

	
	

	ofstream fout(OUTPUT_FILE_NAME);
	if(abs(abc+abd) != 2 && abs(cda+cdb) != 2)
	{
		Interval inter;
		if(a.x - b.x == 0 && c.x - d.x == 0)
		{
			if(b.y < a.y)
				swap(a, b);
			if(d.y < c.y)
				swap(c, d);
			inter = Interval{ max(a.y, c.y), min(b.y, d.y)};

		}
		else
		{
			if(b.x < a.x)
				swap(a, b);
			if(d.x < c.x)
				swap(c, d);
			inter = Interval{ max(a.x, c.x), min(b.x, d.x)};
		}
		if( inter.e - inter.b >= 0)
			fout << "Yes" << flush;
		else 
			fout << "No" << flush;
	}
	else
		fout << "No" << flush;


	return 0;
}





// end
