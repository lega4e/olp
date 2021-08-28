#include <iostream>
#include <stack>

#include <quix/Field.hpp>


using namespace std;
using namespace quix;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	static constexpr PointI const OFFSET[4] = {
		{ 1, 0 }, { -1, 0 },
		{ 0, 1 }, { 0, -1 }
	};

	Field<char> f;
	
	
	
	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i", &f.w);
		f.h = f.w;
		f.init();
		int inp;
		for(auto b = f.begin(), e = f.end(); b != e; ++b)
		{
			while( isspace(inp = fgetc(file)) );
			*b = (char)inp;
		}
		fclose(file);
	}
	
	
	
	// solve
	stack<PointI> vers;
	f[0][0] = 'W';
	vers.push({0, 0});

	PointI v;
	PointI p;
	int count = 0;

again:
	while(!vers.empty())
	{
		v = vers.top();
		vers.pop();

		for(auto off : OFFSET)
		{
			p = v+off;

			if(!f.isValid(p) || f[p] == '#')
			{
				++count;
				continue;
			}

			if(!f.isValid(p) || f[p] == 'W')
				continue;

			f[p] = 'W';
			vers.push(p);
		}
	}

	if( *(f.end()-1) != 'W' )
	{
		vers.push( { f.w-1, f.w-1 } );
		f[ vers.top() ] = 'W';
		goto again;
	}
	
	
	
	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		fprintf(file, "%i\n", 25*(count-4));
		fclose(file);
	}



	return 0;
}





// end
