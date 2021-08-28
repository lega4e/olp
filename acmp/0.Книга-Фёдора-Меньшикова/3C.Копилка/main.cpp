#include <iostream>
#include <fstream>
#include <map>


using namespace std;





// structs
struct Token
{
	int p, w; // price and weight
};





char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

int toklen;
Token *tokens;
pair<int, int> *calculated;

int weight;





// functions
pair<int, int> minmax_for_weight(int w)
{
	if( w < 0 )
	{
		return { -1, -1 };
	}

	if(calculated[w].first != -2)
	{
		return calculated[w];
	}

	pair< int, int > result{ -1, -1 };
	pair< int, int > temp;
	for(auto *b = tokens, *e = tokens+toklen; b != e; ++b)
	{
		temp = minmax_for_weight(w - b->w);
		if(temp.first != -1)
		{
			if( temp.first + b->p < result.first || result.first == -1 )
			{
				result.first = temp.first + b->p;
			}
			if( temp.second + b->p > result.second)
			{
				result.second = temp.second + b->p;
			}
		}
	}

	calculated[w] = result;
	return result;
}




int main( int argc, char *argv[] )
{
	// input
	{
		ifstream fin(INPUT_FILE_NAME);

		// weights
		int e, f;
		fin >> e >> f;
		weight = f-e;

		// token counts
		fin >> toklen;
		tokens = new Token[toklen];

		// token characteristics
		for(auto *b = tokens, *e = tokens+toklen; b != e; ++b)
		{
			fin >> b->p >> b->w;
		}
		calculated = new pair<int, int>[ weight+1 ];
		calculated[0] = { 0, 0 };
		for(auto *b = calculated+1, *e = calculated+weight+1; b != e; ++b)
		{
			*b = { -2, -2 };
		}
	}


	// calculate
	auto const result = minmax_for_weight( weight );


	// output
	if(result.first == -1)
		ofstream(OUTPUT_FILE_NAME) << "This is impossible." << flush;
	else
		ofstream(OUTPUT_FILE_NAME) << result.first << " " << result.second << flush;

	return 0;
}





// end
