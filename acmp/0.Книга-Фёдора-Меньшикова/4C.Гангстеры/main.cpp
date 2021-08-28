#include <algorithm>
#include <cmath>
#include <cstdio>


using namespace std;





// struct
struct Gangster
{
	long t, p, s;
};

struct Stage
{
	long t, p, k;
};





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

long t;




// functions
void calculate(
	Gangster const &gan,
	long maxk,
	Stage const *b, Stage *e
)
{
	Stage best = e[-1];
	while(b != e && gan.t >= b->t)
	{
		if(
			gan.s <= maxk &&
			gan.t <= t &&
			abs(b->k-gan.s) <= gan.t-b->t &&
			gan.t-b->t != 0 &&
			b->p+gan.p > best.p
		)
		{

			best = Stage{ gan.t, b->p+gan.p, gan.s };
		}
		++b;
	}
	*e = best;
	return;
}





// main
int main( int argc, char *argv[] )
{
	long n;
	Gangster *gans;
	long stagelen;
	Stage *stages;
	long maxk;


	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(
			file, "%li%li%li",
			&n, &maxk, &t
		);
		gans = new Gangster[n];
		stagelen = n+1;
		stages = new Stage[stagelen];

		for(auto *b = gans, *e = gans+n; b != e; ++b)
		{
			fscanf(file, "%li", &b->t);
		}
		for(auto *b = gans, *e = gans+n; b != e; ++b)
		{
			fscanf(file, "%li", &b->p);
		}
		for(auto *b = gans, *e = gans+n; b != e; ++b)
		{
			fscanf(file, "%li", &b->s);
		}
		fclose(file);


		// sort by time
		sort(
			gans, gans+n,
			[]( Gangster const &lhs, Gangster const &rhs )
				{ return lhs.t < rhs.t; }
		);
	}


	// calculate
	stages[0] = Stage{0, 0, 0};
	for(int i = 0; i < n; ++i)
	{
		calculate(gans[i], maxk, stages, stages+i+1);
	}


	long maxel = max_element(
		stages, stages+stagelen,
		[]( Stage const &lhs, Stage const &rhs )
			{ return lhs.p < rhs.p; }
	)->p;


	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		fprintf(file, "%li", maxel);
		fflush(file);
		fclose(file);

	}
	

	return 0;
}





// end
