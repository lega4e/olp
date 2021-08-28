#include <iostream>
#include <fstream>
#include <queue>
#include <set>

#include <quix/Point.hpp>


using namespace std;
using namespace quix;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// functions
inline bool isvalid(PointI p)
{
	return p.x >= 0 && p.x < 4 && p.y >= 0 && p.y < 2;
}

inline char &at(string &s, PointI p)
{
	return s[ p.y*4 + p.x ];
}





// main
int main( int argc, char *argv[] )
{
	struct Stage
	{
		string s;
		int c = 0;
	};

	static constexpr PointI const OFFSET[4] = {
		{ 1, 0 }, { -1, 0 },
		{ 0, 1 }, { 0, -1 }
	};

	string begin, end;
	
	
	
	// input
	{
		string input;
		ifstream fin(INPUT_FILE_NAME);
		fin >> begin >> input;
		begin += input;
		fin >> end >> input;
		end += input;
	}
	
	
	
	// solve
	set<string> set;
	set.insert(begin);
	queue<Stage> que;
	que.push({begin, 0});

	Stage st;
	int pos;
	PointI cur, p;
	int res = -1;
	while(!que.empty())
	{
		st = que.front();
		que.pop();

		if(st.s == end)
		{
			res = st.c;
			break;
		}

		pos = (int)st.s.find('#');
		cur.x = pos%4, cur.y = pos/4;

		for(auto off : OFFSET)
		{
			p = cur + off;

			if(!isvalid(p))
				continue;

			swap(at(st.s, p), at(st.s, cur));
			if( set.insert(st.s).second )
				que.push( { st.s, st.c+1 } );
			swap(at(st.s, p), at(st.s, cur));
		}
	}
	
	
	
	// output
	ofstream(OUTPUT_FILE_NAME) << res << endl;





	return 0;
}





// end
