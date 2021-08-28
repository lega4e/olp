#include <algorithm>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;





char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";




vector< unsigned int > find_simple_mults(
	unsigned int n
)
{
	vector< unsigned int > mults;
	mults.reserve(32u);

	vector< unsigned int > simples;
	simples.reserve(10000u);
	simples.push_back(2u);

	unsigned int p = simples.front();
	unsigned int root, nroot;
	while(n != 1)
	{
		if(n % p == 0)
		{
			mults.push_back(p);
			n /= p;
		}
		else
		{
			nroot = ( unsigned int )ceil( sqrt(n) );
again_label:
			if(p >= nroot)
			{
				mults.push_back(n);
				break;
			}
			++p;
			root = ( unsigned int )ceil( sqrt(p) );
			for(auto b = simples.begin(), e = simples.end(); b != e; ++b)
			{
				if(p % *b == 0)
					goto again_label;
				if(*b >= root)
					break;
			}
			simples.push_back(p);
		}
	}
	cout << "Simple.size: " << simples.size() << endl;
	return mults;
}





int main( int argc, char *argv[] )
{
	// input
	unsigned int n;
	ifstream(INPUT_FILE_NAME) >> n;

	// process
	auto mults = find_simple_mults(n);

	// output
	{
		ofstream fout(OUTPUT_FILE_NAME);
		// mults всегда содержит хотя бы один элемент
		fout << mults.front();
		for(auto b = mults.begin()+1, e = mults.end(); b != e; ++b)
		{
			fout << "*" << *b;
		}
		fout << flush;
	}

	return 0;
}





// end
