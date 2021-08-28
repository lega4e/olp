#ifndef BIG_INT_HPP
#define BIG_INT_HPP





class BigInt
{
public:
	// types, constants
	typedef unsigned int size_type;

	constexpr size_type const BASE = 1000;



	// creation and destroy
	BigInt();
	BigInt( unsigned long long int val );
	BigInt( BitInt const & );
	~BitInt();



	// info-methods
	size_type size() const;
	size_type capacity() const;



private:
	size_type size_, capacity_;
	short *data_;



};







#endif
