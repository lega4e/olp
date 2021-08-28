
#include <cstring>
#include <iostream>
#include <fstream>

#include <clever/BigInteger.cpp>
#include <clever/types.hpp>

using namespace std;



char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

ofstream fout(OUTPUT_FILE_NAME);

void division(
	BigInteger const &lhs,
	ushort rhs,
	BigInteger &target
)
{
	std::vector< ushort > result;

	ulong temp = 0;
	for(auto *b = lhs.d+lhs.size-1, *e = lhs.d-1; b != e; --b)
	{
		temp += *b;
		result.push_back( temp/rhs );
		fout << "*b: " << *b << std::endl;
		fout << "temp: " << temp << std::endl;
		fout << "result.back(): " << result.back() << std::endl;

		temp = ( *b - rhs*result.back() % BASE ) * BASE;
		fout << "temp again: " << temp << std::endl;
		fout << "-----------------------------------" << std::endl;
	}

	auto
		beg = result.crbegin(),
		end = result.crend();

	while( *std::prev(end) == 0 && std::prev(end) != beg )
	{
		--end;
	}

	std::copy(
		beg, end, target.d
	);

	target.size = end-beg;
	if(!target.size)
	{
		target.d[0] = 0;
		target.size = 1;
	}

	return;

}





int main( int argc, char *argv[] )
{
	BigInteger a, res;
	unsigned long long b;
	{
		string f;
		ifstream(INPUT_FILE_NAME) >> f >> b;
		a.init( f.data(), f.size() );
	}
	res.init( a.size );
	res.zeroize();

	cout << a << endl << b << endl;
	division(a, b, res);
	fout << res << flush;




	return 0;
}





// end
