#include <algorithm>
#include <cstdio>
#include <cstring>


using namespace std;





// structs
struct Point
{
	int x, y;
};



struct Field
{
	constexpr static int const N = 8;

	char *d;


	inline void init()
	{
		d = new char[ N*N ];
		return;
	}
	inline void zeroize()
	{
		memset(d, 0, sizeof *d * N * N);
		return;
	}
	inline void free()
	{
		delete[] d;
		return;
	}

	inline char const &at(int x, int y) const
	{
		return d[ y*N + x ];
	}
	inline char &at(int x, int y)
	{
		return d[ y*N + x ];
	}
	inline char const &at(Point const &p) const
	{
		return at(p.x, p.y);
	}
	inline char &at(Point const &p)
	{
		return at(p.x, p.y);
	}
};






// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

Field f;
Point queen, rock, horse;
int result;





// functions
void input()
{
	f.init();
	f.zeroize();
	auto file = fopen(INPUT_FILE_NAME, "r");
	char ch;

	// queen
	ch = getc(file);
	queen.x = ch-'A';
	ch = getc(file);
	queen.y = ch-'1';
	f.at(queen) = 'q';

	// rock
	ch = getc(file); // space
	ch = getc(file);
	rock.x = ch-'A';
	ch = getc(file);
	rock.y = ch-'1';
	f.at(rock) = 'r';

	// horse
	ch = getc(file); // space
	ch = getc(file);
	horse.x = ch-'A';
	ch = getc(file);
	horse.y = ch-'1';
	f.at(horse) = 'h';

	fclose(file);
	return;
}

void output()
{
	auto file = fopen(OUTPUT_FILE_NAME, "w");
	fprintf(file, "%i", result);
	fflush(file);
	fclose(file);
	return;
}

void calculate()
{
#define is_valid(p) ( \
	(p).x >= 0 && (p).x < Field::N && \
	(p).y >= 0 && (p).y < Field::N \
)
	Point aim;

	// queen
	constexpr static int const QOFF[][2] = {
		{ -1, -1 },
		{ 0, -1 },
		{ 1, -1 },
		{ -1, 0 },
		{ 1, 0 },
		{ -1, 1 },
		{ 0, 1 },
		{ 1, 1 }
	};
	for(auto const &i : QOFF)
	{
		aim = queen;
		aim.x += i[0];
		aim.y += i[1];
		while(is_valid(aim))
		{
			if(!f.at(aim))
				f.at(aim) = 1;
			aim.x += i[0];
			aim.y += i[1];
		}
	}

	// rock
	constexpr static int const ROFF[][2] = {
		{ 0, -1 },
		{ 1, 0 },
		{ 0, 1 },
		{ -1, 0 }
	};
	for(auto const &i : ROFF)
	{
		aim = rock;
		aim.x += i[0];
		aim.y += i[1];
		while(is_valid(aim))
		{
			if(!f.at(aim))
				f.at(aim) = 1;
			aim.x += i[0];
			aim.y += i[1];
		}
	}

	// horse
	constexpr static int const HOFF[][2] = {
		{ -1, -2 },
		{ 1, -2 },
		{ 2, -1 },
		{ 2, 1 },
		{ -1, 2 },
		{ 1, 2 },
		{ -2, -1 },
		{ -2, 1 }
	};
	for(auto const &i : HOFF)
	{
		aim = horse;
		aim.x += i[0];
		aim.y += i[1];
		if(is_valid(aim) && !f.at(aim))
			f.at(aim) = 1;
	}

	// result
	result = (int)count(
		f.d, f.d+Field::N*Field::N, 1
	);
	return;
}





// main
int main( int argc, char *argv[] )
{
	input();
	calculate();
	output();

	return 0;
}





// end
