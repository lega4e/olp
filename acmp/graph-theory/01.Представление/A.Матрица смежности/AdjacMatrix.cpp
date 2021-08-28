/*
 * autor:   quix
 * date:    Jan 26 17:00:45 2020
 */

#include <cstring>





struct AdjacMatrix
{
	// data-member
	int n;
	char *d;



	// base
	inline AdjacMatrix &init()
	{
		d = new char[n*n];
		return *this;
	}

	inline AdjacMatrix &init(int newn)
	{
		n = newn;
		d = new char[n*n];
		return *this;
	}

	inline AdjacMatrix &zeroize()
	{
		memset(d, 0, sizeof(char)*n*n);
		return *this;
	}

	inline AdjacMatrix &free()
	{
		delete[] d;
		return *this;
	}



	// at
	inline char *operator[](int i)
	{
		return d + i*n;
	}

	inline const char *operator[](int i) const
	{
		return d + i*n;
	}
	
	
	
	// input, output
	inline AdjacMatrix &scann(FILE *file = stdin)
	{
		fscanf(file, "%i", &n);
		init();
		scan(file);
		return *this;
	}
	
	AdjacMatrix &scan(FILE *file = stdin)
	{
		int input;
		for(auto *b = d, *e = d+n*n; b != e; ++b)
			fscanf(file, "%i", &input),
			*b = input;
		return *this;
	}

	void print(FILE *file = stdout) const
	{
		fprintf(file, "%i\n", n);
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				fprintf(file, "%i ", (int)d[i*n + j]);
			}
			fprintf(file, "\n");
		}
		return;
	}


	
};





// end
