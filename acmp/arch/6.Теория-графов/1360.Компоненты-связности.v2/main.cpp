#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iterator>
#include <map>
#include <vector>


using namespace std;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";






// main
int main( int argc, char *argv[] )
{
	int n;
	int *groups;
	int edgec;
	map<int, vector<int>> counts;

	// input, calc groups
	{
		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i%i", &n, &edgec);
		groups = new int[n];
		memset(groups, 0, sizeof *groups * n);

		int where = 1;
		int first, second;
		for(int i = 0; i < edgec; ++i)
		{
			// read edge
			fscanf(file, "%i%i", &first, &second);
			--first;
			--second;

			// correct
			if(groups[first] > groups[second])
				swap(first, second);

			if(!groups[first])
			{
				if(!groups[second])
				{
					groups[first] = groups[second] = where;
					counts[where] = { first, second };
					++where;
				}
				else
				{
					groups[first] = groups[second];
					counts[ groups[first] ].push_back(first);
				}
			}
			else if(groups[first] != groups[second])
			{
				auto it = counts.find( groups[second] );
				for(auto i : it->second)
				{
					groups[i] = groups[first];
				}
				copy(
					it->second.cbegin(), it->second.cend(),
					back_inserter( counts[ groups[first] ] )
				);
				counts.erase( it );
			}
		}
		fclose(file);
	}



	// output
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		int summ = 0;
		for(auto b = counts.cbegin(), e = counts.cend(); b != e; ++b)
		{
			summ += b->second.size();
		}
		fprintf( file, "%i\n", (int)counts.size() + (n - summ) );


		for(auto b = counts.begin(), e = counts.end(); b != e; ++b)
		{
			sort(b->second.begin(), b->second.end());
			fprintf(file, "%lu\n", b->second.size());
			for(auto vb = b->second.cbegin(), ve = b->second.cend(); vb != ve; ++vb)
			{
				fprintf(file, "%i ", *vb+1);
			}
			fprintf(file, "\n");
		}

		// alone groups
		for(int i = 0; i < n; ++i)
		{
			if(!groups[i])
				fprintf(file, "1\n%i\n", i+1);
		}
		fclose(file);
	}

	

	return 0;
}





// end
