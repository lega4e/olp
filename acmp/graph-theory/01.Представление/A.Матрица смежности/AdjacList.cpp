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

	AdjacList &scan_riblist(FILE *file = stdin, bool oriented = false) // read n m v11 v12 ...
	{
		int n, m;
		fscanf(file, "%i%i", &n, &m);
		ribs.resize(n);

		int first, second;
		for(int i = 0; i < m; ++i)
		{
			fscanf(file, "%i%i", &first, &second);
			ribs[first].push_back(second);

			if(!oriented)
				ribs[second].push_back(first);
		}

		return *this;
	}

	AdjacList &scan_riblist1(FILE *file = stdin, bool oriented = false) // read n m v11 v12 ...
	{
		int n, m;
		fscanf(file, "%i%i", &n, &m);
		ribs.resize(n);

		int first, second;
		for(int i = 0; i < m; ++i)
		{
			fscanf(file, "%i%i", &first, &second);
			--first, --second;
			ribs[first].push_back(second);

			if(!oriented)
				ribs[second].push_back(first);
		}

		return *this;
	}



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
