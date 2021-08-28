#include <cstdio>
#include <utility>


using namespace std;





// structs
struct Rect
{
	int w, h;

	void sort()
	{
		if(w > h)
			swap(w, h);
		return;
	}

	inline bool operator==(Rect const &other) const
	{
		return w == other.w && h == other.h;
	}

	inline bool operator!=(Rect const &other) const
	{
		return !operator==(other);
	}

};





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

Rect a, b, c, abuf, bbuf, cbuf;
bool result;





// functions
void sort_all()
{
	a.sort();
	b.sort();
	c.sort();
	abuf.sort();
	bbuf.sort();
	cbuf.sort();
	return;
}

bool first_stage()
{
	constexpr int N = 6u;
	Rect *refs[N] = {
		&a, &b, &c, &abuf, &bbuf, &cbuf
	};

	int it;
	int i = 0;
	while( true )
	{
		it = -1;
		for( int j = i+1; j < N-i; ++j )
		{
			if(*refs[i] == *refs[j])
			{
				it = j;
				break;
			}
		}
		if(it == -1)
			return false;
		if( ++i >= N/2 )
			break;
		while(++it < N)
			*refs[it-1] = *refs[it];
	}

	return true;
}

bool second_stage()
{
	Rect *refs[3] = {
		&a, &b, &c
	};

	for(auto *b = refs, *e = refs+3; b != e; ++b)
	{
		printf("w: %i, h: %i\n", (*b)->w, (*b)->h);
	}

	if(a.w == b.h)
	{
		swap(b.w, b.h);
	}
	else if(a.w == c.w)
	{
		swap(b, c);
	}
	else if(a.w == c.h)
	{
		swap(b, c);
		swap(b.w, b.h);
	}
	else if(a.w != b.w)
		return false;

	if(a.h == c.w)
	{
		swap(c.w, c.h);
	}
	else if(a.h != c.h)
		return false;

	return b.h == c.w;
}





// main
int main( int argc, char *argv[] )
{
	
	
	
	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(
			file, "%i%i%i%i%i%i%i%i%i%i%i%i",
			&a.w, &a.h,
			&b.w, &b.h,
			&c.w, &c.h,
			&abuf.w, &abuf.h,
			&bbuf.w, &bbuf.h,
			&cbuf.w, &cbuf.h
		);
		fclose(file);
	}
	
	
	
	// calculate
	sort_all();
	result = first_stage() && second_stage();
	
	
	
	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		if(result)
			fprintf(file, "POSSIBLE");
		else
			fprintf(file, "IMPOSSIBLE");
		fflush(file);
		fclose(file);
	}
	
	
	
	return 0;
}





// end
