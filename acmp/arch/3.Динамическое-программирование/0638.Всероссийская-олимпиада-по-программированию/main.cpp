#include <algorithm>
#include <cstdio>
#include <set>


using namespace std;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	int n, k;
	int w, dwlen, s;
	int *dw;
	int dmlen;
	int *dm;
	
	set<int> warning;
	int variants;
	
	
	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(
			file, "%i%i%i%i%i",
			&n, &k, &w, &dwlen, &s
		);
		--s;

		dw = new int[dwlen];
		for(auto *b = dw, *e = dw+dwlen; b != e; ++b)
		{
			fscanf( file, "%i", b );
			--*b;
		}

		fscanf( file, "%i", &dmlen );
		dm = new int[dmlen];
		for(auto *b = dm, *e = dm+dmlen; b != e; ++b)
		{
			fscanf( file, "%i", b );
			--*b;
		}
	}
	
	
	
	// calculate
		// warning days
	for(int i = 0; i < n; ++i)
	{
		if( find(dw, dw+dwlen, (i+s)%w) != dw+dwlen )
			warning.insert(i);
	}
	for(auto *b = dm, *e = dm+dmlen; b != e; ++b)
	{
		warning.insert(*b);
	}
	warning.insert(n);
		// variants
	{
		variants = 0;
		int current = 0;
		auto b = warning.begin();
		while(current < n)
		{
			printf("cur: %i, *b: %i", current, *b);
			if(*b-current >= k)
			{
				printf(" - ok");
				variants += (*b-current)-k+1;
				current = *b+1;
			}
			else
				++current;
			++b;
			printf("\n");
		}
	}
	
	
	
	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		fprintf(file, "%i\n", variants);
		for(auto b = warning.begin(), e = warning.end(); b != e; ++b)
		{
			fprintf(file, "%i ", *b);
		}

		fflush(file);
		fclose(file);
	}
	
	

	return 0;
}





// end
