#include <cmath>
#include <iostream>
#include <vector>


using namespace std;





// types
typedef long long llong;





// functions
void sieve_by_count(llong count, vector<llong> &sie)
{
	sie.assign(count * ceil(log(count)) * 6 / 5 + 5, 0);
	sie[0] = sie[1] = 1; // вычёркиваем 0 и 1
	for(llong i = 2; i < (llong)sie.size(); ++i)
	{
		if(sie[i])
			continue;
		for(llong j = i*i; j < (llong)sie.size(); j += i)
		{
			sie[j] = 1;
		}
	}
	return;
}





// main
int main( int argc, char *argv[] )
{
	int beg, end;
	vector<llong> sie;
	
	
	
	// input
	scanf("%i%i", &beg, &end);
	
	
	
	// solve
	sieve_by_count(end, sie);
	int ptr = 0;
	llong sum = 0;
	for(int i = 0; i < (int)sie.size(); ++i)
	{
		if(sie[i])
			continue;
		++ptr;
		if(ptr > end)
			break;
		if(ptr >= beg)
			sum += i;
	}
	
	
	
	// output
	cout << sum << endl;



	return 0;
}





// end
