#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;





char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

int cards[5];

vector<
	vector<int>
> equals()
{
	vector< vector<int> > mainvec;
	decltype(mainvec)::iterator it;
	for(int i = 0; i < 5; ++i)
	{
		it = find_if(
			mainvec.begin(), mainvec.end(),
			[&](vector<int> const &vec)
			{
				return cards[vec.front()] == cards[i];
			}
		);

		if(it == mainvec.end())
		{
			mainvec.push_back( {i} );
		}
		else
		{
			it->push_back(i);
		}
	}
	return mainvec;
}

bool is_straight()
{
	std::sort(cards, cards+5);
	for(auto *b = cards, *e = cards+4; b != e; ++b)
	{
		if(*b+1 != *(b+1))
			return false;
	}
	return true;
}






int main( int argc, char *argv[] )
{
	ifstream(INPUT_FILE_NAME) >>
		cards[0] >> cards[1] >> cards[2] >>
		cards[3] >> cards[4];

	auto vec = equals();


	ofstream fout(OUTPUT_FILE_NAME);
	if(vec.size() == 1)
	{
		fout << "Impossible" << flush;
	}
	else if( any_of(
		vec.begin(), vec.end(),
		[](vector<int> const &vec)
		{
			return vec.size() == 4;
		}
	) )
	{
		fout << "Four of a Kind" << flush;
	}
	else if( vec.size() == 2 )
	{
		fout << "Full House" << flush;
	}
	else if(is_straight())
	{
		fout << "Straight" << flush;
	}
	else if( any_of(
		vec.begin(), vec.end(),
		[](vector<int> const &vec)
		{
			return vec.size() == 3;
		}
	) )
	{
		fout << "Three of a Kind" << flush;
	}
	else if( vec.size() == 3 )
	{
		fout << "Two Pairs" << flush;
	}
	else if(vec.size() == 4 )
	{
		fout << "One Pair" << flush;
	}
	else
	{
		fout << "Nothing" << flush;
	}

	return 0;
}





// end
