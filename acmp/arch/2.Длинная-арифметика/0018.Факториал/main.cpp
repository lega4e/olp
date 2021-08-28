#include <cstring>
#include <iostream>
#include <fstream>


using namespace std;





constexpr unsigned int const BASE = 1000u;
struct BigInteger
{
	int size, capacity;
	short *d;

	void init(int cap)
	{
		size = 0;
		capacity = cap;
		d = new short[ capacity ];
		return;
	}

	void init(char const *beg, unsigned int n)
	{
		size = capacity = n/3 + 
			( n%3 == 0 ? 0 : 1 );
		d = new short[ capacity ];

		int pos = 0;
		for(auto *b = beg+n-1, *e = beg-1; b > e; --b)
		{
			d[pos] = *b - '0';
			if( --b > e )
			{
				d[pos] += (*b-'0')*10;
				if( --b > e )
				{
					d[pos] += (*b-'0') * 100;
				}
			}
			++pos;
		}
		return;
	}

	inline void zeroize()
	{
		memset(d, 0, sizeof *d * capacity);
		return;
	}

	void reserve(int n)
	{
		if(capacity >= n)
			return;

		capacity = n;
		short *oldd = d;

		d = new short[ capacity ];
		zeroize();

		memcpy( d, oldd, sizeof *oldd * size );

		delete[] oldd;
		return;
	}

	template<typename Ostream>
	Ostream &print( Ostream &os ) const
	{
		if(!size)
			return os << '0';
		auto b = d+size-1, e = d-1;
		os << *b;
		--b;
		while(b != e)
		{
			if(*b < 100)
			{
				os << '0';
				if(*b < 10)
				{
					os << '0';
				}
			}
			os << *b;
			--b;
		}
		
		return os;
	}


};

template<typename Ostream>
Ostream &operator<<( Ostream &os, BigInteger const &toprint )
{
	return toprint.print(os);
}




char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// function
void multiplication(
	BigInteger const &lhs,
	BigInteger const &rhs,
	BigInteger &target
)
{
	unsigned long long temp, carry = 0u;
	unsigned int pos = 0u;
	for(int i = 0; i < rhs.size; ++i)
	{
		for(int j = 0; j < lhs.size; ++j)
		{
			temp = target.d[pos] + rhs.d[i] * lhs.d[j] + carry;
			carry = temp / BASE;
			target.d[pos] = temp - carry*BASE;
			++pos;
		}

		if(carry)
		{
			target.d[pos] += carry;
			carry = 0u;
		}

		pos -= lhs.size-1;
	}

	pos += lhs.size-1;
	target.size = 
		target.d[pos] ? pos+1 : pos;
	
	return;
}




int main( int argc, char *argv[] )
{
	BigInteger fac, first, second;
	{
		int n;
		ifstream(INPUT_FILE_NAME) >> n;
		fac.init( 1 );
		fac.d[0] = n;
		fac.size = 1;
	}
	if(fac.d[0] == 0)
	{
		ofstream(OUTPUT_FILE_NAME) << 1;
		return 0;
	}

	first.init( 32 );
	first.zeroize();

	second.init( 32 );
	second.zeroize();
	second.d[0] = 1;
	second.size = 1;

	BigInteger *lhs = &first, *target = &second;


	while(fac.d[0] != 1)
	{
		swap(lhs, target);
		multiplication(*lhs, fac, *target);
		if( target->size > target->capacity/2 )
		{
			target->reserve( target->capacity*2 );
			delete[] lhs->d;
			lhs->init( lhs->capacity*2 );
			lhs->zeroize();
		}
		else
			lhs->zeroize();

		--fac.d[0];
	}

	ofstream(OUTPUT_FILE_NAME) << *target;




	return 0;
}





// end
