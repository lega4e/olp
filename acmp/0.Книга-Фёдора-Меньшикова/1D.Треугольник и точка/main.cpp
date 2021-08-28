#include <cmath>
#include <iostream>
#include <fstream>


using namespace std;





typedef struct Point
{
	double x, y;
	Point operator-(Point const &p)
	{
		return Point{x-p.x, y-p.y};
	}
} Vector;

double angle(Vector const &rhs, Vector const &lhs)
{
	double div = hypot(lhs.x, lhs.y)*hypot(rhs.x, rhs.y);
	if( fabs(div) < 0.0000001f)
		return 0.0f;
	return acos(
		(lhs.x*rhs.x + lhs.y*rhs.y) /
		div
	);
}





char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

int n;
Point *figure;
Point *fig_at(int i)
{
	i = i < 0 ?
		( i%n == 0 ? 0 : i - (i/n - 1)*n ) :
		i % n;
	return figure+i;
}
Point p;






int main( int argc, char *argv[] )
{
	{
		ifstream fin(INPUT_FILE_NAME);
		n = 3;
		figure = new Point[n];
		for(int i = 0; i < n; ++i)
		{
			fin >> figure[i].x >> figure[i].y;
		}
		fin >> p.x >> p.y;
	}

	Point *next, *prev, *cur;
	double alpha, beta, gamma;
	bool isin = true;
	for(int i = 0; i < n-1; ++i)
	{
		cur = figure+i;
		prev = fig_at(i-1);
		next = fig_at(i+1);

		alpha = angle( *next-*cur, *prev-*cur );
		beta = angle( *next-*cur, p-*cur );
		gamma = angle( *prev-*cur, p-*cur );

		if(alpha - beta < -0.000001 || alpha - gamma < -0.000001)
		{
			isin = false;
			break;
		}
	}

	if(isin)
	{
		ofstream(OUTPUT_FILE_NAME) << "In" << flush;
	}
	else
	{
		ofstream(OUTPUT_FILE_NAME) << "Out" << flush;
	}


	delete[] figure;
	return 0;
}





// end
