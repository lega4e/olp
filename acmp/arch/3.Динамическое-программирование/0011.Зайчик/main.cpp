#include <iostream>
#include <fstream>


using namespace std;





char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";

int k, n;





int calculate_variants()
{
	long long unsigned *variants = new long long unsigned[n+1];
	variants[0] = 1;
	variants[1] = 1;

	for(
		auto *varbeg = variants+2, *varend = variants+n+1;
		varbeg != varend;
		++varbeg
	)
	{
		*varbeg = 0;
		for(
			auto
				*curbeg = varbeg-1,
				*curend = max( variants-1, varbeg-k-1 );
			curbeg != curend;
			--curbeg
		)
		{
			*varbeg += *curbeg;
		}
	}

	return variants[n];
}





int main( int argc, char *argv[] )
{
	ifstream(INPUT_FILE_NAME) >> k >> n;
	ofstream(OUTPUT_FILE_NAME) << calculate_variants();

	return 0;
}





// end
