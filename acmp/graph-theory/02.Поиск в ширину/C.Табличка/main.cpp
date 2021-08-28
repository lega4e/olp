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

	Field<int> f;
	queue<PointI> que;

	
	
	
	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i%i", &f.h, &f.w);
		f.init().clear(-1);

		int input;
		for(PointI p{0, 0}; p.y < f.h; ++p.y)
		for(p.x = 0; p.x < f.w; ++p.x)
		{
			fscanf(file, "%i", &input);
			if(input)
				f[p] = 0,
				que.push(p);
		}

		fclose(file);
	}
	
	
	
	// solve
	PointI cur;
	while(!que.empty())
	{
		cur = que.front();

		for(auto off : OFFSET)
		{
			if(!f.isValid(cur+off) || f[cur+off] != -1)
				continue;
			que.push(cur+off);
			f[cur+off] = f[cur] + 1;
		}
		
		que.pop();
	}
	
	
	
	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		for(int y = 0; y < f.h; ++y)
		{
			for(int x = 0; x < f.w; ++x)
				fprintf(file, "%i ", f[y][x]);
			fprintf(file, "\n");
		}
		fclose(file);
	}



	// end
	f.free();

	return 0;
}





// end
