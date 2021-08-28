#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

vector< unsigned int > simple;

bool is_simple( unsigned int i )
{
	unsigned int root = ceil( sqrt(i) );
	for(
		auto b = simple.begin(), e = simple.end();
		b != e && *b <= root;
		++b
	)
	{
		if(i % *b == 0)
			return false;
	}
	return true;
}







int main( int argc, char *argv[] )
{
	unsigned int b, e;
	ifstream(INPUT_FILE_NAME) >> b >> e;

	simple.reserve(512);

	for(unsigned int i = 2; i <= e; ++i)
	{
		if(is_simple(i))
		{
			simple.push_back(i);
		}
	}

	{
		ofstream fout(OUTPUT_FILE_NAME);
		auto it = lower_bound(
			simple.cbegin(), simple.cend(), b
		);
		auto e = simple.end();
		if(it == e)
		{
			fout << "Absent";
		}
		else do
		{
			fout << *it << '\n';
		} while(++it != e);

		fout << flush;
	}

	return 0;
}





// end
