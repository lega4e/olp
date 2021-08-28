#include <iostream>
#include <fstream>


using namespace std;





char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";


bool less_string( string const &lhs, string const &rhs )
{
	if(lhs.size() < rhs.size())
		return true;
	if(lhs.size() > rhs.size())
		return false;

	return lhs < rhs;
}



int main( int argc, char *argv[] )
{

	string f, s, t;
	string *res;
	ifstream(INPUT_FILE_NAME) >> f >> s >> t;

	if(less_string(f, s))
	{
		if(less_string(s, t))
			res = &t;
		else
			res = &s;
	}
	else
	{
		if(less_string(f, t))
			res = &t;
		else
			res = &f;
	}

	ofstream(OUTPUT_FILE_NAME) << *res;

	return 0;
}





// end
