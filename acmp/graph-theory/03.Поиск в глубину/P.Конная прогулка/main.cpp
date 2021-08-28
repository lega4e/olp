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
	struct Stage
	{
		PointI v;
		int c;
	};

	static constexpr PointI const OFFSET[8] = {
		{ 1, 2 },
		{ 1, -2 },
		{ -1, 2 },
		{ -1, -2 },
		{ 2, 1 },
		{ 2, -1 },
		{ -2, 1 },
		{ -2, -1 }
	};

	Field<char> f;
	PointI beg;
	
	
	
	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i%i%i%i", &f.h, &f.w, &beg.y, &beg.x);
		fclose(file);
		f.init().zeroize();
	}
	
	
	
	// solve
	bool res = false;

	stack<Stage> stages;
	stages.push({beg, 1});

	Stage st;
	PointI p;
	while(!stages.empty())
	{
		st = stages.top();
		
		if(st.c == f.w*f.h)
		{
			f[st.v] = st.c;
			res = true;
			goto output_label;
		}

		if(st.v.x < 0)
		{
			st.v.x = -st.v.x-1;
			stages.pop();
			f[st.v] = 0;
			continue;
		}

		stages.top() = { PointI { -st.v.x-1, st.v.y }, st.c };

		f[st.v] = st.c;
		for(auto off : OFFSET)
		{
			p = st.v+off;

			if(!f.isValid(p) || f[p])
				continue;

			stages.push({p, st.c+1});
		}
	}
	
	
	
	// output
output_label:
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");

		if(res) for(int y = 0; y < f.h; ++y)
		{
			for(int x = 0; x < f.w; ++x)
				fprintf(file, "%i ", f[y][x]);
			fprintf(file, "\n");
		}
		else
			fprintf(file, "NOT\n");
		fclose(file);
	}



	return 0;
}





// end
