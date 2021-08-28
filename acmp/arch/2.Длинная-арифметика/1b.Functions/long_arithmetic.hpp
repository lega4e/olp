#ifndef LONG_ARIPHMETHIC_HPP
#define LONG_ARIPHMETHIC_HPP

#include <cstring>
#include <stack>




// objects, structs
constexpr unsigned int const BASE = 1000u;



struct BigInteger
{
	unsigned int size, capacity;
	short *d;
};





// functions
template<class Ostream>
Ostream &print(
	Ostream &os,
	BigInteger const &bi
)
{
	if(bi.size)
	{
		os << *(bi.d+bi.size-1);
		for(auto *b = bi.d+bi.size-2, *e = bi.d-1; b > e; --b)
		{
			if( *b < 100 )
			{
				os << '0';
				if( *b < 10 )
					os << '0';
			}
			os << *b;
		}
	}
	return os;
}



// help
void read_bigint(
	char const *begin, unsigned int n,
	BigInteger &bi
);


inline void zeroize(
	BigInteger &bi
)
{
	std::memset( bi.d, 0, sizeof(*bi.d)*bi.capacity );
	return;
}





void addition(
	BigInteger const &lhs,
	BigInteger const &rhs,
	BigInteger &result
);



void substraction(
	BigInteger const &lhs,
	BigInteger const &rhs,
	BigInteger &result
);




void multiplication(
	BigInteger const &lhs,
	BigInteger const &rhs,
	BigInteger &result
);


void multiplicate_decomposition(
	BigInteger const &bi,
	std::stack<char> &result
);

void multiplicate_decomposition(
	unsigned long long bi,
	std::stack<char> &result
);

void multiplication_log(
	BigInteger const &lhs,
	BigInteger const &rhs,
	BigInteger &result
);





#endif
