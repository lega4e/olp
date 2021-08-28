#include <cmath>
#include <iostream>
#include <fstream>


using namespace std;





// structs
typedef struct Point
{
	double x;
	double y;



	double distance(Point const &p) const
	{
		return hypot( p.x-x, p.y-y );
	}
	
	Point operator-(Point const &p) const
	{
		return { x-p.x, y-p.y };
	}
} Vector;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

int n;
Point *vers;





// functions
double triangle_area(
	Point const &f, Point const &s, Point const &t
)
{
	double const a = f.distance(s);
	double const b = s.distance(t);
	double const c = t.distance(f);
	double const p = (a+b+c) / 2.0f;

	return sqrt( p*(p-a)*(p-b)*(p-c) );
}



double calculate_area(int n, Point **vers)
{
	if(n < 3)
		throw "invalid count of vertexes";

	double area = 0.0f;

	area += triangle_area(
		*vers[0], *vers[1], *vers[2]
	);

	if(n != 3)
	{
		Point **nextvers = new Point*[n-1];
		nextvers[0] = vers[0];
		for(int i = 2; i < n; ++i)
		{
			nextvers[i-1] = vers[i];
		}
		area += calculate_area(n-1, nextvers);
	}
	
	delete[] vers;
	return area;
}





// main
int main( int argc, char *argv[] )
{
	{
		ifstream fin(INPUT_FILE_NAME);
		fin >> n;
		vers = new Point[n];
		for(auto *b = vers, *e = vers+n; b != e; ++b)
		{
			fin >> b->x >> b->y;
		}
	}

	Point **curvers = new Point*[n];
	for(int i = 0; i < n; ++i)
	{
		curvers[i] = vers+i;
	}

	cout << calculate_area(n, curvers) << endl;


	return 0;
}





// end
