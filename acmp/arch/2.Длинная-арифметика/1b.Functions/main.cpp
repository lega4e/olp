#include <iostream>
#include <fstream>
#include <string>

#include "long_arithmetic.hpp"


using namespace std;





char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





int main( int argc, char *argv[] )
{
	BigInteger a, b, c;
	{
		string lhs, rhs;
		ifstream(INPUT_FILE_NAME) >> lhs >> rhs;

		read_bigint( lhs.data(), lhs.size(), a );
		read_bigint( rhs.data(), rhs.size(), b );
	}

	// addition&sub
/*
 *         c.size = 0;
 *         c.capacity = max(a.size, b.size)+1;
 *         c.d = new short[ c.capacity ];
 * 
 *         // addition(a, b, c);
 *         substraction(a, b, a);
 */



	// multiplication
	c.size = 0;
	c.capacity = a.size + b.size;
	c.d = new short[ c.capacity ];
	zeroize(c);

	multiplication(a, b, c);



	// print
	// print(cout, c) << endl;
	{
		ofstream fout(OUTPUT_FILE_NAME);
		print(fout, c) << flush;
	}

	return 0;

}





// end
