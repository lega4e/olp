#include <algorithm>
#include <iostream>
#include <fstream>
#include <stack>
#include <string>


using namespace std;





char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

string const OPEN_BRACKETS("([{");
string const CLOSE_BRACKETS(")]}");


bool assert_brackets(string const &s)
{
	stack<char> st;
	string::const_iterator strit;

	for(auto b = s.begin(), e = s.end(); b != e; ++b)
	{
		strit = find(
			OPEN_BRACKETS.begin(), OPEN_BRACKETS.end(),
			*b
		);
		if(strit != OPEN_BRACKETS.end())
		{
			st.push(*b);
		}
		else
		{
			strit = find(
				CLOSE_BRACKETS.begin(), CLOSE_BRACKETS.end(),
				*b
			);
			if(strit != CLOSE_BRACKETS.end())
			{
				if(
					st.empty() ||
					find(
						OPEN_BRACKETS.begin(), OPEN_BRACKETS.end(),
						st.top()
					) - OPEN_BRACKETS.begin() !=
					strit - CLOSE_BRACKETS.begin()
				)
					return false;
			}
			st.pop();

		}
	}

	return st.empty();
}



int main( int argc, char *argv[] )
{
	string s;
	{
		int slen;
		ifstream(INPUT_FILE_NAME) >> slen >> s;
	}


	if(assert_brackets(s))
	{
		ofstream(OUTPUT_FILE_NAME) << "Yes" << flush;
	}
	else
	{
		ofstream(OUTPUT_FILE_NAME) << "No" << flush;
	}


	return 0;
}





// end
