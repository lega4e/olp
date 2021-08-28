#include <iostream>
#include <fstream>
#include <functional>
#include <queue>
#include <set>

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

	struct Unit
	{
		char what;
		int count;
	};

	Field<Unit> f;
	PointI begin;
	
	
	
	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i%i", &f.h, &f.w);
		f.init();
		int inp;
		for(auto b = f.begin(), e = f.end(); b != e; ++b)
		{
			while( isspace(inp = fgetc(file)) );
			b->what = inp;
			b->count = inp == 'S' ? 0 : -1;

			if(inp == 'S')
				begin = f.getxy(b);
		}
		fclose(file);
	}
	
	
	
	// solve
	set<
		PointI,
		function<bool(PointI, PointI)>
	> set(
		[&f](PointI lhs, PointI rhs)->bool {
			return f[lhs].count != f[rhs].count ?
				f[lhs].count < f[rhs].count :
				lhs < rhs;
		}
	);
	set.insert(begin);

	PointI cur, p;
	int addcount;
	int res = -1;
	while(!set.empty())
	{
		cur = *set.begin();
		set.erase(set.begin());

		if(f[cur].what == 'E')
		{
			res = f[cur].count;
			break;
		}

		for(auto off : OFFSET)
		{
			addcount = 0;
			p = cur + off;

		offloop_again:
			if( !f.isValid(p) || f[p].what == '#' || f[p].count >= 0 )
				continue;

			if(f[p].what == 'B')
			{
				p += off;
				++addcount;
				goto offloop_again;
			}

			f[p].count = f[cur].count + 1 + addcount;
			set.insert(p);
		}
	}
	
	
	
	// output
	ofstream(OUTPUT_FILE_NAME) << res << endl;
	


	return 0;
}





// end
