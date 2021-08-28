#include <iostream>
#include <fstream>


using namespace std;





// objects
char const *INPUT_FILE_NAME = "INPUT.TXT";
char const *OUTPUT_FILE_NAME = "OUTPUT.TXT";





// function
int digit_summ(int a)
{
	int result = 0;
	while(a)
	{
		result += a % 10;
		a /= 10;
	}
	return result;
}





// main
int main( int argc, char *argv[] )
{
	int n;
	
	
	
	// input
	ifstream(INPUT_FILE_NAME) >> n;
	
	
	
	// calculate
	int best = n;
	int bestdigsumm = digit_summ(best);
	for(int i = n-1, idigsumm; i >= 1; --i)
	{
		if(n % i)
			continue;
		idigsumm = digit_summ(i);
		if(idigsumm >= bestdigsumm)
		{
			best = i;
			bestdigsumm = idigsumm;
		}
	}
	
	
	
	// output
	ofstream(OUTPUT_FILE_NAME) << best << flush;
	
	

	return 0;
}





// end
