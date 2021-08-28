#include <algorithm>
#include <iostream>
#include <fstream>
#include <map>
#include <utility>


using namespace std;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";


int n;
int *data;

map<
	pair< int *, int * >,
	pair< int, int >
> calculated;





// functions
std::pair<int, int> calculate(int *beg, int *end)
{
	auto it = calculated.find( {beg, end} );
	if(it != calculated.end())
	{
		return it->second;
	}

	if(end - beg == 1)
	{
		calculated[ make_pair(beg, end) ] =
			{ *beg, 0 };
		return { *beg, 0 };
	}
	if(end - beg == 2)
	{
		auto mm = minmax(beg[0], beg[1]);
		calculated[ make_pair(beg, end) ] =
			{ mm.second, mm.first };
		return { mm.second, mm.first };
	}

	auto left = calculate(beg+1, end);
	auto right = calculate(beg, end-1);
	auto res = 
		left.second + *beg > right.second + *(end-1) ?
			make_pair( left.second + *beg, left.first ) :
			make_pair( right.second + *(end-1), right.first );

	calculated[ make_pair(beg, end) ] = res;
	return res;
}





// main
int main( int argc, char *argv[] )
{
	{
		ifstream fin(INPUT_FILE_NAME);
		fin >> n;
		data = new int[n];
		for(auto *b = data, *e = data+n; b != e; ++b)
		{
			fin >> *b;
		}
	}

	auto result = calculate(data, data+n);

	{
		ofstream fout(OUTPUT_FILE_NAME);
		if(result.first > result.second)
		{
			fout << 1;
		}
		else if(result.second > result.first)
		{
			fout << 2;
		}
		else
			fout << 0;
		fout << flush;
		cout << "count: " << calculated.size() << endl;
	}

	return 0;
}





// end
