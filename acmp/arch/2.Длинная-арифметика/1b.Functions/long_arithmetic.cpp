#include <iostream>
#include <stack>

#include "long_arithmetic.hpp"





void read_bigint(
	char const *begin, unsigned int n,
	BigInteger &a
)
{
	a.size = a.capacity = n / 3 +
		( n % 3 == 0 ? 0 : 1 );
	a.d = new short[ a.capacity ];

	int pointer = 0;
	for(auto b = begin+n-1, e = begin-1; b > e; --b)
	{
		a.d[ pointer ] =
			int( *b - '0' );
		if( --b > e )
		{
			a.d[ pointer ] += int( *b - '0' ) * 10;
			if( --b > e )
			{
				a.d[ pointer ] += int( *b - '0' ) * 100;
			}
		}
		++pointer;
	}

	return;
}





void addition(
	BigInteger const &lhs,
	BigInteger const &rhs,
	BigInteger &result
)
{
	if(lhs.size < rhs.size)
	{
		addition( rhs, lhs, result );
		return;
	}


	// process
	unsigned long long temp;
	int carry = 0;

	for(unsigned int i = 0; i < rhs.size; ++i)
	{
		temp = lhs.d[i] + rhs.d[i] + carry;

		if( temp >= BASE )
		{
			temp -= BASE;
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		result.d[i] = temp;
	}

	for(unsigned int i = rhs.size; i < lhs.size; ++i)
	{
		temp = lhs.d[i] + carry;

		if(temp >= BASE)
		{
			temp -= BASE;
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		result.d[i] = temp;
	}

	result.size = lhs.size;
	if(carry)
	{
		result.d[ lhs.size ] = carry;
		++result.size;
	}

	return;
}





void substraction(
	BigInteger const &lhs,
	BigInteger const &rhs,
	BigInteger &result
)
{
	long long temp;
	int carry = 0;
	
	for(unsigned int i = 0; i < rhs.size; ++i)
	{
		temp = lhs.d[i] - rhs.d[i] + carry;

		if(temp < 0)
		{
			temp += BASE;
			carry = -1;
		}
		else
		{
			carry = 0;
		}
		result.d[i] = temp;
	}

	for( unsigned int i = rhs.size; i < lhs.size; ++i )
	{
		temp = lhs.d[i] + carry;

		if(temp < 0)
		{
			temp += BASE;
			carry = -1;
		}
		else
		{
			carry = 0;
		}
		result.d[i] = temp;
	}
	result.size = lhs.size;

	return;
}





void multiplication(
	BigInteger const &lhs,
	BigInteger const &rhs,
	BigInteger &result
)
{
	unsigned long long temp;
	unsigned long long carry = 0;

	int position = 0;
	for(size_t i = 0; i < rhs.size; ++i)
	{
		for(size_t j = 0; j < lhs.size; ++j)
		{
			temp = result.d[ position ] + rhs.d[i] * lhs.d[j] + carry;
			carry = temp / BASE;
			result.d[ position ] = temp - carry*BASE;
			++position;
		}

		if(carry)
		{
			result.d[ position ] += carry;
			carry = 0;
		}

		position -= lhs.size-1;
	}

	position += lhs.size-1;
	result.size =
		result.d[ position ] ? position+1 : position;
	
	return;
}



void multiplicate_decomposition(
	unsigned long long bi,
	std::stack<char> &result
)
{
	// '*' - multiplicate on 2
	// '+' - addition rhs
	while(bi != 1)
	{
		if(bi%2 == 1)
		{
			result.push('+');
		}

		result.push('*');

		bi /= 2;
	}

	return;
}

void multiplicate_decomposition(
	BigInteger const &bref,
	std::stack<char> &result
)
{
	// '*' - multiplicate on 2
	// '+' - addition rhs
	BigInteger bi;
	bi.size = bi.capacity = bref.size;
	bi.d = new short[ bi.capacity ];
	memcpy( bi.d, bref.d, sizeof *bi.d * bi.size );

	bool carry;
	while(bi.size != 1 || bi.d[0] != 1)
	{
		if(bi.d[0]%2 == 1)
		{
			result.push('+');
		}
		result.push('*');

		carry = false;
		for(auto *b = bi.d+bi.size-1, *e = bi.d-1; b != e; --b)
		{
			if(carry)
			{
				carry = *b%2 == 1;
				*b /= 2;
				*b += BASE/2;
			}
			else
			{
				carry = *b%2 == 1;
				*b /= 2;
			}
		}
		if( bi.d[bi.size-1] == 0 )
		{
			--bi.size;
		}
	}

	return;
}



void multiplication_log(
	BigInteger const &lhs,
	BigInteger const &rhs,
	BigInteger &result
)
{

	if(lhs.size < rhs.size)
	{
		multiplication(rhs, lhs, result);
		return;
	}

	result.size = lhs.size;
	std::memcpy( result.d, lhs.d, sizeof *lhs.d * lhs.size );

	std::stack<char> actions;
	multiplicate_decomposition(rhs, actions);
	std::cout << "actions.size(): " << actions.size() << std::endl;

	while(!actions.empty())
	{
		if(actions.top() == '*')
		{
			addition(result, result, result);
		}
		else
		{
			addition(result, lhs, result);
		}
		actions.pop();
	}

	return;
}





void division(
	BigInteger const &lhs,
	BigInteger const &rhs,
	BigInteger &result
)
{

}
	




// end
