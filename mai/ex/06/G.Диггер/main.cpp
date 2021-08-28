#include <iostream>


using namespace std;





// types
struct Field
{
	int w, h;
	int *d;

	int *operator[](int y)
	{
		return d + w*y;
	}
};





// main
int main( int argc, char *argv[] )
{
	Field f;
	
	
	
	// input
	scanf("%i%i", &f.h, &f.w);
	f.d = new int[f.w*f.h];
	for(auto *b = f.d, *e = f.d+f.w*f.h; b != e; ++b)
		scanf("%i", b);
	
	
	
	// solve
	{
		int amax;
		for(int y = 0; y < f.h; ++y)
		for(int x = 0; x < f.w; ++x)
		{
			amax = 0;
			if(x > 0 && f[y][x-1] > amax)
				amax = f[y][x-1];
			if(y > 0 && f[y-1][x] > amax)
				amax = f[y-1][x];
			f[y][x] += amax;
		}
	}
	
	
	
	// output
	printf("%i\n", f[f.h-1][f.w-1]);



	return 0;
}





// end
