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

	int n;
	PointI b, e;
	
	
	
	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i%i%i%i%i", &n, &b.x, &b.y, &e.x, &e.y);
		--b.x, --b.y, --e.x, --e.y;
		fclose(file);
	}
	
	
	
	// solve
	Field<char> marks;
	marks.init(n, n).zeroize();
	marks[b] = 1;

	queue<PointI> que;
	que.push(b);
	PointI cur;
	int res = -1;
	while(!que.empty())
	{
		cur = que.front();
		for(auto off : OFFSET)
		{
			if(!marks.isValid(cur+off))
				continue;

			if(cur + off == e)
			{
				res = marks[cur];
				goto output_label;
			}

			if(!marks[cur+off])
				marks[cur+off] = marks[cur] + 1,
				que.push(cur+off);
		}

		que.pop();
	}
	
	
	
	// output
output_label:
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		fprintf(file, "%i\n", res);
		fclose(file);
	}



	return 0;
}





// end
