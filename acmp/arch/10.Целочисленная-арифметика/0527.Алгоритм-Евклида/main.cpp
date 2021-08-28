#include <cstdio>
#include <utility>


using namespace std;





// types
typedef unsigned long long ullong;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	int k;
	ullong a, b, c, d;
	
	
	
	// input
	auto infile = fopen(INPUT_FILE_NAME, "r");
	auto outfile = fopen(OUTPUT_FILE_NAME, "w");

	fscanf(infile, "%i", &k);
	bool success;
	while(k)
	{
		fscanf(
			infile, "%llu%llu%llu%llu",
			&a, &b, &c, &d
		);
		success = false;
		
		
		if(a == c && b == d)
		{
			success = true;
		}
		else
		{
			if(b > a)
				swap(a, b);
			
			// calculate
			while(true)
			{
				if( !(a % b) )
				{
					success = ( c <= a && b == d && !((a - c) % b) );
					break;
				}
				if( c <= a && b == d && !((a-c) % b) )
				{
					success = true;
					break;
				}
				a %= b;
				if( a == c && b == d )
				{
					success = true;
					break;
				}
				swap(a, b);
			}
		}
		
		
		
		// output
		if(success)
			fprintf(outfile, "YES\n");
		else
			fprintf(outfile, "NO\n");

		--k;

	}
	
	
	
	// close
	fclose(infile);
	fflush(outfile);
	fclose(outfile);

	
	
	return 0;
}





// end
