#include <algorithm>
#include <cstdio>
#include <iterator>
#include <vector>


using namespace std;





// objects
constexpr char const *INPUT_FILE_NAME = "INPUT.TXT";
constexpr char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	int result;



	// calculate
	{
		int buf;
		int count;
		int loops = 0;
		vector<int> sections;
		decltype(sections)::iterator it;

		auto file = fopen(INPUT_FILE_NAME, "r");
		fscanf(file, "%i%i", &count, &buf);
		sections.push_back(buf);
		--count;

		while(count)
		{
			fscanf(file, "%i", &buf);
			if(loops == 0)
			{
				if(buf != sections.front())
					sections.push_back(buf);
				else
				{
					loops = 1;
					it = sections.begin() + 1;
				}
			}
			else
			{
				if(it == sections.end())
				{
					it = sections.begin();
					++loops;
				}
				if(buf == *it)
				{
					++it;
				}
				else
				{
					auto vecbuf = sections;
					while(--loops)
					{
						copy( 
							vecbuf.begin(), vecbuf.end(),
							push_iterator(sections)
						);
					}
				}
			}
		}
	}

	
	
	// output
output_label:
	{
		auto file = fopen(OUTPUT_FILE_NAME, "w");
		fprintf(file, "%i", result);
		fflush(file);
		fclose(file);
	}



	return 0;
}





// end
