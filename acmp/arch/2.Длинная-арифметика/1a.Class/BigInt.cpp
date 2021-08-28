#include "BigInt.hpp"

#include <algorithm>





// creation and destroy
BigInt::BigInt(): size_(0), capacity(0), data_(nullptr) {}

BigInt::BigInt( unsigned long long int val )
{

}

BigInt::BigInt( BigInt const &tocp ):
	size_(tocp.size_), capacity_(tocp.size_),
	data_(new short[ tocp.size_ ])
{
	std::copy( 
		tocp.data_, tocp.data_+tocp.size_,
		data_
	);
	return;
}

BigInt::~BigInt();





// info-methods
BigInt::size_type BigInt::size() const;
BigInt::size_type BigInt::capacity() const;





// end
