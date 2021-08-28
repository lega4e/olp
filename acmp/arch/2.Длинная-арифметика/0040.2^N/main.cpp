#include <cstring>
#include <iostream>
#include <fstream>

#include <clever/BigInteger.cpp>


using namespace std;





char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





int main( int argc, char *argv[] )
{
	BigInteger a, b, c;
	{
		string f, s;
		ifstream(INPUT_FILE_NAME) >> f >> s;
		a.init( f.data(), f.size() );
		b.init( s.data(), s.size() );
	}

	c.init( a.size + b.size ).
		zeroize();
	multiplication(a, b, c);
	ofstream(OUTPUT_FILE_NAME) <<
		// a << endl <<
		// b << endl << 
		c << flush;


	a.free();
	b.free();
	c.free();
	return 0;
}





// end
