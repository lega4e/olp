#include <cstring>
#include <iostream>

#define MOD(x) ( (x) % 1000000007 )


using namespace std;





// types
typedef long long llong;

struct Field
{
	int w, h;
	llong *d;

	llong *operator[](int y)
	{
		return d + y*w;
	}
};





// main
int main( int argc, char *argv[] )
{
	Field f;
	int dang;
	
	
	
	// input
	scanf("%i%i%i", &f.w, &f.h, &dang);
	f.w += 1, f.h += 1;
	f.d = new llong[f.w*f.h];
	memset( f.d, 0, sizeof(llong)*(f.w*f.h) );

	for(int i = 0, x, y; i < dang; ++i)
		scanf("%i%i", &x, &y),
		f[y][x] = -1;
	
	
	
	// solve
	f[0][0] = 1;
	for(int y = 0; y < f.h; ++y)
	{
		for(int x = 0; x < f.w; ++x)
		{
			if(f[y][x] < 0)
			{
				f[y][x] = 0;
				continue;
			}

			if(x > 0)
				f[y][x] += f[y][x-1];
			if(y > 0)
				f[y][x] += f[y-1][x];

			f[y][x] = MOD(f[y][x]);
		}
	}
	
	
	
	// output
	printf("%lli\n", f[f.h-1][f.w-1]);



	return 0;
}





// end
