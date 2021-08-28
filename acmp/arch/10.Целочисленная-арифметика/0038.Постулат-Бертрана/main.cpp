#include <algorithm>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// main
int main( int argc, char *argv[] )
{
	int n;
	int result;
	
	
	
	// input
	ifstream(INPUT_FILE_NAME) >> n;
	
	
	
	// calculate
	vector<int> simple{ 2 };

	for(
		int cur = 3, iroot = 1;
		cur < 2*n;
		cur += 2, iroot = (int)sqrt(cur)
	)
	{
		for(
			auto b = simple.begin()+1, e = simple.end();
			b != e && *b <= iroot; ++b
		)
		{
			if(cur % *b == 0)
				goto fail_label;
		}
		simple.push_back(cur);
	fail_label:
		;
	}
	

	
	// output
	result = simple.end() - upper_bound( simple.begin(), simple.end(), n );
	ofstream(OUTPUT_FILE_NAME) << result << endl;
	
	

	return 0;
}





// end
