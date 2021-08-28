#include <iostream>

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

/*
 * autor:   quix
 * date:    Jan 26 17:18:52 2020
 */

#include <algorithm>
#include <vector>





struct AdjacList
{
	// data-members
	std::vector< std::vector<int> > ribs;
	
	
	
	// base
	inline int n() const
	{
		return (int)ribs.size();
	}

	inline AdjacList &clear()
	{
		ribs.clear();
		return *this;
	}

	inline AdjacList &sort()
	{
		for(auto b = ribs.begin(), e = ribs.end(); b != e; ++b)
			std::sort( b->begin(), b->end() );
		return *this;
	}



	// at
	inline std::vector<int> &operator[](int i)
	{
		return ribs[i];
	}

	inline std::vector<int> const &operator[](int i) const
	{
		return ribs[i];
	}
	
	
	
	// scan, print
	AdjacList &scan(FILE *file = stdin);

	void print(FILE *file = stdout) const
	{
		fprintf(file, "%i\n", (int)n());
		for(auto b = ribs.begin(), e = ribs.end(); b != e; ++b)
		{
			if(b->empty())
			{
				fprintf(file, "-1\n");
				continue;
			}

			for(auto bb = b->begin(), ee = b->end(); bb != ee; ++bb)
			{
				fprintf(file, "%i ", *bb);
			}
			fprintf(file, "\n");
		}
		return;
	}

	void print1(FILE *file = stdout) const
	{
		fprintf(file, "%i\n", (int)n());
		for(auto b = ribs.begin(), e = ribs.end(); b != e; ++b)
		{
			if(b->empty())
			{
				fprintf(file, "0\n");
				continue;
			}

			for(auto bb = b->begin(), ee = b->end(); bb != ee; ++bb)
			{
				fprintf(file, "%i ", *bb+1);
			}
			fprintf(file, "\n");
		}
		return;
	}

};





// end

/*
 * autor:   quix
 * date:    Jan 26 17:50:01 2020
 */





// adjl must be clear
void conv(AdjacMatrix const &adjm, AdjacList &adjl)
{
	adjl.ribs.resize(adjm.n);
	for(int i = 0; i < adjm.n; ++i)
	{
		for(int j = 0; j < adjm.n; ++j)
		{
			if(adjm[i][j])
				adjl[i].push_back(j);
		}
	}
	return;
}

// adjm must be clear
void conv(AdjacList const &adjl, AdjacMatrix &adjm)
{
	adjm.init( adjl.n() ).zeroize();
	for(int i = 0; i < adjl.n(); ++i)
	{
		for(auto b = adjl[i].begin(), e = adjl[i].end(); b != e; ++b)
			adjm[i][*b] = 1;
	}
	return;
}





// end



using namespace std;





// objects
char const *INPUT_FILE_NAME = "input.txt";
char const *OUTPUT_FILE_NAME = "output.txt";





// main
int main( int argc, char *argv[] )
{
	AdjacMatrix adjm;
	AdjacList adjl;
	FILE *file;

	file = fopen(INPUT_FILE_NAME, "r");
	adjm.scann(file);
	fclose(file);

	conv(adjm, adjl);
	file = fopen(OUTPUT_FILE_NAME, "w");
	adjl.print1(file);
	fclose(file);



	return 0;
}





// end
