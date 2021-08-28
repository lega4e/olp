#include <cmath>
#include <iostream>
#include <fstream>


using namespace std;





char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";


void process( int m, int n )
{
	int root;
	int summ;
	while(m <= n)
	{
		root = ceil( sqrt(m) );
		summ = 0;
		for(int i = 1; i <= root; ++i)
		{
			if( m % i == 0 )
			{
				summ += i;
				if(summ > m)
					break;
			}
		}
		if( summ == m )
			cout << summ << endl;
		++m;
	}
}



int main( int argc, char *argv[] )
{
	process(1000000, 2000000);

	return 0;
}





// end
