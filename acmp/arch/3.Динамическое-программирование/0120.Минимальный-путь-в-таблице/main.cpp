#include <algorithm>
#include <cstdio>


using namespace std;





struct Field
{
	int w, h;
	int *d;

	inline int &at( int x, int y )
	{
		return d[ y*w + x ];
	}
	inline int const &at( int x, int y ) const
	{
		return d[ y*w + x ];
	}
};




// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";




void define_min_price(
	Field const &f, 
	Field &mp,
	int x, int y
)
{
	if(x == 0)
	{
		if(y == 0)
			mp.at(x, y) = f.at(x, y);
		else
			mp.at(x, y) = mp.at(x, y-1) + f.at(x, y);
		return;
	}
	if(y == 0)
	{
		mp.at(x, y) = mp.at(x-1, y) + f.at(x, y);
		return;
	}

	mp.at(x, y) = min(
		mp.at(x-1, y),
		mp.at(x, y-1)
	) + f.at(x, y);
	return;
}




int main( int argc, char *argv[] )
{
	Field f;
	Field minprice;



	// input
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i%i", &f.h, &f.w);
		minprice.w = f.w;
		minprice.h = f.h;

		f.d = new int[f.w*f.h];
		minprice.d = new int[ minprice.w * minprice.h ];

		for(int i = 0; i < f.w*f.h; ++i)
		{
			fscanf(file, "%i", f.d+i);
		}

		fclose(file);
	}


	// calculate
	{
		for(int y = 0; y < f.h; ++y)
		{
			for(int x = 0; x < f.w; ++x)
			{
				define_min_price(
					f, minprice, x, y
				);
			}
		}
	}


	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		fprintf(
			file, "%i",
			minprice.at(
				minprice.w-1,
				minprice.h-1
			)
		);
		fflush(file);
		fclose(file);
	}



	// free
	delete[] f.d;
	delete[] minprice.d;

	return 0;
}





// end
