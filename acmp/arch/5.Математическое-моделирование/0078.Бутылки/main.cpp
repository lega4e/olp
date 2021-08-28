#include <algorithm>
#include <iostream>
#include <fstream>


using namespace std;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";


int f, p;
constexpr int const N = 5;
int w[N] = { 0 };




class IntIterator
{
public:
	IntIterator(int val = 0): val_(val) {}



	IntIterator &operator++()
	{
		++val_;
		return *this;
	}
	IntIterator &operator--()
	{
		--val_;
		return *this;
	}

	IntIterator &operator+=(int n)
	{
		val_ += n;
		return *this;
	}
	IntIterator &operator-=(int n)
	{
		val_ -= n;
		return *this;
	}



	int operator*()
	{
		return val_;
	}


private:
	int val_;

};



// functions
void calculate_stage(int i)
{
	int upper = 1;
	int lower = upper-1;
	while(
		upper%f + upper/f*p < w[ i+1 ] 
	)
	{
		lower = upper;
		upper *= 2;
	}

	while(
		lower%f + lower/f*p < w[ i+1 ] 
	)
	{
		++lower;
	}

	
	// int distance;
	// while( lower+1 != upper )
	// {
		// distance = (upper - lower) / 2;
		// if(
			// (lower+distance)%f + (lower+distance)/f*p >=
			// w[ i+1 ]
		// )
		// {
			// upper = lower+distance;
		// }
		// else
		// {
			// lower = lower+distance;
		// }
	// }

	w[i] = lower;
	return;
}



void calculate()
{
	w[N-1] = f;

	for(int i = N-2; i >= 0; --i)
	{
		calculate_stage(i);
	}

	return;
}





// main
int main( int argc, char *argv[] )
{
	ifstream(INPUT_FILE_NAME) >> f >> p;
	calculate();
	ofstream(OUTPUT_FILE_NAME) << w[0];
	

	return 0;
}





// end
