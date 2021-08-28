#include <cmath>
#include <cstdio>
#include <vector>


using namespace std;





// struct
typedef struct Point
{
	double x, y;
} Vector;

struct Triangle
{
	Point a, b, c;
};




// objects
constexpr double const ALPHA = 0.0000000001f;
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// functions
inline Vector operator-(Point const &lhs, Point const &rhs)
{
	return Vector{ lhs.x-rhs.x, lhs.y-rhs.y };
}

inline double length(Vector const &v)
{
	return std::hypot(v.x, v.y);
}


inline double sin(Vector const &f, Vector const &s)
{
	double const flen = length(f), slen = length(s);
	if( std::fabs(flen) < ALPHA || std::fabs(slen) < ALPHA )
		return 0.0f;
	return 
		(f.x*s.y - s.x*f.y) /
		( flen * slen );
}

inline double angle(Vector const &f, Vector const &s)
{
	return std::asin(
		sin(f, s)
	);
}


int define_position( 
	Point const &beg, 
	Point const &end,
	Point const &p
)
{
	double const angl = 
		angle( end - beg, p - beg );
	return fabs(angl) < ALPHA ?
		0 :
		( angl < ALPHA ? 1 : -1 );
}

int define_position(
	Point const &beg, 
	Point const &fend, Point const &send,
	Point const &p
)
{
	Point const mid{
		(fend.x + send.x) / 2.0f,
		(fend.y + send.y) / 2.0f
	};

	int const
		fp = define_position( beg, fend, p ),
		sp = define_position( beg, send, p ),
		midfp = define_position( beg, fend, mid ),
		midsp = define_position( beg, send, mid );

	if(fp == midfp)
	{
		if(sp == 0)
			return 0;
		if(sp == midsp)
			return 1;
		return -1;
	}
	if(fp == 0 && ( sp == midsp || sp == 0 ))
		return 0;
	return -1;
}

int define_position(Triangle const &t, Point const &p)
{
	int const
		fres = define_position(t.a, t.b, t.c, p),
		sres = define_position(t.b, t.a, t.c, p);

	if(fres == -1 || sres == -1)
		return -1;
	if(fres == 0 || sres == 0)
		return 0;
	return 1;
}





// main
int main( int argc, char *argv[] )
{
	vector<int> countryes;


	// input
	{
		Point town;
		int n;
		Triangle tr;

		// read first input
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%lf%lf%i", &town.x, &town.y, &n);

		// calcaulte
		for(int i = 0; i < n; ++i)
		{
			fscanf(
				file, "%lf%lf%lf%lf%lf%lf",
				&tr.a.x, &tr.a.y,
				&tr.b.x, &tr.b.y,
				&tr.c.x, &tr.c.y
			);
			if(define_position(tr, town) == 1)
			{
				countryes.push_back(i);
			}
		}

		fclose(file);
	}


	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		fprintf(file, "%lu\n", countryes.size());
		if(!countryes.empty())
		{
			fprintf(file, "%i", countryes.front()+1);
			for(auto b = countryes.begin()+1, e = countryes.end(); b != e; ++b)
			{
				fprintf(file, " %i", *b+1);
			}
		}
		fflush(file);
		fclose(file);
	}


	return 0;
}





// end
