#include <cstring>
#include <iostream>
#include <fstream>


using namespace std;


constexpr unsigned int const BASE = 10000u;
struct BigInteger
{
	unsigned int size, capacity;
	unsigned short *d;



	// creation&destroy
	BigInteger &init( unsigned int cap = 0 )
	{
		capacity = cap;
		size = 0;
		if(capacity)
			d = new unsigned short[capacity];
		return *this;
	}

	BigInteger &init(char const *num, unsigned int n)
	{
		while( *num == '0' )
		{
			++num;
			--n;
		}

		size = capacity = n / 4 + 
			( n % 4 == 0 ? 0 : 1 );
		d = new unsigned short[ capacity ];

		auto it = d;
		for( auto b = num+n-1, e = num-1; b > e; --b )
		{
			*it = *b-'0';
			if( --b > e )
			{
				*it += (*b-'0') * 10;
				if( --b > e )
				{
					*it += (*b-'0') * 100;
					if( --b > e )
						*it += (*b-'0') * 1000;
				}
			}
			++it;
		}

		return *this;
	}

	inline BigInteger &free()
	{
		delete[] d;
		return *this;
	}

	inline BigInteger &zeroize()
	{
		memset( d, 0, sizeof *d * capacity );
		return *this;
	}

	BigInteger &reserve( unsigned int cap )
	{
		if(capacity >= cap)
			return *this;

		auto *oldd = d;
		capacity = cap;
		d = new unsigned short[capacity];
		zeroize();
		memcpy( d, oldd, sizeof *d * size );
		delete[] oldd;

		return *this;
	}



	template<typename Ostream>
	Ostream &print( Ostream &os ) const
	{
		if(!size)
			return os;

		auto b = d+size-1, e = d-1;
		os << *b;
		while( --b != e )
		{
			if(*b < 1000)
			{
				os << '0';
				if(*b < 100)
				{
					os << '0';
					if(*b < 10)
					{
						os << '0';
					}
				}
			}
			os << *b;
		}

		return os;
	}
};

template<typename Ostream>
Ostream &operator<<( Ostream &os, BigInteger const &toprint )
{
	return toprint.print(os);
}

void multiplication(
	BigInteger const &lhs,
	BigInteger const &rhs,
	BigInteger &target
)
{
	unsigned long long temp;
	unsigned long long carry = 0;

	auto it = target.d;
	for(auto *rb = rhs.d, *re = rhs.d+rhs.size; rb != re; ++rb)
	{
		for(auto *lb = lhs.d, *le = lhs.d+lhs.size; lb != le; ++lb)
		{
			temp = *it + *rb * *lb + carry;
			carry = temp / BASE;
			*it = temp - carry*BASE;
			++it;
		}

		if(carry)
		{
			*it = carry;
			carry = 0;
		}

		it -= lhs.size-1;
	}

	it += lhs.size-1;
	target.size =
		*it ? it-target.d+1 : it-target.d;
	
	return;
}

char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





int main( int argc, char *argv[] )
{
	int n;
	ifstream(INPUT_FILE_NAME) >> n;
	if( n == 0 )
	{
		ofstream(OUTPUT_FILE_NAME) << 0;
		return 0;
	}
	
	BigInteger ff, mult, multbuf;

	ff.init(1);
	ff.d[0] = 45;
	ff.size = 1;

	mult.init(16);
	mult.d[0] = 1;
	mult.size = 1;

	multbuf.init(16);
	multbuf.zeroize();

	for(int i = 0; i < n; ++i)
	{
		multiplication(mult, ff, multbuf);
		swap(mult, multbuf);
		if(mult.size > mult.capacity/2)
		{
			mult.reserve( mult.capacity*2 );
			multbuf.free().
				init( mult.capacity*2 );
		}
		multbuf.zeroize();
	}

	ofstream(OUTPUT_FILE_NAME) << mult << flush;

	return 0;
}





// end
