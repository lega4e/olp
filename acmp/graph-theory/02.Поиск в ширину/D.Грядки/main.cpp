#include <iostream>
#include <queue>

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

	struct Unit { char what; int group; };

	Field<Unit> f;
	vector<PointI> vec;
	int groupc;
	
	
	
	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i%i", &f.h, &f.w);
		f.init().zeroize();
		int inp;
		for(auto b = f.begin(), e = f.end(); b != e; ++b)
		{
			while( isspace(inp = fgetc(file)) );
			b->what = (char)inp;
			if(inp == '#')
				vec.push_back( f.getxy(b) );
		}
		fclose(file);
	}
	
	
	
	// solve
	groupc = 0;

	queue<PointI> que;
	PointI cur;
	int curgroup;
	for(auto b = vec.begin(), e = vec.end(); b != e; ++b)
	{
		if( f[*b].group )
			continue;

		curgroup = ++groupc;
		f[*b].group = curgroup;

		que = queue<PointI>();
		que.push(*b);
		while(!que.empty())
		{
			cur = que.front();

			for(auto off : OFFSET)
			{
				if(
					!f.isValid(cur+off) ||
					f[cur+off].what == '.' ||
					f[cur+off].group
				)
					continue;
				que.push(cur+off);
				f[cur+off].group = curgroup;
			}
			
			que.pop();
		}
	}
	
	
	
	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		fprintf(file, "%i\n", groupc);
		fclose(file);
	}



	return 0;
}





// end
