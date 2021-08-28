#include <cstdio>


using namespace std;

typedef long long llong;





struct Point
{
	llong x, y;
};





int main( int argc, char *argv[] )
{
	Point beg, end, p;
	
	// read input
	FILE *infile = fopen("INPUT.TXT", "r");
	if( fscanf(
		infile, "%lli%lli%lli%lli%lli%lli",
		&beg.x, &beg.y, &end.x, &end.y, &p.x, &p.y
	) != 6 )
	{
		fprintf(stderr, "error with read input\n");
		return 1;
	}

	
	// horizontal
	if( beg.y == end.y )
	{
		p.y -= 2 * (p.y - beg.y);
	}
	// vertical
	else
	{
		p.x -= 2 * (p.x - beg.x);
	}


	FILE *outfile = fopen("OUTPUT.TXT", "w");
	fprintf(outfile, "%lli %lli", p.x, p.y);
	fflush(outfile);
	fclose(outfile);

	return 0;
}





// end
