#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;





// types
typedef unsigned long long ullong;
struct Simple
{
	vector< unsigned int > nums = { 2, 3 };

	void reserve(unsigned int n)
	{
		if(nums.size() >= n)
			return;
		nums.reserve(n);
		unsigned int candidate = nums.back()+2;
		unsigned int size = nums.size();
		unsigned int root;
		while(size < n)
		{
			root = ( unsigned int )sqrt(candidate);
			for(
				auto b = nums.begin()+1, e = nums.end();
				*b <= root && b != e; ++b
			)
			{
				if( candidate % *b == 0 )
					goto while_continue;
			}
			nums.push_back(candidate);
			++size;

		while_continue:
			candidate += 2;
		}
		return;
	}
};




// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

Simple simple;





// functions
void decomposition(
	ullong number,
	vector<pair<ullong, int>> &vec
)
{
	ullong root = (ullong)sqrt(number);
	int scount = 100;
	simple.reserve(100);
	int realc = 0;
	for(
		auto b = simple.nums.begin(), e = simple.nums.end();
		*b <= root && b != e;
		++b, ++realc
	)
	{
		if(number % *b == 0)
		{
			vec.push_back({*b, 1});
			number /= *b;
			while(number % *b == 0)
			{
				++vec.back().second;
				number /= *b;
			}
			root = (ullong)sqrt(number);
			if(number == 1)
				return;
		}
		if(realc == scount-1)
		{
			scount *= 2;
			simple.reserve(scount);
			b = simple.nums.begin() + realc;
			e = simple.nums.end();
		}
	}
	vec.push_back({number, 1});

	return;
}





// main
int main( int argc, char *argv[] )
{
	ullong a, b;
	ullong result;
	
	
	
	// input
	ifstream(INPUT_FILE_NAME) >> a >> b;
	
	
	
	// calculate
		// decomposition
	vector< pair<ullong, int> > adec, bdec, fusion;
	decomposition(a, adec);
	decomposition(b, bdec);
		// fusion
	{
		auto abeg = adec.begin(), aend = adec.end();
		auto bbeg = bdec.begin(), bend = bdec.end();
		while(abeg < aend || bbeg < bend)
		{
			if(abeg == aend)
				goto add_bbeg_label;
			if(bbeg == bend)
				goto add_abeg_label;
			if(abeg->first < bbeg->first)
				goto add_abeg_label;
			if(bbeg->first < abeg->first)
				goto add_bbeg_label;

			fusion.push_back({
				abeg->first, max(abeg->second, bbeg->second)
			});
			++abeg;
			++bbeg;
			continue;

		add_abeg_label:
			fusion.push_back(*abeg);
			++abeg;
			continue;

		add_bbeg_label:
			fusion.push_back(*bbeg);
			++bbeg;
			continue;
		}
	}
		// result
	result = 1;
	for(auto b = fusion.begin(), e = fusion.end(); b != e; ++b)
	{
		result *= pow(b->first, b->second);
	}
	
	

	// output
	ofstream(OUTPUT_FILE_NAME) << result << flush;

	

	return 0;
}





// end
